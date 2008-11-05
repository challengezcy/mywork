#ifndef DISPLAY_IF_PRV_H_
#define DISPLAY_IF_PRV_H_
#include "globaldef.h"

/*--------------------------------------------------------------------------*/
/*
**                            DATATYPE DECLARATIONS
*/
/*---------------------------------------------------------------------
**
** display Interface DEVICE STRUCT
**
** This structure used to store information about display interface device
** for the IO device table
*/
typedef struct io_display_if_device_struct
{
   /* [IN] A string that identifies the device for fopen */
   char_ptr	  ID_PTR;  
      
   /* The I/O init function */
   uint_32 (_CODE_PTR_ DEV_INIT)(pointer, char _PTR_);

   /* The I/O deinit function */
   uint_32 (_CODE_PTR_ DEV_DEINIT)(pointer, pointer);
   
   /* [IN] The READ function */
   uint_32 (_CODE_PTR_ DEV_READ)(pointer, char_ptr, _mqx_int);
      
   /* [IN] The WRITE function */
   uint_32 (_CODE_PTR_ DEV_WRITE)(pointer, char_ptr, _mqx_int);
   
   /* The ioctl function, (change bauds etc) */
   uint_32 (_CODE_PTR_ DEV_IOCTL)(pointer, uint_32, uint_32_ptr);

   /* The I/O channel initialization data */
   pointer             DEV_INIT_DATA_PTR;
   
   /* Device specific information */
   pointer             DEV_INFO_PTR;

   /* Open count for number of accessing file descriptors */
   uint_32             COUNT;

   /* Open flags for this channel */
   uint_32             FLAGS;
   
   
} IO_DISPLAY_IF_DEVICE_STRUCT, _PTR_ IO_DISPLAY_IF_DEVICE_STRUCT_PTR;


/*--------------------------------------------------------------------------*/
/*
**                            FUNCTION PROTOTYPES
*/

#ifdef __cplusplus
extern "C" {
#endif

/* I/O prototypes */
extern _mqx_int _io_display_if_open(FILE_DEVICE_STRUCT_PTR, char _PTR_, char _PTR_);
extern _mqx_int _io_display_if_close(FILE_DEVICE_STRUCT_PTR);
extern _mqx_int _io_display_if_read(FILE_DEVICE_STRUCT_PTR, char_ptr, _mqx_int);
extern _mqx_int _io_display_if_write(FILE_DEVICE_STRUCT_PTR, char_ptr, _mqx_int);
extern _mqx_int _io_display_if_ioctl(FILE_DEVICE_STRUCT_PTR, _mqx_uint, pointer);

#ifdef __cplusplus
}
#endif

#endif /*DISPLAY_IF_PRV_H_*/
