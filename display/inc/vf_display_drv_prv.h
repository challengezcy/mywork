#ifndef VF_DISPLAY_DRV_PRV_H_
#define VF_DISPLAY_DRV_PRV_H_


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

     uint_32     LCDC_VECTOR;  
    /* The previous interrupt handler and data */
    /* The previous interrupt handler and data for the UART */
    void          (_CODE_PTR_   OLD_ISR)(pointer);
    void          (_CODE_PTR_   OLD_ISR_EXCEPTION_HANDLER)(_mqx_uint, _mqx_uint,pointer, pointer);
    pointer                     OLD_ISR_DATA;
    
   
} VF_DISPLAY_IF_INFO_STRUCT, _PTR_ VF_DISPLAY_IF_INFO_STRUCT_PTR;


#endif /*VF_DISPLAY_DRV_PRV_H_*/
