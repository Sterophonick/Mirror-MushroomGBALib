
#ifndef MSH_GBA_H
#define MSH_GBA_H

/*---------------------------------------------------------------------------*
 *  MISC                                                                     *
 *---------------------------------------------------------------------------*/

// Screen size in pixels
#define SCR_WIDTH	240
#define SCR_HEIGHT	160

/*---------------------------------------------------------------------------*
 *  MEMORY LOCATIONS                                                         *
 *---------------------------------------------------------------------------*/

#define MEM_SYSROM   0x00000000  // System ROM              (  16 kb | 32 bit)
#define MEM_EWRAM    0x02000000  // External Work RAM       ( 256 kb | 16 bit)
#define MEM_IWRAM    0x03000000  // Internal Work RAM       (  32 kb | 32 bit)
#define MEM_IO       0x04000000  // Register Base           (   1 kb | 32 bit)
#define MEM_PAL      0x05000000  // Palette Base            (   1 kb | 16 bit)
#define MEM_PAL_BG   0x05000000  // Palette for BG          ( 512 b  | 16 bit)
#define MEM_PAL_OBJ  0x05000200  // Palette for OBJ         ( 512 b  | 16 bit)
#define MEM_VRAM     0x06000000  // Video RAM Base          (  96 kb | 16 bit)
#define MEM_BG       0x06000000  // Video RAM for BG        (  64 kb | 16 bit)
#define MEM_OBJ      0x06010000  // Video RAM for OBJ       (  32 kb | 16 bit)
#define MEM_OAM      0x07000000  // Object Attribute Memory (   1 kb | 32 bit)
#define MEM_ROM0     0x08000000  // ROM Image 0             (0-32 mb | 16 bit)
#define MEM_ROM1     0x0A000000  // ROM Image 1             (0-32 mb | 16 bit)
#define MEM_ROM2     0x0C000000  // ROM Image 2             (0-32 mb | 16 bit)
#define MEM_SRAM     0x0E000000  // Save RAM                (0-64 kb |  8 bit)

/*---------------------------------------------------------------------------*
 *  REGISTERS                                                                *
 *---------------------------------------------------------------------------*/

/* DISPLAY ------------------------------------------------------------------*/

#define REG_DISPCNT			*(vu16 *)0x04000000    // rw  (bit 3 read only)
#define REG_DISPSTAT		*(vu16 *)0x04000004    // rw  (bits 0-2 read only)
#define REG_VCOUNT			*(vu16 *)0x04000006    // r-  Vertical Counter (0-227)

/* BACKGROUND ---------------------------------------------------------------*/

// Control
#define REG_BG0CNT			*(vu16 *)0x04000008    // rw
#define REG_BG1CNT			*(vu16 *)0x0400000A    // rw
#define REG_BG2CNT			*(vu16 *)0x0400000C    // rw
#define REG_BG3CNT			*(vu16 *)0x0400000E    // rw

// Scroll
#define REG_BG0HOFS			*(vu16 *)0x04000010    // -w
#define REG_BG0VOFS			*(vu16 *)0x04000012    // -w
#define REG_BG1HOFS			*(vu16 *)0x04000014    // -w
#define REG_BG1VOFS			*(vu16 *)0x04000016    // -w
#define REG_BG2HOFS			*(vu16 *)0x04000018    // -w
#define REG_BG2VOFS			*(vu16 *)0x0400001A    // -w
#define REG_BG3HOFS			*(vu16 *)0x0400001C    // -w
#define REG_BG3VOFS			*(vu16 *)0x0400001E    // -w

// Rotate
#define REG_BG2PA			*(vu16 *)0x04000020    // -w
#define REG_BG2PB			*(vu16 *)0x04000022    // -w
#define REG_BG2PC			*(vu16 *)0x04000024    // -w
#define REG_BG2PD			*(vu16 *)0x04000026    // -w
#define REG_BG2X			*(vu32 *)0x04000028    // -w
#define REG_BG2Y			*(vu32 *)0x0400002C    // -w

#define REG_BG3PA			*(vu16 *)0x04000030    // -w
#define REG_BG3PB			*(vu16 *)0x04000032    // -w
#define REG_BG3PC			*(vu16 *)0x04000034    // -w
#define REG_BG3PD			*(vu16 *)0x04000036    // -w
#define REG_BG3X			*(vu32 *)0x04000038    // -w
#define REG_BG3Y			*(vu32 *)0x0400003C    // -w

/* WINDOWS ------------------------------------------------------------------*/

#define REG_WIN0H			*(vu16 *)0x04000040
#define REG_WIN1H			*(vu16 *)0x04000042
#define REG_WIN0V			*(vu16 *)0x04000044
#define REG_WIN1V			*(vu16 *)0x04000046

#define REG_WININ			*(vu16 *)0x04000048
#define REG_WINOUT			*(vu16 *)0x0400004A

/* EFFECTS ------------------------------------------------------------------*/

#define REG_MOSAIC			*(vu16 *)0x0400004C
#define REG_BLDMOD			*(vu16 *)0x04000050
#define REG_COLEV			*(vu16 *)0x04000052
#define REG_COLEY			*(vu16 *)0x04000054

/* SOUND --------------------------------------------------------------------*/

#define REG_SOUND1CNT_L		*(vu16 *)0x04000060
#define REG_SOUND1CNT_H		*(vu16 *)0x04000062
#define REG_SOUND1CNT_X		*(vu16 *)0x04000064
#define REG_SOUND2CNT_L		*(vu16 *)0x04000068
#define REG_SOUND2CNT_H		*(vu16 *)0x0400006C
#define REG_SOUND3CNT_L		*(vu16 *)0x04000070
#define REG_SOUND3CNT_H		*(vu16 *)0x04000072
#define REG_SOUND3CNT_X		*(vu16 *)0x04000074
#define REG_SOUND4CNT_L		*(vu16 *)0x04000078
#define REG_SOUND4CNT_H		*(vu16 *)0x0400007C
#define REG_SOUNDCNT_L		*(vu16 *)0x04000080
#define REG_SOUNDCNT_H		*(vu16 *)0x04000082
#define REG_SOUNDCNT_X		*(vu16 *)0x04000084
#define REG_SOUNDBIAS		*(vu16 *)0x04000088

#define REG_WAVE_RAM0		*(vu32 *)0x04000090
#define REG_WAVE_RAM0_L		*(vu16 *)0x04000090
#define REG_WAVE_RAM0_H		*(vu16 *)0x04000092
#define REG_WAVE_RAM1		*(vu32 *)0x04000094
#define REG_WAVE_RAM1_L		*(vu16 *)0x04000094
#define REG_WAVE_RAM1_H		*(vu16 *)0x04000096
#define REG_WAVE_RAM2		*(vu32 *)0x04000098
#define REG_WAVE_RAM2_L		*(vu16 *)0x04000098
#define REG_WAVE_RAM2_H		*(vu16 *)0x0400009A
#define REG_WAVE_RAM3		*(vu32 *)0x0400009C
#define REG_WAVE_RAM3_L		*(vu16 *)0x0400009C
#define REG_WAVE_RAM3_H		*(vu16 *)0x0400009E

#define REG_FIFO_A_L		*(vu16 *)0x040000A0
#define REG_FIFO_A_H		*(vu16 *)0x040000A2
#define REG_FIFO_B_L		*(vu16 *)0x040000A4
#define REG_FIFO_B_H		*(vu16 *)0x040000A6

/* DMA ----------------------------------------------------------------------*/

// DMA source address
#define REG_DMA0SAD			*(vu32 *)0x040000B0
#define REG_DMA1SAD			*(vu32 *)0x040000BC
#define REG_DMA2SAD			*(vu32 *)0x040000C8
#define REG_DMA3SAD			*(vu32 *)0x040000D4

// DMA destination address
#define REG_DMA0DAD			*(vu32 *)0x040000B4
#define REG_DMA1DAD			*(vu32 *)0x040000C0
#define REG_DMA2DAD			*(vu32 *)0x040000CC
#define REG_DMA3DAD			*(vu32 *)0x040000D8

// DMA count (num of 32bit or 16bit values to copy)
#define REG_DMA0CNT_L		*(vu16 *)0x040000B8
#define REG_DMA1CNT_L		*(vu16 *)0x040000C4
#define REG_DMA2CNT_L		*(vu16 *)0x040000D0
#define REG_DMA3CNT_L		*(vu16 *)0x040000DC

// DMA control
#define REG_DMA0CNT_H		*(vu16 *)0x040000BA
#define REG_DMA1CNT_H		*(vu16 *)0x040000C6
#define REG_DMA2CNT_H		*(vu16 *)0x040000D2
#define REG_DMA3CNT_H		*(vu16 *)0x040000DE

/* TIMER --------------------------------------------------------------------*/

// timer data
#define REG_TM0D			*(vu16 *)0x04000100
#define REG_TM1D			*(vu16 *)0x04000104
#define REG_TM2D			*(vu16 *)0x04000108
#define REG_TM3D			*(vu16 *)0x0400010C

// timer control
#define REG_TM0CNT			*(vu16 *)0x04000102
#define REG_TM1CNT			*(vu16 *)0x04000106
#define REG_TM2CNT			*(vu16 *)0x0400010A
#define REG_TM3CNT			*(vu16 *)0x0400010E

/* SERIAL COMMUNICATION -----------------------------------------------------*/

#define REG_SCD0			*(vu16 *)0x04000120
#define REG_SCD1			*(vu16 *)0x04000122
#define REG_SCD2			*(vu16 *)0x04000124
#define REG_SCD3			*(vu16 *)0x04000126

#define REG_SCCNT_L			*(vu16 *)0x04000128
#define REG_SCCNT_H			*(vu16 *)0x0400012A

/* KEYPAD -------------------------------------------------------------------*/

#define REG_KEY				*(vu16 *)0x04000130
#define REG_KEYCNT			*(vu16 *)0x04000132

/* INTERRUPT ----------------------------------------------------------------*/

#define REG_IE				*(vu16 *)0x04000200    // Interrupt Enable Register
#define REG_IF				*(vu16 *)0x04000202    // Interrupt Flags Regster
#define REG_WSCNT			*(vu16 *)0x04000204    // Wait State Control
#define REG_IME				*(vu16 *)0x04000208    // Interrupt Master Enable
#define REG_IFUNC			*(vu32 *)0x03007FFC    // Address of Interrupt Handler

#endif

