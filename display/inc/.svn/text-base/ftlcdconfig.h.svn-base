#ifndef __FTLCDCONFIG_H__
#define __FTLCDCONFIG_H__

#define LCD_TRUE	1
#define LCD_FALSE   0

typedef struct LcdMTypeTag
{
	int Valid;
	unsigned char Descriptor[20];
	unsigned int LCDEnable;
	unsigned int PanelPixel;
	unsigned int HorizontalTiming;
	unsigned int VerticalTiming1;
	unsigned int VerticalTiming2;
	unsigned int Polarity;
	unsigned int SerialPanelPixel;
	unsigned int CCIR656;
	unsigned int CSTNPanelControl;
	unsigned int CSTNPanelParam1;
	int Width;
	int Height;
} LCDMTYPE_T;

LCDMTYPE_T FLcdModule[] = 
{
	//TYPE0 : AUO A036QN01 with CPLD on, ie. accept the parallel signal*******************************
 { // Valid,	Descriptor  00000
    LCD_TRUE,	"AUO A036QN01",

    //LCDEnable
    // (LCD_FALSE	<< 14)			//Test pattern generator, not implement now
    (0x0 << 11)
    |(LCD_FALSE	<<  1)			//LCD screen on/off control
    |(LCD_FALSE		 ),			//LCD controller enable control
    
    //PanelPixel
     (LCD_FALSE	<< 15)			//LC_CLK domain reset
    |(LCD_FALSE	<< 14)			//HCLK domain reset
    |(0			<< 11)			//TFT panel color depth selection, 6-bit per channel
	|(1 		<<  4),			//RGB or BGR format selection
    
	//HorizontalTiming
	/*
	 ((0x2b	-1) << 24)	 		//Horizontal back porch
	|((0x21	-1) << 16)			//Horizontal front porch
	|((0x15	-1) <<  8)			//Horizontal Sync. pulse width
	|((320 >> 4)   -1),			//pixels-per-line = 16(PL+1)
	/*/
    	 ((0x06	-1) << 24)	 		//Horizontal back porch
	|((0x08	-1) << 16)			//Horizontal front porch
	|((0x02	-1) <<  8)			//Horizontal Sync. pulse width
	|((320 >> 4)   -1),			//pixels-per-line = 16(PL+1)
	//|((640 >> 4)   -1),			//pixels-per-line = 16(PL+1) paul.zhang
	
	//VerticalTiming1
	/*
	 (0x8		<< 24)			//Vertical front porch
	|((7	-1)	<< 16) 			//Vertical Sync. pulse width
	|(240	-1		 ),			//Lines-per-frame
	//|(480	-1		 ),			//Lines-per-frame paul.zhang
	
	//VerticalTiming2
	(14 	-1		 ),			//Vertical back porch
	/*/
	 (0x2		<< 24)			//Vertical front porch
	|((1	-1)	<< 16) 			//Vertical Sync. pulse width
	|(240	-1		 ),			//Lines-per-frame
	//|(480	-1		 ),			//Lines-per-frame paul.zhang
	
	//VerticalTiming2
	(2 	-1		 ),			//Vertical back porch
	
    
	//Polarity
	/*
	 (4			<<  8)			//Panel clock divisor = (DivNo + 1), DivNo >= 3 --> does not FIFO under run
	|(LCD_FALSE	<<  3)			//The invert output enable
	|(LCD_FALSE	<<  2)			//Select the edge of the panel clock
	|(LCD_TRUE	<<  1)			//The invert horizontal sync bit
	//|(LCD_FALSE		 ),			//The invert vertical sync bit
	|(LCD_TRUE		 ),			//The invert vertical sync bit
	/*/
	
	 (4			<<  8)			//Panel clock divisor = (DivNo + 1), DivNo >= 3 --> does not FIFO under run
	|(LCD_FALSE	<<  3)			//The invert output enable
	|(LCD_TRUE	<<  2)			//Select the edge of the panel clock
	|(LCD_TRUE	<<  1)			//The invert horizontal sync bit
	|(LCD_TRUE		 ),			//The invert vertical sync bit
    	
	//SerialPanelPixel
	 (LCD_FALSE	<<  5)			//AUO052 mode
	|(LCD_FALSE	<<  4)			//Left shift rotate
	|(LCD_FALSE	<<  2)			//Color sequence of odd line
	|(LCD_FALSE	<<  1)			//Delta type arrangement color filter
	|(LCD_FALSE		 ),			//RGB serial output mode

	//CCIR656
	 (LCD_FALSE	<<  2)			//TVE clock phase
	|(LCD_FALSE	<<  1)			//720 pixels per line
	|(LCD_FALSE		 ),			//NTSC/PAL select

	//CSTNPanelControl
	 (LCD_FALSE	<< 27)			//CSTN function enable bit
	|(LCD_FALSE	<< 25)			//Bus width of CSTN panel
	|(LCD_FALSE	<< 24)			//CSTN panel type
	|(LCD_FALSE	<< 16) 			//Virtual window width in framebuffer
	|(LCD_FALSE		 ),			//Horizontal dot's resolution of CSTN panel

	//CSTNPanelParam1
	 (LCD_FALSE	<< 16)			//CSTN horizontal back porch
	|(LCD_FALSE	<<  7) 			//Type of the signal, "AC", inverts
	|(LCD_FALSE		 ),			//Line numbers that "AC" inverts once
	
	//Width
	320,
	//640,
	//Height
	240,
	//480,
  },

	{ // Valid,	Descriptor  00000
		LCD_TRUE,	"AUO A036QN01",

		//LCDEnable
		 (LCD_FALSE	<< 14)			//Test pattern generator, not implement now
		|(0x2 << 11)
		|(LCD_FALSE	<<  1)			//LCD screen on/off control
		|(LCD_FALSE		 ),			//LCD controller enable control

		//PanelPixel
		(LCD_FALSE	<< 15)			//LC_CLK domain reset
		|(LCD_FALSE	<< 14)			//HCLK domain reset
		|(0			<< 11)			//TFT panel color depth selection, 6-bit per channel
		|(1 		<<  4),			//RGB or BGR format selection

		//HorizontalTiming
		((0x2b	-1) << 24)	 		//Horizontal back porch
		|((0x21	-1) << 16)			//Horizontal front porch
		|((0x15	-1) <<  8)			//Horizontal Sync. pulse width
		|((320 >> 4)   -1),			//pixels-per-line = 16(PL+1)

		//VerticalTiming1
		(0x8		<< 24)			//Vertical front porch
		|((7	-1)	<< 16) 			//Vertical Sync. pulse width
		|(240	-1		 ),			//Lines-per-frame

		//VerticalTiming2
		(14 	-1		 ),			//Vertical back porch

		//Polarity
		(2			<<  8)			//Panel clock divisor = (DivNo + 1), DivNo >= 3 --> does not FIFO under run
		|(LCD_FALSE	<<  3)			//The invert output enable
		|(LCD_FALSE	<<  2)			//Select the edge of the panel clock
		|(LCD_TRUE	<<  1)			//The invert horizontal sync bit
		|(LCD_FALSE		 ),			//The invert vertical sync bit

		//SerialPanelPixel
		(LCD_FALSE	<<  5)			//AUO052 mode
		|(LCD_FALSE	<<  4)			//Left shift rotate
		|(LCD_FALSE	<<  2)			//Color sequence of odd line
		|(LCD_FALSE	<<  1)			//Delta type arrangement color filter
		|(LCD_FALSE		 ),			//RGB serial output mode

		//CCIR656
		(LCD_FALSE	<<  2)			//TVE clock phase
		|(LCD_FALSE	<<  1)			//720 pixels per line
		|(LCD_FALSE		 ),			//NTSC/PAL select

		//CSTNPanelControl
		(LCD_FALSE	<< 27)			//CSTN function enable bit
		|(LCD_FALSE	<< 25)			//Bus width of CSTN panel
		|(LCD_FALSE	<< 24)			//CSTN panel type
		|(LCD_FALSE	<< 16) 			//Virtual window width in framebuffer
		|(LCD_FALSE		 ),			//Horizontal dot's resolution of CSTN panel

		//CSTNPanelParam1
		(LCD_FALSE	<< 16)			//CSTN horizontal back porch
		|(LCD_FALSE	<<  7) 			//Type of the signal, "AC", inverts
		|(LCD_FALSE		 ),			//Line numbers that "AC" inverts once

		320,	240,
	},

	//TYPE1 : AUO A036QN01 without CPLD, ie. accept the serial signal *****************************
	{ // Valid,	Descriptor  00001
		LCD_TRUE,	"AUO A036QN01",

		//LCDEnable
		(LCD_FALSE	<< 14)			//Test pattern generator, not implement now
		|(LCD_FALSE	<<  1)			//LCD screen on/off control
		|(LCD_FALSE		 ),			//LCD controller enable control

		//PanelPixel
		(LCD_FALSE	<< 15)			//LC_CLK domain reset
		|(LCD_FALSE	<< 14)			//HCLK domain reset
		|(1			<< 11)			//TFT panel color depth selection, 6-bit per channel
		|(0 		<<  4),			//RGB or BGR format selection

		//HorizontalTiming
		// ((0x2b	-1) << 24)	 		//Horizontal back porch
		((1-1) << 24)	 		//Horizontal back porch
		|((0x62	-1) << 16)			//Horizontal front porch
		|((0x1e	-1) <<  8)			//Horizontal Sync. pulse width
		|((320 >> 4)   -1),			//pixels-per-line = 16(PL+1)

		//VerticalTiming1
		(0x8		<< 24)			//Vertical front porch
		//|((7	-1)	<< 16) 			//Vertical Sync. pulse width
		|((2	-1)	<< 16) 			//Vertical Sync. pulse width
		|(240	-1 		 ),			//Lines-per-frame

		//VerticalTiming2
		(14 	-1		 ),			//Vertical back porch
		//(11 	-1		 ),			//Vertical back porch
		//Polarity
		(0			<<  8)			//Panel clock divisor = (DivNo + 1), DivNo >= 3 --> does not FIFO under run
		|(LCD_FALSE	<<  3)			//The invert output enable
		|(LCD_FALSE	<<  2)			//Select the edge of the panel clock
		|(LCD_TRUE	<<  1)			//The invert horizontal sync bit
		//|(LCD_FALSE		 ),			//The invert vertical sync bit
		|(LCD_TRUE		 ),			//The invert vertical sync bit

		//SerialPanelPixel
		(LCD_FALSE	<<  5)			//AUO052 mode
		|(LCD_FALSE	<<  4)			//Left shift rotate
		//|(LCD_TRUE	<<  2)			//Color sequence of odd line
		|(LCD_FALSE	<<  2)			//Color sequence of odd line
		|(LCD_FALSE	<<  1)			//Delta type arrangement color filter
		|(LCD_TRUE		 ),			//RGB serial output mode

		//CCIR656
		(LCD_FALSE	<<  2)			//TVE clock phase
		|(LCD_FALSE	<<  1)			//720 pixels per line
		|(LCD_FALSE		 ),			//NTSC/PAL select

		//CSTNPanelControl
		(LCD_FALSE	<< 27)			//CSTN function enable bit
		|(LCD_FALSE	<< 25)			//Bus width of CSTN panel
		|(LCD_FALSE	<< 24)			//CSTN panel type
		|(LCD_FALSE	<< 16) 			//Virtual window width in framebuffer
		|(LCD_FALSE		 ),			//Horizontal dot's resolution of CSTN panel

		//CSTNPanelParam1
		(LCD_FALSE	<< 16)			//CSTN horizontal back porch
		|(LCD_FALSE	<<  7) 			//Type of the signal, "AC", inverts
		|(LCD_FALSE		 ),			//Line numbers that "AC" inverts once

		320, 240,
	},

	//TYPE2 : Sharp Sharp LQ057Q3DC02 ***********************************************
	{ // Valid,	Descriptor  000002
		LCD_TRUE,	"Sharp LQ057Q3DC02",

		//LCDEnable
		(LCD_FALSE	<< 14)			//Test pattern generator, not implement now
		|(LCD_FALSE	<<  1)			//LCD screen on/off control
		|(LCD_FALSE		 ),			//LCD controller enable control

		//PanelPixel
		(LCD_FALSE	<< 15)			//LC_CLK domain reset
		|(LCD_FALSE	<< 14)			//HCLK domain reset
		|(0			<< 11)			//TFT panel color depth selection, 6-bit per channel
		|(1 		<<  4),			//RGB or BGR format selection

		//HorizontalTiming
		((0x11	-1) << 24)	 		//Horizontal back porch
		|((0x11	-1) << 16)			//Horizontal front porch
		|((0x11	-1) <<  8)			//Horizontal Sync. pulse width
		|((320 >> 4)   -1),			//pixels-per-line = 16(PL+1)

		//VerticalTiming1
		(0xF		<< 24)			//Vertical front porch
		|((1	-1)	<< 16) 			//Vertical Sync. pulse width
		|(240	 -1		 ),			//Lines-per-frame

		//VerticalTiming2
		(7 	-1		 	),			//Vertical back porch

		//Polarity
		(5			<<  8)			//Panel clock divisor = (DivNo + 1), DivNo >= 3 --> does not FIFO under run
		|(LCD_FALSE	<<  3)			//The invert output enable
		|(LCD_FALSE	<<  2)			//Select the edge of the panel clock
		|(LCD_TRUE	<<  1)			//The invert horizontal sync bit
		|(LCD_FALSE		 ),			//The invert vertical sync bit

		//SerialPanelPixel
		(LCD_FALSE	<<  5)			//AUO052 mode
		|(LCD_FALSE	<<  4)			//Left shift rotate
		|(LCD_FALSE	<<  2)			//Color sequence of odd line
		|(LCD_FALSE	<<  1)			//Delta type arrangement color filter
		|(LCD_FALSE		 ),			//RGB serial output mode

		//CCIR656
		(LCD_FALSE	<<  2)			//TVE clock phase
		|(LCD_FALSE	<<  1)			//720 pixels per line
		|(LCD_FALSE		 ),			//NTSC/PAL select

		//CSTNPanelControl
		(LCD_FALSE	<< 27)			//CSTN function enable bit
		|(LCD_FALSE	<< 25)			//Bus width of CSTN panel
		|(LCD_FALSE	<< 24)			//CSTN panel type
		|(LCD_FALSE	<< 16) 			//Virtual window width in framebuffer
		|(LCD_FALSE		 ),			//Horizontal dot's resolution of CSTN panel

		//CSTNPanelParam1
		(LCD_FALSE	<< 16)			//CSTN horizontal back porch
		|(LCD_FALSE	<<  7) 			//Type of the signal, "AC", inverts
		|(LCD_FALSE		 ),			//Line numbers that "AC" inverts once

		320,	240,
	},


	//TYPE3 : Sharp LQ084V1DG21 ***********************************************
	{ // Valid,	Descriptor  000003
		LCD_TRUE,	"Sharp LQ084V1DG21",

		//LCDEnable
		(LCD_FALSE	<< 14)			//Test pattern generator, not implement now
		|(LCD_FALSE	<<  1)			//LCD screen on/off control
		|(LCD_FALSE		 ),			//LCD controller enable control

		//PanelPixel
		(LCD_FALSE	<< 15)			//LC_CLK domain reset
		|(LCD_FALSE	<< 14)			//HCLK domain reset
		|(0			<< 11)			//TFT panel color depth selection, 
		|(0			<<  4),			//RGB or BGR format selection, 0 -> RGB

		//HorizontalTiming
		((44	-1) << 24)	 		//Horizontal back porch
		|((20	-1) << 16)			//Horizontal front porch
		|((96	-1) <<  8)			//Horizontal Sync. pulse width
		|((640 >> 4)-   1),			//pixels-per-line = 16(PPL+1)

		//VerticalTiming1
		(16		<< 24)			//Vertical front porch
		|((17	-1)	<< 16) 			//Vertical Sync. pulse width
		|(480	 -1		 ),			//Lines-per-frame

		//VerticalTiming2
		(17 	-1		 ),			//Vertical back porch

		//Polarity
		(1			<<  8)			//Panel clock divisor = (DivNo + 1)
		|(LCD_FALSE	<<  3)			//The invert output enable
		|(LCD_FALSE	<<  2)			//Select the edge of the panel clock
		|(LCD_FALSE	<<  1)			//The invert horizontal sync bit
		|(LCD_TRUE		 ),			//The invert vertical sync bit

		//SerialPanelPixel
		(LCD_FALSE	<<  5)			//AUO052 mode
		|(LCD_FALSE	<<  4)			//Left shift rotate
		|(LCD_FALSE	<<  2)			//Color sequence of odd line
		|(LCD_FALSE	<<  1)			//Delta type arrangement color filter
		|(LCD_FALSE		 ),			//RGB serial output mode

		//CCIR656
		(LCD_FALSE	<<  2)			//TVE clock phase
		|(LCD_FALSE	<<  1)			//720 pixels per line
		|(LCD_FALSE		 ),			//NTSC/PAL select

		//CSTNPanelControl
		(LCD_FALSE	<< 27)			//CSTN function enable bit
		|(LCD_FALSE	<< 25)			//Bus width of CSTN panel
		|(LCD_FALSE	<< 24)			//CSTN panel type
		|(LCD_FALSE	<< 16) 			//Virtual window width in framebuffer
		|(LCD_FALSE		 ),			//Horizontal dot's resolution of CSTN panel

		//CSTNPanelParam1
		(LCD_FALSE	<< 16)			//CSTN horizontal back porch
		|(LCD_FALSE	<<  7) 			//Type of the signal, "AC", inverts
		|(LCD_FALSE		 ),			//Line numbers that "AC" inverts once

		640,	480,
	},

	//TYPE3 : TVEncoder av3168 ***********************************************
	{ // Valid,	Descriptor  000004
		LCD_TRUE,	"Sharp LQ084V1DG21",

		//LCDEnable
		(LCD_FALSE	<< 14)			//Test pattern generator, not implement now
		|(LCD_FALSE	<<  1)			//LCD screen on/off control
		|(LCD_FALSE		 ),			//LCD controller enable control

		//PanelPixel
		(LCD_FALSE	<< 15)			//LC_CLK domain reset
		|(LCD_FALSE	<< 14)			//HCLK domain reset
		|(0			<< 11)			//TFT panel color depth selection, 
		|(0			<<  4),			//RGB or BGR format selection, 0 -> RGB

		//HorizontalTiming
		((8	-1) << 24)	 		//Horizontal back porch
		|((208	-1) << 16)			//Horizontal front porch
		|((8	-1) <<  8)			//Horizontal Sync. pulse width
		|(40 -   1),			//pixels-per-line = 16(PPL+1)	

		//VerticalTiming1
		(53		<< 24)			//Vertical front porch
		|((11	-1)	<< 16) 			//Vertical Sync. pulse width
		|(480	 -1		 ),			//Lines-per-frame	
		//VerticalTiming2
		(81 	-1		 ),			//Vertical back porch

		//Polarity
		(0			<<  8)			//Panel clock divisor = (DivNo + 1)
		|(LCD_FALSE	<<  3)			//The invert output enable
		|(LCD_TRUE	<<  2)			//Select the edge of the panel clock
		|(LCD_TRUE	<<  1)			//The invert horizontal sync bit
		|(LCD_TRUE		 ),			//The invert vertical sync bit

		//SerialPanelPixel
		(LCD_FALSE	<<  5)			//AUO052 mode
		|(LCD_FALSE	<<  4)			//Left shift rotate
		|(LCD_FALSE	<<  2)			//Color sequence of odd line
		|(LCD_FALSE	<<  1)			//Delta type arrangement color filter
		|(LCD_FALSE		 ),			//RGB serial output mode

		//CCIR656
		(LCD_FALSE	<<  2)			//TVE clock phase
		|(LCD_FALSE	<<  1)			//720 pixels per line
		|(0		 ),					//NTSC/PAL select


		//CSTNPanelControl
		(LCD_FALSE	<< 27)			//CSTN function enable bit
		|(LCD_FALSE	<< 25)			//Bus width of CSTN panel
		|(LCD_FALSE	<< 24)			//CSTN panel type
		|(LCD_FALSE	<< 16) 			//Virtual window width in framebuffer
		|(LCD_FALSE		 ),			//Horizontal dot's resolution of CSTN panel

		//CSTNPanelParam1
		(LCD_FALSE	<< 16)			//CSTN horizontal back porch
		|(LCD_FALSE	<<  7) 			//Type of the signal, "AC", inverts
		|(LCD_FALSE		 ),			//Line numbers that "AC" inverts once

		640,	480,
	},

	//TYPE4 : PRIME VIEW PD035VX2 ***********************************************
	{ // Valid,	Descriptor
		LCD_TRUE,	"PRIME VIEW PD035VX2",

		//LCDEnable
		(LCD_FALSE	<< 14)			//Test pattern generator, not implement now
		|(LCD_FALSE	<<  1)			//LCD screen on/off control
		|(LCD_FALSE		 ),			//LCD controller enable control

		//PanelPixel
		(LCD_FALSE	<< 15)			//LC_CLK domain reset
		|(LCD_FALSE	<< 14)			//HCLK domain reset
		|(0			<< 11)			//TFT panel color depth selection, 0 -> 6-bit per channel
		|(1			<<  4),			//RGB or BGR format selection, 0 -> RGB

		//HorizontalTiming
		((0x30	-1) << 24)	 		//Horizontal back porch
		|((20	-1) << 16)			//Horizontal front porch
		|((96	-1) <<  8)			//Horizontal Sync. pulse width
		|((640 >> 4)-   1),			//pixels-per-line = 16(PPL+1)

		//VerticalTiming1
		(16		<< 24)			//Vertical front porch
		|((69	-1)	<< 16) 			//Vertical Sync. pulse width
		|(480	 -1		 ),			//Lines-per-frame

		//VerticalTiming2
		(0x1E 	-1		 ),			//Vertical back porch

		//Polarity
		(6			<<  8)			//Panel clock divisor = (DivNo + 1)
		|(LCD_FALSE	<<  3)			//The invert output enable
		|(LCD_TRUE	<<  2)			//Select the edge of the panel clock
		|(LCD_TRUE	<<  1)			//The invert horizontal sync bit
		|(LCD_TRUE		 ),			//The invert vertical sync bit

		//SerialPanelPixel
		(LCD_FALSE	<<  5)			//AUO052 mode
		|(LCD_FALSE	<<  4)			//Left shift rotate
		|(LCD_FALSE	<<  2)			//Color sequence of odd line
		|(LCD_FALSE	<<  1)			//Delta type arrangement color filter
		|(LCD_FALSE		 ),			//RGB serial output mode

		//CCIR656
		(LCD_FALSE	<<  2)			//TVE clock phase
		|(LCD_FALSE	<<  1)			//720 pixels per line
		|(LCD_FALSE		 ),			//NTSC/PAL select

		//CSTNPanelControl
		(LCD_FALSE	<< 27)			//CSTN function enable bit
		|(LCD_FALSE	<< 25)			//Bus width of CSTN panel
		|(LCD_FALSE	<< 24)			//CSTN panel type
		|(LCD_FALSE	<< 16) 			//Virtual window width in framebuffer
		|(LCD_FALSE		 ),			//Horizontal dot's resolution of CSTN panel

		//CSTNPanelParam1
		(LCD_FALSE	<< 16)			//CSTN horizontal back porch
		|(LCD_FALSE	<<  7) 			//Type of the signal, "AC", inverts
		|(LCD_FALSE		 ),			//Line numbers that "AC" inverts once

		640,	480,

	},

	//TYPE5 : KOROLA 6.5-inch TFT-LCD TV NTSC ***********************************************
	{ // Valid,	Descriptor
		LCD_TRUE,	"KOROLA 6.5'' LCD TV",

		//LCDEnable
		(LCD_FALSE	<< 14)			//Test pattern generator, not implement now
		|(LCD_TRUE	<<  1)			//LCD screen on/off control
		|(LCD_TRUE		 ),			//LCD controller enable control

		//PanelPixel
		(LCD_FALSE	<< 15)			//LC_CLK domain reset
		|(LCD_FALSE	<< 14)			//HCLK domain reset
		|(LCD_FALSE	<< 11)			//TFT panel color depth selection
		|(LCD_FALSE	<<  4),			//RGB or BGR format selection

		//HorizontalTiming
		((3	-1) << 24)	 		//Horizontal back porch
		|((0xD3	-1) << 16)			//Horizontal front porch
		|((4	-1) <<  8)			//Horizontal Sync. pulse width
		|((640 >> 4)   -1),			//pixels-per-line = 16(PL+1)

		//VerticalTiming1
		(1			<< 24)			//Vertical front porch
		|((18	-1)	<< 16) 			//Vertical Sync. pulse width
		|(480	-1 		 ),			//Lines-per-frame

		//VerticalTiming2
		(0x1a 	-1		 ),			//Vertical back porch, for NTSC/PAL, VBP has to add 1 if sharpness disabled

		//Polarity
		(0			<<  8)			//Panel clock divisor = (DivNo + 1)
		|(LCD_FALSE	<<  3)			//The invert output enable
		|(LCD_FALSE	<<  2)			//Select the edge of the panel clock
		|(LCD_TRUE	<<  1)			//The invert horizontal sync bit
		|(LCD_TRUE		 ),			//The invert vertical sync bit

		//SerialPanelPixel
		(LCD_FALSE	<<  5)			//AUO052 mode
		|(LCD_FALSE	<<  4)			//Left shift rotate
		|(LCD_FALSE	<<  2)			//Color sequence of odd line
		|(LCD_FALSE	<<  1)			//Delta type arrangement color filter
		|(LCD_FALSE		 ),			//RGB serial output mode

		//CCIR656
		(LCD_TRUE	<<  2)			//TVE clock phase
		|(LCD_FALSE	<<  1)			//720 pixels per line
		|(LCD_TRUE		 ),			//NTSC/PAL select

		//CSTNPanelControl
		(LCD_FALSE	<< 27)			//CSTN function enable bit
		|(LCD_FALSE	<< 25)			//Bus width of CSTN panel
		|(LCD_FALSE	<< 24)			//CSTN panel type
		|(LCD_FALSE	<< 16) 			//Virtual window width in framebuffer
		|(LCD_FALSE		 ),			//Horizontal dot's resolution of CSTN panel

		//CSTNPanelParam1
		(LCD_FALSE	<< 16)			//CSTN horizontal back porch
		|(LCD_FALSE	<<  7) 			//Type of the signal, "AC", inverts
		|(LCD_FALSE		 ),			//Line numbers that "AC" inverts once

		640,	480
	},


	//TYPE6 : KOROLA 6.5-inch TFT-LCD TV NTSC ***********************************************
	{ // Valid,	Descriptor
		LCD_TRUE,	"KOROLA 6.5'' LCD TV",

		//LCDEnable
		(LCD_FALSE	<< 14)			//Test pattern generator, not implement now
		|(LCD_TRUE	<<  1)			//LCD screen on/off control
		|(LCD_TRUE		 ),			//LCD controller enable control

		//PanelPixel
		(LCD_FALSE	<< 15)			//LC_CLK domain reset
		|(LCD_FALSE	<< 14)			//HCLK domain reset
		|(LCD_FALSE	<< 11)			//TFT panel color depth selection
		|(LCD_FALSE	<<  4),			//RGB or BGR format selection

		//HorizontalTiming
		((3	-1) << 24)	 		//Horizontal back porch
		|((0x7f	-1) << 16)			//Horizontal front porch
		|((8	-1) <<  8)			//Horizontal Sync. pulse width
		|((720 >> 4)   -1),			//pixels-per-line = 16(PL+1)

		//VerticalTiming1
		(1			<< 24)			//Vertical front porch
		|((0x11	-1)	<< 16) 			//Vertical Sync. pulse width
		|(480	-1 		 ),			//Lines-per-frame

		//VerticalTiming2
		(0x1b 	-1		 ),			//Vertical back porch, for NTSC/PAL, VBP has to add 1 if sharpness disabled

		//Polarity
		(0			<<  8)			//Panel clock divisor = (DivNo + 1)
		|(LCD_FALSE	<<  3)			//The invert output enable
		|(LCD_FALSE	<<  2)			//Select the edge of the panel clock
		|(LCD_TRUE	<<  1)			//The invert horizontal sync bit
		|(LCD_TRUE		 ),			//The invert vertical sync bit

		//SerialPanelPixel
		(LCD_FALSE	<<  5)			//AUO052 mode
		|(LCD_FALSE	<<  4)			//Left shift rotate
		|(LCD_FALSE	<<  2)			//Color sequence of odd line
		|(LCD_FALSE	<<  1)			//Delta type arrangement color filter
		|(LCD_FALSE		 ),			//RGB serial output mode

		//CCIR656
		(LCD_TRUE	<<  2)			//TVE clock phase
		|(LCD_TRUE	<<  1)			//720 pixels per line
		|(LCD_TRUE		 ),			//NTSC/PAL select

		//CSTNPanelControl
		(LCD_FALSE	<< 27)			//CSTN function enable bit
		|(LCD_FALSE	<< 25)			//Bus width of CSTN panel
		|(LCD_FALSE	<< 24)			//CSTN panel type
		|(LCD_FALSE	<< 16) 			//Virtual window width in framebuffer
		|(LCD_FALSE		 ),			//Horizontal dot's resolution of CSTN panel

		//CSTNPanelParam1
		(LCD_FALSE	<< 16)			//CSTN horizontal back porch
		|(LCD_FALSE	<<  7) 			//Type of the signal, "AC", inverts
		|(LCD_FALSE		 ),			//Line numbers that "AC" inverts once

		720,	480
	},


	//TYPE 7 : KOROLA 6.5-inch TFT-LCD TV PAL 640x480 ***************************************
	{ // Valid,	Descriptor
		LCD_TRUE,	"KOROLA 6.5'' LCD TV",

		//LCDEnable
		(LCD_FALSE	<< 14)			//Test pattern generator, not implement now
		|(LCD_TRUE	<<  1)			//LCD screen on/off control
		|(LCD_TRUE		 ),			//LCD controller enable control

		//PanelPixel
		(LCD_FALSE	<< 15)			//LC_CLK domain reset
		|(LCD_FALSE	<< 14)			//HCLK domain reset
		|(LCD_FALSE	<< 11)			//TFT panel color depth selection
		|(LCD_FALSE	<<  4),			//RGB or BGR format selection

		//HorizontalTiming
		((8	-1) << 24)	 		//Horizontal back porch
		|((0xd0	-1) << 16)			//Horizontal front porch
		|((8	-1) <<  8)			//Horizontal Sync. pulse width
		|((640 >> 4)   -1),			//pixels-per-line = 16(PL+1)

		//VerticalTiming1, VFP + VW + LF + VBP = 625 and VW + VBP = 91
		(0x35			<< 24)			//Vertical front porch
		|((0x0b	-1)	<< 16) 			//Vertical Sync. pulse width
		|(480	-1 		 ),			//Lines-per-frame

		//VerticalTiming2
		(0x51 	-1		 ),			//Vertical back porch, for NTSC/PAL, VBP has to add 1 if sharpness disabled

		//Polarity
		(0			<<  8)			//Panel clock divisor = (DivNo + 1)
		|(LCD_FALSE	<<  3)			//The invert output enable
		|(LCD_FALSE	<<  2)			//Select the edge of the panel clock
		|(LCD_TRUE	<<  1)			//The invert horizontal sync bit
		|(LCD_TRUE		 ),			//The invert vertical sync bit

		//SerialPanelPixel
		(LCD_FALSE	<<  5)			//AUO052 mode
		|(LCD_FALSE	<<  4)			//Left shift rotate
		|(LCD_FALSE	<<  2)			//Color sequence of odd line
		|(LCD_FALSE	<<  1)			//Delta type arrangement color filter
		|(LCD_FALSE		 ),			//RGB serial output mode

		//CCIR656
		(LCD_TRUE	<<  2)			//TVE clock phase
		|(LCD_FALSE	<<  1)			//720 pixels per line
		|(LCD_FALSE		 ),			//NTSC/PAL select

		//CSTNPanelControl
		(LCD_FALSE	<< 27)			//CSTN function enable bit
		|(LCD_FALSE	<< 25)			//Bus width of CSTN panel
		|(LCD_FALSE	<< 24)			//CSTN panel type
		|(LCD_FALSE	<< 16) 			//Virtual window width in framebuffer
		|(LCD_FALSE		 ),			//Horizontal dot's resolution of CSTN panel

		//CSTNPanelParam1
		(LCD_FALSE	<< 16)			//CSTN horizontal back porch
		|(LCD_FALSE	<<  7) 			//Type of the signal, "AC", inverts
		|(LCD_FALSE		 ),			//Line numbers that "AC" inverts once

		640,	480
	},

	//TYPE 8 : KOROLA 6.5-inch TFT-LCD TV PAL 720x576 ***************************************
	{ // Valid,	Descriptor
		LCD_TRUE,	"KOROLA 6.5'' LCD TV",

		//LCDEnable
		(LCD_FALSE	<< 14)			//Test pattern generator, not implement now
		|(LCD_TRUE	<<  1)			//LCD screen on/off control
		|(LCD_TRUE		 ),			//LCD controller enable control

		//PanelPixel
		(LCD_FALSE	<< 15)			//LC_CLK domain reset
		|(LCD_FALSE	<< 14)			//HCLK domain reset
		|(LCD_FALSE	<< 11)			//TFT panel color depth selection
		|(LCD_FALSE	<<  4),			//RGB or BGR format selection

		//HorizontalTiming
		((3	-1) << 24)	 		//Horizontal back porch
		|((0x85	-1) << 16)			//Horizontal front porch
		|((8	-1) <<  8)			//Horizontal Sync. pulse width
		|((720 >> 4)   -1),			//pixels-per-line = 16(PL+1)

		//VerticalTiming1
		(5			<< 24)			//Vertical front porch
		|((0x11	-1)	<< 16) 			//Vertical Sync. pulse width
		|(576	-1 		 ),			//Lines-per-frame

		//VerticalTiming2
		(0x1b 	-1		 ),			//Vertical back porch, for NTSC/PAL, VBP has to add 1 if sharpness disabled

		//Polarity
		(0			<<  8)			//Panel clock divisor = (DivNo + 1)
		|(LCD_FALSE	<<  3)			//The invert output enable
		|(LCD_FALSE	<<  2)			//Select the edge of the panel clock
		|(LCD_TRUE	<<  1)			//The invert horizontal sync bit
		|(LCD_TRUE		 ),			//The invert vertical sync bit

		//SerialPanelPixel
		(LCD_FALSE	<<  5)			//AUO052 mode
		|(LCD_FALSE	<<  4)			//Left shift rotate
		|(LCD_FALSE	<<  2)			//Color sequence of odd line
		|(LCD_FALSE	<<  1)			//Delta type arrangement color filter
		|(LCD_FALSE		 ),			//RGB serial output mode

		//CCIR656
		(LCD_TRUE	<<  2)			//TVE clock phase
		|(LCD_TRUE	<<  1)			//720 pixels per line
		|(LCD_FALSE		 ),			//NTSC/PAL select

		//CSTNPanelControl
		(LCD_FALSE	<< 27)			//CSTN function enable bit
		|(LCD_FALSE	<< 25)			//Bus width of CSTN panel
		|(LCD_FALSE	<< 24)			//CSTN panel type
		|(LCD_FALSE	<< 16) 			//Virtual window width in framebuffer
		|(LCD_FALSE		 ),			//Horizontal dot's resolution of CSTN panel

		//CSTNPanelParam1
		(LCD_FALSE	<< 16)			//CSTN horizontal back porch
		|(LCD_FALSE	<<  7) 			//Type of the signal, "AC", inverts
		|(LCD_FALSE		 ),			//Line numbers that "AC" inverts once

		720,	576
	},


	//TYPE 9 : 240x160 CSTN-LCD  ***********************************************
	{ // Valid,	Descriptor
		LCD_TRUE,	"CSTN Panel",

		//LCDEnable
		(LCD_FALSE	<< 14)			//Test pattern generator, not implement now
		|(LCD_TRUE	<<  1)			//LCD screen on/off control
		|(LCD_TRUE		 ),			//LCD controller enable control

		//PanelPixel
		(LCD_FALSE	<< 15)			//LC_CLK domain reset
		|(LCD_FALSE	<< 14)			//HCLK domain reset
		|(LCD_FALSE	<< 11)			//TFT panel color depth selection
		|(LCD_FALSE	<<  4),			//RGB or BGR format selection

		//HorizontalTiming
		((6	-1) << 24)	 		//Horizontal back porch
		|((1	-1) << 16)			//Horizontal front porch
		|((2	-1) <<  8)			//Horizontal Sync. pulse width
		|((240 >> 4)   -1),			//pixels-per-line = 16(PL+1)

		//VerticalTiming1
		(0			<< 24)			//Vertical front porch
		|((1	-1)	<< 16) 			//Vertical Sync. pulse width
		|(160	-1 		 ),			//Lines-per-frame

		//VerticalTiming2
		(1 	-1		 ),				//Vertical back porch

		//Polarity
		(0			<<  8)			//Panel clock divisor = (DivNo + 1)	//166HZ on 20MHZ
		|(LCD_FALSE	<<  3)			//The invert output enable
		|(LCD_FALSE	<<  2)			//Select the edge of the panel clock
		|(LCD_FALSE	<<  1)			//The invert horizontal sync bit
		|(LCD_FALSE		 ),			//The invert vertical sync bit

		//SerialPanelPixel
		(LCD_FALSE	<<  5)			//AUO052 mode
		|(LCD_FALSE	<<  4)			//Left shift rotate
		|(LCD_FALSE	<<  2)			//Color sequence of odd line
		|(LCD_FALSE	<<  1)			//Delta type arrangement color filter
		|(LCD_FALSE		 ),			//RGB serial output mode

		//CCIR656
		(LCD_FALSE	<<  2)			//TVE clock phase
		|(LCD_FALSE	<<  1)			//720 pixels per line
		|(LCD_FALSE		 ),			//NTSC/PAL select

		//CSTNPanelControl
		(LCD_TRUE	<< 27)			//CSTN function enable bit
		|(3			<< 25)			//Bus width of CSTN panel
		|(0			<< 24)			//CSTN panel type
		|((240/16)	<< 16) 			//Virtual window width in framebuffer
		|(240*3	-1		 ),			//Horizontal dot's resolution of CSTN panel

		//CSTNPanelParam1
		(1		<< 16)			//CSTN horizontal back porch
		|(LCD_FALSE	<<  7) 			//Type of the signal, "AC", inverts
		|(2*160	+1		 ),			//Line numbers that "AC" inverts once

		240,	160
	},


	//TYPE 10 : 160x160 STN-LCD  ***********************************************
	{ // Valid,	Descriptor
		LCD_TRUE,	"STN Panel",

		//LCDEnable
		(LCD_FALSE	<< 14)			//Test pattern generator, not implement now
		|(LCD_TRUE	<<  1)			//LCD screen on/off control
		|(LCD_TRUE		 ),			//LCD controller enable control

		//PanelPixel
		(LCD_FALSE	<< 15)			//LC_CLK domain reset
		|(LCD_FALSE	<< 14)			//HCLK domain reset
		|(LCD_FALSE	<< 11)			//TFT panel color depth selection
		|(LCD_FALSE	<<  4),			//RGB or BGR format selection

		//HorizontalTiming
		((6	-1) << 24)	 		//Horizontal back porch
		|((1	-1) << 16)			//Horizontal front porch
		|((2	-1) <<  8)			//Horizontal Sync. pulse width
		|((160 >> 4)   -1),			//pixels-per-line = 16(PL+1)

		//VerticalTiming1
		(0			<< 24)			//Vertical front porch
		|((1	-1)	<< 16) 			//Vertical Sync. pulse width
		|(160	-1 		 ),			//Lines-per-frame

		//VerticalTiming2
		(1 	-1		 ),				//Vertical back porch

		//Polarity
		(5			<<  8)			//Panel clock divisor = (DivNo + 1)
		|(LCD_FALSE	<<  3)			//The invert output enable
		|(LCD_FALSE	<<  2)			//Select the edge of the panel clock
		|(LCD_FALSE	<<  1)			//The invert horizontal sync bit
		|(LCD_FALSE		 ),			//The invert vertical sync bit

		//SerialPanelPixel
		(LCD_FALSE	<<  5)			//AUO052 mode
		|(LCD_FALSE	<<  4)			//Left shift rotate
		|(LCD_FALSE	<<  2)			//Color sequence of odd line
		|(LCD_FALSE	<<  1)			//Delta type arrangement color filter
		|(LCD_FALSE		 ),			//RGB serial output mode

		//CCIR656
		(LCD_FALSE	<<  2)			//TVE clock phase
		|(LCD_FALSE	<<  1)			//720 pixels per line
		|(LCD_FALSE		 ),			//NTSC/PAL select

		//CSTNPanelControl
		(LCD_TRUE	<< 27)			//CSTN function enable bit
		|(2			<< 25)			//Bus width of CSTN panel
		|(1			<< 24)			//CSTN panel type
		|((160/16)	<< 16) 			//Virtual window width in framebuffer
		|(160	-1		 ),			//Horizontal dot's resolution of CSTN panel

		//CSTNPanelParam1
		(1			<< 16)			//CSTN horizontal back porch
		|(LCD_FALSE	<<  7) 			//Type of the signal, "AC", inverts
		|(2*160	+1		 ),			//Line numbers that "AC" inverts once

		160,	160
	},
  
	//TYPE 11 : 160x80 STN-LCD (Mono) *******************************************
	{ // Valid,	Descriptor, it is not good for grayscale because the frame rate cannot be fast, almost < 113MHZ
		LCD_TRUE,	"STN Panel",

		//LCDEnable
		(LCD_FALSE	<< 14)			//Test pattern generator, not implement now
		|(LCD_TRUE	<<  1)			//LCD screen on/off control
		|(LCD_TRUE		 ),			//LCD controller enable control

		//PanelPixel
		(LCD_FALSE	<< 15)			//LC_CLK domain reset
		|(LCD_FALSE	<< 14)			//HCLK domain reset
		|(LCD_FALSE	<< 11)			//TFT panel color depth selection
		|(LCD_FALSE	<<  4),			//RGB or BGR format selection

		//HorizontalTiming
		((6	-1) << 24)	 		//Horizontal back porch
		|((1	-1) << 16)			//Horizontal front porch
		|((2	-1) <<  8)			//Horizontal Sync. pulse width
		|((160 >> 4)   -1),			//pixels-per-line = 16(PL+1)

		//VerticalTiming1
		(0 		<< 24)			//Vertical front porch
		|((1	-1)	<< 16) 			//Vertical Sync. pulse width
		|(80	-1 		 ),			//Lines-per-frame

		//VerticalTiming2
		(1 	-1		 ),				//Vertical back porch

		//Polarity
		(15		<<  8)			//Panel clock divisor = (DivNo + 1), max = 4MHZ, 0xe(27MHZ oscillator) = 113HZ
		|(LCD_FALSE	<<  3)			//The invert output enable
		|(LCD_FALSE	<<  2)			//Select the edge of the panel clock
		|(LCD_FALSE	<<  1)			//The invert horizontal sync bit
		|(LCD_FALSE		 ),			//The invert vertical sync bit

		//SerialPanelPixel
		(LCD_FALSE	<<  5)			//AUO052 mode
		|(LCD_FALSE	<<  4)			//Left shift rotate
		|(LCD_FALSE	<<  2)			//Color sequence of odd line
		|(LCD_FALSE	<<  1)			//Delta type arrangement color filter
		|(LCD_FALSE		 ),			//RGB serial output mode

		//CCIR656
		(LCD_FALSE	<<  2)			//TVE clock phase
		|(LCD_FALSE	<<  1)			//720 pixels per line
		|(LCD_FALSE		 ),			//NTSC/PAL select

		//CSTNPanelControl
		(LCD_TRUE	<< 27)			//CSTN function enable bit
		|(0			<< 25)			//Bus width of CSTN panel
		|(1			<< 24)			//CSTN panel type
		|((160/16)	<< 16) 			//Virtual window width in framebuffer
		|(160	-1		 ),			//Horizontal dot's resolution of CSTN panel

		//CSTNPanelParam1
		(1			<< 16)			//CSTN horizontal back porch
		|(LCD_FALSE	<<  7) 			//Type of the signal, "AC", inverts
		|(2*80	+1		 ),			//Line numbers that "AC" inverts once

		160,	80
	},
  
  	//TYPE12 : 320x240 TPG, ie. accept the serial signal *****************************
	{	// Valid, Descriptor
		LCD_TRUE, "TPG051 serial RGB",

		//LCDEnable
		(LCD_FALSE << 14)	//Test pattern generator, not implement now
		|(LCD_FALSE <<  1)	//LCD screen on/off control
		|(LCD_FALSE   ),		//LCD controller enable control

		//PanelPixel
		(LCD_FALSE << 15)	//LC_CLK domain reset
		|(LCD_FALSE << 14) 	//HCLK domain reset
		|(1   << 11)			//TFT panel color depth selection, 6-bit per channel
		|(1   <<  4)			//RGB or BGR format selection
		|(4   <<  0),			//BppFifo: 16bpp

		//HorizontalTiming
		((47 -1) << 24)    //Horizontal back porch
		|((20 -1) << 16)   //Horizontal front porch
		|((4 -1) <<  8)   //Horizontal Sync. pulse width
		|((320 >> 4)   -1),   //pixels-per-line = 16(PL+1)

		//VerticalTiming1
		(15  << 24)       //Vertical front porch
		|((1 -1) << 16)    //Vertical Sync. pulse width
		|(240 -1   ),       //Lines-per-frame

		//VerticalTiming2
		(14  -1   ),   //Vertical back porch

		//Polarity
		(0   <<  8)                   //Panel clock divisor = (DivNo + 1), DivNo >= 3 --> does not FIFO under run
		|(LCD_FALSE <<  3)   //The invert output enable
		|(LCD_FALSE <<  2)   //Select the edge of the panel clock
		|(LCD_TRUE <<  1)   //The invert horizontal sync bit
		|(LCD_TRUE   ),       //The invert vertical sync bit

		//SerialPanelPixel
		(LCD_FALSE <<  5)   //AUO052 mode
		|(LCD_FALSE <<  4)   //Left shift rotate
		|(1 <<  2)			//Color sequence of odd line; BRG
		|(LCD_TRUE <<  1)   //Delta type arrangement color filter
		|(LCD_TRUE   ),       //RGB serial output mode

		//CCIR656
		(LCD_FALSE <<  2)   //TVE clock phase
		|(LCD_FALSE <<  1)   //720 pixels per line
		|(LCD_FALSE   ),       //NTSC/PAL select

			//CSTNPanelControl
		 (LCD_FALSE	<< 27)			//CSTN function enable bit
		|(LCD_FALSE	<< 25)			//Bus width of CSTN panel
		|(LCD_FALSE	<< 24)			//CSTN panel type
		|(LCD_FALSE	<< 16) 			//Virtual window width in framebuffer
		|(LCD_FALSE		 ),			//Horizontal dot's resolution of CSTN panel

		//CSTNPanelParam1
		 (LCD_FALSE	<< 16)			//CSTN horizontal back porch
		|(LCD_FALSE	<<  7) 			//Type of the signal, "AC", inverts
		|(LCD_FALSE		 ),			//Line numbers that "AC" inverts once

		//Width, //Height
		320, 240
	},
	  
   // Null ***********************************************
   //  Valid,	Descriptor, Timing1, Timing2, Timing2, Control,	Width, Height 
    {LCD_FALSE,	"",			0,0,0,0,0,0,0,0,0,		 0,		  0,	   0, },    
};

#endif
