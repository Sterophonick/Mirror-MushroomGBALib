/*!
 *  @file   msh_key.h
 *  @brief  Functions for reading GBA keys
 */

#ifndef MSH_KEY_H
#define MSH_KEY_H

/*---------------------------------------------------------------------------*
 *  DEFINES                                                                  *
 *---------------------------------------------------------------------------*/

/*!
 *  @defgroup  KEY  Key
 *  <b>Key defines:</b><br>
 *  @code
 */
#define KEY_NONE	0x0000
#define KEY_A		0x0001
#define KEY_B		0x0002
#define KEY_SELECT	0x0004
#define KEY_START	0x0008
#define KEY_RIGHT	0x0010
#define KEY_LEFT	0x0020
#define KEY_UP		0x0040
#define KEY_DOWN	0x0080
#define KEY_R		0x0100
#define KEY_L		0x0200
#define KEY_ALL		0x03FF
/*! @endcode @{ @} */

/*!
 *  @defgroup  KEY_IRQTYPE  Key Interrupt Type
 *  <b>Key Interrupt Type defines:</b><br>
 *  @code
 */
#define KEY_IRQTYPE_OR		0
#define KEY_IRQTYPE_AND		1
/*! @endcode @{ @} */

#define _KEY_IRQ_POS		14
#define _KEY_IRQ_BITS		0x4000    // 0100 0000 0000 0000
#define _KEY_IRQ_MASK		0xBFFF    // 1011 1111 1111 1111

#define _KEY_IRQTYPE_POS	15
#define _KEY_IRQTYPE_BITS	0x8000    // 1000 0000 0000 0000
#define _KEY_IRQTYPE_MASK	0x7FFF    // 0111 1111 1111 1111

/*---------------------------------------------------------------------------*
 *  MACROS                                                                   *
 *---------------------------------------------------------------------------*/

#define KEY_UPDATE() \
	{_keys_pressed  = ((~REG_KEY) & (~_keys_down)) & KEY_ALL; \
	_keys_released = (REG_KEY & _keys_down) & KEY_ALL; \
	_keys_down     = (~REG_KEY) & KEY_ALL;}

#define _KEY_DOWN(keys) \
	(((_keys_down & (keys)) == (keys)) ? (TRUE) : (FALSE))

#define _KEY_UP(keys) \
	((((~_keys_down) & (keys)) == (keys)) ? (TRUE) : (FALSE))

#define KEY_PRESSED(keys) \
	((((_keys_pressed) & (keys)) == (keys)) ? (TRUE) : (FALSE))

#define KEY_RELEASED(keys) \
	((((_keys_released) & (keys)) == (keys)) ? (TRUE) : (FALSE))

#define ANY_KEY_DOWN(keys) \
	((_keys_down & (keys)) ? (TRUE) : (FALSE))

#define ANY_KEY_UP(keys) \
	(((~_keys_down) & (keys)) ? (TRUE) : (FALSE))

#define ANY_KEY_PRESSED(keys) \
	((_keys_pressed & (keys)) ? (TRUE) : (FALSE))

#define ANY_KEY_RELEASED(keys) \
	((_keys_released & (keys)) ? (TRUE) : (FALSE))

#define SET_KEY_IRQ(irq) \
	{REG_KEYCNT &= _KEY_IRQ_MASK; \
	REG_KEYCNT |= (irq) << _KEY_IRQ_POS;}

#define GET_KEY_IRQ()  ((REG_KEYCNT & _KEY_IRQ_BITS) >> _KEY_IRQ_POS)

#define SET_KEY_IRQTYPE(irqtype) \
	{REG_KEYCNT &= _KEY_IRQTYPE_MASK; \
	REG_KEYCNT |= (irqtype) << _KEY_IRQTYPE_POS;}

#define GET_KEY_IRQTYPE()  ((REG_KEYCNT & _KEY_IRQTYPE_BITS) >> _KEY_IRQTYPE_POS)

#define SET_KEY_IRQTARGETS(keys) \
	{REG_KEYCNT &= ~KEY_ALL; \
	REG_KEYCNT |= (keys);}

#define GET_KEY_IRQTARGETS()  (REG_KEYCNT & KEY_ALL)


/*!
 *  Update key status. Should be called every VBL.
 */
#define key_update()  KEY_UPDATE()


/*!
 *  @param   keys  <b>u16</b> [KEY] Keys to query
 *  @return  <b>bool</b> [TRUE or FALSE] Keys down
 *
 *  Returns TRUE if all of the specified keys are currently down.<br>
 *  Use the bitwise OR operator to specify multiple keys.<br>
 *  <br>
 *  @copydoc KEY
 */
#define key_down(keys)  _KEY_DOWN(keys)


/*!
 *  @param   keys  <b>u16</b> [KEY] Keys to query
 *  @return  <b>bool</b> [TRUE or FALSE] Keys up
 *
 *  Returns TRUE if all of the specified keys are currently up.<br>
 *  Use the bitwise OR operator to specify multiple keys.<br>
 *  <br>
 *  @copydoc KEY
 */
#define key_up(keys)  _KEY_UP(keys)


/*!
 *  @param   keys  <b>u16</b> [KEY] Keys to query
 *  @return  <b>bool</b> [TRUE or FALSE] Keys pressed
 *
 *  Returns TRUE if all of the specified keys have been pressed
 *  since last call to key_update().<br>
 *  Use the bitwise OR operator to specify multiple keys.<br>
 *  <br>
 *  @copydoc KEY
 */
#define key_pressed(keys)  KEY_PRESSED(keys)


/*!
 *  @param   keys  <b>u16</b> [KEY] Keys to query
 *  @return  <b>bool</b> [TRUE or FALSE] Keys released
 *
 *  Returns TRUE if all of the specified keys have been released
 *  since last call to key_update().<br>
 *  Use the bitwise OR operator to specify multiple keys.<br>
 *  <br>
 *  @copydoc KEY
 */
#define key_released(keys)  KEY_RELEASED(keys)


/*!
 *  @param   keys  <b>u16</b> [KEY] Keys to query
 *  @return  <b>bool</b> [TRUE or FALSE] Keys down
 *
 *  Returns TRUE if any of the specified keys are currently down.<br>
 *  Use the bitwise OR operator to specify multiple keys.<br>
 *  <br>
 *  @copydoc KEY
 */
#define any_key_down(keys)  ANY_KEY_DOWN(keys)


/*!
 *  @param   keys  <b>u16</b> [KEY] Keys to query
 *  @return  <b>bool</b> [TRUE or FALSE] Keys up
 *
 *  Returns TRUE if any of the specified keys are currently up.<br>
 *  Use the bitwise OR operator to specify multiple keys.<br>
 *  <br>
 *  @copydoc KEY
 */
#define any_key_up(keys)  ANY_KEY_UP(keys)


/*!
 *  @param   keys  <b>u16</b> [KEY] Keys to query
 *  @return  <b>bool</b> [TRUE or FALSE] Keys pressed
 *
 *  Returns TRUE if any of the specified keys have been pressed
 *  since last call to key_update().<br>
 *  Use the bitwise OR operator to specify multiple keys.<br>
 *  <br>
 *  @copydoc KEY
 */
#define any_key_pressed(keys)  ANY_KEY_PRESSED(keys)


/*!
 *  @param   keys  <b>u16</b> [KEY] Keys to query
 *  @return  <b>bool</b> [TRUE or FALSE] Keys released
 *
 *  Returns TRUE if any of the specified keys have been released
 *  since last call to key_update().<br>
 *  Use the bitwise OR operator to specify multiple keys.<br>
 *  <br>
 *  @copydoc KEY
 */
#define any_key_released(keys)  ANY_KEY_RELEASED(keys)


/*!
 *  @param  irq  <b>bool</b> [TRUE or FALSE] Enable/Disable IRQ
 */
#define set_key_irq(irq)  SET_KEY_IRQ(irq)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable/Disable IRQ
 */
#define get_key_irq()  GET_KEY_IRQ()


/*!
 *  @param  irqtype  <b>bool</b> [KEY_IRQTYPE] Key IRQ Type
 *
 *  @copydoc KEY_IRQTYPE
 */
#define set_key_irqtype(irqtype)  SET_KEY_IRQTYPE(irqtype)


/*!
 *  @return  <b>bool</b> [KEY_IRQTYPE] Key IRQ Type
 *
 *  @copydoc KEY_IRQTYPE
 */
#define get_key_irqtype()  GET_KEY_IRQTYPE()


/*!
 *  @param  keys  <b>u16</b> [KEY] Keys
 *
 *  Used to set which keys should trigger an interrupt.<br>
 *  Use the bitwise OR operator to specify multiple keys.<br>
 *  <br>
 *  @copydoc KEY
 */
#define set_key_irqtargets(keys)  SET_KEY_IRQTARGETS(keys)

/*!
 *  @return  <b>u16</b> [KEY] Keys
 *
 *  Returns the keys currently used to trigger an interrupt.<br>
 *  Use the bitwise OR operator to specify multiple keys.<br>
 *  <br>
 *  @copydoc KEY
 */
#define get_key_irqtargets()  GET_KEY_IRQTARGETS()

/*---------------------------------------------------------------------------*
 *  VARIABLES                                                                *
 *---------------------------------------------------------------------------*/

extern u16 _keys_pressed;
extern u16 _keys_released;
extern u16 _keys_down;

#endif

