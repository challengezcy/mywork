#ifndef __VF1002_RTC_H__
#define __VF1002_RTC_H__

//#define RTC_BASE     0x8100c000
typedef struct
{
	VF_REG  rtcdr;      //data register        		(0x00)
	VF_REG  rtcmr;    //match register  		(0x04)
	VF_REG  rtclr;    //load register  (0x08)
	VF_REG  rtccr;     //control register        (0x0c)
	VF_REG  rtcimsc;    // Interrupt mask, set , clear register       (0x10)
	VF_REG  rtcris;     //Raw Interrupt status Register		(0x14)
	VF_REG  rtcmis;     //Masked Interrupt status Register		(0x18)
	VF_REG  rtcicr;     //Interrupt Clear Register		(0x1c)
} VF_RTC_REGS_T;

//#define APB_RTC   ((APB_RTC_REGS_T *)(RTC_BASE))

#endif
