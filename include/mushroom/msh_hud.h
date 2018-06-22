/*!
 *  @file   msh_hud.h
 *  @brief  Sprite based text functions
 *
 *  The HUD provides a 30x8 character interface for printing text on
 *  the GBA screen. This is similar to using the dtext() functions, but
 *  the HUD renders text with sprites instead of using a background layer.
 *  These functions are generally meant for debugging and probably not
 *  very suitable for use as text in games.
 */

#ifndef MSH_HUD_H
#define MSH_HUD_H

/*---------------------------------------------------------------------------*
 *  DEFINES                                                                  *
 *---------------------------------------------------------------------------*/

#define MSH_HUD_WIDTH		30
#define MSH_HUD_HEIGHT		8

/*---------------------------------------------------------------------------*
 *  MACROS                                                                   *
 *---------------------------------------------------------------------------*/

/*!
 *  @param  x     [0..29] X Position
 *  @param  y     [0..7] Y Position
 *  @param  ...   Format string
 *
 *  Used for writing text to the HUD
 */
#define hud_print(x, y, ...)  {sprintf(_hud_string, __VA_ARGS__); _hud_print(x, y, _hud_string);}

/*---------------------------------------------------------------------------*
 *  VARIABLES                                                                *
 *---------------------------------------------------------------------------*/

extern char _hud_string[256];

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

/*!
 *  @param  y_offset  [0..255] Y Position
 *
 *  Moves the HUD to the specified Y position (in pixels)
 */
void set_hud_y_offset (u8 y_offset);


/*!
 *  @param  obj          [0..124] Starting sprite index (uses 4 sprites)
 *  @param  pal          [0..15] Palette
 *  @param  y_offset     [0..255] HUD Y Position (in pixels)
 *  @param  tile_offset  [0..768] Starting sprite tile (uses 256 tiles)
 *
 *  Sets 2 colors in the palette specified and sets up 4 objects (sprites)
 *  from the obj index. The HUD will also use 256 sprite tiles.<br>
 *  <br>
 *  Call this function before using any of the other HUD functions.
 */
void hud_init (u8 obj, u8 pal, u8 y_offset, u16 tile_offset);


/*!
 *  @param  show  [TRUE or FALSE] Display the HUD
 *
 *  Show or hide the HUD
 */
void hud_show (bool show);


/*!
 *  @param  y  [0..7] Line to clear
 *
 *  Clears the specified HUD line
 */
void hud_clear_line (u8 y);


/*!
 *  Clears the entire HUD
 */
void hud_clear_all ();


/*!
 *  @internal
 *
 *  @param  x     [0..29] X Position
 *  @param  y     [0..7] Y Position
 *  @param  text  Text string
 *
 *  Use the hud_print() macro.<br>
 *  Used for writing text to the HUD.
 */
void _hud_print (u8 x, u8 y, char *text);

#endif

