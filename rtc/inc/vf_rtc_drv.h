/*HEADER******************************************************************
* $Filenam:     vf_dispaly_if_drv.h  $
 * $Revision:   1.0  $
 * $Author:     jelphi zhang $
 * $Date:       4/18/2008  $
 *
 * Project: VFxxx MQX-Based rtc bsp
 *
 * Description:
 *    This file contains rtc inteface control head file for vfxxxx multimedia soc 
 *    
 * Revision History:
 *  04/18/2008 initial version

*END*********************************************************************/
#ifndef VF_RTC_IF_DRV_H_
#define VF_RTC_IF_DRV_H_

#include "vf1002_rtc.h"
/*****************************************************************
** VF_RTC_INIT_STRUCT
**
** This structure defines the initialization parameters to be used
** when rtc device is initialized.
*/
typedef struct vf_rtc_if_init_struct
{
	/* A pointer to a string that identifies the device for fopen */
	//char_ptr	ID_PTR;
	/* The SSP port address */
	uint_32     BASE_ADDRESS;	
       /* The rtc interrupt vector to use if interrupt driven */
      //uint_32     RTC_VECTOR;     
} VF_RTC_IF_INIT_STRUCT, _PTR_ VF_RTC_IF_INIT_STRUCT_PTR;


#define IO_RTC_CMD_SETDAY_TIME		(0x81008001)
#define IO_RTC_CMD_GETDAY_TIME		(0x81008002)
#define IO_RTC_CMD_SET_INT_MATCH		(0x81008003)

typedef struct _CONFIG_RTC{
	UINT32 YEAR;
	UINT32 DATE;
	UINT32 TIME;
}CONFIG_RTC;

/*----------------------------------------------------------------------------
** rtc interface DEVICE STRUCT
**
** This structure used to store information about an vf rtc if device
** for the IO device table
------------------------------------------------------------------------------*/
typedef struct vf_rtc_if_info_struct
{
    /* The address of the I2s/Ac97 device */
    VF_RTC_REGS_T  _PTR_   RTC_REGS_PTR;
    
    /* Current initialized values */
    VF_RTC_IF_INIT_STRUCT  INIT;  
    /* The vector number which the audio device will interrupt on*/
    _mqx_uint           RTC_VECTOR;    
    /* The previous interrupt handler and data */
    /* The previous interrupt handler and data for the UART */
    void          (_CODE_PTR_   OLD_ISR)(pointer);
    void          (_CODE_PTR_   OLD_ISR_EXCEPTION_HANDLER)(_mqx_uint, _mqx_uint,pointer, pointer);
    pointer                     OLD_ISR_DATA;
    
   
} VF_RTC_IF_INFO_STRUCT, _PTR_ VF_RTC_IF_INFO_STRUCT_PTR;
/*--------------------------------------------------------------------------*/
/* 
**                        FUNCTION PROTOTYPES
*/

#ifdef __cplusplus
extern "C" {
#endif

extern uint_32 _vf_rtc_if_install(char_ptr, pointer);

#ifdef __cplusplus
}
#endif


#endif /*VF_RTC_IF_DRV_H_*/
