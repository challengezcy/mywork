/*HEADER******************************************************************
* $Filenam:     vf_audio_if.c  $
 * $Revision:   1.0  $
 * $Author:     jelphi zhang $
 * $Date:       4/18/2008  $
 *
 * Project: VFxxx MQX-Based LCDC BSP
 *
 * Description:
 *    This file contains rtc inteface control souce file for vfxxxx multimedia soc 
 *    
 * Revision History:
 *  04/18/2008 initial version

*END*********************************************************************/

#include "mqx.h"
#include "bsp.h"
#include "io_prv.h"
#include "fio_prv.h"
#include "timer.h"
#include "io_prv.h"
#include "rtc_if.h"
#include "rtc_if_prv.h"
#include "vf1002_rtc.h"
#include "vf_rtc_drv.h"

extern uint_32 _vf_rtc_init(IO_RTC_IF_DEVICE_STRUCT_PTR,char_ptr);
extern uint_32 _vf_rtc_deinit(VF_RTC_IF_INIT_STRUCT_PTR,VF_RTC_IF_INFO_STRUCT_PTR);
extern uint_32 _vf_rtc_ioctl(IO_RTC_IF_DEVICE_STRUCT_PTR, uint_32, uint_32_ptr);
extern void    _vf_rtc_int_isr(VF_RTC_IF_INFO_STRUCT_PTR io_info_ptr);

static uint_32 baseyear = 2000;	//2000 year
static uint_32 basedate = 100;	//01.00 date
static uint_32 basetime = 0;	//00:00:00 time

static uint_32 comyear[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
static uint_32 intercalary[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

static uint_32 comyearmon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static uint_32 intercalarymon[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static uint_32 getdays(uint_32 value, uint_32 flag)
{
	uint_32 *base;
	int i;
	int tmp, tmp1;
	
	if(flag == 0)
		base = comyear;
	else
		base = intercalary;

	tmp = value /100;
	return (base[tmp]+value %100);
}

static uint_32 getmon(uint_32 value, uint_32 flag, uint_32 *date)
{
	uint_32 *base;
	int i;
	if(flag == 0)
		base = comyear;
	else
		base = intercalary;

	for(i=1; i<13; i++){
		if(value <= base[i]){
			*date = value - base[i-1];
			return (i-1);
		}
	}
}

static uint_32 time2value(CONFIG_RTC _PTR_ para)
{
	CONFIG_RTC  tmp;
	uint_32 year, date, time;
	int flag = -1;	
	uint_32 i, count;
	uint_32 tmpvalue = 0;
	uint_32 value = 0;

	if(para->YEAR == 0)
		year = tmp.YEAR - baseyear;
	else 
		year = para->YEAR - baseyear;

	if(para->DATE == 0)
		date = tmp.DATE - basedate;
	else 
		date = para->DATE - basedate;

	if(para->TIME == 0)
		time = tmp.TIME;
	else
		time = para->TIME;

	for(i=0, count=0; i<=year; ){
		if(((baseyear+i)%400 == 0) || (((baseyear+i)%4 == 0)&&((baseyear+i)%100 != 0)))
			count++;
		i++;
	}	

	flag = (((baseyear+year)%400 == 0) || (((baseyear+year)%4 == 0)&&((baseyear+year)%100 != 0)))?1:0;
	if(flag == 1){
		tmpvalue = year*365+count-1;
	}else{
		tmpvalue = year*365+count;
	}
	
	 tmpvalue += getdays(date, flag);
	 value = ((tmpvalue*24+time/10000)*60+(time%10000)/100)*60 + (time%100);

	 return value;
}

static void value2time(CONFIG_RTC _PTR_ para, uint_32 value)
{
	uint_32	sec, min, hour;
	uint_32 	tmpdate;
	uint_32	date, mon, year;
	uint_32    day;
	int flag = -1;	
	uint_32 i, count;

	sec = value%60;
	value = value/60;
	min = value%60;
	value = value/60;
	hour = value%24;
	value = value/24;

	tmpdate = value%365;
	year = value/365;
	value = tmpdate;
	for(i=0, count=0; i<=year; ){
		if(((baseyear+i)%400 == 0) || (((baseyear+i)%4 == 0)&&((baseyear+i)%100 != 0)))
			count++;
		i++;
	}

	flag = (((baseyear+year)%400 == 0) || (((baseyear+year)%4 == 0)&&((baseyear+year)%100 != 0)))?1:0;

	if(value > count){
		tmpdate = (value-count)%365;
		if(flag == 1)
			tmpdate += 1;
	}else if(value == count){
		if(year > 0){
			if(flag == 1)
				count -= 1;
			year = year -1;
			flag = (((baseyear+year)%400 == 0) || (((baseyear+year)%4 == 0)&&((baseyear+year)%100 != 0)))?1:0;
			if(flag == 1)
				tmpdate += 366;
			else
				tmpdate += 365;
			tmpdate = (tmpdate-count);
			if(flag == 1 && tmpdate > 366){
				tmpdate -= 366;
				year += 1;
				flag = 0;
			}else if(flag != 1 && tmpdate > 365){
				tmpdate -= 365;
				year += 1;
				flag = (((baseyear+year)%400 == 0) || (((baseyear+year)%4 == 0)&&((baseyear+year)%100 != 0)))?1:0;
			}	
		}else{
			if(flag == 1)
				tmpdate = 1;
			else
				tmpdate = 0;
		}
	}else{
		if(year > 0){
			if(flag == 1)
				count -= 1;
			year = year -1;
			flag = (((baseyear+year)%400 == 0) || (((baseyear+year)%4 == 0)&&((baseyear+year)%100 != 0)))?1:0;
			if(flag == 1)
				tmpdate += 366;
			else
				tmpdate += 365;
			tmpdate = (tmpdate-count);
		}else
			tmpdate = 0;		
	}

	mon = getmon(tmpdate, flag, &date);

	para->DATE = basedate+mon*100+date;
	para->YEAR = baseyear+year;
	para->TIME = (hour*100+min)*100+sec;
}

static uint_32 timevalid(CONFIG_RTC _PTR_ para, uint_32 value)
{
	uint_32 year, mon, day;
	uint_32 hour, min, sec;
	uint_32 flag;
	uint_32 *base;
	CONFIG_RTC  tmp;

	if(para->YEAR == 0 && para->DATE == 0 && para->TIME == 0)
		return 1;
	
	value2time(&tmp, value);
	if(para->YEAR == 0)
		para->YEAR  = tmp.YEAR;
	if(para->DATE == 0)
		para->DATE = tmp.DATE;
	if(para->TIME == 0)
		para->TIME = tmp.TIME;
	
	year = para->YEAR;
	mon = para->DATE/100;
	day = para->DATE%100;
	hour = para->TIME/10000;
	min = (para->TIME%10000)/100;
	sec = para->TIME%100;
	if(year < (baseyear) ||year > (baseyear + 135) || mon < 1 || mon > 12 || hour > 23 || min > 59 || sec > 59)
		return 1;
	flag = (((baseyear+year)%400 == 0) || (((baseyear+year)%4 == 0)&&((baseyear+year)%100 != 0)))?1:0;
	if(flag == 0)
		base = comyearmon;
	else
		base = intercalarymon;

	if(day > base[mon])
		return 1;

	return 0;
}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : _io_vf_rtc_if_install
* Returned Value   : uint_32 a task error code or MQX_OK
* Comments         :
*    Install an rtc device.
*
*END*----------------------------------------------------------------------*/

uint_32 _vf_rtc_if_install
   (
      /* [IN] A string that identifies the device for fopen */
      char_ptr           identifier,
  
      /* [IN] The I/O init data pointer */
      pointer            init_data_ptr
    )
{ /* Body */

   return _io_rtc_if_install(identifier,
      (uint_32 (_CODE_PTR_)(pointer, char _PTR_))_vf_rtc_init,
      (uint_32 (_CODE_PTR_)(pointer, pointer))_vf_rtc_deinit,
      NULL,
      NULL,
      (uint_32 (_CODE_PTR_)(pointer, uint_32, uint_32_ptr))_vf_rtc_ioctl, 
      init_data_ptr);

} /* Endbody */


/*FUNCTION****************************************************************
* 
* Function Name    : _vf_rtc_init
* Returned Value   : MQX_OK or a mqx error code
* Comments         :
*    This function initializes i2s/ac97 controller and codec.
*
*END*********************************************************************/

uint_32 _vf_rtc_init
   (
      /* [IN] the initialization information for the device being opened */
      IO_RTC_IF_DEVICE_STRUCT_PTR   io_dev_ptr,

      /* [IN] the rest of the name of the device opened */
      char_ptr                        open_name_ptr

   )
{ /* Body */
   
   VF_RTC_IF_INFO_STRUCT                   _PTR_ io_info_ptr;
   VF_RTC_IF_INIT_STRUCT                   _PTR_ io_init_ptr;
   VF_RTC_REGS_T                 _PTR_ regs_ptr;
   uint_32                                     result;  
   
   io_init_ptr = io_dev_ptr->DEV_INIT_DATA_PTR;
   io_info_ptr = (VF_RTC_IF_INFO_STRUCT _PTR_)(_mem_alloc_system_zero((uint_32)sizeof(VF_RTC_IF_INFO_STRUCT)));
#if MQX_CHECK_MEMORY_ALLOCATION_ERRORS
   if (io_info_ptr == NULL) {
      return(MQX_OUT_OF_MEMORY);
   } /* Endif */
#endif
   io_dev_ptr->DEV_INFO_PTR = io_info_ptr;
   //get init value
   io_info_ptr->INIT = *io_init_ptr;   
   /* reg_ptr will point to the rtc Registers */
   regs_ptr  =  (VF_RTC_REGS_T _PTR_)io_info_ptr->INIT.BASE_ADDRESS;
   io_info_ptr->RTC_REGS_PTR   = regs_ptr;   
   //set up rtc interrupt
   io_info_ptr->RTC_VECTOR = BSP_RTC_INTERRUPT_VECTOR;
   io_info_ptr->OLD_ISR_DATA = _int_get_isr_data(io_info_ptr->RTC_VECTOR);
   io_info_ptr->OLD_ISR_EXCEPTION_HANDLER =
	   _int_get_exception_handler(io_info_ptr->RTC_VECTOR);
   io_info_ptr->OLD_ISR =
      _int_install_isr(io_info_ptr->RTC_VECTOR,_vf_rtc_int_isr,io_info_ptr);   
   //now init ssp regs with defult values
   //	APB_RTC->rtcicr = 0x1;
   //	APB_RTC->rtcimsc = 0x1;
   //	APB_RTC->rtclr = 0x2;
   //	APB_RTC->rtccr = 0x1;
   //	APB_RTC->rtcmr = 0x50;   
   SysCtl_EnableRtc();
   _vf_enable_int(BSP_RTC_INTERRUPT_VECTOR);    
   //======================
   return (MQX_OK);
   
} /* Endbody */

/*FUNCTION****************************************************************
* 
* Function Name    : _vf_rtc_deinit
* Returned Value   : MQX_OK or a mqx error code
* Comments         :
*    This function de-initializes vf audio if device
*
*END*********************************************************************/

uint_32 _vf_rtc_deinit
   (
      /* [IN] the initialization information for the device being opened */
	  VF_RTC_IF_INIT_STRUCT_PTR io_init_ptr,
      /* [IN] the address of the device specific information */
	  VF_RTC_IF_INFO_STRUCT_PTR io_info_ptr
   )
{ /* Body */
   _mem_free(io_info_ptr);  
   return(MQX_OK);

} /* Endbody */

 
/*FUNCTION****************************************************************
* 
* Function Name    : _vf_rtc_ioctl
* Returned Value   : uint_32 MQX_OK or a mqx error code.
* Comments         : 
*    This function performs miscellaneous services for
*    the audio device.  
*
*END*********************************************************************/

uint_32 _vf_rtc_ioctl
   (
      /* [IN] the address of the device specific information */
     IO_RTC_IF_DEVICE_STRUCT_PTR   io_dev_ptr,

      /* [IN] The command to perform */
      uint_32                    cmd,

      /* [IN] Parameters for the command */
      uint_32_ptr                param_ptr
   )
{ /* Body */
	VF_RTC_IF_INFO_STRUCT             _PTR_ io_info_ptr;
	VF_RTC_REGS_T                 _PTR_ regs_ptr;  
	uint_32                               result = 1; 
	/* Get Info Pointer from Device */
	io_info_ptr = io_dev_ptr->DEV_INFO_PTR; 
	regs_ptr = (VF_RTC_REGS_T _PTR_)io_info_ptr->RTC_REGS_PTR;
	 switch (cmd) {
		case IO_RTC_CMD_SETDAY_TIME:
			{
			CONFIG_RTC _PTR_ p;
			uint_32 value;
			p = (CONFIG_RTC _PTR_)param_ptr;
			
			value = regs_ptr->rtcdr;			
			if(timevalid(p, value) == 0){
				regs_ptr->rtccr = 0x0;
	  			regs_ptr->rtcicr = 0x1;
	 			regs_ptr->rtcimsc = 0x1;	

	 			value = time2value(p);

	 			regs_ptr->rtclr = value;
	 			regs_ptr->rtccr = 0x1;
				}
			}
			break;	
		case IO_RTC_CMD_GETDAY_TIME:
			{
			CONFIG_RTC _PTR_ p;
			uint_32 value;
			p = (CONFIG_RTC _PTR_)param_ptr;

			value = regs_ptr->rtcdr;
			value2time(p, value);
			}
			break;	
		case IO_RTC_CMD_SET_INT_MATCH:  //caution: only used for waking up system from sleep mode
			{
			CONFIG_RTC _PTR_ p;
			uint_32 value;
			p = (CONFIG_RTC _PTR_)param_ptr;
			
			value = regs_ptr->rtcdr;			
			if(timevalid(p, value) == 0){
		 			value = time2value(p);
		 			regs_ptr->rtcmr = value;
				}
			}
			break;				
		default:
                     break;
	 }
   return result;

} /* Endbody */
void  _vf_rtc_int_isr(VF_RTC_IF_INFO_STRUCT_PTR io_info_ptr)
{
	volatile int status = 0;
	VF_RTC_REGS_T _PTR_ regs_ptr;
	regs_ptr = (VF_RTC_REGS_T _PTR_)io_info_ptr->RTC_REGS_PTR;	
	regs_ptr->rtcicr = 0x1;
	_vf_clear_int(BSP_RTC_INTERRUPT_VECTOR);
}
