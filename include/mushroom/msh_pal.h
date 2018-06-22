/*!
 *  @file   msh_pal.h
 *  @brief  Palette and color functions
 */

#ifndef MSH_PAL_H
#define MSH_PAL_H

/*---------------------------------------------------------------------------*
 *  MACROS                                                                   *
 *---------------------------------------------------------------------------*/

/*!
 *  @param   r  <b>u8</b> [0..31] Red
 *  @param   g  <b>u8</b> [0..31] Green
 *  @param   b  <b>u8</b> [0..31] Blue
 *  @return  <b>u16</b> 15 bit Color
 *
 *  Returns a 15 bit color
 */
#define RGB(r, g, b)  ((r) | ((g) << 5) | ((b) << 10))

/*!
 *  @param  color  <b>u16</b> 15 bit color
 *  @param  r      <b>u8</b> [0..31] Red
 *
 *  Sets the red content of color
 */
#define SET_COLOR_R(color, r) \
	{(color) &= 0xFFE0; \
	(color) |= (r);}

/*!
 *  @param  color  <b>u16</b> 15 bit color
 *  @param  g      <b>u8</b> [0..31] Green
 *
 *  Sets the green content of color
 */
#define SET_COLOR_G(color, g) \
	{(color) &= 0xFC1F; \
	(color) |= (g) << 5;}

/*!
 *  @param  color  <b>u16</b> 15 bit color
 *  @param  b      <b>u8</b> [0..31] Blue
 *
 *  Sets the blue content of color
 */
#define SET_COLOR_B(color, b) \
	{(color) &= 0x83FF; \
	(color) |= (b) << 10;}

/*!
 *  @param   color  <b>u16</b> 15 bit color
 *  @return  <b>u8</b> [0..31] Red
 *
 *  Returns the red content of color
 */
#define GET_COLOR_R(color)  ((color) & 0x001F)

/*!
 *  @param   color  <b>u16</b> 15 bit color
 *  @return  <b>u8</b> [0..31] Green
 *
 *  Returns the green content of color
 */
#define GET_COLOR_G(color)  (((color) & 0x03E0) >> 5)

/*!
 *  @param   color  <b>u16</b> 15 bit color
 *  @return  <b>u8</b> [0..31] Blue
 *
 *  Returns the blue content of color
 */
#define GET_COLOR_B(color)  (((color) & 0x7C00) >> 10)


#define SET_BGPAL_COLOR(index, color) \
	GET_BGPAL_COLOR(index) = (color);

#define SET_OBJPAL_COLOR(index, color) \
	GET_OBJPAL_COLOR(index) = (color);

#define GET_BGPAL_COLOR(index)  (*((vu16 *)MEM_PAL_BG + (index)))
#define GET_OBJPAL_COLOR(index)  (*((vu16 *)MEM_PAL_OBJ + (index)))

#define LOAD_BGPAL(data, index, length, channel) \
	dmemcpy(channel, (void *)(MEM_PAL_BG + ((index) << 1)), data, (length) << 1);

#define LOAD_OBJPAL(data, index, length, channel) \
	dmemcpy(channel, (void *)(MEM_PAL_OBJ + ((index) << 1)), data, (length) << 1);


/*!
 *  @param  index  <b>u8</b> [0..255] Bg Color
 *  @param  color  <b>u16</b> 15 bit Color
 */
#define set_bgpal_color(index, color)  SET_BGPAL_COLOR(index, color)


/*!
 *  @param  index  <b>u8</b> [0..255] Obj Color
 *  @param  color  <b>u16</b> 15 bit Color
 */
#define set_objpal_color(index, color)  SET_OBJPAL_COLOR(index, color)


/*!
 *  @param   index  <b>u8</b> [0..255] Bg Color
 *  @return  color  <b>u16</b> 15 bit Color
 */
#define get_bgpal_color(index)  GET_BGPAL_COLOR(index)


/*!
 *  @param   index  <b>u8</b> [0..255] Obj Color
 *  @return  color  <b>u16</b> 15 bit Color
 */
#define get_objpal_color(index)  GET_OBJPAL_COLOR(index)


/*!
 *  @param  data     <b>void*</b> Pointer to palette data
 *  @param  index    <b>u8</b> [0..255] Starting color index
 *  @param  length   <b>u16</b> [0..256] Number of colors to load
 *  @param  channel  <b>u8</b> [CPY] Copy type
 *
 *  @copydoc CPY
 */
#define load_bgpal(data, index, length, channel) \
	LOAD_BGPAL(data, index, length, channel)


/*!
 *  @param  data     <b>void*</b> Pointer to palette data
 *  @param  index    <b>u8</b> [0..255] Starting color index
 *  @param  length   <b>u16</b> [0..256] Number of colors to load
 *  @param  channel  <b>u8</b> [CPY] Copy type
 *
 *  @copydoc CPY
 */
#define load_objpal(data, index, length, channel) \
	LOAD_OBJPAL(data, index, length, channel)

#endif

