/*HEADER******************************************************************
* $Filenam:     vf_audio_if.c  $
 * $Revision:   1.0  $
 * $Author:     jelphi zhang $
 * $Date:       4/18/2008  $
 *
 * Project: VFxxx MQX-Based LCDC BSP
 *
 * Description:
 *    This file contains display inteface control souce file for vfxxxx multimedia soc 
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
#include "display_if.h"
#include "display_if_prv.h"
#include "vf1002_lcdc.h"
#include "Font.h"
#include "ftlcdconfig.h"
#include "vf_display_drv.h"

extern uint_32 _vf_lcdc_init(IO_DISPLAY_IF_DEVICE_STRUCT_PTR,char_ptr);
extern uint_32 _vf_lcdc_deinit(VF_DISPLAY_IF_INIT_STRUCT_PTR,VF_DISPLAY_IF_INFO_STRUCT_PTR);
extern uint_32 _vf_lcdc_ioctl(IO_DISPLAY_IF_DEVICE_STRUCT_PTR, uint_32, uint_32_ptr);
extern void    _vf_lcdc_int_isr(VF_DISPLAY_IF_INFO_STRUCT_PTR io_info_ptr);
/*local func*--------------------------------------------------------------------*/
static int flag = 0;
void Putstr(UINT8 *tmp, VF_REG _PTR_ p, int size)
{
	int cn = 0;
	int flag = 0;
	
	
	while(size > 0){
		if(*tmp == ' ')
			*p++ = 36 << 8 | 1;
		else if(*tmp == ':')
			*p++ = 39 << 8 | 1;
		else{
			cn = *tmp - '0';
			if(cn >= 0 && cn <= 9)
			{
				if(flag == 0){
					*p++ = cn << 8 | 2<<4 | 1;
					flag = 1;
				}else{
					*p++ = cn << 8 | 2;
					flag = 0;
				}
			}else{
				cn = *tmp - 'A';
				if(flag == 0){
					*p++ = (cn+10) << 8 | 2<<4 |1;
					flag = 1;
				}else{
					*p++ = (cn+10) << 8 | 2;
					flag = 0;					
				}
			}	
		}
		tmp++;
		size--;
	}
}

UINT32 rgb2ycbcr( UINT8 *r, UINT8 *g, UINT8 *b)
{
	UINT8 r_tmp, g_tmp, b_tmp;
  
	r_tmp = *r;
	g_tmp = *g;
	b_tmp = *b;
   
	*r= (UINT8) (0.299   * r_tmp + 0.587  * g_tmp + 0.114  * b_tmp);        //Y =¡@0.299 R + 0.587¡@G¡@ + 0.114 B
	*g= (UINT8) (-0.1687 * r_tmp - 0.3313 * g_tmp + 0.5    * b_tmp   +128);  //Cb = - 0.1687R - 0.3313G  + 0.5¡@B + 128
	*b= (UINT8) (0.5     * r_tmp - 0.4187 * g_tmp - 0.0813 * b_tmp  + 128); //Cr = 0.5 R - 0.4187G - 0.0813 B + 128
	
	return ( (*r << 16) | (*g << 8) | (*b << 0) );
}

void OSD_Color_Paletle(UINT32 baddr)
{
	UINT8 r, g, b;
	r=0xff;	g=0;	b=0;
	*(VF_REG *) (baddr + PCR) = rgb2ycbcr( &r, &g, &b );  // Palette 0 = Red
	r=0;	g=0xff; b=0;
	*(VF_REG *) (baddr + PCR + 0x4) = rgb2ycbcr( &r, &g, &b );  // Palette 1 = Green	
	r=0;	g=0;	b=0xff;
	*(VF_REG *) (baddr + PCR + 0x8) = rgb2ycbcr( &r, &g, &b );  // Palette 2 = Blue		
	r=36;	g=16;	b=16;
	*(VF_REG *) (baddr + PCR + 0xC) = rgb2ycbcr( &r, &g, &b );  // Palette 3 = similar Black	
	r=0xff;	g=0xff; b=0xff;
	*(VF_REG *) (baddr + PCR + 0x10) = rgb2ycbcr( &r, &g, &b );  // Palette 4 = White	
	r=0xaa;	g=0;	b=0;
	*(VF_REG *) (baddr + PCR + 0x14) = rgb2ycbcr( &r, &g, &b );  // Palette 5 = Red
	r=0;	g=0xaa; b=0;
	*(VF_REG *) (baddr + PCR + 0x18) = rgb2ycbcr( &r, &g, &b );  // Palette 6 = Green
	r=0;	g=0;	b=0xaa;
	*(VF_REG *) (baddr + PCR + 0x1c) = rgb2ycbcr( &r, &g, &b );  // Palette 7 = Blue
	r=0x45;	g=0x45;	b=0x45;
	*(VF_REG *) (baddr + PCR + 0x20) = rgb2ycbcr( &r, &g, &b );  // Palette 8 = Black
	r=0x90;	g=0x90; b=0x90;
	*(VF_REG *) (baddr + PCR + 0x24) = rgb2ycbcr( &r, &g, &b );  // Palette 9 = White
	r=0x55;	g=0;	b=0;
	*(VF_REG *) (baddr + PCR + 0x28) = rgb2ycbcr( &r, &g, &b );  // Palette 10 = Red
	r=0;	g=0x55;	b=0;
	*(VF_REG *) (baddr + PCR + 0x2c) = rgb2ycbcr( &r, &g, &b );  // Palette 11 = Green
	r=0;	g=0;	b=0x55;
	*(VF_REG *) (baddr + PCR + 0x30) = rgb2ycbcr( &r, &g, &b );  // Palette 12 = Blue
	r=0x20;	g=0x50;	b=0x70;
	*(VF_REG *) (baddr + PCR + 0x34) = rgb2ycbcr( &r, &g, &b );  // Palette 13 = Black
	r=0xff;	g=0xf; b=0xf0;
	*(VF_REG *) (baddr + PCR + 0x38) = rgb2ycbcr( &r, &g, &b );  // Palette 14 = White
	r=0x11;	g=0;	b=0;
	*(VF_REG *) (baddr + PCR + 0x3c) = rgb2ycbcr( &r, &g, &b );  // Palette 15 = Red
}

void Color_FillGammaTable( UINT32 item, UINT32 baddr, INT32 r, INT32 g, INT32 b )
{
	if( item < GSIZE )
	{
		*(VF_REG *) (baddr + GROFFSET + item*(0x04)) = r;
		*(VF_REG *) (baddr + GGOFFSET + item*(0x04)) = g;
		*(VF_REG *) (baddr + GBOFFSET + item*(0x04)) = b;
	}else
		printf("Gamma lookup table item error\n");
}

void SetBPP( UINT8 bpp, UINT32 baddr)
{	
   *(VF_REG *)(baddr + 0x04) &= 0xFFFFFFF8;

   switch( bpp)
   {
         case 1:
                *(VF_REG *)(baddr + 0x04) |= 0x00000000;
                break;
         case 2:
                *(VF_REG *)(baddr + 0x04) |= 0x00000001;
                break;
         case 4:
                *(VF_REG *)(baddr + 0x04) |= 0x00000002;
                break;
         case 8:
                *(VF_REG *)(baddr + 0x04) |= 0x00000003;
                break;
         case 16:
                *(VF_REG *)(baddr + 0x04) |= 0x00000004;
                break;  
         case 24:
                *(VF_REG *)(baddr + 0x04) |= 0x00000005;
                break;
   }           
}    
/*local func end*----------------------------------------------------------------*/

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : _io_vf_display_if_install
* Returned Value   : uint_32 a task error code or MQX_OK
* Comments         :
*    Install an display device.
*
*END*----------------------------------------------------------------------*/

uint_32 _vf_display_if_install
   (
      /* [IN] A string that identifies the device for fopen */
      char_ptr           identifier,
  
      /* [IN] The I/O init data pointer */
      pointer            init_data_ptr
    )
{ /* Body */

   return _io_display_if_install(identifier,
      (uint_32 (_CODE_PTR_)(pointer, char _PTR_))_vf_lcdc_init,
      (uint_32 (_CODE_PTR_)(pointer, pointer))_vf_lcdc_deinit,
      NULL,
      NULL,
      (uint_32 (_CODE_PTR_)(pointer, uint_32, uint_32_ptr))_vf_lcdc_ioctl, 
      init_data_ptr);

} /* Endbody */


/*FUNCTION****************************************************************
* 
* Function Name    : _vf_lcdc_init
* Returned Value   : MQX_OK or a mqx error code
* Comments         :
*    This function initializes i2s/ac97 controller and codec.
*
*END*********************************************************************/

uint_32 _vf_lcdc_init
   (
      /* [IN] the initialization information for the device being opened */
      IO_DISPLAY_IF_DEVICE_STRUCT_PTR   io_dev_ptr,

      /* [IN] the rest of the name of the device opened */
      char_ptr                        open_name_ptr

   )
{ /* Body */
   
   VF_DISPLAY_IF_INFO_STRUCT                   _PTR_ io_info_ptr;
   VF_DISPLAY_IF_INIT_STRUCT                   _PTR_ io_init_ptr;
   VF_REGS_FT200_LCDC                 _PTR_ regs_ptr;
   uint_32                                     result;  
   
   VF_REG _PTR_  Fontbase;
   uint_32 lcd_type;
   uint_32 bit_type;
   uint_32 baseaddr;
   int i;
   
   io_init_ptr = io_dev_ptr->DEV_INIT_DATA_PTR;
   io_info_ptr = (VF_DISPLAY_IF_INFO_STRUCT _PTR_)(_mem_alloc_system_zero((uint_32)sizeof(VF_DISPLAY_IF_INFO_STRUCT)));
#if MQX_CHECK_MEMORY_ALLOCATION_ERRORS
   if (io_info_ptr == NULL) {
      return(MQX_OUT_OF_MEMORY);
   } /* Endif */
#endif
   io_dev_ptr->DEV_INFO_PTR = io_info_ptr;
   //get init value
   io_info_ptr->INIT = *io_init_ptr;   
   /* reg_ptr will point to the lcdc Registers */
   regs_ptr  =  (VF_REGS_FT200_LCDC _PTR_)io_info_ptr->INIT.BASE_ADDRESS;
   io_info_ptr->LCDC_REGS_PTR   = regs_ptr;   
   //set up lcdc interrupt
   io_info_ptr->OLD_ISR_DATA = _int_get_isr_data(io_info_ptr->INIT.LCDC_VECTOR);
   io_info_ptr->OLD_ISR_EXCEPTION_HANDLER =
	   _int_get_exception_handler(io_info_ptr->INIT.LCDC_VECTOR);
   io_info_ptr->OLD_ISR =
      _int_install_isr(io_info_ptr->INIT.LCDC_VECTOR,_vf_lcdc_int_isr,io_info_ptr);   
   //now init ssp regs with defult values
   //======================
   lcd_type = io_init_ptr->PANEL_TYPE;
   bit_type = io_init_ptr->BIT_TYPE;
   baseaddr = io_info_ptr->INIT.BASE_ADDRESS;

   SysCtl_EnableApb();
   SysCtl_EnableDisplay();
    for( i=0; i<GSIZE; i++ ){
    	INT32 val;	  
    	val = 0x03020100 + 0x04040404 * i;
    	Color_FillGammaTable( i, baseaddr, val, val, val);	
    }

   regs_ptr->GP_REGS.fen = FLcdModule[lcd_type].LCDEnable;
   regs_ptr->GP_REGS.ppp = FLcdModule[lcd_type].PanelPixel;
   regs_ptr->GP_REGS.int_clr = 0x1 << 1;
   regs_ptr->GP_REGS.int_msk = 0x1 << 1;

   regs_ptr->TPP_REGS.htcp = FLcdModule[lcd_type].HorizontalTiming;
   regs_ptr->TPP_REGS.vtc1 = FLcdModule[lcd_type].VerticalTiming1;
   regs_ptr->TPP_REGS.vtc2 = FLcdModule[lcd_type].VerticalTiming2;
   regs_ptr->TPP_REGS.pcp  = FLcdModule[lcd_type].Polarity;   

   regs_ptr->OFP_REGS.spp = FLcdModule[lcd_type].SerialPanelPixel;
   regs_ptr->OFP_REGS.ccir = FLcdModule[lcd_type].CCIR656;

    regs_ptr->CSTN_REGS.cstnpc = FLcdModule[lcd_type].CSTNPanelControl;
    regs_ptr->CSTN_REGS.cstnpp1 = FLcdModule[lcd_type].CSTNPanelParam1;
    io_info_ptr->Width = FLcdModule[lcd_type].Width;	//set the panel width
    io_info_ptr->High = FLcdModule[lcd_type].Height;	//set the panel height    

    SetBPP(24, baseaddr);
    //24bit panel
    if(bit_type == 1){
	 SysCtl_EnableLCD24Bit();	
   	 regs_ptr->GP_REGS.ppp |= (0x1 << 11);
    }
    
    OSD_Color_Paletle(baseaddr);

    Fontbase = regs_ptr->OSDFRAMD; 
    //mytest start here!!!
    for(i=0; i<40*18; i++)	
    	*(Fontbase++)  = OSD_Font[i];
    for(i=0; i<23*18; i++)
    	*(Fontbase++)  = myprocflag[i];	// i*4 -> 1 word = 4 bytes
    	
    _vf_enable_int(BSP_LCDC_INTERRUPT_VECTOR);    
   //======================
   return (MQX_OK);
   
} /* Endbody */

/*FUNCTION****************************************************************
* 
* Function Name    : _vf_lcdc_deinit
* Returned Value   : MQX_OK or a mqx error code
* Comments         :
*    This function de-initializes vf audio if device
*
*END*********************************************************************/

uint_32 _vf_lcdc_deinit
   (
      /* [IN] the initialization information for the device being opened */
	  VF_DISPLAY_IF_INIT_STRUCT_PTR io_init_ptr,
      /* [IN] the address of the device specific information */
	  VF_DISPLAY_IF_INFO_STRUCT_PTR io_info_ptr
   )
{ /* Body */
   _mem_free(io_info_ptr);  
   return(MQX_OK);

} /* Endbody */

 
/*FUNCTION****************************************************************
* 
* Function Name    : _vf_lcdc_ioctl
* Returned Value   : uint_32 MQX_OK or a mqx error code.
* Comments         : 
*    This function performs miscellaneous services for
*    the audio device.  
*
*END*********************************************************************/

uint_32 _vf_lcdc_ioctl
   (
      /* [IN] the address of the device specific information */
     IO_DISPLAY_IF_DEVICE_STRUCT_PTR   io_dev_ptr,

      /* [IN] The command to perform */
      uint_32                    cmd,

      /* [IN] Parameters for the command */
      uint_32_ptr                param_ptr
   )
{ /* Body */
	VF_DISPLAY_IF_INFO_STRUCT             _PTR_ io_info_ptr;
	VF_REGS_FT200_LCDC                 _PTR_ regs_ptr;  
	uint_32                               result = 1; 
	/* Get Info Pointer from Device */
	int i=0;
	io_info_ptr = io_dev_ptr->DEV_INFO_PTR; 
	regs_ptr = (VF_REGS_FT200_LCDC _PTR_)io_info_ptr->LCDC_REGS_PTR;
	 switch (cmd) {
	 	case IO_IOCTL_FTLCDC_CMD_CONFIG_HV:
	 		{
				CONFIG_FTLCD_HV _PTR_ p;
				uint_32 tmph, hbp, hfp, pl, hm, plc;
				uint_32 tmpv1, tmpv2, vbp, vfp, vm, lf, lfc;
				p = (CONFIG_FTLCD_HV _PTR_)param_ptr;
				
				tmph = regs_ptr->TPP_REGS.htcp;
				tmpv1 = regs_ptr->TPP_REGS.vtc1;
				tmpv2 = regs_ptr->TPP_REGS.vtc2;

				pl = tmph & 0xff;
				hm = (tmph >> 8)  & 0xff;
				hfp = (tmph >> 16) & 0xff;
				hbp = (tmph >> 24) & 0xff;

				lf = (tmpv1) & 0xfff;
				vm = (tmpv1 >> 16) & 0x3f;
				vfp = (tmpv1 >> 24) & 0xff;
				vbp = (tmpv2) & 0xff;

				pl = (pl+1)*16;
				plc = pl - p->wide;
				pl = p->wide/16 - 1;
				if(plc <= (0xff - hfp))
					hfp = hfp + plc;
				else {
					hfp = 0xff;
					plc = plc - (0xff - hfp);
					hbp = hbp + plc;
				}

				lf = lf + 1;
				lfc = lf - p->high;
				lf = p->high -1;
				if(lfc <= (0xf8 - vfp))
					vfp = lfc + vfp;
				else {
					vfp = 0xf8;
					lfc = lfc -(0xf8 - vfp);
					vbp = vbp + lfc;
				}

				tmph = pl | (hm << 8) | (hfp << 16) | (hbp << 24);
				tmpv1 = lf | (vm << 16) | (vfp << 24);
				tmpv2 = vbp;
				
				regs_ptr->TPP_REGS.htcp = tmph;
				regs_ptr->TPP_REGS.vtc1 = tmpv1;
				regs_ptr->TPP_REGS.vtc2 = tmpv2;				
	 		}
			break;	 	 	
		case IO_IOCTL_FTLCDC_CMD_START:
			regs_ptr->GP_REGS.fen |= 0x3;
			flag = 0;
			break;
		case IO_IOCTL_FTLCDC_CMD_STOP:
			regs_ptr->GP_REGS.fen &= 0xfffffffe;
			flag = 0;
			break;
		case IO_IOCTL_FTLCDC_CMD_YUV420:
			regs_ptr->GP_REGS.fen |= 0x3 << 2;
        	       break;
		case IO_IOCTL_FTLCDC_CMD_YUV422:
			regs_ptr->GP_REGS.fen |= 0x1 << 3;
			regs_ptr->GP_REGS.fen &= ~(0x1 << 2);
        	       break;        	       
		case IO_IOCTL_FTLCDC_CMD_RGB:
			regs_ptr->GP_REGS.fen &= ~(0x1 << 3);	
			break;
		case IO_IOCTL_FTLCDC_CMD_PiPDis:
			regs_ptr->GP_REGS.fen &= ~(0x3 << 9);	
			break;
		case IO_IOCTL_FTLCDC_CMD_PiPEn_SW:
			regs_ptr->GP_REGS.fen &= ~(0x1 << 7);
			regs_ptr->GP_REGS.fen &= ~(0x1 << 5);
			regs_ptr->GP_REGS.fen |= (0x1 << 9);
			break;
		case IO_IOCTL_FTLCDC_CMD_PiPEn_DW:
			regs_ptr->GP_REGS.fen &= ~(0x1 << 7);
			regs_ptr->GP_REGS.fen &= ~(0x1 << 5);
			regs_ptr->GP_REGS.fen |= (0x2 << 9);
			break;
		case IO_IOCTL_FTLCDC_CMD_BlendDis:
			regs_ptr->GP_REGS.fen &= ~(0x1 << 8);
			break;			
		case IO_IOCTL_FTLCDC_CMD_BlendEn:
			regs_ptr->GP_REGS.fen |= (0x1 << 8);	
			break;
		case IO_IOCTL_FTLCDC_CMD_PoPDis:
			regs_ptr->GP_REGS.fen &= ~(0x1 << 7);	
			break;
		case IO_IOCTL_FTLCDC_CMD_PoPEn:
			regs_ptr->GP_REGS.fen &= ~(0x3 << 9);	
			regs_ptr->GP_REGS.fen &= ~(0x1 << 5);
			regs_ptr->GP_REGS.fen |= (0x1 << 7);	
			break;
		case IO_IOCTL_FTLCDC_CMD_DitherDis:
			regs_ptr->GP_REGS.fen &= ~(0x1 << 6);
			break;
		case IO_IOCTL_FTLCDC_CMD_DitherEn:
			regs_ptr->GP_REGS.fen |= (0x1 << 6);		
			break;
		case IO_IOCTL_FTLCDC_CMD_ScalerDis:
			regs_ptr->GP_REGS.fen &= ~(0x1 << 5);
			break;
		case IO_IOCTL_FTLCDC_CMD_ScalerEn:
			regs_ptr->GP_REGS.fen |=  (0x1 << 5);	
			break;
		case IO_IOCTL_FTLCDC_CMD_OSDDis:
			regs_ptr->GP_REGS.fen &= ~(0x1 << 4);
			break;
		case IO_IOCTL_FTLCDC_CMD_OSDEn:
			regs_ptr->GP_REGS.fen |= (0x1 << 4);			
			break;	
		case IO_IOCTL_FTLCDC_CMD_PoPSD:
			if(regs_ptr->GP_REGS.ppbd == 0x5500)
				regs_ptr->GP_REGS.ppbd = 0x0;		
			else
				regs_ptr->GP_REGS.ppbd = 0x5500;
			break;				
		case IO_IOCTL_FTLCDC_CMD_PIPPARA:
			{
				CONFIG_PiP _PTR_ p;
				p = (CONFIG_PiP _PTR_)param_ptr;
				if((p->PiPBlend1 + p->PiPBlend2) <= 16){
					regs_ptr->IMGP_REGS.pipp = (p->PiPBlend1) | (p->PiPBlend2 << 8);
					//regs_ptr->GP_REGS.fen |= (0x1 << 8);
				}

				if(((p->PiP1HPos + p->PiP1HDim) <  io_info_ptr->Width) && ((p->PiP1VPos + p->PiP1VDim) < io_info_ptr->High)){
					regs_ptr->IMGP_REGS.sp1p = (p->PiP1VPos) | (p->PiP1HPos << 16);
					regs_ptr->IMGP_REGS.sp1d = (p->PiP1VDim) | (p->PiP1HDim << 16);
				}

				if(((p->PiP2HPos + p->PiP2HDim) <  io_info_ptr->Width) && ((p->PiP2VPos + p->PiP2VDim) < io_info_ptr->High)){
					regs_ptr->IMGP_REGS.sp2p = (p->PiP2VPos) | (p->PiP2HPos << 16);
					regs_ptr->IMGP_REGS.sp2d = (p->PiP2VDim) | (p->PiP2HDim << 16);
				}				
			}
			break;	
		case IO_IOCTL_FTLCDC_CMD_ScalerPARA:
			{
				CONFIG_SCALAE _PTR_ p;
				int tmp;
				int Scal_ver_num, Scal_hor_num;
				p = (CONFIG_SCALAE _PTR_)param_ptr;
				if(p->d_high/p->s_high > 2 || p->d_width/p->s_width > 2)
					break;

				if((p->s_high/p->d_high == p->s_width/p->d_width) 
					&& (p->s_width != p->d_width) && (p->s_high != p->d_high))
					tmp = p->s_width/p->d_width;
				else
					break;

				switch(tmp){
					case 0: //scalar up
						regs_ptr->SCR_REGS.hrsi = p->s_width -1;
						regs_ptr->SCR_REGS.vrsi = p->s_high -1;
						regs_ptr->SCR_REGS.hrso = p->d_width;
						regs_ptr->SCR_REGS.vrso = p->d_high;					
						Scal_ver_num = p->s_high* 256/p->d_high ;
						Scal_hor_num = p->s_width* 256/p->d_width ;
						regs_ptr->SCR_REGS.mcr = 0;
						regs_ptr->SCR_REGS.srp = Scal_ver_num | Scal_hor_num << 8;
						break;
					case 1:
						regs_ptr->SCR_REGS.hrsi = p->s_width -1;
						regs_ptr->SCR_REGS.vrsi = p->s_high -1;
						regs_ptr->SCR_REGS.hrso = p->d_width;
						regs_ptr->SCR_REGS.vrso = p->d_high;					
						Scal_ver_num = ((p->s_high%p->d_high) * 256)/p->d_high;
						Scal_hor_num = ((p->s_width%p->d_width) * 256)/p->d_width;
						regs_ptr->SCR_REGS.mcr = 0;
						regs_ptr->SCR_REGS.srp = Scal_ver_num | Scal_hor_num << 8;						
						break;
					case 2:
					case 3:
						p->s_width /= 2;
						p->s_high /= 2;
						regs_ptr->SCR_REGS.hrsi = p->s_width -1;
						regs_ptr->SCR_REGS.vrsi = p->s_high -1;
						regs_ptr->SCR_REGS.hrso = p->d_width;
						regs_ptr->SCR_REGS.vrso = p->d_high;					
						Scal_ver_num = ((p->s_high%p->d_high) * 256)/p->d_high;
						Scal_hor_num = ((p->s_width%p->d_width) * 256)/p->d_width;
						regs_ptr->SCR_REGS.mcr = 0x40;
						regs_ptr->SCR_REGS.srp = Scal_ver_num | Scal_hor_num << 8;							
						break;
					case 4:
					case 5:
					case 6:
					case 7:
						p->s_width /= 4;
						p->s_high /= 4;
						regs_ptr->SCR_REGS.hrsi = p->s_width -1;
						regs_ptr->SCR_REGS.vrsi = p->s_high -1;
						regs_ptr->SCR_REGS.hrso = p->d_width;
						regs_ptr->SCR_REGS.vrso = p->d_high;					
						Scal_ver_num = ((p->s_high%p->d_high) * 256)/p->d_high;
						Scal_hor_num = ((p->s_width%p->d_width) * 256)/p->d_width;
						regs_ptr->SCR_REGS.mcr = 0x80;
						regs_ptr->SCR_REGS.srp = Scal_ver_num | Scal_hor_num << 8;							
						break;
					case 8:
					case 9:
					case 10:
					case 11:
					case 12:
					case 13:
					case 14:
					case 15:		
						p->s_width /= 8;
						p->s_high /= 8;
						regs_ptr->SCR_REGS.hrsi = p->s_width -1;
						regs_ptr->SCR_REGS.vrsi = p->s_high -1;
						regs_ptr->SCR_REGS.hrso = p->d_width;
						regs_ptr->SCR_REGS.vrso = p->d_high;					
						Scal_ver_num = ((p->s_high%p->d_high) * 256)/p->d_high;
						Scal_hor_num = ((p->s_width%p->d_width) * 256)/p->d_width;
						regs_ptr->SCR_REGS.mcr = 0xC0;
						regs_ptr->SCR_REGS.srp = Scal_ver_num | Scal_hor_num << 8;							
						break;
					default:
						p->s_width /= 16;
						p->s_high /= 16;
						regs_ptr->SCR_REGS.hrsi = p->s_width -1;
						regs_ptr->SCR_REGS.vrsi = p->s_high -1;
						regs_ptr->SCR_REGS.hrso = p->d_width;
						regs_ptr->SCR_REGS.vrso = p->d_high;					
						Scal_ver_num = ((p->s_high%p->d_high) * 256)/p->d_high;
						Scal_hor_num = ((p->s_width%p->d_width) * 256)/p->d_width;
						regs_ptr->SCR_REGS.mcr = 0x100;
						regs_ptr->SCR_REGS.srp = Scal_ver_num | Scal_hor_num << 8;							
						break;						
				}				
			}	
			break;	
		case IO_IOCTL_FTLCDC_CMD_OSDPARA:
			{
				CONFIG_OSD _PTR_ p;
				p = (CONFIG_OSD _PTR_)param_ptr;			
				regs_ptr->COSD_REGS.fcr0 = p->b_cfr0;
				regs_ptr->COSD_REGS.fcr1 = p->b_cfr1;
				regs_ptr->COSD_REGS.mcfba = 512;

				if(p->win[0].wen == 1){
					regs_ptr->COSD_REGS.en |= 1 << 0;

					regs_ptr->COSD_REGS.w1c0 = (p->win[0].posix) | (p->win[0].posiy << 8);
					regs_ptr->COSD_REGS.w1c1 = (p->win[0].shdclr << 26) | (p->win[0].shdtyp << 24) | (p->win[0].bdclr << 20)
										| (p->win[0].bdtyp << 18) | (p->win[0].hlsel << 17) | (p->win[0].hlen << 16)
										| (p->win[0].ydim << 8) | (p->win[0].xdim << 0);
					regs_ptr->COSD_REGS.w1c2 = 0x0;
				}else{
					regs_ptr->COSD_REGS.en &= ~(1 << 0);
				}

				if(p->win[1].wen == 1){
					regs_ptr->COSD_REGS.en |= 1 << 1;

					regs_ptr->COSD_REGS.w2c0 = (p->win[1].posix) | (p->win[1].posiy << 8);
					regs_ptr->COSD_REGS.w2c1 = (p->win[1].shdclr << 26) | (p->win[1].shdtyp << 24) | (p->win[1].bdclr << 20)
										| (p->win[1].bdtyp << 18) | (p->win[1].hlsel << 17) | (p->win[1].hlen << 16)
										| (p->win[1].ydim << 8) | (p->win[1].xdim << 0);
					regs_ptr->COSD_REGS.w2c2 = 0x101;
				}else{
					regs_ptr->COSD_REGS.en &= ~(1 << 1);
				}

				if(p->win[2].wen == 1){
					regs_ptr->COSD_REGS.en |= 1 << 2;

					regs_ptr->COSD_REGS.w3c0 = (p->win[2].posix) | (p->win[2].posiy << 8);
					regs_ptr->COSD_REGS.w3c1 = (p->win[2].shdclr << 26) | (p->win[2].shdtyp << 24) | (p->win[2].bdclr << 20)
										| (p->win[2].bdtyp << 18) | (p->win[2].hlsel << 17) | (p->win[2].hlen << 16)
										| (p->win[2].ydim << 8) | (p->win[2].xdim << 0);
					regs_ptr->COSD_REGS.w3c2 = 0x101 + 0x55;
				}else{
					regs_ptr->COSD_REGS.en &= ~(1 << 2);
				}

				if(p->win[3].wen == 1){
					regs_ptr->COSD_REGS.en |= 1 << 3;

					regs_ptr->COSD_REGS.w4c0 = (p->win[3].posix) | (p->win[3].posiy << 8);
					regs_ptr->COSD_REGS.w4c1 = (p->win[3].shdclr << 26) | (p->win[3].shdtyp << 24) | (p->win[3].bdclr << 20)
										| (p->win[3].bdtyp << 18) | (p->win[3].hlsel << 17) | (p->win[3].hlen << 16)
										| (p->win[3].ydim << 8) | (p->win[3].xdim << 0);
					regs_ptr->COSD_REGS.w4c2 = 0x101 + 0x55 + 0x55;
				}else{
					regs_ptr->COSD_REGS.en &= ~(1 << 3);
				}				
			}
			break;	
		case IO_IOCTL_FTLCDC_CMD_OSDSHOW:
			{
				CONFIG_OSD_SHOW _PTR_ p;
				int i;
				VF_REG _PTR_  Featurebase;
				Featurebase = regs_ptr->OSDFARAMD;
				p = (CONFIG_OSD_SHOW _PTR_)param_ptr;	

				switch(p->win){
					case 0:
						Featurebase += 0;
						break;
					case 1:
						Featurebase += 0x101;
						break;
					case 2:
						Featurebase += 0x101 + 0x55;
						break;
					case 3:
						Featurebase += 0x101 + 0x55 + 0x55;
						break;
					default:
						Featurebase += 0;
						break;
				}

				Putstr(p->ch, Featurebase, p->len);
			}			
			break;	
		case IO_IOCTL_FTLCDC_CMD_SET_BADDR:
			{
				CONFIG_FTLCD_BADDR _PTR_ p;
				p = (CONFIG_FTLCD_BADDR _PTR_)param_ptr;
				if(flag == 0x0){
					regs_ptr->GP_REGS.img0add =  p->ADDR0;
					regs_ptr->GP_REGS.img1add =  p->ADDR1;
					regs_ptr->GP_REGS.img2add =  p->ADDR2;
					flag = 0x1;
				}
				io_info_ptr->ADDRESS0 = p->ADDR0;
				io_info_ptr->ADDRESS1 = p->ADDR1;
				io_info_ptr->ADDRESS2 = p->ADDR2;	
				//io_info_ptr->ADDRESS3 = p->ADDR3;	
			}
			break;				
		default:
                     break;
	 }
   return result;

} /* Endbody */
void  _vf_lcdc_int_isr(VF_DISPLAY_IF_INFO_STRUCT_PTR io_info_ptr)
{
	volatile int status = 0;
	VF_REGS_FT200_LCDC _PTR_ regs_ptr;
	regs_ptr = (VF_REGS_FT200_LCDC _PTR_)io_info_ptr->LCDC_REGS_PTR;	
	status = regs_ptr->GP_REGS.int_sts;
	if(status & (0x1 << 1)){
		regs_ptr->GP_REGS.img0add =  io_info_ptr->ADDRESS0;
		regs_ptr->GP_REGS.img1add =  io_info_ptr->ADDRESS1;
		regs_ptr->GP_REGS.img2add =  io_info_ptr->ADDRESS2;
		//regs_ptr->GP_REGS.img3add =  io_info_ptr->ADDRESS3;
	}
	regs_ptr->GP_REGS.int_clr = 0xf;	
	_vf_clear_int(BSP_LCDC_INTERRUPT_VECTOR);
}
