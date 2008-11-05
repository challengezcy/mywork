/*HEADER******************************************************************
* $Filenam:     vf_dispaly_if_drv.h  $
 * $Revision:   1.0  $
 * $Author:     jelphi zhang $
 * $Date:       4/18/2008  $
 *
 * Project: VFxxx MQX-Based lcdc bsp
 *
 * Description:
 *    This file contains display inteface control head file for vfxxxx multimedia soc 
 *    
 * Revision History:
 *  04/18/2008 initial version

*END*********************************************************************/
#ifndef VF_DISPLAY_IF_DRV_H_
#define VF_DISPLAY_IF_DRV_H_

#include "vf1002_lcdc.h"
typedef struct _CONFIG_PiP{
	UINT32 PiPBlend2;
	UINT32 PiPBlend1;
	UINT32 PiP1HPos;
	UINT32 PiP1VPos;
	UINT32 PiP1HDim;
	UINT32 PiP1VDim;
	UINT32 PiP2HPos;
	UINT32 PiP2VPos;
	UINT32 PiP2HDim;
	UINT32 PiP2VDim;	
}CONFIG_PiP;

typedef struct _CONFIG_SCALAE{
	UINT32 s_width;
	UINT32 s_high;
	UINT32 d_width;
	UINT32 d_high;
}CONFIG_SCALAE;

typedef struct _CONFIG_OSD_WIN{
	UINT32 wen; //if you want the flow configuration efect, please set wen = 1, other wen = 0;
	
	UINT32 posix; //Specify the horizontal position of the OSD window
	UINT32 posiy; //Specify the vertical position of the OSD window
	
	UINT32 xdim; //Specify the horizontal dimension of OSD window
	UINT32 ydim;	 //Specify the vertical dimension of OSD window
	UINT32 shdclr; //Select the color for OSD window shadow effect from Palette
	UINT32 shdtyp; //Select the width for OSD window shadow effect (Unit: pixel) 00: 0 01: 1 10: 2 11: 3
	UINT32 bdclr; //Select the color for OSD window border effect from Palette
	UINT32 bdtyp; //Select the width for OSD window 1 border effect (Unit: pixel) 00: 0 01: 1 10: 2 11: 3
	UINT32 hlsel; //Select window highlight effect for OSD window 0: Border 1: Shadow
	UINT32 hlen;	//Enable window highlight effect for OSD window 0: Off 1: On	
}CONFIG_OSD_WIN;
typedef struct _CONFIG_OSD{
	UINT32 b_cfr0;
	UINT32 b_cfr1;
	CONFIG_OSD_WIN win[4];
}CONFIG_OSD;

typedef struct _CONFIG_OSD_SHOW{
	UINT8 _PTR_ ch;
	UINT32 len;
	UINT32 win;
}CONFIG_OSD_SHOW;

typedef struct _CONFIG_FTLCD_BADDR{
	UINT32 ADDR0;
	UINT32 ADDR1;
	UINT32 ADDR2;
	UINT32 ADDR3;
}CONFIG_FTLCD_BADDR;

typedef struct _CONFIG_FTLCD_HV{
	UINT32 wide;
	UINT32 high;
}CONFIG_FTLCD_HV;
//======================================================
#define IO_IOCTL_FTLCDC_CMD_START		(0x80100000)
#define IO_IOCTL_FTLCDC_CMD_STOP		(0x80100001)
#define IO_IOCTL_FTLCDC_CMD_YUV420		0x80100102
#define IO_IOCTL_FTLCDC_CMD_YUV422		0x80100003
#define IO_IOCTL_FTLCDC_CMD_RGB			0x80100004
#define IO_IOCTL_FTLCDC_CMD_PiPDis		0x80100050
#define IO_IOCTL_FTLCDC_CMD_PiPEn_SW	0x80100051
#define IO_IOCTL_FTLCDC_CMD_PiPEn_DW	0x80100052
#define IO_IOCTL_FTLCDC_CMD_PIPPARA		0x80100053
#define IO_IOCTL_FTLCDC_CMD_BlendDis	0x80100060
#define IO_IOCTL_FTLCDC_CMD_BlendEn		0x80100061
#define IO_IOCTL_FTLCDC_CMD_PoPDis		0x80100070
#define IO_IOCTL_FTLCDC_CMD_PoPEn		0x80100071
#define IO_IOCTL_FTLCDC_CMD_PoPSD		0x80100072
#define IO_IOCTL_FTLCDC_CMD_DitherDis	0x80100080
#define IO_IOCTL_FTLCDC_CMD_DitherEn	0x80100081
#define IO_IOCTL_FTLCDC_CMD_ScalerDis	0x80100090
#define IO_IOCTL_FTLCDC_CMD_ScalerEn	0x80100091
#define IO_IOCTL_FTLCDC_CMD_ScalerPARA	0x80100092
#define IO_IOCTL_FTLCDC_CMD_OSDDis		0x80100100
#define IO_IOCTL_FTLCDC_CMD_OSDEn		0x80100101
#define IO_IOCTL_FTLCDC_CMD_OSDPARA		0x80100103
#define IO_IOCTL_FTLCDC_CMD_OSDSHOW		0x80100104
#define IO_IOCTL_FTLCDC_CMD_SET_BADDR	0x80100110
#define IO_IOCTL_FTLCDC_CMD_CONFIG_HV	0x80100111
//======================================================
/*****************************************************************
** VF_DISPLAY_INIT_STRUCT
**
** This structure defines the initialization parameters to be used
** when display device is initialized.
*/
typedef struct vf_display_if_init_struct
{
	/* A pointer to a string that identifies the device for fopen */
	//char_ptr	ID_PTR;
	/* The SSP port address */
	uint_32     BASE_ADDRESS;	
	//uint_32     INIT_WIDTH;
       //uint_32     INIT_HEIGHT;
      uint_32     PANEL_TYPE;
	uint_32    BIT_TYPE;
    /* The lcdc interrupt vector to use if interrupt driven */
     uint_32     LCDC_VECTOR;     
} VF_DISPLAY_IF_INIT_STRUCT, _PTR_ VF_DISPLAY_IF_INIT_STRUCT_PTR;


/*----------------------------------------------------------------------------
** display interface DEVICE STRUCT
**
** This structure used to store information about an vf display if device
** for the IO device table
------------------------------------------------------------------------------*/
typedef struct vf_display_if_info_struct
{
    /* The address of the I2s/Ac97 device */
    VF_REGS_FT200_LCDC  _PTR_   LCDC_REGS_PTR;
    
    /* Current initialized values */
    VF_DISPLAY_IF_INIT_STRUCT  INIT;  
    uint_32     ADDRESS0;
    uint_32     ADDRESS1;
    uint_32     ADDRESS2;
    uint_32     ADDRESS3;
    uint_32     Width;
    uint_32     High;
    /* The previous interrupt handler and data */
    /* The previous interrupt handler and data for the UART */
    void          (_CODE_PTR_   OLD_ISR)(pointer);
    void          (_CODE_PTR_   OLD_ISR_EXCEPTION_HANDLER)(_mqx_uint, _mqx_uint,pointer, pointer);
    pointer                     OLD_ISR_DATA;
    
   
} VF_DISPLAY_IF_INFO_STRUCT, _PTR_ VF_DISPLAY_IF_INFO_STRUCT_PTR;



/*--------------------------------------------------------------------------*/
/* 
**                        FUNCTION PROTOTYPES
*/

#ifdef __cplusplus
extern "C" {
#endif

extern uint_32 _vf_display_if_install(char_ptr, pointer);

#ifdef __cplusplus
}
#endif


#endif /*VF_DISPLAY_IF_DRV_H_*/
