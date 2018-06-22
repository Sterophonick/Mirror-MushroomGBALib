/*!
 *  @file   msh_obj.h
 *  @brief  OBJ (sprite) functions
 */

#ifndef MSH_OBJ_H
#define MSH_OBJ_H

/*---------------------------------------------------------------------------*
 *  DEFINES                                                                  *
 *---------------------------------------------------------------------------*/

/*!
 *  @defgroup  OAM_BLDMOD  Obj Blend Mode
 *  <b>Obj Blend Mode defines:</b><br>
 *  @code
 */
#define OAM_BLDMOD_NORMAL		0
#define OAM_BLDMOD_SEMITRANS	1
#define OAM_BLDMOD_OBJWIN		2
/*! @endcode @{ @} */

/*!
 *  @defgroup  OAM_COLMOD  Obj Color Mode
 *  <b>Obj Color Mode defines:</b><br>
 *  @code
 */
#define OAM_COLMOD_16			0
#define OAM_COLMOD_256			1
/*! @endcode @{ @} */

/*!
 *  @defgroup  OAM_SHAPE  Obj Shape
 *  <b>Obj Shape defines:</b><br>
 *  @code
 */
#define OAM_SHAPE_SQUARE		0
#define OAM_SHAPE_WIDE			1
#define OAM_SHAPE_TALL			2
/*! @endcode @{ @} */

/*!
 *  @defgroup  OAM_SIZE  Obj Size
 *  <b>Obj Size defines:</b><br>
 *  @code
 */
#define OAM_SIZE_8x8			0
#define OAM_SIZE_16x16			1
#define OAM_SIZE_32x32			2
#define OAM_SIZE_64x64			3
#define OAM_SIZE_16x8			0
#define OAM_SIZE_32x8			1
#define OAM_SIZE_32x16			2
#define OAM_SIZE_64x32			3
#define OAM_SIZE_8x16			0
#define OAM_SIZE_8x32			1
#define OAM_SIZE_16x32			2
#define OAM_SIZE_32x64			3
/*! @endcode @{ @} */

/*---------------------------------------------------------------------------*
 *  OAM BITS                                                                 *
 *---------------------------------------------------------------------------*/

/*
 * POS   Starting bit for the value
 * BITS  The bits of the value set to 1
 * MASK  The inverse of BITS
 */

/* ATTRIBUTE 0 --------------------------------------------------------------*/

// 8 bits
#define _OAM_Y_POS			0
#define _OAM_Y_BITS			0x00FF    // 0000 0000 1111 1111
#define _OAM_Y_MASK			0xFF00    // 1111 1111 0000 0000

// 1 bit
#define _OAM_ROTSCALE_POS	8
#define _OAM_ROTSCALE_BITS	0x0100    // 0000 0001 0000 0000
#define _OAM_ROTSCALE_MASK	0xFEFF    // 1111 1110 1111 1111

// 1 bit
#define _OAM_DBLSIZE_POS		9
#define _OAM_DBLSIZE_BITS	0x0200    // 0000 0010 0000 0000
#define _OAM_DBLSIZE_MASK	0xFDFF    // 1111 1101 1111 1111

// 2 bits
#define _OAM_BLDMOD_POS		10
#define _OAM_BLDMOD_BITS	0x0C00    // 0000 1100 0000 0000
#define _OAM_BLDMOD_MASK	0xF3FF    // 1111 0011 1111 1111

// 1 bit
#define _OAM_MOSAIC_POS		12
#define _OAM_MOSAIC_BITS	0x1000    // 0001 0000 0000 0000
#define _OAM_MOSAIC_MASK	0xEFFF    // 1110 1111 1111 1111

// 1 bit
#define _OAM_COLMOD_POS		13
#define _OAM_COLMOD_BITS	0x2000    // 0010 0000 0000 0000
#define _OAM_COLMOD_MASK	0xDFFF    // 1101 1111 1111 1111

// 2 bits
#define _OAM_SHAPE_POS		14
#define _OAM_SHAPE_BITS		0xC000    // 1100 0000 0000 0000
#define _OAM_SHAPE_MASK		0x3FFF    // 0011 1111 1111 1111

/* ATTRIBUTE 1 --------------------------------------------------------------*/

// 9 bits
#define _OAM_X_POS			0
#define _OAM_X_BITS			0x01FF    // 0000 0001 1111 1111
#define _OAM_X_MASK			0xFE00    // 1111 1110 0000 0000

// 5 bits
#define _OAM_ROTINDEX_POS	9
#define _OAM_ROTINDEX_BITS	0x3E00    // 0011 1110 0000 0000
#define _OAM_ROTINDEX_MASK	0xC1FF    // 1100 0001 1111 1111

// 1 bit
#define _OAM_HFLIP_POS		12
#define _OAM_HFLIP_BITS		0x1000    // 0001 0000 0000 0000
#define _OAM_HFLIP_MASK		0xEFFF    // 1110 1111 1111 1111

// 1 bit
#define _OAM_VFLIP_POS		13
#define _OAM_VFLIP_BITS		0x2000    // 0010 0000 0000 0000
#define _OAM_VFLIP_MASK		0xDFFF    // 1101 1111 1111 1111

// 2 bits
#define _OAM_SIZE_POS		14
#define _OAM_SIZE_BITS		0xC000    // 1100 0000 0000 0000
#define _OAM_SIZE_MASK		0x3FFF    // 0011 1111 1111 1111

/* ATTRIBUTE 2 --------------------------------------------------------------*/

// 10 bits
#define _OAM_TILE_POS		0
#define _OAM_TILE_BITS		0x03FF    // 0000 0011 1111 1111
#define _OAM_TILE_MASK		0xFC00    // 1111 1100 0000 0000

// 2 bits
#define _OAM_PRIO_POS		10
#define _OAM_PRIO_BITS		0x0C00    // 0000 1100 0000 0000
#define _OAM_PRIO_MASK		0xF3FF    // 1111 0011 1111 1111

// 4 bits
#define _OAM_PAL_POS		12
#define _OAM_PAL_BITS		0xF000    // 1111 0000 0000 0000
#define _OAM_PAL_MASK		0x0FFF    // 0000 1111 1111 1111

/*---------------------------------------------------------------------------*
 *  MACROS                                                                   *
 *---------------------------------------------------------------------------*/

#define SET_ATTR_Y(a0, y) \
	{(a0) &= _OAM_Y_MASK; \
	(a0) |= (y);}

#define SET_ATTR_ROTSCALE(a0, rotscale) \
	{(a0) &= _OAM_ROTSCALE_MASK; \
	(a0) |= (rotscale) << _OAM_ROTSCALE_POS;}

#define SET_ATTR_DBLSIZE(a0, dblsize) \
	{(a0) &= _OAM_DBLSIZE_MASK; \
	(a0) |= (dblsize) << _OAM_DBLSIZE_POS;}

#define SET_ATTR_BLDMOD(a0, bldmod) \
	{(a0) &= _OAM_BLDMOD_MASK; \
	(a0) |= (bldmod) << _OAM_BLDMOD_POS;}

#define SET_ATTR_MOSAIC(a0, mosaic) \
	{(a0) &= _OAM_MOSAIC_MASK; \
	(a0) |= (mosaic) << _OAM_MOSAIC_POS;}

#define SET_ATTR_COLMOD(a0, colmod) \
	{(a0) &= _OAM_COLMOD_MASK; \
	(a0) |= (colmod) << _OAM_COLMOD_POS;}

#define SET_ATTR_SHAPE(a0, shape) \
	{(a0) &= _OAM_SHAPE_MASK; \
	(a0) |= (shape) << _OAM_SHAPE_POS;}

#define SET_ATTR_X(a1, x) \
	{(a1) &= _OAM_X_MASK; \
	(a1) |= (x);}

#define SET_ATTR_ROTINDEX(a1, rotindex) \
	{(a1) &= _OAM_ROTINDEX_MASK; \
	(a1) |= (rotindex) << _OAM_ROTINDEX_POS;}

#define SET_ATTR_HFLIP(a1, hflip) \
	{(a1) &= _OAM_HFLIP_MASK; \
	(a1) |= (hflip) << _OAM_HFLIP_POS;}

#define SET_ATTR_VFLIP(a1, vflip) \
	{(a1) &= _OAM_VFLIP_MASK; \
	(a1) |= (vflip) << _OAM_VFLIP_POS;}

#define SET_ATTR_SIZE(a1, size) \
	{(a1) &= _OAM_SIZE_MASK; \
	(a1) |= (size) << _OAM_SIZE_POS;}

#define SET_ATTR_TILE(a2, tile) \
	{(a2) &= _OAM_TILE_MASK; \
	(a2) |= (tile);}

#define SET_ATTR_PRIO(a2, prio) \
	{(a2) &= _OAM_PRIO_MASK; \
	(a2) |= (prio) << _OAM_PRIO_POS;}

#define SET_ATTR_PAL(a2, pal) \
	{(a2) &= _OAM_PAL_MASK; \
	(a2) |= (pal) << _OAM_PAL_POS;}

#define GET_ATTR_Y(a0)         ((a0) & _OAM_Y_BITS)
#define GET_ATTR_ROTSCALE(a0)  (((a0) & _OAM_ROTSCALE_BITS) >> _OAM_ROTSCALE_POS)
#define GET_ATTR_DBLSIZE(a0)   (((a0) & _OAM_DBLSIZE_BITS) >> _OAM_DBLSIZE_POS)
#define GET_ATTR_BLDMOD(a0)    (((a0) & _OAM_BLDMOD_BITS) >> _OAM_BLDMOD_POS)
#define GET_ATTR_MOSAIC(a0)    (((a0) & _OAM_MOSAIC_BITS) >> _OAM_MOSAIC_POS)
#define GET_ATTR_COLMOD(a0)    (((a0) & _OAM_COLMOD_BITS) >> _OAM_COLMOD_POS)
#define GET_ATTR_SHAPE(a0)     (((a0) & _OAM_SHAPE_BITS) >> _OAM_SHAPE_POS)
#define GET_ATTR_X(a1)         ((a1) & _OAM_X_BITS)
#define GET_ATTR_ROTINDEX(a1)  (((a1) & _OAM_ROTINDEX_BITS) >> _OAM_ROTINDEX_POS)
#define GET_ATTR_HFLIP(a1)     (((a1) & _OAM_HFLIP_BITS) >> _OAM_HFLIP_POS)
#define GET_ATTR_VFLIP(a1)     (((a1) & _OAM_VFLIP_BITS) >> _OAM_VFLIP_POS)
#define GET_ATTR_SIZE(a1)      (((a1) & _OAM_SIZE_BITS) >> _OAM_SIZE_POS)
#define GET_ATTR_TILE(a2)      ((a2) & _OAM_TILE_BITS)
#define GET_ATTR_PRIO(a2)      (((a2) & _OAM_PRIO_BITS) >> _OAM_PRIO_POS)
#define GET_ATTR_PAL(a2)       (((a2) & _OAM_PAL_BITS) >> _OAM_PAL_POS)


#define SET_OAM_A0(obj, a0)      GET_OAM_A0(obj) = (a0);
#define SET_OAM_A1(obj, a1)      GET_OAM_A1(obj) = (a1);
#define SET_OAM_A2(obj, a2)      GET_OAM_A2(obj) = (a2);

#define GET_OAM_A0(obj)          (*((vu16 *)MEM_OAM + ((obj) << 2)))
#define GET_OAM_A1(obj)          (*((vu16 *)MEM_OAM + ((obj) << 2) + 1))
#define GET_OAM_A2(obj)          (*((vu16 *)MEM_OAM + ((obj) << 2) + 2))

#define SET_ROTDATA_PA(rot, pa)  GET_ROTDATA_PA(rot) = (pa);
#define SET_ROTDATA_PB(rot, pb)  GET_ROTDATA_PB(rot) = (pb);
#define SET_ROTDATA_PC(rot, pc)  GET_ROTDATA_PC(rot) = (pc);
#define SET_ROTDATA_PD(rot, pd)  GET_ROTDATA_PD(rot) = (pd);

#define GET_ROTDATA_PA(rot)      (*((vu16 *)MEM_OAM + ((rot) << 4) + 3))
#define GET_ROTDATA_PB(rot)      (*((vu16 *)MEM_OAM + ((rot) << 4) + 7))
#define GET_ROTDATA_PC(rot)      (*((vu16 *)MEM_OAM + ((rot) << 4) + 11))
#define GET_ROTDATA_PD(rot)      (*((vu16 *)MEM_OAM + ((rot) << 4) + 15))

#define SET_OAM_Y(obj, y) \
	SET_ATTR_Y(GET_OAM_A0(obj), y)

#define SET_OAM_ROTSCALE(obj, rotscale) \
	SET_ATTR_ROTSCALE(GET_OAM_A0(obj), rotscale)

#define SET_OAM_DBLSIZE(obj, dblsize) \
	SET_ATTR_DBLSIZE(GET_OAM_A0(obj), dblsize)

#define SET_OAM_BLDMOD(obj, bldmod) \
	SET_ATTR_BLDMOD(GET_OAM_A0(obj), bldmod)

#define SET_OAM_MOSAIC(obj, mosaic) \
	SET_ATTR_MOSAIC(GET_OAM_A0(obj), mosaic)

#define SET_OAM_COLMOD(obj, colmod) \
	SET_ATTR_COLMOD(GET_OAM_A0(obj), colmod)

#define SET_OAM_SHAPE(obj, shape) \
	SET_ATTR_SHAPE(GET_OAM_A0(obj), shape)

#define SET_OAM_X(obj, x) \
	SET_ATTR_X(GET_OAM_A1(obj), x)

#define SET_OAM_ROTINDEX(obj, rotindex) \
	SET_ATTR_ROTINDEX(GET_OAM_A1(obj), rotindex)

#define SET_OAM_HFLIP(obj, hflip) \
	SET_ATTR_HFLIP(GET_OAM_A1(obj), hflip)

#define SET_OAM_VFLIP(obj, vflip) \
	SET_ATTR_VFLIP(GET_OAM_A1(obj), vflip)

#define SET_OAM_SIZE(obj, size) \
	SET_ATTR_SIZE(GET_OAM_A1(obj), size)

#define SET_OAM_TILE(obj, tile) \
	SET_ATTR_TILE(GET_OAM_A2(obj), tile)

#define SET_OAM_PRIO(obj, prio) \
	SET_ATTR_PRIO(GET_OAM_A2(obj), prio)

#define SET_OAM_PAL(obj, pal) \
	SET_ATTR_PAL(GET_OAM_A2(obj), pal)

#define GET_OAM_Y(obj)         GET_ATTR_Y(GET_OAM_A0(obj))
#define GET_OAM_ROTSCALE(obj)  GET_ATTR_ROTSCALE(GET_OAM_A0(obj))
#define GET_OAM_DBLSIZE(obj)   GET_ATTR_DBLSIZE(GET_OAM_A0(obj))
#define GET_OAM_BLDMOD(obj)    GET_ATTR_BLDMOD(GET_OAM_A0(obj))
#define GET_OAM_MOSAIC(obj)    GET_ATTR_MOSAIC(GET_OAM_A0(obj))
#define GET_OAM_COLMOD(obj)    GET_ATTR_COLMOD(GET_OAM_A0(obj))
#define GET_OAM_SHAPE(obj)     GET_ATTR_SHAPE(GET_OAM_A0(obj))
#define GET_OAM_X(obj)         GET_ATTR_X(GET_OAM_A1(obj))
#define GET_OAM_ROTINDEX(obj)  GET_ATTR_ROTINDEX(GET_OAM_A1(obj))
#define GET_OAM_HFLIP(obj)     GET_ATTR_HFLIP(GET_OAM_A1(obj))
#define GET_OAM_VFLIP(obj)     GET_ATTR_VFLIP(GET_OAM_A1(obj))
#define GET_OAM_SIZE(obj)      GET_ATTR_SIZE(GET_OAM_A1(obj))
#define GET_OAM_TILE(obj)      GET_ATTR_TILE(GET_OAM_A2(obj))
#define GET_OAM_PRIO(obj)      GET_ATTR_PRIO(GET_OAM_A2(obj))
#define GET_OAM_PAL(obj)       GET_ATTR_PAL(GET_OAM_A2(obj))

#define LOAD_OBJTILES(data, index, length, channel) \
	dmemcpy(channel, (void *)(MEM_OBJ + ((index) << 5)), data, (length) << 5);

/*!
 *  @param  obj  <b>u8</b> [0..127] Object Index
 *  @param  a0   <b>u16</b> Attribute 0
 */
#define set_oam_a0(obj, a0)  SET_OAM_A0(obj, a0)


/*!
 *  @param  obj  <b>u8</b> [0..127] Object Index
 *  @param  a1   <b>u16</b> Attribute 1
 */
#define set_oam_a1(obj, a1)  SET_OAM_A1(obj, a1)


/*!
 *  @param  obj  <b>u8</b> [0..127] Object Index
 *  @param  a2   <b>u16</b> Attribute 2
 */
#define set_oam_a2(obj, a2)  SET_OAM_A2(obj, a2)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>u16</b> Attribute 0
 */
#define get_oam_a0(obj)  GET_OAM_A0(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>u16</b> Attribute 1
 */
#define get_oam_a1(obj)  GET_OAM_A1(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>u16</b> Attribute 2
 */
#define get_oam_a2(obj)  GET_OAM_A2(obj)


/*!
 *  @param  rot  <b>u8</b> [0..31] Rotate Data Index
 *  @param  pa   <b>u16</b> PA
 */
#define set_rotdata_pa(rot, pa)  SET_ROTDATA_PA(rot, pa)


/*!
 *  @param  rot  <b>u8</b> [0..31] Rotate Data Index
 *  @param  pb   <b>u16</b> PB
 */
#define set_rotdata_pb(rot, pb)  SET_ROTDATA_PB(rot, pb)


/*!
 *  @param  rot  <b>u8</b> [0..31] Rotate Data Index
 *  @param  pc   <b>u16</b> PC
 */
#define set_rotdata_pc(rot, pc)  SET_ROTDATA_PC(rot, pc)


/*!
 *  @param  rot  <b>u8</b> [0..31] Rotate Data Index
 *  @param  pd   <b>u16</b> PD
 */
#define set_rotdata_pd(rot, pd)  SET_ROTDATA_PD(rot, pd)


/*!
 *  @param   rot  <b>u8</b> [0..31] Rotate Data Index
 *  @return  <b>u16</b> PA
 */
#define get_rotdata_pa(rot)  GET_ROTDATA_PA(rot)


/*!
 *  @param   rot  <b>u8</b> [0..31] Rotate Data Index
 *  @return  <b>u16</b> PB
 */
#define get_rotdata_pb(rot)  GET_ROTDATA_PB(rot)


/*!
 *  @param   rot  <b>u8</b> [0..31] Rotate Data Index
 *  @return  <b>u16</b> PC
 */
#define get_rotdata_pc(rot)  GET_ROTDATA_PC(rot)


/*!
 *  @param   rot  <b>u8</b> [0..31] Rotate Data Index
 *  @return  <b>u16</b> PD
 */
#define get_rotdata_pd(rot)  GET_ROTDATA_PD(rot)


/*!
 *  @param  obj  <b>u8</b> [0..127] Object Index
 *  @param  y    <b>u8</b> [0..255] Y Position
 */
#define set_oam_y(obj, y)  SET_OAM_Y(obj, y)


/*!
 *  @param  obj       <b>u8</b> [0..127] Object Index
 *  @param  rotscale  <b>bool</b> [TRUE or FALSE] Rotate/Scale
 */
#define set_oam_rotscale(obj, rotscale)  SET_OAM_ROTSCALE(obj, rotscale)


/*!
 *  @param  obj      <b>u8</b> [0..127] Object Index
 *  @param  dblsize  <b>bool</b> [TRUE or FALSE] Double Size
 */
#define set_oam_dblsize(obj, dblsize)  SET_OAM_DBLSIZE(obj, dblsize)


/*!
 *  @param  obj     <b>u8</b> [0..127] Object Index
 *  @param  bldmod  <b>u8</b> [OAM_BLDMOD] Blend Mode
 *
 *  @copydoc OAM_BLDMOD
 */
#define set_oam_bldmod(obj, bldmod)  SET_OAM_BLDMOD(obj, bldmod)


/*!
 *  @param  obj     <b>u8</b> [0..127] Object Index
 *  @param  mosaic  <b>bool</b> [TRUE or FALSE] Mosaic
 */
#define set_oam_mosaic(obj, mosaic)  SET_OAM_MOSAIC(obj, mosaic)


/*!
 *  @param  obj     <b>u8</b> [0..127] Object Index
 *  @param  colmod  <b>bool</b> [OAM_COLMOD] Color Mode
 *
 *  @copydoc OAM_COLMOD
 */
#define set_oam_colmod(obj, colmod)  SET_OAM_COLMOD(obj, colmod)


/*!
 *  @param  obj    <b>u8</b> [0..127] Object Index
 *  @param  shape  <b>u8</b> [OAM_SHAPE] Shape
 *
 *  @copydoc OAM_SHAPE
 */
#define set_oam_shape(obj, shape)  SET_OAM_SHAPE(obj, shape)


/*!
 *  @param  obj  <b>u8</b> [0..127] Object Index
 *  @param  x    <b>u16</b> [0..511] X Position
 */
#define set_oam_x(obj, x)  SET_OAM_X(obj, x)


/*!
 *  @param  obj       <b>u8</b> [0..127] Object Index
 *  @param  rotindex  <b>u8</b> [0..31] Rotate/Scale Data Index
 */
#define set_oam_rotindex(obj, rotindex)  SET_OAM_ROTINDEX(obj, rotindex)


/*!
 *  @param  obj    <b>u8</b> [0..127] Object Index
 *  @param  hflip  <b>bool</b> [TRUE or FALSE] Horizontal Flip
 */
#define set_oam_hflip(obj, hflip)  SET_OAM_HFLIP(obj, hflip)


/*!
 *  @param  obj    <b>u8</b> [0..127] Object Index
 *  @param  vflip  <b>bool</b> [TRUE or FALSE] Vertical Flip
 */
#define set_oam_vflip(obj, vflip)  SET_OAM_VFLIP(obj, vflip)


/*!
 *  @param  obj   <b>u8</b> [0..127] Object Index
 *  @param  size  <b>u8</b> [OAM_SIZE] Size
 *
 *  @copydoc OAM_SIZE
 */
#define set_oam_size(obj, size)  SET_OAM_SIZE(obj, size)


/*!
 *  @param  obj   <b>u8</b> [0..127] Object Index
 *  @param  tile  <b>u16</b> [0..1023] Tile Number
 */
#define set_oam_tile(obj, tile)  SET_OAM_TILE(obj, tile)


/*!
 *  @param  obj   <b>u8</b> [0..127] Object Index
 *  @param  prio  <b>u8</b> [0..3] Priority
 */
#define set_oam_prio(obj, prio)  SET_OAM_PRIO(obj, prio)


/*!
 *  @param  obj  <b>u8</b> [0..127] Object Index
 *  @param  pal  <b>u8</b> [0..15] Palette Number
 */
#define set_oam_pal(obj, pal)  SET_OAM_PAL(obj, pal)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>u8</b> [0..255] Y Position
 */
#define get_oam_y(obj)  GET_OAM_Y(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>bool</b> [TRUE or FALSE] Rotate/Scale
 */
#define get_oam_rotscale(obj)  GET_OAM_ROTSCALE(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>bool</b> [TRUE or FALSE] Double Size
 */
#define get_oam_dblsize(obj)  GET_OAM_DBLSIZE(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>u8</b> [OAM_BLDMOD] Blend Mode
 *
 *  @copydoc OAM_BLDMOD
 */
#define get_oam_bldmod(obj)  GET_OAM_BLDMOD(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>bool</b> [TRUE or FALSE] Mosaic
 */
#define get_oam_mosaic(obj)  GET_OAM_MOSAIC(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>bool</b> [OAM_COLMOD] Color Mode
 *
 *  @copydoc OAM_COLMOD
 */
#define get_oam_colmod(obj)  GET_OAM_COLMOD(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>u8</b> [OAM_SHAPE] Shape
 *
 *  @copydoc OAM_SHAPE
 */
#define get_oam_shape(obj)  GET_OAM_SHAPE(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>u16</b> [0..511] X Position
 */
#define get_oam_x(obj)  GET_OAM_X(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>u8</b> [0..31] Rotate/Scale Data Index
 */
#define get_oam_rotindex(obj)  GET_OAM_ROTINDEX(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>bool</b> [TRUE or FALSE] Horizontal Flip
 */
#define get_oam_hflip(obj)  GET_OAM_HFLIP(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>bool</b> [TRUE or FALSE] Vertical Flip
 */
#define get_oam_vflip(obj)  GET_OAM_VFLIP(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>u8</b> [OAM_SIZE] Size
 *
 *  @copydoc OAM_SIZE
 */
#define get_oam_size(obj)  GET_OAM_SIZE(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>u16</b> [0..1023] Tile Number
 */
#define get_oam_tile(obj)  GET_OAM_TILE(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>u8</b> [0..3] Priority
 */
#define get_oam_prio(obj)  GET_OAM_PRIO(obj)


/*!
 *  @param   obj  <b>u8</b> [0..127] Object Index
 *  @return  <b>u8</b> [0..15] Palette Number
 */
#define get_oam_pal(obj)  GET_OAM_PAL(obj)


/*!
 *  @param  data     <b>void*</b> Pointer to tile data
 *  @param  index    <b>u16</b> [0..1023] Starting tile location
 *  @param  length   <b>u16</b> [0..1023] Number of tiles to copy
 *  @param  channel  <b>u8</b> [CPY] Copy type
 *
 *  Tiles are 32 bytes each. For 256 color tiles (64 bytes), you
 *  need to enter double the number of tiles as the length. And 256
 *  color tiles must have an even starting index.<br>
 *  <br>
 *  @copydoc CPY
 */
#define load_objtiles(data, index, length, channel) \
	LOAD_OBJTILES(data, index, length, channel)

/*---------------------------------------------------------------------------*
 *  STRUCTURES                                                               *
 *---------------------------------------------------------------------------*/

/*!
 *  OAM Structure
 */
typedef struct {
	u16 a0;
	u16 a1;
	u16 a2;
	u16 a3;
} _oam_t;


/*!
 *  Rotate Data Structure
 */
typedef struct {
	u16 _filler0[3];
	u16 pa;
	u16 _filler1[3];
	u16 pb;
	u16 _filler2[3];
	u16 pc;
	u16 _filler3[3];
	u16 pd;
} _rotdata_t;

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

/*!
 *  @param   obj  [0..127] Object Index
 *  @return  [1..8] Width (in tiles)
 *
 *  Returns the width of the object.<br>
 *  This is determined by the object's specified shape and size.
 */
u8 get_oam_width_tl (u8 obj);


/*!
 *  @param   obj  [0..127] Object Index
 *  @return  [1..8] Height (in tiles)
 *
 *  Returns the height of the object.<br>
 *  This is determined by the object's specified shape and size.
 */
u8 get_oam_height_tl (u8 obj);


/*!
 *  @param   obj  [0..127] Object Index
 *  @return  [1..8] Width (in pixels)
 *
 *  Returns the width of the object in pixels.<br>
 *  This is determined by the object's specified shape and size.
 */
u8 get_oam_width_px (u8 obj);


/*!
 *  @param   obj  [0..127] Object Index
 *  @return  [1..8] Height (in tiles)
 *
 *  Returns the height of the object in pixels.<br>
 *  This is determined by the object's specified shape and size.
 */
u8 get_oam_height_px (u8 obj);


/*!
 *  @param  obj  [0..127] Object Index
 *  @return  [1..128] Tile Volume
 *
 *  Returns the number of VRAM tiles the object uses.<br>
 *  This is determined by the object's shape, size, and color mode.<br>
 *  Eg. An object that is 32x32 and uses 256 colors...<br>
 *  4 tiles * 4 tiles * 2 (256 color tiles take up 2 tile slots) = 32 tiles
 */
u8 get_oam_tilevol (u8 obj);


/*!
 *  @param  start   [0..127] Start object index
 *  @param  length  [0..128] Number of objects
 *
 *  This hides the specified number of objects by moving them
 *  offscreen to (240, 160). This should be called before using
 *  any objects to prevent unwanted objects from being displayed.
 */
void hide_objs (u8 start, u8 length);


/*!
 *  @param  start   [0..127] Start object index
 *  @param  length  [0..128] Number of objects
 *
 *  This dumps the current data for each object to the console in
 *  an easily readable format.<br>
 *  <br>
 *  The output format is:<br>
 *  <pre>OOO: SSSSS  CCC  (XXX,YYY)  tile:TTTT  pal:PP  rot:AA  pr:I  RDMHVB</pre>
 *  - O: Object Index
 *  - S: Size
 *  - C: Color Mode
 *  - X: X Position
 *  - Y: Y Position
 *  - T: Tile
 *  - P: Palette
 *  - A: Rotate/Scale Index
 *  - I: Priority
 *  - R: Rotate/Scale - r = enabled
 *  - D: Double Size - d = enabled
 *  - M: Mosaic - m = enabled
 *  - H: Horizontal Flip - h = enabled (N/A if rotate/scale is enabled)
 *  - V: Vertical Flip - v = enabled (N/A if rotate/scale is enabled)
 *  - B: Blend Mode - n = Normal, s = Semi-trans, o = Obj win
 *  .
 *  <br>
 *  Eg. <pre>004: 64x64  16   (100, 80)  tile:41    pal:8   rot:0   pr:0  rd---n</pre>
 *  Object at index 4 is a 64x64 16 color object, at screen position (100, 80),
 *  using tiles starting from tile index 41, using palette 8, rotate/scale
 *  index 0, prioity 0, rotate/scale enabled, double size enabled, and normal
 *  blend mode.
 */
void oam_dump (u8 start, u8 length);

#endif

