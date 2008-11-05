
/*HEADER******************************************************************
* $Filenam:    display_if.c  $
 * $Revision:   1.0  $
 * $Author:     jelphi zhang $
 * $Date:       4/18/2008  $
 *
 * Project: VFxxx MQX-Based BSP
 *
 * Description:
 *    This file contains display inteface general souce file for vfxxxx multimedia soc 
 *    
 * Revision History:
 *  04/18/2008 initial version

*END*********************************************************************/

#include "mqx_inc.h"
#include "fio.h"
#include "fio_prv.h"
#include "io.h"
#include "io_prv.h"
#include "display_if.h"
#include "display_if_prv.h"


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : _display_if_install
* Returned Value   : uint_32 a task error code or MQX_OK
* Comments         :
*    Install the display interface device.
*
*END*----------------------------------------------------------------------*/

_mqx_uint _io_display_if_install
   (
      /* [IN] A string that identifies the device for fopen */
      char_ptr            identifier,
  
      /* [IN] The I/O init function */
      uint_32 (_CODE_PTR_ init)(pointer, char _PTR_),
      
      /* [IN] The I/O de-init function */
      uint_32 (_CODE_PTR_ deinit)(pointer, pointer),
      
      /* [IN] The input function */
      uint_32 (_CODE_PTR_ recv)(pointer, char _PTR_, _mqx_int),
     
      /* [IN] The output function */
      uint_32 (_CODE_PTR_ xmit)(pointer, char _PTR_, _mqx_int),

      /* [IN] The I/O ioctl function */
      uint_32 (_CODE_PTR_ ioctl)(pointer, uint_32, uint_32_ptr),

      /* [IN] The I/O init data pointer */
      pointer             init_data_ptr
      
   )

{ /* Body */
   IO_DISPLAY_IF_DEVICE_STRUCT_PTR display_if_dev_ptr;

   display_if_dev_ptr = _mem_alloc_system_zero((uint_32)
      sizeof(IO_DISPLAY_IF_DEVICE_STRUCT));

#if MQX_CHECK_MEMORY_ALLOCATION_ERRORS
   if (display_if_dev_ptr == NULL) {
      return(MQX_OUT_OF_MEMORY);
   } /* Endif */
#endif

   display_if_dev_ptr->DEV_INIT          = init;
   display_if_dev_ptr->DEV_DEINIT        = deinit;
   display_if_dev_ptr->DEV_READ          = recv;
   display_if_dev_ptr->DEV_WRITE         = xmit;
   display_if_dev_ptr->DEV_IOCTL         = ioctl;
   display_if_dev_ptr->DEV_INIT_DATA_PTR = init_data_ptr;
   
   return (_io_dev_install(identifier,
      (_mqx_int (_CODE_PTR_)(FILE_PTR, char _PTR_, char _PTR_))_io_display_if_open,
      (_mqx_int (_CODE_PTR_)(FILE_PTR))                        _io_display_if_close,
      (_mqx_int (_CODE_PTR_)(FILE_PTR, char_ptr, _mqx_int))    _io_display_if_read, 
      (_mqx_int (_CODE_PTR_)(FILE_PTR, char_ptr, _mqx_int))    _io_display_if_write, 
      (_mqx_int (_CODE_PTR_)(FILE_PTR, _mqx_uint, pointer))    _io_display_if_ioctl,
      (pointer)display_if_dev_ptr)); 

} /* Endbody */


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _DISPLAY_if_uninstall
* Returned Value   : _mqx_int a task error code or MQX_OK
* Comments         :
*    Un-Install a DISPLAY device.
*
*END*----------------------------------------------------------------------*/

_mqx_int _io_display_if_uninstall
   (
      /* [IN] The IO device structure for the device */
      IO_DEVICE_STRUCT_PTR   io_dev_ptr
   )
{ /* Body */
	IO_DISPLAY_IF_DEVICE_STRUCT_PTR display_if_dev_ptr = io_dev_ptr->DRIVER_INIT_PTR;

   if (display_if_dev_ptr->COUNT == 0) {
      if (display_if_dev_ptr->DEV_DEINIT) {
         (*display_if_dev_ptr->DEV_DEINIT)(display_if_dev_ptr->DEV_INIT_DATA_PTR,
        		 display_if_dev_ptr->DEV_INFO_PTR);
      } /* Endif */
      _mem_free(io_dev_ptr);
      io_dev_ptr->DRIVER_INIT_PTR = NULL;
      return(IO_OK);
   } else {
      return(IO_ERROR_DEVICE_BUSY);
   } /* Endif */

} /* Endbody */


/*FUNCTION****************************************************************
* 
* Function Name    : _display_if_open
* Returned Value   : int_32 error code
* Comments         :
*    This routine initializes the DISPLAY interface. It acquires
*    memory, then stores information into it about the display device.
*    It then calls the hardware interface function to initialize the channel.
* 
*END**********************************************************************/

_mqx_int _io_display_if_open
   (
      /* [IN] the file handle for the device being opened */
      FILE_DEVICE_STRUCT_PTR         fd_ptr,
       
      /* [IN] the remaining portion of the name of the device */
      char                     _PTR_ open_name_ptr,

      /* [IN] the flags to be used during operation:
      ** echo, translation, xon/xoff.
      */
      char                     _PTR_ flags
   )
{ /* Body */
   IO_DEVICE_STRUCT_PTR               io_dev_ptr;
   IO_DISPLAY_IF_DEVICE_STRUCT_PTR    io_display_if_dev_ptr;
   _mqx_int                           result = MQX_OK;

   io_dev_ptr   = (IO_DEVICE_STRUCT_PTR)fd_ptr->DEV_PTR;
   io_display_if_dev_ptr = (IO_DISPLAY_IF_DEVICE_STRUCT_PTR)(io_dev_ptr->DRIVER_INIT_PTR);
   
   if (io_display_if_dev_ptr->COUNT) {
      /* Device is already opened */
	  io_display_if_dev_ptr->COUNT++;
      fd_ptr->FLAGS = io_display_if_dev_ptr->FLAGS;
      return(result);
   } /* Endif */
     
      
   result = (io_display_if_dev_ptr->DEV_INIT)(io_display_if_dev_ptr, open_name_ptr);
   if (result == MQX_OK) {
	   io_display_if_dev_ptr->COUNT = 1;
	   
   } /* Endif */
   
   return(result);

} /* Endbody */



/*FUNCTION****************************************************************
* 
* Function Name    : _DISPLAY_if_close
* Returned Value   : int_32 error code
* Comments         :
*    This routine closes the SPI I/O channel.
* 
*END**********************************************************************/

_mqx_int _io_display_if_close
   (
      /* [IN] the file handle for the device being closed */
      FILE_DEVICE_STRUCT_PTR fd_ptr
   )
{ /* Body */
   IO_DEVICE_STRUCT_PTR            io_dev_ptr;
   IO_DISPLAY_IF_DEVICE_STRUCT_PTR      display_io_dev_ptr;
   _mqx_int                        result = MQX_OK;

   io_dev_ptr     = (IO_DEVICE_STRUCT_PTR)fd_ptr->DEV_PTR;
   display_io_dev_ptr = (pointer)io_dev_ptr->DRIVER_INIT_PTR;

   if (--display_io_dev_ptr->COUNT == 0) {
      if (display_io_dev_ptr->DEV_DEINIT) {
         result = (*display_io_dev_ptr->DEV_DEINIT)(display_io_dev_ptr->DEV_INIT_DATA_PTR,
        		 display_io_dev_ptr->DEV_INFO_PTR);
      } /* Endif */ 
   } /* Endif */
   return(result);
} /* Endbody */


  
/*FUNCTION****************************************************************
* 
* Function Name    : _display_if_read
* Returned Value   : int_32 number of characters read
* Comments         :
*    Reads bytes into array from SPI input buffers.
*    Returns number of characters received, or 0 if timed-out
*
*END*********************************************************************/

_mqx_int _io_display_if_read
   (
      /* [IN] the handle returned from _fopen */
      FILE_DEVICE_STRUCT_PTR          fd_ptr,

      /* [IN] where the characters are to be stored */
      char_ptr                        data_ptr,

      /* [IN] timeout (immediate return if 0) */
      _mqx_int                        n
   )
{  /* Body */

   IO_DEVICE_STRUCT_PTR                  io_dev_ptr;
   IO_DISPLAY_IF_DEVICE_STRUCT_PTR         display_io_dev_ptr;
   _mqx_int                              num = 0;
   
   io_dev_ptr     = (IO_DEVICE_STRUCT_PTR)fd_ptr->DEV_PTR;
   display_io_dev_ptr = (pointer)io_dev_ptr->DRIVER_INIT_PTR;

   num = (*display_io_dev_ptr->DEV_READ)(display_io_dev_ptr, data_ptr, n);

   return( num );

}  /* Endbody */



/*FUNCTION****************************************************************
* 
* Function Name    : _display_if_write
* Returned Value   : void
* Comments         :
*    This routine calls the appropriate write routine.
*
*END**********************************************************************/

_mqx_int _io_display_if_write
   (
      /* [IN] the handle returned from _fopen */
      FILE_DEVICE_STRUCT_PTR    fd_ptr,

      /* [IN] where the pcm are written from*/
      char_ptr  data_ptr,

      /* [IN] the number of pcm data to output */
      _mqx_int  n
   )
{  /* Body */
	
       
    return( 0 );
              
} /* Endbody */
   
   
   
/*FUNCTION*****************************************************************
* 
* Function Name    : _display_if_ioctl
* Returned Value   : int_32
* Comments         :
*    Returns result of spi ioctl operation.
*
*END*********************************************************************/

_mqx_int _io_display_if_ioctl
   (
      /* [IN] the file handle for the device */
      FILE_DEVICE_STRUCT_PTR fd_ptr,

      /* [IN] the ioctl command */
      _mqx_uint              cmd,

      /* [IN] the ioctl parameters */
      pointer                input_param_ptr
   )
{ /* Body */
   IO_DEVICE_STRUCT_PTR               io_dev_ptr;
   IO_DISPLAY_IF_DEVICE_STRUCT_PTR    display_io_dev_ptr;
   _mqx_int                           result = MQX_OK;

   uint_32_ptr                        param_ptr = (uint_32_ptr)input_param_ptr;

   io_dev_ptr     = (IO_DEVICE_STRUCT_PTR)fd_ptr->DEV_PTR;
   display_io_dev_ptr = (pointer)io_dev_ptr->DRIVER_INIT_PTR;

   if (display_io_dev_ptr->DEV_IOCTL != NULL) {
           //result = (*display_io_dev_ptr->DEV_IOCTL)(display_io_dev_ptr->DEV_INFO_PTR, 
            result = (*display_io_dev_ptr->DEV_IOCTL)(display_io_dev_ptr,  //zcy
              cmd, param_ptr);
        } /* Endif */
                 
   return result;

} /* Endbody */

