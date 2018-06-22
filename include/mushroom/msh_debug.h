/*!
 *  @file   msh_debug.h
 *  @brief  Debug functions
 */

#ifndef MSH_DEBUG_H
#define MSH_DEBUG_H

/*---------------------------------------------------------------------------*
 *  DEFINES                                                                  *
 *---------------------------------------------------------------------------*/

#define MSH_PRF_TIMER	3

/*---------------------------------------------------------------------------*
 *  MACROS                                                                   *
 *---------------------------------------------------------------------------*/

/*!
 *  @param  cond  True/False Condition
 *  @param  msg   Message to display
 *
 *  Displays a message if the specified condition fails
 */
#ifdef MSH_DEBUG
	#define	assert(cond, msg)  _assert(cond, msg, #cond, __FILE__, __LINE__);
#else
	#define assert(cond, msg);
#endif


/*!
 *  @param  str  String
 *
 *  Used for writing debug text to the console
 */
#define dprint(str)  print_mappy(str);


/*!
 *  @param  ...  Format string
 *
 *  Used for writing debug text to the console
 */
#define dprintf(...)  {sprintf(_dbg_string, __VA_ARGS__); dprint(_dbg_string);}


/*!
 *  @param  x    <b>u16</b> X Position
 *  @param  y    <b>u16</b> Y Position
 *  @param  ...  Format string
 *
 *  Used for writing debug text onto a virtual map or BG map
 */
#define dtext(x, y, ...)  {sprintf(_dbg_string, __VA_ARGS__); _dtext(x, y, _dbg_string);}


#define PRF_START() \
	{set_timer_cnt(MSH_PRF_TIMER, 0); \
	set_timer_data(MSH_PRF_TIMER, 0); \
	set_timer_cnt(MSH_PRF_TIMER, TIM_FREQ_1024 | TIM_ENABLE);}

#define PRF_END() \
	set_timer_cnt(MSH_PRF_TIMER, 0);

#define GET_PRF_TOTAL()  ((u16)get_timer_data(MSH_PRF_TIMER))

#define GET_PRF_LINES()  ((u16)(get_prf_total() / 1.19))

#define PRF_PRINT(msg) \
	dprintf("PRF: %s - %d ticks (%d lines)\n", msg, get_prf_total(), get_prf_lines());

#define PRF_TEXT(x, y) \
	dtext(x, y, "PRF: %d ticks (%d lines)", get_prf_total(), get_prf_lines());


/*!
 *  Start a profiling block. Used to time functions.
 */
#define prf_start()  PRF_START()


/*!
 *  End a profiling block. Stop timing.
 */
#define prf_end()  PRF_END()


/*!
 *  @return  <b>u16</b> Number of ticks
 *
 *  Returns the number of ticks elapsed between calling prf_start()
 *  and prf_end().
 */
#define get_prf_total()  GET_PRF_TOTAL()


/*!
 *  @return  <b>u16</b> Number of scanlines
 *
 *  Returns the number of scanlines elapsed between calling prf_start()
 *  and prf_end(). This function is helpful to check if certain functions
 *  will fit within the VBlank period.<br>
 *  <br>
 *  This function provides an approximation of scanlines elapsed and will
 *  sometimes report an extra scanline.
 */
#define get_prf_lines()  GET_PRF_LINES()


/*!
 *  @param  msg  <b>char*</b> Message String
 *
 *  Prints out the profile results to the console. You can also enter
 *  your own message so you can make notes of what is being profiled.
 */
#define prf_print(msg)  PRF_PRINT(msg)


/*!
 *  @param  x  <b>u16</b> X Location
 *  @param  y  <b>u16</b> Y Location
 *
 *  Prints out the profile results to the GBA screen
 */
#define prf_text(x, y)  PRF_TEXT(x, y)

/*---------------------------------------------------------------------------*
 *  VARIABLES                                                                *
 *---------------------------------------------------------------------------*/

extern char _dbg_string[256];

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

/*!
 *  @internal
 *
 *  @param  cond  True/False Condition
 *  @param  msg   Message to display
 *  @param  exp   Condition as a string
 *  @param  file  Current file
 *  @param  line  Line number of file
 *
 *  Use assert() macro instead.
 */
void _assert (bool cond, char *msg, char *exp, char *file, u32 line);


/*!
 *  @param  msg  Message String
 *
 *  Prints a message to the console under VisualBoyAdvance.
 */
void print_vba_thb (char *msg);


/*!
 *  @param  msg  Message String
 *
 *  Prints a message to the console under VisualBoyAdvance.
 */
void print_vba_arm (char *msg);


/*!
 *  @param  msg  Message String
 *
 *  Prints a message to the console under Mappy or VisualBoyAdvance.
 */
void print_mappy (const char *msg);


/*!
 *  @internal
 *
 *  @param  x     X Position
 *  @param  y     Y Position
 *  @param  text  Text String
 *
 *  Use the dtext() macro.
 *  Used for writing debug text onto a virtual map or BG map.
 */
void _dtext (u16 x, u16 y, char *text);


/*!
 *  @param  mapdata  Pointer to map data
 *
 *  Use the BG_MAPBASE() macro if you want to write to BG MEM.<br>
 *  <br>
 *  <b>Example:</b><br>
 *  Sets dtext() to write to mapbase 31 of BG MEM.<br>
 *  <br>
 *  @code
 *  set_dtext_mapdata((void *)BG_MAPBASE(31));
 *  @endcode
 */
inline void set_dtext_mapdata (void *mapdata);


/*!
 *  @param  pal  [0..15] Palette
 */
inline void set_dtext_pal (u8 pal);


/*!
 *  @param  fontmap  Array mapping font tiles to ASCII
 */
inline void set_dtext_fontmap (char *fontmap);


/*!
 *  @param  tile_offset  The starting tile in VRAM of the font tileset
 */
inline void set_dtext_tile_offset (u16 tile_offset);


/*!
 *  @param  mapwidth  Map Width
 */
inline void set_dtext_mapwidth (u16 mapwidth);


/*!
 *  @return  Pointer to map data
 */
inline void *get_dtext_mapdata ();


/*!
 *  @return  [0..15] Palette
 */
inline u8 get_dtext_pal ();


/*!
 *  @return  Array mapping font tiles to ASCII
 */
inline char *get_dtext_fontmap ();


/*!
 *  @return  The starting tile in VRAM of the font tileset
 */
inline u16 get_dtext_tile_offset ();


/*!
 *  @return  Map Width
 */
inline u16 get_dtext_mapwidth ();


/*!
 *  @param  mapbase      [0..31] Map base
 *  @param  mapwidth     Map Width
 *  @param  pal          [0..15] Palette
 *  @param  tile_offset  The starting tile in VRAM of the font tileset
 *
 *  Sets 2 colors in the palette you choose and loads the default font.
 *  Call this function before using dtext() or set the dtext() values
 *  manually.
 */
void dtext_init (u8 mapbase, u16 mapwidth, u8 pal, u16 tile_offset);


/*!
 *  @return  EWRAM Bytes Free
 *
 *  Returns the largest free block of EWRAM
 */
u32 get_ewram_avail ();


/*!
 *  @param  addr    Start Address
 *  @param  length  Length (in bytes)
 *
 *  Performs a hex dump of memory from the start address to the
 *  console
 */
void hexdump (void *addr, u32 length);


/*!
 *  @param  addr    Start Address
 *  @param  length  Length (in bytes)
 *
 *  Performs a bit dump of memory from the start address to the
 *  console
 */
void bitdump (void *addr, u32 length);

#endif

