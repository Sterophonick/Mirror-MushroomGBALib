/*!
 *  @file   msh_sram.h
 *  @brief  SaveRAM functions used for savegames
 */

#ifndef MSH_SRAM_H
#define MSH_SRAM_H

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

/*!
 *  @param  data    Data to save
 *  @param  slot    Slot Number
 *  @param  size    Size of slot in bytes
 *  @param  offset  Offset in bytes
 *
 *  Copies <b>data</b> to a save slot in SRAM. You can specify an offset
 *  if you put other data such as game options at the start
 *  of SaveRAM.<br>
 *  <br>
 *  The data being copied must be the same size as specified in
 *  <b>size</b>.
 */
void save_to_sram (void *data, u8 slot, u16 size, u16 offset);


/*!
 *  @param  save_id  SaveID
 *  @param  id_len   Length of SaveID in bytes
 *  @param  slot     Slot Number
 *  @param  size     Size of slot in bytes
 *  @param  offset   Offset in bytes
 *
 *  Returns TRUE if <b>save_id</b> is found in the specified
 *  slot. This means the savegame should exist there as well. This
 *  should be used before attempting to use load_from_sram().
 */
u8 sram_exists (char save_id[], u8 id_len, u8 slot, u16 size, u16 offset);


/*!
 *  @param  data    Data Destination
 *  @param  slot    Slot Number
 *  @param  size    Size of slot in bytes
 *  @param  offset  Offset in bytes
 *
 *  Loads data from SRAM into <b>data</b>. Use
 *  sram_exists() first to check if the data actually exists.
 */
void load_from_sram (void *data, u8 slot, u16 size, u16 offset);


/*!
 *  @param  num_erasebytes  Number of bytes to erase
 *  @param  slot            Slot Number
 *  @param  size            Size of slot in bytes
 *  @param  offset          Offset in bytes
 *
 *  Erases <b>num_erasebytes</b> of SRAM. The bytes are
 *  set to zero. You only need to erase the save_id portion of
 *  a savegame, as that is the only part used to check if it
 *  exists when using sram_exists(). However, you can erase any
 *  ammount of SRAM you like.
 */
void erase_sram (u16 num_erasebytes, u8 slot, u16 size, u16 offset);

#endif

