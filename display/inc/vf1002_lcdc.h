#ifndef __VF1002_LCDC_H__
#define __VF1002_LCDC_H__

// *****************************************************************************
//   FTLCD200C  Module Register Structure
// *****************************************************************************
typedef struct _VF_REGS_FT200_LCDC_GP {
	VF_REG	fen; 	    	//LCD Function Enable
	VF_REG	ppp; 	    	//LCD Panel Pixel Parameters
	VF_REG	int_msk;   	//LCD Interrupt Enable Mask Parameters
	VF_REG	int_clr; 	 	//LCD Interrupt Status Clear Parameters	
	VF_REG	int_sts; 		//LCD Interrupt Status Parameters
	VF_REG	fbp; 		//Frame Buffer Parameters
	VF_REG	img0add; 	//LCD Panel Image0 Frame0 Base Address
	VF_REG   dummy0[2];
	VF_REG	img1add;	//LCD Panel Image1 Frame0 Base Address
	VF_REG   dummy1[2];
	VF_REG   img2add;	//LCD Panel Image2 Frame0 Base Address
	VF_REG   dummy2[2];
	VF_REG   img3add;	//LCD Panel Image3 Frame0 Base Address
	VF_REG   dummy3[2];	
	VF_REG   ppbd;			//PatGen Pattern Bar Distance Parameters
	VF_REG   fifotc;		//FIFO Threshold Control Parameters
	VF_REG   ggcp;		//GPI/GPO Control Parameters
} FT200_LCDC_REGS_GP;

#define TPPOFFSET	(0x100)
typedef struct _VF_REGS_FT200_LCDC_TPP {
	VF_REG htcp;		//LCD Horizontal Timing Control Parameters
	VF_REG vtc1;		//LCD Vertical Timing Control Parameters
	VF_REG vtc2;		//LCD Vertical Timing Control
	VF_REG pcp;		//LCD Polarity Control Parameters
}FT200_LCDC_REGS_TPP;

#define OFPOFFSET	(0x200)
typedef struct _VF_REGS_FT200_LCDC_OFP {
	VF_REG spp;		//LCD Serial Panel Pixel Parameters
	VF_REG ccir;		//LCD CCIR656 Parameters
}FT200_LCDC_REGS_OFP;

#define IMGPOFFSET	(0x300)
typedef struct _VF_REGS_FT200_LCDC_IMGP {
	VF_REG pipp; 	 //LCD PIP Parameter
	VF_REG sp1p;	 //PiP Sub-Picture1 Position
	VF_REG sp1d;	 //Sub-Picture1 Diminution
	VF_REG sp2p;	 //PiP Sub-Picture2 Position
	VF_REG sp2d;	 //Sub-Picture2 Diminution	
}FT200_LCDC_REGS_IMGP;

#define ICMOFFSET	(0x400)
typedef struct _VF_REGS_FT200_LCDC_ICM {
	VF_REG cmp0p; 	 //LCD Color Management Parament0 Parameters
	VF_REG cmp1p;	 //LCD Color Management Parament1 Parameters
	VF_REG cmp2p;	 //LCD Color Management Parament2 Parameters
	VF_REG cmp3p;	 //LCD Color Management Parament3 Parameters
}FT200_LCDC_REGS_ICM;

#define GROFFSET	(0x600)
#define GGOFFSET	(0x700)
#define GBOFFSET	(0x800)
#define GSIZE		(0x40)

#define PRAMOFFSET 	(0xA00) //Palette RAM Write Accessing Port

#define CSTNOFFSET	(0xC00)
typedef struct _VF_REGS_FT200_LCDC_CSTN {
	VF_REG	cstnpc; //CSTN Panel Control Parameters
	VF_REG	cstnpp1; //CSTN Panel Parameter1
	VF_REG	cstnpp2; //CSTN Panel Parameter2
}FT200_LCDC_REGS_CSTN;
#define CSTNMR	(0xE00+0x00)
#define CSTNMG	(0xE00+0x40)
#define CSTNMB	(0xE00+0x80)

#define SCROFFSET  (0x1100) 	//Scalar Control Registers
typedef struct _VF_REGS_FT200_LCDC_SCR {
	VF_REG	hrsi; //Horizontal Resolution Register of Scalar Input
	VF_REG	vrsi; //Vertical Resolution Register of Scalar Input
	VF_REG	hrso; //Horizontal Resolution Register of Scalar Output
	VF_REG	vrso; //Vertical Resolution Register of Scalar Output
	VF_REG	mcr; //Miscellaneous Control Register
	VF_REG	hhtr; //Horizontal High Threshold Register
	VF_REG	hltr; //Horizontal Low Threshold Register
	VF_REG	vhtr;//Vertical High Threshold Register
	VF_REG	vltr; //Vertical Low Threshold Register
	VF_REG  dummy[2];
	VF_REG   srp; //Scalar Resolution Parameters
}FT200_LCDC_REGS_SCR;

#define COSDOFFSET (0x2000) //OSD Control Registers with Complex Configuration
typedef struct _VF_REGS_FT200_LCDC_COSD {
	VF_REG	en; //OSD Windows On/Off Switch Register
	VF_REG	fcr0; //OSD Font Control Register 0
	VF_REG	fcr1; //OSD Font Control Register 1
	
	VF_REG	w1c0; //OSD Windows 1 Control Register 0
	VF_REG	w1c1; //OSD Windows 1 Control Register 1
	VF_REG	w1c2; //OSD Windows 1 Control Register 2
	VF_REG	w2c0; //OSD Windows 2 Control Register 0
	VF_REG	w2c1; //OSD Windows 2 Control Register 1
	VF_REG	w2c2; //OSD Windows 2 Control Register 2
	VF_REG	w3c0; //OSD Windows 3 Control Register 0
	VF_REG	w3c1; //OSD Windows 3 Control Register 1
	VF_REG	w3c2; //OSD Windows 3 Control Register 2
	VF_REG	w4c0; //OSD Windows 4 Control Register 0
	VF_REG	w4c1; //OSD Windows 4 Control Register 1
	VF_REG	w4c2; //OSD Windows 4 Control Register 2
	
	VF_REG	mcfba; //OSD Multi-Color Font Base Address
}FT200_LCDC_REGS_COSD;
#define PCR		(0x2040)  //OSD Palette Color Registers
#define FRAMD	(0x10000) //OSD Font RAM Data
#define FARAMD   (0x20000) //OSD Font Attribute RAM Data

typedef struct _VF_REGS_FT200_LCDC {
	FT200_LCDC_REGS_GP GP_REGS;
	VF_REG DUMMY0[(TPPOFFSET-0x50)/4 - 1];
	FT200_LCDC_REGS_TPP TPP_REGS;
	VF_REG DUMMY1[(OFPOFFSET-0x10c)/4 - 1];
	FT200_LCDC_REGS_OFP OFP_REGS;
	VF_REG DUMMY2[(IMGPOFFSET-0x204)/4 - 1];
	FT200_LCDC_REGS_IMGP IMGP_REGS;
	VF_REG DUMMY3[(ICMOFFSET-0x310)/4 - 1];
	FT200_LCDC_REGS_ICM ICM_REGS;
	VF_REG DUMMY4[(GROFFSET-0x40c)/4 - 1];
	VF_REG GR[(0x6fc - 0x600)/4 + 1];
	//VF_REG DUMMY5[(GGOFFSET-0x6fc)/4 - 1];
	VF_REG GG[(0x7fc - 0x700)/4 + 1];
	//VF_REG DUMMY6[(GBOFFSET-0x7fc)/4 - 1];
	VF_REG GB[(0x8fc - 0x800)/4 + 1];
	VF_REG DUMMY7[(PRAMOFFSET-0x8fc)/4 - 1];
	VF_REG PRAM[(0xc00 - 0xa00)/4];
	FT200_LCDC_REGS_CSTN CSTN_REGS;
	VF_REG DUMMY8[(SCROFFSET-0xc08)/4 - 1];
	FT200_LCDC_REGS_SCR SCR_REGS;
	VF_REG DUMMY9[(COSDOFFSET-0x112c)/4 - 1];
	FT200_LCDC_REGS_COSD COSD_REGS;
	VF_REG OSDPCR[(0x207c - 0x2040)/4 + 1];
	VF_REG DUMMY10[(FRAMD-0x207c)/4 - 1];
	VF_REG OSDFRAMD[(0x18ffc - 0x10000)/4 + 1];
	VF_REG DUMMY11[(FARAMD-0x18ffc)/4 - 1];
	VF_REG OSDFARAMD[(0x207fc - 0x20000)/4 + 1];
}VF_REGS_FT200_LCDC;
//======================================================

// For Complex OSD Configuration
#define ShColorSel(n) 		_SBF(20,n)
#define BdColorSel(n)			_SBF(16,n)
#define HighLightType(n) 		_SBF(13,n) //0:normal, 1: Border, 2: shadow, 3: reserved
#define TranType(n)			_SBF(10,n) //000: 0% 001: 25% 010: 50% 011: 75% 100: 100% Others: Reserved
#define HZoomOutMod(n) 		_SBF(9,n) //0: Normal 1: 0.5x
#define HZoomInMod(n)		_SBF(7,n) //00: Normal 01: 2x 10: 3x 11: 4x
#define HZoomMod(n) 		_SBF(6,n) //0: Zoom-out 1: Zoom-in
#define HZoomEn(n)			_SBF(5,n) //0: Off 1: On
#define VZoomOutMod(n) 		_SBF(4,n) //0: Normal 1: 0.5x
#define VZoomInMod(n)		_SBF(2,n) //00: Normal 01: 2x 10: 3x 11: 4x
#define VZoomMod(n) 		_SBF(1,n) //0: Zoom-out 1: Zoom-in
#define VZoomEn(n)			_SBF(0,n) //0: Off 1: On

#define ColSpace(n) 			_SBF(9,n) //Column space, 0 ~ 15  Note: When using the horizontal zoom-out mode (x0.5), the column space only supports from 7 to 15 pixels.
#define ColSpaceEn(n)		_SBF(8,n) //0: Off 1: On
#define RowSpace(n) 			_SBF(1,n) //Row space, 0 ~ 15
#define RowSpaceEn(n)		_SBF(0,n) //0: Off 1: On
//======================================================
#endif
