/*!
 *  @file   msh_bitmap.h
 *  @brief  Bitmap functions for modes 3, 4, 5
 */

#ifndef MSH_BITMAP_H
#define MSH_BITMAP_H

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

/*!
 *  @param  data     Pointer to bitmap data
 *  @param  frmbuf   [0..1] BG Frame Buffer
 *  @param  channel  [CPY] Copy type
 *
 *  Display mode must already be set in the range [3..5].<br>
 *  <br>
 *  @copydoc CPY
 */
void load_bitmap (void *data, bool frmbuf, u8 channel);

#endif

