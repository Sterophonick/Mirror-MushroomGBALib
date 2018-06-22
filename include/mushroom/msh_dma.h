/*!
 *  @file   msh_dma.h
 *  @brief  DMA functions
 */

#ifndef MSH_DMA_H
#define MSH_DMA_H

/*---------------------------------------------------------------------------*
 *  DEFINES                                                                  *
 *---------------------------------------------------------------------------*/

/*!
 *  @defgroup  DMA  DMA Attribute
 *  <b>DMA Attribute defines:</b><br>
 *  @code
 */
#define DMA_DST_INC		0x0000
#define DMA_DST_DEC		0x0020
#define DMA_DST_UNMOD	0x0040
#define DMA_DST_INCRL	0x0060

#define DMA_SRC_INC		0x0000
#define DMA_SRC_DEC		0x0080
#define DMA_SRC_UNMOD	0x0100

#define DMA_REPEAT		0x0200

#define DMA_SIZE_16		0x0000
#define DMA_SIZE_32		0x0400

#define DMA_START_NOW	0x0000
#define DMA_START_VBL	0x1000
#define DMA_START_HBL	0x2000
#define DMA_START_FIFO	0x3000

#define DMA_IRQ			0x4000

#define DMA_ENABLE		0x8000
/*! @endcode @{ @} */

/*!
 *  @defgroup  CPY  dmemcpy() type
 *  <b>dmemcpy() type defines:</b><br>
 *  These are Mushroom specific, not GBA values.
 *  @code
 */
#define CPY_DMA0		0
#define CPY_DMA1		1
#define CPY_DMA2		2
#define CPY_DMA3		3
#define CPY_MEMCPY		4
/*! @endcode @{ @} */

#define _DMA_IRQ_POS	14
#define _DMA_IRQ_BITS	0x4000    // 0100 0000 0000 0000
#define _DMA_IRQ_MASK	0xBFFF    // 1011 1111 1111 1111

/*---------------------------------------------------------------------------*
 *  MACROS                                                                   *
 *---------------------------------------------------------------------------*/

#define SET_DMA_SRC(channel, src)      GET_DMA_SRC(channel) = (u32)(src);
#define SET_DMA_DST(channel, dst)      GET_DMA_DST(channel) = (u32)(dst);
#define SET_DMA_CNT_L(channel, cnt_l)  GET_DMA_CNT_L(channel) = (cnt_l);
#define SET_DMA_CNT_H(channel, cnt_h)  GET_DMA_CNT_H(channel) = (cnt_h);

#define GET_DMA_SRC(channel) \
	(*((vu32 *)0x040000B0 + ((channel) * 3)))

#define GET_DMA_DST(channel) \
	(*((vu32 *)0x040000B4 + ((channel) * 3)))

#define GET_DMA_CNT_L(channel) \
	(*((vu16 *)0x040000B8 + ((channel) * 6)))

#define GET_DMA_CNT_H(channel) \
	(*((vu16 *)0x040000BA + ((channel) * 6)))

#define DMA(channel, dst, src, length, attr) \
	{GET_DMA_DST(channel) = (u32)(dst); \
	GET_DMA_SRC(channel) = (u32)(src); \
	GET_DMA_CNT_L(channel) = (length); \
	GET_DMA_CNT_H(channel) = (attr);}

#define SET_DMA_IRQ(channel, irq) \
	{GET_DMA_CNT_H(channel) &= _DMA_IRQ_MASK; \
	GET_DMA_CNT_H(channel) |= (irq) << _DMA_IRQ_POS;}

#define GET_DMA_IRQ(channel) \
	((GET_DMA_CNT_H(channel) & _DMA_IRQ_BITS) >> _DMA_IRQ_POS)

#define DMACPY16(channel, dst, src, size) \
	DMA(channel, dst, src, size, DMA_SIZE_16 | DMA_ENABLE | DMA_START_NOW)

#define DMACPY32(channel, dst, src, size) \
	DMA(channel, dst, src, size, DMA_SIZE_32 | DMA_ENABLE | DMA_START_NOW)

#define DMEMCPY(channel, dst, src, size) \
	{if ((channel) <= 3) { \
		DMACPY16(channel, dst, src, (size) >> 1) \
	} else { \
		memcpy(dst, src, size); \
	}}

#define DMASET16(channel, dst, val, size) \
	{_dmaset16_value = (val); \
	DMA(channel, dst, &_dmaset16_value, size, DMA_SRC_UNMOD | DMA_SIZE_16 | DMA_ENABLE | DMA_START_NOW);}

#define DMASET32(channel, dst, val, size) \
	{_dmaset32_value = (val); \
	DMA(channel, dst, &_dmaset32_value, size, DMA_SRC_UNMOD | DMA_SIZE_32 | DMA_ENABLE | DMA_START_NOW);}

/*!
 *  @param  channel  <b>u8</b> [0..3] DMA Channel
 *  @param  dst      <b>void*</b> Destination Address
 *  @param  src      <b>void*</b> Source Address
 *  @param  length   <b>u16</b> Number of 16/32 bit values to copy
 *  @param  attr     <b>u16</b> [DMA] DMA Control Attributes
 *
 *  Add multiple DMA attributes using the bitwise OR operator.<br>
 *  <br>
 *  @copydoc DMA
 */
#define dma(channel, dst, src, length, attr)  DMA(channel, dst, src, length, attr)


/*!
 *  @param  channel  <b>u8</b> [0..3] DMA Channel
 *  @param  src      <b>void*</b> Source Address
 */
#define set_dma_src(channel, src)  SET_DMA_SRC(channel, src)


/*!
 *  @param  channel  <b>u8</b> [0..3] DMA Channel
 *  @param  dst      <b>void*</b> Destination Address
 */
#define set_dma_dst(channel, dst)  SET_DMA_DST(channel, dst)


/*!
 *  @param  channel  <b>u8</b> [0..3] DMA Channel
 *  @param  cnt_l    <b>u16</b> Number of 16/32 bit values to copy
 */
#define set_dma_cnt_l(channel, cnt_l)  SET_DMA_CNT_L(channel, cnt_l)


/*!
 *  @param  channel  <b>u8</b> [0..3] DMA Channel
 *  @param  cnt_h    <b>u16</b> [DMA] DMA Control Attributes
 *
 *  Add multiple DMA attributes using the bitwise OR operator.<br>
 *  <br>
 *  @copydoc DMA
 */
#define set_dma_cnt_h(channel, cnt_h)  SET_DMA_CNT_H(channel, cnt_h)


/*!
 *  @param  channel  <b>u8</b> [0..3] DMA Channel
 *  @param  irq      <b>bool</b> [TRUE or FALSE] Enable/Disable IRQ
 */
#define set_dma_irq(channel, irq)  SET_DMA_IRQ(channel, irq)


/*!
 *  @param   channel  <b>u8</b> [0..3] DMA Channel
 *  @return  <b>bool</b> [TRUE or FALSE] Enable/Disable IRQ
 */
#define get_dma_irq(channel)  GET_DMA_IRQ(channel)


/*!
 *  @param  channel  <b>u8</b> [CPY] Copy type
 *  @param  dst      <b>void*</b> Destination Address
 *  @param  src      <b>void*</b> Source Address
 *  @param  size     <b>u32</b> Number of bytes to copy
 *
 *  Copies data using a DMA channel or using memcpy() if the channel
 *  is set to CPY_MEMCPY. size must be a multiple of 2 if using DMA.<br>
 *  <br>
 *  @copydoc CPY
 */
#define dmemcpy(channel, dst, src, size)  DMEMCPY(channel, dst, src, size)

/*---------------------------------------------------------------------------*
 *  STRUCTURES                                                               *
 *---------------------------------------------------------------------------*/

/*!
 *  DMA Control Structure
 */
typedef struct {
	vu32 src;
	vu32 dst;
	vu16 cnt_l;
	vu16 cnt_h;
} _dma_t;

/*---------------------------------------------------------------------------*
 *  VARIABLES                                                                *
 *---------------------------------------------------------------------------*/

extern u16 _dmaset16_value;
extern u32 _dmaset32_value;

#endif

