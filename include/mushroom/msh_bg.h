/*!
 *  @file   msh_bg.h
 *  @brief  Tile background functions
 */

#ifndef MSH_BG_H
#define MSH_BG_H

/*---------------------------------------------------------------------------*
 *  DEFINES                                                                  *
 *---------------------------------------------------------------------------*/

/*!
 *  @defgroup  BG_COLMOD  BG Color Mode
 *  <b>BG Color Mode defines:</b><br>
 *  @code
 */
#define BG_COLMOD_16			0
#define BG_COLMOD_256			1
/*! @endcode @{ @} */

/*!
 *  @defgroup  BG_SIZE  BG Map Size
 *  <b>BG Map Size defines:</b><br>
 *  @code
 */
#define BG_SIZE_256x256			0
#define BG_SIZE_512x256			1
#define BG_SIZE_256x512			2
#define BG_SIZE_512x512			3
/*! @endcode @{ @} */

/*!
 *  @defgroup  BG_ROTSIZE  BG Rotate Map Size
 *  <b>BG Rotate Map Size defines:</b><br>
 *  @code
 */
#define BG_ROTSIZE_128x128		0
#define BG_ROTSIZE_256x256		1
#define BG_ROTSIZE_512x512		2
#define BG_ROTSIZE_1024x1024	3
/*! @endcode @{ @} */

/*!
 *  @defgroup  BG_MAPTYPE  BG Map Type
 *  <b>BG Map Type defines:</b><br>
 *  These are Mushroom specific, not GBA values.
 *  @code
 */
#define BG_MAPTYPE_NORMAL		0
#define BG_MAPTYPE_ROTSCALE		1
/*! @endcode @{ @} */

/*---------------------------------------------------------------------------*
 *  BGCNT BITS                                                               *
 *---------------------------------------------------------------------------*/

// 2 bits
#define _BG_PRIO_POS		0
#define _BG_PRIO_BITS		0x0003    // 0000 0000 0000 0011
#define _BG_PRIO_MASK		0xFFFC    // 1111 1111 1111 1100

// 2 bits
#define _BG_TILEBASE_POS	2
#define _BG_TILEBASE_BITS	0x000C    // 0000 0000 0000 1100
#define _BG_TILEBASE_MASK	0xFFF3    // 1111 1111 1111 0011

// 1 bit
#define _BG_MOSAIC_POS		6
#define _BG_MOSAIC_BITS		0x0040    // 0000 0000 0100 0000
#define _BG_MOSAIC_MASK		0xFFBF    // 1111 1111 1011 1111

// 1 bit
#define _BG_COLMOD_POS		7
#define _BG_COLMOD_BITS		0x0080    // 0000 0000 1000 0000
#define _BG_COLMOD_MASK		0xFF7F    // 1111 1111 0111 1111

// 5 bits
#define _BG_MAPBASE_POS		8
#define _BG_MAPBASE_BITS	0x1F00    // 0001 1111 0000 0000
#define _BG_MAPBASE_MASK	0xE0FF    // 1110 0000 1111 1111

// 1 bit
#define _BG_OVERFLOW_POS	13
#define _BG_OVERFLOW_BITS	0x2000    // 0010 0000 0000 0000
#define _BG_OVERFLOW_MASK	0xDFFF    // 1101 1111 1111 1111

// 2 bits
#define _BG_SIZE_POS		14
#define _BG_SIZE_BITS		0xC000    // 1100 0000 0000 0000
#define _BG_SIZE_MASK		0x3FFF    // 0011 1111 1111 1111

/*---------------------------------------------------------------------------*
 *  MACROS                                                                   *
 *---------------------------------------------------------------------------*/

#define BG_MAPBASE(mb)  (MEM_BG + (0x800 * (mb)))
#define BG_TILEBASE(tb)  (MEM_BG + (0x4000 * (tb)))

#define BG_TILE(tile, pal, v, h)  (((pal) << 12) | ((v) << 11) | ((h) << 10) | (tile))

#define SET_ATTR_BG_PRIO(bgcnt, prio) \
	{(bgcnt) &= _BG_PRIO_MASK; \
	(bgcnt) |= (prio);}

#define SET_ATTR_BG_TILEBASE(bgcnt, tilebase) \
	{(bgcnt) &= _BG_TILEBASE_MASK; \
	(bgcnt) |= (tilebase) << _BG_TILEBASE_POS;}

#define SET_ATTR_BG_MOSAIC(bgcnt, mosaic) \
	{(bgcnt) &= _BG_MOSAIC_MASK; \
	(bgcnt) |= (mosaic) << _BG_MOSAIC_POS;}

#define SET_ATTR_BG_COLMOD(bgcnt, colmod) \
	{(bgcnt) &= _BG_COLMOD_MASK; \
	(bgcnt) |= (colmod) << _BG_COLMOD_POS;}

#define SET_ATTR_BG_MAPBASE(bgcnt, mapbase) \
	{(bgcnt) &= _BG_MAPBASE_MASK; \
	(bgcnt) |= (mapbase) << _BG_MAPBASE_POS;}

#define SET_ATTR_BG_OVERFLOW(bgcnt, overflow) \
	{(bgcnt) &= _BG_OVERFLOW_MASK; \
	(bgcnt) |= (overflow) << _BG_OVERFLOW_POS;}

#define SET_ATTR_BG_SIZE(bgcnt, size) \
	{(bgcnt) &= _BG_SIZE_MASK; \
	(bgcnt) |= (size) << _BG_SIZE_POS;}

#define GET_ATTR_BG_PRIO(bgcnt)      ((bgcnt) & _BG_PRIO_BITS)
#define GET_ATTR_BG_TILEBASE(bgcnt)  (((bgcnt) & _BG_TILEBASE_BITS) >> _BG_TILEBASE_POS)
#define GET_ATTR_BG_MOSAIC(bgcnt)    (((bgcnt) & _BG_MOSAIC_BITS) >> _BG_MOSAIC_POS)
#define GET_ATTR_BG_COLMOD(bgcnt)    (((bgcnt) & _BG_COLMOD_BITS) >> _BG_COLMOD_POS)
#define GET_ATTR_BG_MAPBASE(bgcnt)   (((bgcnt) & _BG_MAPBASE_BITS) >> _BG_MAPBASE_POS)
#define GET_ATTR_BG_OVERFLOW(bgcnt)  (((bgcnt) & _BG_OVERFLOW_BITS) >> _BG_OVERFLOW_POS)
#define GET_ATTR_BG_SIZE(bgcnt)      (((bgcnt) & _BG_SIZE_BITS) >> _BG_SIZE_POS)

#define GET_BGCNT(bg)  (*((vu16 *)0x04000008 + (bg)))

#define SET_BG_PRIO(bg, prio)          SET_ATTR_BG_PRIO(GET_BGCNT(bg), prio)
#define SET_BG_TILEBASE(bg, tilebase)  SET_ATTR_BG_TILEBASE(GET_BGCNT(bg), tilebase)
#define SET_BG_MOSAIC(bg, mosaic)      SET_ATTR_BG_MOSAIC(GET_BGCNT(bg), mosaic)
#define SET_BG_COLMOD(bg, colmod)      SET_ATTR_BG_COLMOD(GET_BGCNT(bg), colmod)
#define SET_BG_MAPBASE(bg, mapbase)    SET_ATTR_BG_MAPBASE(GET_BGCNT(bg), mapbase)
#define SET_BG_OVERFLOW(bg, overflow)  SET_ATTR_BG_OVERFLOW(GET_BGCNT(bg), overflow)
#define SET_BG_SIZE(bg, size)          SET_ATTR_BG_SIZE(GET_BGCNT(bg), size)

#define GET_BG_PRIO(bg)      GET_ATTR_BG_PRIO(GET_BGCNT(bg))
#define GET_BG_TILEBASE(bg)  GET_ATTR_BG_TILEBASE(GET_BGCNT(bg))
#define GET_BG_MOSAIC(bg)    GET_ATTR_BG_MOSAIC(GET_BGCNT(bg))
#define GET_BG_COLMOD(bg)    GET_ATTR_BG_COLMOD(GET_BGCNT(bg))
#define GET_BG_MAPBASE(bg)   GET_ATTR_BG_MAPBASE(GET_BGCNT(bg))
#define GET_BG_OVERFLOW(bg)  GET_ATTR_BG_OVERFLOW(GET_BGCNT(bg))
#define GET_BG_SIZE(bg)      GET_ATTR_BG_SIZE(GET_BGCNT(bg))

#define SET_BG_ROTDATA_PA(bg, pa)  GET_BG_ROTDATA_PA(bg) = (pa);
#define SET_BG_ROTDATA_PB(bg, pb)  GET_BG_ROTDATA_PB(bg) = (pb);
#define SET_BG_ROTDATA_PC(bg, pc)  GET_BG_ROTDATA_PC(bg) = (pc);
#define SET_BG_ROTDATA_PD(bg, pd)  GET_BG_ROTDATA_PD(bg) = (pd);
#define SET_BG_ROTDATA_X(bg, x)    GET_BG_ROTDATA_X(bg) = (x);
#define SET_BG_ROTDATA_Y(bg, y)    GET_BG_ROTDATA_Y(bg) = (y);

#define GET_BG_ROTDATA_PA(bg)  (*((vu16 *)0x04000020 + (((bg) - 2) << 4)))
#define GET_BG_ROTDATA_PB(bg)  (*((vu16 *)0x04000022 + (((bg) - 2) << 4)))
#define GET_BG_ROTDATA_PC(bg)  (*((vu16 *)0x04000024 + (((bg) - 2) << 4)))
#define GET_BG_ROTDATA_PD(bg)  (*((vu16 *)0x04000026 + (((bg) - 2) << 4)))
#define GET_BG_ROTDATA_X(bg)   (*((vu32 *)0x04000028 + (((bg) - 2) << 2)))
#define GET_BG_ROTDATA_Y(bg)   (*((vu32 *)0x0400002C + (((bg) - 2) << 2)))

#define SET_BG_HOFS(bg, hofs)  GET_BG_HOFS(bg) = (hofs) & 0x01FF;
#define SET_BG_VOFS(bg, vofs)  GET_BG_VOFS(bg) = (vofs) & 0x01FF;

#define GET_BG_HOFS(bg) \
	(*((vu16 *)0x04000010 + ((bg) << 1)))

#define GET_BG_VOFS(bg) \
	(*((vu16 *)0x04000012 + ((bg) << 1)))

#define SET_BG_HOFS_BUF(bg, hscroll) \
	{_bgofs_buf[bg].hofs = (hscroll) & 0x01FF; \
	SET_BG_HOFS(bg, hscroll);}

#define SET_BG_VOFS_BUF(bg, vscroll) \
	{_bgofs_buf[bg].vofs = (vscroll) & 0x01FF; \
	SET_BG_VOFS(bg, vscroll);}

#define GET_BG_HOFS_BUF(bg)  (_bgofs_buf[bg].hofs)
#define GET_BG_VOFS_BUF(bg)  (_bgofs_buf[bg].vofs)

#define LOAD_BGTILES(data, index, length, channel) \
	dmemcpy(channel, (void *)(MEM_BG + ((index) << 5)), data, length << 5);

#define SET_MAP_TILE(mapdata, mapwidth, x, y, tile) \
	*((vu16 *)(mapdata) + ((y) * (mapwidth)) + (x)) = (tile);

#define GET_MAP_TILE(mapdata, mapwidth, x, y) \
	(*((vu16 *)(mapdata) + ((y) * (mapwidth)) + (x)))

#define SET_ROTMAP_TILE(mapdata, mapwidth, x, y, tile) \
	*((vu8 *)(mapdata) + ((y) * (mapwidth)) + (x)) = (tile);

#define GET_ROTMAP_TILE(mapdata, mapwidth, x, y) \
	(*((vu8 *)(mapdata) + ((y) * (mapwidth)) + (x)))

#define SET_BG(bg, size, colmod, tilebase, mapbase) \
	{SET_BG_SIZE(bg, size); \
	SET_BG_COLMOD(bg, colmod); \
	SET_BG_TILEBASE(bg, tilebase); \
	SET_BG_MAPBASE(bg, mapbase);}


/*!
 *  @param  bg    <b>u8</b> [0..3] Background
 *  @param  prio  <b>u8</b> [0..3] Priority
 *
 *  Priority 0 puts the background in front, priority 3 puts it to the
 *  back. If a sprite has the same priority as a background, it will be
 *  displayed on top of the background.
 */
#define set_bg_prio(bg, prio)  SET_BG_PRIO(bg, prio)


/*!
 *  @param  bg        <b>u8</b> [0..3] Background
 *  @param  tilebase  <b>u8</b> [0..3] Tilebase
 *
 *  Sets the starting location of tiledata for the background.
 */
#define set_bg_tilebase(bg, tilebase)  SET_BG_TILEBASE(bg, tilebase)


/*!
 *  @param  bg      <b>u8</b> [0..3] Background
 *  @param  mosaic  <b>bool</b> [TRUE or FALSE] Enable/Disable Mosaic
 */
#define set_bg_mosaic(bg, mosaic)  SET_BG_MOSAIC(bg, mosaic)


/*!
 *  @param  bg      <b>u8</b> [0..3] Background
 *  @param  colmod  <b>bool</b> [BG_COLMOD] Color Mode
 *
 *  @copydoc BG_COLMOD
 */
#define set_bg_colmod(bg, colmod)  SET_BG_COLMOD(bg, colmod)


/*!
 *  @param  bg       <b>u8</b> [0..3] Background
 *  @param  mapbase  <b>u8</b> [0..31] Mapbase
 *
 *  Sets the starting location of mapdata for the background.
 */
#define set_bg_mapbase(bg, mapbase)  SET_BG_MAPBASE(bg, mapbase)


/*!
 *  @param  bg        <b>u8</b> [0..3] Background
 *  @param  overflow  <b>bool</b> [TRUE or FALSE] Enable/Disable Overflow
 */
#define set_bg_overflow(bg, overflow)  SET_BG_OVERFLOW(bg, overflow)


/*!
 *  @param  bg    <b>u8</b> [0..3] Background
 *  @param  size  <b>u8</b> [BG_SIZE or BG_ROTSIZE] Background Size
 *
 *  @copydoc BG_SIZE
 *  <br>
 *  @copydoc BG_ROTSIZE
 */
#define set_bg_size(bg, size)  SET_BG_SIZE(bg, size)

/*!
 *  @param   bg  <b>u8</b> [0..3] Background
 *  @return  <b>u8</b> [0..3] Priority
 *
 *  Priority 0 puts the background in front, priority 3 puts it to the
 *  back. If a sprite has the same priority as a background, it will be
 *  displayed on top of the background.
 */
#define get_bg_prio(bg)  GET_BG_PRIO(bg)


/*!
 *  @param   bg  <b>u8</b> [0..3] Background
 *  @return  <b>u8</b> [0..3] Tilebase
 *
 *  Sets the starting location of tiledata for the background.
 */
#define get_bg_tilebase(bg)  GET_BG_TILEBASE(bg)


/*!
 *  @param   bg  <b>u8</b> [0..3] Background
 *  @return  <b>bool</b> [TRUE or FALSE] Enable/Disable Mosaic
 */
#define get_bg_mosaic(bg)  GET_BG_MOSAIC(bg)


/*!
 *  @param   bg  <b>u8</b> [0..3] Background
 *  @return  <b>bool</b> [BG_COLMOD] Color Mode
 *
 *  @copydoc BG_COLMOD
 */
#define get_bg_colmod(bg)  GET_BG_COLMOD(bg)


/*!
 *  @param   bg  <b>u8</b> [0..3] Background
 *  @return  <b>u8</b> [0..31] Mapbase
 *
 *  Sets the starting location of mapdata for the background.
 */
#define get_bg_mapbase(bg)  GET_BG_MAPBASE(bg)


/*!
 *  @param   bg  <b>u8</b> [0..3] Background
 *  @return  <b>bool</b> [TRUE or FALSE] Enable/Disable Overflow
 */
#define get_bg_overflow(bg)  GET_BG_OVERFLOW(bg)


/*!
 *  @param   bg  <b>u8</b> [0..3] Background
 *  @return  <b>u8</b> [BG_SIZE or BG_ROTSIZE] Background Size
 *
 *  @copydoc BG_SIZE
 *  <br>
 *  @copydoc BG_ROTSIZE
 */
#define get_bg_size(bg)  GET_BG_SIZE(bg)


/*!
 *  @param  bg  <b>u8</b> [2..3] Background
 *  @param  pa  <b>u16</b> PA
 */
#define set_bg_rotdata_pa(bg, pa)  SET_BG_ROTDATA_PA(bg, pa)


/*!
 *  @param  bg  <b>u8</b> [2..3] Background
 *  @param  pb  <b>u16</b> PB
 */
#define set_bg_rotdata_pb(bg, pb)  SET_BG_ROTDATA_PB(bg, pb)


/*!
 *  @param  bg  <b>u8</b> [2..3] Background
 *  @param  pc  <b>u16</b> PC
 */
#define set_bg_rotdata_pc(bg, pc)  SET_BG_ROTDATA_PC(bg, pc)


/*!
 *  @param  bg  <b>u8</b> [2..3] Background
 *  @param  pd  <b>u16</b> PD
 */
#define set_bg_rotdata_pd(bg, pd)  SET_BG_ROTDATA_PD(bg, pd)


/*!
 *  @param  bg  <b>u8</b> [2..3] Background
 *  @param  x   <b>u32</b> X
 */
#define set_bg_rotdata_x(bg, x)  SET_BG_ROTDATA_X(bg, x)


/*!
 *  @param  bg  <b>u8</b> [2..3] Background
 *  @param  y   <b>u32</b> Y
 */
#define set_bg_rotdata_y(bg, y)  SET_BG_ROTDATA_Y(bg, y)


/*!
 *  @param  bg    <b>u8</b> [0..3] Background
 *  @param  hofs  <b>u16</b> [0..511] Horizontal Scroll Offset
 *
 *  Sets the horizontal scroll offset of the BG.
 *  This determines which horizontal pixel of the BG will be set
 *  in the left edge of the screen.
 */
#define set_bg_hofs(bg, hofs)  SET_BG_HOFS_BUF(bg, hofs)


/*!
 *  @param  bg    <b>u8</b> [0..3] Background
 *  @param  vofs  <b>u16</b> [0..511] Vertical Scroll Offset
 *
 *  Sets the vertical scroll offset of the BG.
 *  This determines which vertical pixel of the BG will be set
 *  in the top edge of the screen.
 */
#define set_bg_vofs(bg, vofs)  SET_BG_VOFS_BUF(bg, vofs)


/*!
 *  @param   bg  <b>u8</b> [0..3] Background
 *  @return  <b>u16</b> [0..511] Horizontal Scroll Offset
 *
 *  Returns the horizontal scroll offset of the BG.
 */
#define get_bg_hofs(bg)  GET_BG_HOFS_BUF(bg)


/*!
 *  @param   bg  <b>u8</b> [0..3] Background
 *  @return  <b>u16</b> [0..511] Vertical Scroll Offset
 *
 *  Returns the vertical scroll offset of the BG.
 */
#define get_bg_vofs(bg)  GET_BG_VOFS_BUF(bg)


/*!
 *  @param  data     <b>void*</b> Pointer to tile data
 *  @param  index    <b>u16</b> [0..2047] Start tile
 *  @param  length   <b>u16</b> [0..2048] Number of tiles
 *  @param  channel  <b>u8</b> [CPY] Copy type
 *
 *  Tiles are 32 bytes each. For 256 color tiles (64 bytes), you
 *  need to enter double the number of tiles as the length. And 256
 *  color tiles must have an even starting index.<br>
 *  <br>
 *  @copydoc CPY
 */
#define load_bgtiles(data, index, length, channel) \
	LOAD_BGTILES(data, index, length, channel)


/*!
 *  @param  mapdata   <b>void*</b> Pointer to Map
 *  @param  mapwidth  <b>u16</b> Map Width (in tiles)
 *  @param  x         <b>u16</b> X Tile Offset
 *  @param  y         <b>u16</b> Y Tile Offset
 *  @param  tile      <b>u16</b> Tile
 *
 *  Lets you set any tile on any map. Use BG_MAPBASE() macro to
 *  write to BG MEM. Use BG_TILE() macro to set specific options
 *  on a tile. If you are using a rotational map then use
 *  set_rotmap_tile() instead of this function.<br>
 *  <br>
 *  <b>Example:</b><br>
 *  This will locate tile position (10, 12) on mapbase 31 of BG MEM.<br>
 *  Then it will set that tile to tile number 21 with palette 2, and no VFlip
 *  or HFlip.<br>
 *  <br>
 *  @code
 *  set_map_tile(BG_MAPBASE(31), 32, 10, 12, BG_TILE(21, 2, FALSE, FALSE));
 *  @endcode
 */
#define set_map_tile(mapdata, mapwidth, x, y, tile) \
	SET_MAP_TILE(mapdata, mapwidth, x, y, tile)


/*!
 *  @param   mapdata   <b>void*</b> Pointer to Map
 *  @param   mapwidth  <b>u16</b> Map Width (in tiles)
 *  @param   x         <b>u16</b> X Tile Offset
 *  @param   y         <b>u16</b> Y Tile Offset
 *
 *  @return  <b>u16</b> Tile
 *
 *  Returns the tile at (x, y) from the specified map. If you are
 *  using a rotational map then use get_rotmap_tile().
 */
#define get_map_tile(mapdata, mapwidth, x, y) \
	GET_MAP_TILE(mapdata, mapwidth, x, y)


/*!
 *  @param  mapdata   <b>void*</b> Pointer to Map
 *  @param  mapwidth  <b>u16</b> Map Width (in tiles)
 *  @param  x         <b>u16</b> X Tile Offset
 *  @param  y         <b>u16</b> Y Tile Offset
 *  @param  tile      <b>u8</b> Tile
 *
 *  Lets you set any tile on any rotational map.
 */
#define set_rotmap_tile(mapdata, mapwidth, x, y, tile) \
	SET_ROTMAP_TILE(mapdata, mapwidth, x, y, tile)


/*!
 *  @param   mapdata   <b>void*</b> Pointer to Map
 *  @param   mapwidth  <b>u16</b> Map Width (in tiles)
 *  @param   x         <b>u16</b> X Tile Offset
 *  @param   y         <b>u16</b> Y Tile Offset
 *
 *  @return  <b>u8</b> Tile
 *
 *  Returns the tile at (x, y) from the specified rotational map.
 */
#define get_rotmap_tile(mapdata, mapwidth, x, y) \
	GET_ROTMAP_TILE(mapdata, mapwidth, x, y)

/*!
 *  @param  bg        <b>u8</b> [0..3] Background
 *  @param  size      <b>u8</b> [BG_SIZE or BG_ROTSIZE] Background Size
 *  @param  colmod    <b>bool</b> [BG_COLMOD] Color Mode
 *  @param  tilebase  <b>u8</b> [0..3] Tilebase
 *  @param  mapbase   <b>u8</b> [0..31] Mapbase
 *
 *  Sets a bunch of BG properties at once<br>
 *  <br>
 *  @copydoc BG_SIZE
 *  <br>
 *  @copydoc BG_ROTSIZE
 *  <br>
 *  @copydoc BG_COLMOD
 */
#define set_bg(bg, size, colmod, tilebase, mapbase) \
	SET_BG(bg, size, colmod, tilebase, mapbase)

/*---------------------------------------------------------------------------*
 *  STRUCTURES                                                               *
 *---------------------------------------------------------------------------*/

/*!
 *  BG Scroll Structure
 */
typedef struct {
	vu16 hofs;
	vu16 vofs;
} _bgofs_t;


/*!
 *  BG Rotate/Scale Data Structure
 */
typedef struct {
	vu16 pa;
	vu16 pb;
	vu16 pc;
	vu16 pd;
	vu32 x;
	vu32 y;
} _bgrotdata_t;

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

/*!
 *  @param  dst      Destination Map
 *  @param  dw       Destination Map Width
 *  @param  dx       Destination X Offset
 *  @param  dy       Destination Y Offset
 *  @param  src      Source Map Data
 *  @param  sw       Source Map Width
 *  @param  sx       Source X Offset
 *  @param  sy       Source Y Offset
 *  @param  sx_num   Number of horizontal tiles to copy per row
 *  @param  sy_num   Number of rows to copy
 *  @param  maptype  [BG_MAPTYPE]
 *  @param  channel  [CPY] Copy type
 *
 *  @copydoc BG_MAPTYPE
 *  <br>
 *  @copydoc CPY
 */
void copy_bgmap (void *dst, u16 dw, u16 dx, u16 dy,
                 void *src, u16 sw, u16 sx, u16 sy, u16 sx_num, u16 sy_num,
                 bool maptype, u8 channel);


/*!
 *  @param  data     Pointer to Map Data
 *  @param  mapbase  [0..31] Mapbase
 *  @param  dw       Destination Map Width
 *  @param  dx       Destination X Offset
 *  @param  dy       Destination Y Offset
 *  @param  sx_num   Width of source map
 *  @param  sy_num   Height of source map
 *  @param  maptype  [BG_MAPTYPE] Map Type
 *  @param  channel  [CPY] Copy type
 *
 *  Load mapdata onto a BG map.<br>
 *  <br>
 *  @copydoc BG_MAPTYPE
 *  <br>
 *  @copydoc CPY
 */
void load_bgmap (void *data, u8 mapbase, u16 dw, u16 dx, u16 dy, u16 sx_num, u16 sy_num, bool maptype, u8 channel);

/*---------------------------------------------------------------------------*
 *  VARIABLES                                                                *
 *---------------------------------------------------------------------------*/

extern _bgofs_t _bgofs_buf[4];

#endif

