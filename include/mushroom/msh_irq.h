/*!
 *  @file   msh_irq.h
 *  @brief  Interrupt functions
 */

#ifndef MSH_IRQ_H
#define MSH_IRQ_H

/*---------------------------------------------------------------------------*
 *  DEFINES                                                                  *
 *---------------------------------------------------------------------------*/

/*!
 *  @defgroup  IRQ  Interrupt Type
 *  <b>Interrupt Type defines:</b><br>
 *  @code
 */
#define IRQ_VBL		0
#define IRQ_HBL		1
#define IRQ_VCOUNT	2
#define IRQ_TIM0	3
#define IRQ_TIM1	4
#define IRQ_TIM2	5
#define IRQ_TIM3	6
#define IRQ_COMM	7
#define IRQ_DMA0	8
#define IRQ_DMA1	9
#define IRQ_DMA2	10
#define IRQ_DMA3	11
#define IRQ_KEY		12
#define IRQ_CART	13
/*! @endcode @{ @} */

#define _IRQ_VBL_BITS		0x0001
#define _IRQ_HBL_BITS		0x0002
#define _IRQ_VCOUNT_BITS	0x0004
#define _IRQ_TIM0_BITS		0x0008
#define _IRQ_TIM1_BITS		0x0010
#define _IRQ_TIM2_BITS		0x0020
#define _IRQ_TIM3_BITS		0x0040
#define _IRQ_COMM_BITS		0x0080
#define _IRQ_DMA0_BITS		0x0100
#define _IRQ_DMA1_BITS		0x0200
#define _IRQ_DMA2_BITS		0x0400
#define _IRQ_DMA3_BITS		0x0800
#define _IRQ_KEY_BITS		0x1000
#define _IRQ_CART_BITS		0x2000

/*---------------------------------------------------------------------------*
 *  MACROS                                                                   *
 *---------------------------------------------------------------------------*/

#define ENABLE_IRQ()   REG_IME = 1;
#define DISABLE_IRQ()  REG_IME = 0;

/*!
 *  Enable Master Interrupt
 */
#define enable_irq()  ENABLE_IRQ();


/*!
 *  Disable Master Interrupt
 */
#define disable_irq()  DISABLE_IRQ();

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

/*!
 *  Clears associated functions of all interrupts.
 */
void clear_irq_funcs ();


/*!
 *  Clears all interrupts and sets the master interrupt handling
 *  function. This must be called before using any interrupt
 *  functions.
 */
void irq_init ();


/*!
 *  @param  type  [IRQ] Interrupt Type
 *  @param  func  Pointer to function
 *
 *  Associates a function with an interrupt type.<br>
 *  <br>
 *  @copydoc IRQ
 */
inline void set_irq_func (u8 type, void (*func)());


/*!
 *  @param   type  [IRQ] Interrupt Type
 *  @return  Pointer to function
 *
 *  Returns the function associated to the interrupt type.<br>
 *  <br>
 *  @copydoc IRQ
 */
inline void (*get_irq_func (u8 type))();


/*!
 *  @param  type    [IRQ] Interrupt Type
 *  @param  enable  [TRUE or FALSE] Enable Interrupt
 *
 *  Enable or disable the interrupt. Make sure to use set_irq_func() first.<br>
 *  <br>
 *  @copydoc IRQ
 */
void set_irq_mode (u8 type, bool enable);


/*!
 *  @param  type  [IRQ] Interrupt Type
 *
 *  Enable the interrupt. Make sure to use set_irq_func() first.<br>
 *  <br>
 *  @copydoc IRQ
 */
void irq_start (u8 type);


/*!
 *  @param  type  [IRQ] Interrupt Type
 *
 *  Disable the interrupt.<br>
 *  <br>
 *  @copydoc IRQ
 */
void irq_stop (u8 type);

/*---------------------------------------------------------------------------*
 *  VARIABLES                                                                *
 *---------------------------------------------------------------------------*/

extern void (*IntrTable[14])();

#endif

