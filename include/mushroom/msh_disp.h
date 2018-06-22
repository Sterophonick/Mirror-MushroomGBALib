/*!
 *  @file   msh_disp.h
 *  @brief  Display control functions
 */

#ifndef MSH_DISP_H
#define MSH_DISP_H

/*---------------------------------------------------------------------------*
 *  DEFINES                                                                  *
 *---------------------------------------------------------------------------*/

/*!
 *  @defgroup  DISP_OBJMAP  Object Map Type
 *  <b>Object Map Type defines:</b><br>
 *  @code
 */
#define DISP_OBJMAP_2D	0
#define DISP_OBJMAP_1D	1
/*! @endcode @{ @} */

/*---------------------------------------------------------------------------*
 *  DISPCNT BITS                                                             *
 *---------------------------------------------------------------------------*/

// 3 bits
#define _DISP_MODE_POS		0
#define _DISP_MODE_BITS		0x0007    // 0000 0000 0000 0111
#define _DISP_MODE_MASK		0xFFF8    // 1111 1111 1111 1000

// 1 bit
#define _DISP_GBCMODE_POS	3
#define _DISP_GBCMODE_BITS	0x0008    // 0000 0000 0000 1000
#define _DISP_GBCMODE_MASK	0xFFF7    // 1111 1111 1111 0111

// 1 bit
#define _DISP_FRMBUF_POS	4
#define _DISP_FRMBUF_BITS	0x0010    // 0000 0000 0001 0000
#define _DISP_FRMBUF_MASK	0xFFEF    // 1111 1111 1110 1111

// 1 bit
#define _DISP_HBLPROC_POS	5
#define _DISP_HBLPROC_BITS	0x0020    // 0000 0000 0010 0000
#define _DISP_HBLPROC_MASK	0xFFDF    // 1111 1111 1101 1111

// 1 bit
#define _DISP_OBJMAP_POS	6
#define _DISP_OBJMAP_BITS	0x0040    // 0000 0000 0100 0000
#define _DISP_OBJMAP_MASK	0xFFBF    // 1111 1111 1011 1111

// 1 bit
#define _DISP_FRCBLK_POS	7
#define _DISP_FRCBLK_BITS	0x0080    // 0000 0000 1000 0000
#define _DISP_FRCBLK_MASK	0xFF7F    // 1111 1111 0111 1111

// 1 bit
#define _DISP_BG0_POS		8
#define _DISP_BG0_BITS		0x0100    // 0000 0001 0000 0000
#define _DISP_BG0_MASK		0xFEFF    // 1111 1110 1111 1111

// 1 bit
#define _DISP_BG1_POS		9
#define _DISP_BG1_BITS		0x0200    // 0000 0010 0000 0000
#define _DISP_BG1_MASK		0xFDFF    // 1111 1101 1111 1111

// 1 bit
#define _DISP_BG2_POS		10
#define _DISP_BG2_BITS		0x0400    // 0000 0100 0000 0000
#define _DISP_BG2_MASK		0xFBFF    // 1111 1011 1111 1111

// 1 bit
#define _DISP_BG3_POS		11
#define _DISP_BG3_BITS		0x0800    // 0000 1000 0000 0000
#define _DISP_BG3_MASK		0xF7FF    // 1111 0111 1111 1111

// 1 bit
#define _DISP_OBJ_POS		12
#define _DISP_OBJ_BITS		0x1000    // 0001 0000 0000 0000
#define _DISP_OBJ_MASK		0xEFFF    // 1110 1111 1111 1111

// 1 bit
#define _DISP_WIN0_POS		13
#define _DISP_WIN0_BITS		0x2000    // 0010 0000 0000 0000
#define _DISP_WIN0_MASK		0xDFFF    // 1101 1111 1111 1111

// 1 bit
#define _DISP_WIN1_POS		14
#define _DISP_WIN1_BITS		0x4000    // 0100 0000 0000 0000
#define _DISP_WIN1_MASK		0xBFFF    // 1011 1111 1111 1111

// 1 bit
#define _DISP_OBJWIN_POS	15
#define _DISP_OBJWIN_BITS	0x8000    // 1000 0000 0000 0000
#define _DISP_OBJWIN_MASK	0x7FFF    // 0111 1111 1111 1111

/*---------------------------------------------------------------------------*
 *  DISPSTAT BITS                                                            *
 *---------------------------------------------------------------------------*/

// 1 bit (read only)
#define _DISP_VSTAT_POS			0
#define _DISP_VSTAT_BITS		0x0001    // 0000 0000 0000 0001
#define _DISP_VSTAT_MASK		0xFFFE    // 1111 1111 1111 1110

// 1 bit (read only)
#define _DISP_HSTAT_POS			1
#define _DISP_HSTAT_BITS		0x0002    // 0000 0000 0000 0010
#define _DISP_HSTAT_MASK		0xFFFD    // 1111 1111 1111 1101

// 1 bit (read only)
#define _DISP_VCOUNTSTAT_POS	2
#define _DISP_VCOUNTSTAT_BITS	0x0004    // 0000 0000 0000 0100
#define _DISP_VCOUNTSTAT_MASK	0xFFFB    // 1111 1111 1111 1011

// 1 bit
#define _DISP_VBLIRQ_POS		3
#define _DISP_VBLIRQ_BITS		0x0008    // 0000 0000 0000 1000
#define _DISP_VBLIRQ_MASK		0xFFF7    // 1111 1111 1111 0111

// 1 bit
#define _DISP_HBLIRQ_POS		4
#define _DISP_HBLIRQ_BITS		0x0010    // 0000 0000 0001 0000
#define _DISP_HBLIRQ_MASK		0xFFEF    // 1111 1111 1110 1111

// 1 bit
#define _DISP_VCOUNTIRQ_POS		5
#define _DISP_VCOUNTIRQ_BITS	0x0020    // 0000 0000 0010 0000
#define _DISP_VCOUNTIRQ_MASK	0xFFDF    // 1111 1111 1101 1111

// 8 bits
#define _DISP_VCOUNTTRIG_POS	8
#define _DISP_VCOUNTTRIG_BITS	0xFF00    // 1111 1111 0000 0000
#define _DISP_VCOUNTTRIG_MASK	0x00FF    // 0000 0000 1111 1111

/*---------------------------------------------------------------------------*
 *  MACROS                                                                   *
 *---------------------------------------------------------------------------*/

#define SET_DISP_MODE(mode) \
	{REG_DISPCNT &= _DISP_MODE_MASK; \
	REG_DISPCNT |= (mode);}

#define SET_DISP_FRMBUF(frmbuf) \
	{REG_DISPCNT &= _DISP_FRMBUF_MASK; \
	REG_DISPCNT |= (frmbuf) << _DISP_FRMBUF_POS;}

#define SET_DISP_HBLPROC(hblproc) \
	{REG_DISPCNT &= _DISP_HBLPROC_MASK; \
	REG_DISPCNT |= (hblproc) << _DISP_HBLPROC_POS;}

#define SET_DISP_OBJMAP(objmap) \
	{REG_DISPCNT &= _DISP_OBJMAP_MASK; \
	REG_DISPCNT |= (objmap) << _DISP_OBJMAP_POS;}

#define SET_DISP_FRCBLK(frcblk) \
	{REG_DISPCNT &= _DISP_FRCBLK_MASK; \
	REG_DISPCNT |= (frcblk) << _DISP_FRCBLK_POS;}

#define SET_DISP_BG0(bg0) \
	{REG_DISPCNT &= _DISP_BG0_MASK; \
	REG_DISPCNT |= (bg0) << _DISP_BG0_POS;}

#define SET_DISP_BG1(bg1) \
	{REG_DISPCNT &= _DISP_BG1_MASK; \
	REG_DISPCNT |= (bg1) << _DISP_BG1_POS;}

#define SET_DISP_BG2(bg2) \
	{REG_DISPCNT &= _DISP_BG2_MASK; \
	REG_DISPCNT |= (bg2) << _DISP_BG2_POS;}

#define SET_DISP_BG3(bg3) \
	{REG_DISPCNT &= _DISP_BG3_MASK; \
	REG_DISPCNT |= (bg3) << _DISP_BG3_POS;}

#define SET_DISP_OBJ(obj) \
	{REG_DISPCNT &= _DISP_OBJ_MASK; \
	REG_DISPCNT |= (obj) << _DISP_OBJ_POS;}

#define SET_DISP_WIN0(win0) \
	{REG_DISPCNT &= _DISP_WIN0_MASK; \
	REG_DISPCNT |= (win0) << _DISP_WIN0_POS;}

#define SET_DISP_WIN1(win1) \
	{REG_DISPCNT &= _DISP_WIN1_MASK; \
	REG_DISPCNT |= (win1) << _DISP_WIN1_POS;}

#define SET_DISP_OBJWIN(objwin) \
	{REG_DISPCNT &= _DISP_OBJWIN_MASK; \
	REG_DISPCNT |= (objwin) << _DISP_OBJWIN_POS;}

#define GET_DISP_MODE()     (REG_DISPCNT & _DISP_MODE_BITS)
#define GET_DISP_GBCMODE()  ((REG_DISPCNT & _DISP_GBCMODE_BITS) >> _DISP_GBCMODE_POS)
#define GET_DISP_FRMBUF()   ((REG_DISPCNT & _DISP_FRMBUF_BITS) >> _DISP_FRMBUF_POS)
#define GET_DISP_HBLPROC()  ((REG_DISPCNT & _DISP_HBLPROC_BITS) >> _DISP_HBLPROC_POS)
#define GET_DISP_OBJMAP()   ((REG_DISPCNT & _DISP_OBJMAP_BITS) >> _DISP_OBJMAP_POS)
#define GET_DISP_FRCBLK()   ((REG_DISPCNT & _DISP_FRCBLK_BITS) >> _DISP_FRCBLK_POS)
#define GET_DISP_BG0()      ((REG_DISPCNT & _DISP_BG0_BITS) >> _DISP_BG0_POS)
#define GET_DISP_BG1()      ((REG_DISPCNT & _DISP_BG1_BITS) >> _DISP_BG1_POS)
#define GET_DISP_BG2()      ((REG_DISPCNT & _DISP_BG2_BITS) >> _DISP_BG2_POS)
#define GET_DISP_BG3()      ((REG_DISPCNT & _DISP_BG3_BITS) >> _DISP_BG3_POS)
#define GET_DISP_OBJ()      ((REG_DISPCNT & _DISP_OBJ_BITS) >> _DISP_OBJ_POS)
#define GET_DISP_WIN0()     ((REG_DISPCNT & _DISP_WIN0_BITS) >> _DISP_WIN0_POS)
#define GET_DISP_WIN1()     ((REG_DISPCNT & _DISP_WIN1_BITS) >> _DISP_WIN1_POS)
#define GET_DISP_OBJWIN()   ((REG_DISPCNT & _DISP_OBJWIN_BITS) >> _DISP_OBJWIN_POS)

#define GET_DISP_VSTAT()       (REG_DISPSTAT & _DISP_VSTAT_BITS)
#define GET_DISP_HSTAT()       ((REG_DISPSTAT & _DISP_HSTAT_BITS) >> _DISP_HSTAT_POS)
#define GET_DISP_VCOUNTSTAT()  ((REG_DISPSTAT & _DISP_VCOUNTSTAT_BITS) >> _DISP_VCOUNTSTAT_POS)

#define SET_DISP_VBLIRQ(vblirq) \
	{REG_DISPSTAT &= _DISP_VBLIRQ_MASK; \
	REG_DISPSTAT |= (vblirq) << _DISP_VBLIRQ_POS;}

#define SET_DISP_HBLIRQ(hblirq) \
	{REG_DISPSTAT &= _DISP_HBLIRQ_MASK; \
	REG_DISPSTAT |= (hblirq) << _DISP_HBLIRQ_POS;}

#define SET_DISP_VCOUNTIRQ(vcountirq) \
	{REG_DISPSTAT &= _DISP_VCOUNTIRQ_MASK; \
	REG_DISPSTAT |= (vcountirq) << _DISP_VCOUNTIRQ_POS;}

#define SET_DISP_VCOUNTTRIG(vcounttrig) \
	{REG_DISPSTAT &= _DISP_VCOUNTTRIG_MASK; \
	REG_DISPSTAT |= (vcounttrig) << _DISP_VCOUNTTRIG_POS;}

#define GET_DISP_VBLIRQ()      ((REG_DISPSTAT & _DISP_VBLIRQ_BITS) >> _DISP_VBLIRQ_POS)
#define GET_DISP_HBLIRQ()      ((REG_DISPSTAT & _DISP_HBLIRQ_BITS) >> _DISP_HBLIRQ_POS)
#define GET_DISP_VCOUNTIRQ()   ((REG_DISPSTAT & _DISP_VCOUNTIRQ_BITS) >> _DISP_VCOUNTIRQ_POS)
#define GET_DISP_VCOUNTTRIG()  ((REG_DISPSTAT & _DISP_VCOUNTTRIG_BITS) >> _DISP_VCOUNTTRIG_POS)

#define WAIT_VBL() \
	{while (REG_VCOUNT != 159); \
	while (REG_VCOUNT == 159);}

#define SET_DISP_BG(bg, show) \
	{REG_DISPCNT &= ~(1 << (_DISP_BG0_POS + (bg))); \
	REG_DISPCNT |= (show) << (_DISP_BG0_POS + (bg));}

#define GET_DISP_BG(bg)  ((REG_DISPCNT & (_DISP_BG0_BITS << (bg))) >> (_DISP_BG0_POS + (bg)))

#define SET_DISP_WIN(win, show) \
	{REG_DISPCNT &= ~(1 << (_DISP_WIN0_POS + (win))); \
	REG_DISPCNT |= (show) << (_DISP_WIN0_POS + (win));}

#define GET_DISP_WIN(win)  ((REG_DISPCNT & (_DISP_WIN0_BITS << (win))) >> (_DISP_WIN0_POS + (win)))

#define TL_TO_PX(tl)   ((tl) << 3)
#define PX_TO_TL(px)   ((px) >> 3)
#define PX_MOD_TL(px)  ((px) & 0x7)

/*!
 *  @param  mode  <b>u8</b> [0..5] Display Mode
 */
#define set_disp_mode(mode)  SET_DISP_MODE(mode)


/*!
 *  @param  frmbuf  <b>bool</b> [0..1] BG Frame Buffer
 *
 *  Only available in modes 4 and 5.
 */
#define set_disp_frmbuf(frmbuf)  SET_DISP_FRMBUF(frmbuf)


/*!
 *  @param  hblproc  <b>bool</b> [TRUE or FALSE] Enable/Disable HBL Processing
 */
#define set_disp_hblproc(hblproc)  SET_DISP_HBLPROC(hblproc)


/*!
 *  @param  objmap  <b>bool</b> [DISP_OBJMAP] Object Map Format
 *
 *  @copydoc DISP_OBJMAP
 */
#define set_disp_objmap(objmap)  SET_DISP_OBJMAP(objmap)


/*!
 *  @param  frcblk  <b>bool</b> [TRUE or FALSE] Enable/Disable Force Blank
 */
#define set_disp_frcblk(frcblk)  SET_DISP_FRCBLK(frcblk)


/*!
 *  @param  bg0  <b>bool</b> [TRUE or FALSE] Show/Hide BG0
 */
#define set_disp_bg0(bg0)  SET_DISP_BG0(bg0)


/*!
 *  @param  bg1  <b>bool</b> [TRUE or FALSE] Show/Hide BG1
 */
#define set_disp_bg1(bg1)  SET_DISP_BG1(bg1)


/*!
 *  @param  bg2  <b>bool</b> [TRUE or FALSE] Show/Hide BG2
 */
#define set_disp_bg2(bg2)  SET_DISP_BG2(bg2)


/*!
 *  @param  bg3  <b>bool</b> [TRUE or FALSE] Show/Hide BG3
 */
#define set_disp_bg3(bg3)  SET_DISP_BG3(bg3)


/*!
 *  @param  obj  <b>bool</b> [TRUE or FALSE] Show/Hide Objects
 */
#define set_disp_obj(obj)  SET_DISP_OBJ(obj)


/*!
 *  @param  win0  <b>bool</b> [TRUE or FALSE] Enable/Disable WIN0
 */
#define set_disp_win0(win0)  SET_DISP_WIN0(win0)


/*!
 *  @param  win1  <b>bool</b> [TRUE or FALSE] Enable/Disable WIN1
 */
#define set_disp_win1(win1)  SET_DISP_WIN1(win1)


/*!
 *  @param  objwin  <b>bool</b> [TRUE or FALSE] Enable/Disable Object Windows
 */
#define set_disp_objwin(objwin)  SET_DISP_OBJWIN(objwin)


/*!
 *  @return  <b>u8</b> [0..5] Display Mode
 */
#define get_disp_mode()  GET_DISP_MODE()


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Game Boy Color Mode
 */
#define get_disp_gbcmode()  GET_DISP_GBCMODE()


/*!
 *  @return  <b>bool</b> [0..1] BG Frame Buffer
 */
#define get_disp_frmbuf()  GET_DISP_FRMBUF()


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable/Disable HBL Processing
 */
#define get_disp_hblproc()  GET_DISP_HBLPROC()


/*!
 *  @return  <b>bool</b> [DISP_OBJMAP] Object Map Format
 *
 *  @copydoc DISP_OBJMAP
 */
#define get_disp_objmap()  GET_DISP_OBJMAP()


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable/Disable Force Blank
 */
#define get_disp_frcblk()  GET_DISP_FRCBLK()


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Show/Hide BG0
 */
#define get_disp_bg0()  GET_DISP_BG0()


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Show/Hide BG1
 */
#define get_disp_bg1()  GET_DISP_BG1()


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Show/Hide BG2
 */
#define get_disp_bg2()  GET_DISP_BG2()


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Show/Hide BG3
 */
#define get_disp_bg3()  GET_DISP_BG3()


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Show/Hide Objects
 */
#define get_disp_obj()  GET_DISP_OBJ()


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable/Disable WIN0
 */
#define get_disp_win0()  GET_DISP_WIN0()


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable/Disable WIN1
 */
#define get_disp_win1()  GET_DISP_WIN1()


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable/Disable Object Windows
 */
#define get_disp_objwin()  GET_DISP_OBJWIN()


/*!
 *  @return  <b>bool</b> [0..1] V Refresh Status
 *
 *  Returns 0 during VDraw and 1 during VBlank.
 */
#define get_disp_vstat()  GET_DISP_VSTAT()


/*!
 *  @return  <b>bool</b> [0..1] H Refresh Status
 *
 *  Returns 0 during HDraw and 1 during HBlank.
 */
#define get_disp_hstat()  GET_DISP_HSTAT()


/*!
 *  @return  <b>bool</b> [0..1] VCount Triggered Status
 *
 *  Gets set to 1 when a VCount trigger interrupt occurs.
 */
#define get_disp_vcountstat()  GET_DISP_VCOUNTSTAT()


/*!
 *  @param  vblirq  <b>bool</b> [TRUE or FALSE] Enable/Disable VBL IRQ
 */
#define set_disp_vblirq(vblirq)  SET_DISP_VBLIRQ(vblirq)


/*!
 *  @param  hblirq  <b>bool</b> [TRUE or FALSE] Enable/Disable HBL IRQ
 */
#define set_disp_hblirq(hblirq)  SET_DISP_HBLIRQ(hblirq)


/*!
 *  @param  vcountirq  <b>bool</b> [TRUE or FALSE] Enable/Disable VCount IRQ
 */
#define set_disp_vcountirq(vcountirq)  SET_DISP_VCOUNTIRQ(vcountirq)


/*!
 *  @param  vcounttrig  <b>u8</b> [0..227] VCount Line Trigger
 */
#define set_disp_vcounttrig(vcounttrig)  SET_DISP_VCOUNTTRIG(vcounttrig)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable/Disable VBL IRQ
 */
#define get_disp_vblirq()  GET_DISP_VBLIRQ()


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable/Disable HBL IRQ
 */
#define get_disp_hblirq()  GET_DISP_HBLIRQ()


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable/Disable VCount IRQ
 */
#define get_disp_vcountirq()  GET_DISP_VCOUNTIRQ()


/*!
 *  @return  <b>u8</b> [0..227] VCount Line Trigger
 */
#define get_disp_vcounttrig()  GET_DISP_VCOUNTTRIG()


/*!
 *  Waits for the start of a new VBL. If already in a VBL then it will
 *  wait for the next new VBL.
 */
#define wait_vbl()  WAIT_VBL()


/*!
 *  @param  bg    [0..3] Background
 *  @param  show  [TRUE or FALSE] Show background
 *
 *  Shows or hides the specified background layer
 */
#define set_disp_bg(bg, show)  SET_DISP_BG(bg, show)


/*!
 *  @param   bg    [0..3] Background
 *  @return  [TRUE or FALSE] Show background
 *
 *  Returns TRUE if the specified background layer is displayed, or
 *  FALSE if it is hidden
 */
#define get_disp_bg(bg)  GET_DISP_BG(bg)


/*!
 *  @param  win   [0..1] Window
 *  @param  show  [TRUE or FALSE] Show window
 *
 *  Shows or hides the specified window
 */
#define set_disp_win(win, show)  SET_DISP_WIN(win, show)


/*!
 *  @param   win  [0..1] Window
 *  @return  [TRUE or FALSE] Show window
 *
 *  Returns TRUE if the specified window is displayed, or
 *  FALSE if it is hidden
 */
#define get_disp_win(win)  GET_DISP_WIN(win)

#endif

