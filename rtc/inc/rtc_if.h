#ifndef RTC_IF_H_
#define RTC_IF_H_

    

/*--------------------------------------------------------------------------*/
/*
**                            FUNCTION PROTOTYPES
*/

#ifdef __cplusplus
extern "C" {
#endif

extern uint_32 _io_rtc_if_install(
      char_ptr,
      uint_32 (_CODE_PTR_)(pointer, char _PTR_),
      uint_32 (_CODE_PTR_)(pointer, pointer),
      uint_32 (_CODE_PTR_)(pointer, char _PTR_, _mqx_int),
      uint_32 (_CODE_PTR_)(pointer, char _PTR_, _mqx_int),
      uint_32 (_CODE_PTR_)(pointer, uint_32, uint_32_ptr),
      pointer);

#ifdef __cplusplus
}
#endif

#endif /*RTC_IF_H_*/
