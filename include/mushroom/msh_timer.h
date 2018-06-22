/*!
 *  @file   msh_timer.h
 *  @brief  Timer functions
 */

#ifndef MSH_TIMER_H
#define MSH_TIMER_H

/*---------------------------------------------------------------------------*
 *  DEFINES                                                                  *
 *---------------------------------------------------------------------------*/

/*!
 *  @defgroup  TIM  Timer Attribute
 *  <b>Timer Attribute defines:</b><br>
 *  @code
 */
#define TIM_FREQ_1		0x0000
#define TIM_FREQ_64		0x0001
#define TIM_FREQ_256	0x0002
#define TIM_FREQ_1024	0x0003
#define TIM_CASCADE		0x0004
#define TIM_IRQ			0x0040
#define TIM_ENABLE		0x0080
/*! @endcode @{ @} */

#define _TIM_IRQ_POS	6
#define _TIM_IRQ_BITS	0x0040    // 0000 0000 0100 0000
#define _TIM_IRQ_MASK	0xFFBF    // 1111 1111 1011 1111

/*---------------------------------------------------------------------------*
 *  MACROS                                                                   *
 *---------------------------------------------------------------------------*/

#define SET_TIMER_CNT(timer, cnt) \
	GET_TIMER_CNT(timer) = (cnt);

#define SET_TIMER_DATA(timer, data) \
	GET_TIMER_DATA(timer) = (data);

#define GET_TIMER_CNT(timer) \
	(*((vu16 *)0x04000102 + ((timer) << 1)))

#define GET_TIMER_DATA(timer) \
	(*((vu16 *)0x04000100 + ((timer) << 1)))

#define SET_TIMER_IRQ(timer, irq) \
	{GET_TIMER_CNT(timer) &= _TIM_IRQ_MASK; \
	GET_TIMER_CNT(timer) |= (irq) << _TIM_IRQ_POS;}

#define GET_TIMER_IRQ(timer) \
	((GET_TIMER_CNT(timer) & _TIM_IRQ_BITS) >> _TIM_IRQ_POS)

/*!
 *  @param  timer  <b>u8</b> [0..3] Timer
 *  @param  cnt    <b>u16</b> [TIM] Timer attributes
 *
 *  Sets attributes on the specified timer.<br>
 *  <br>
 *  @copydoc TIM
 */
#define set_timer_cnt(timer, cnt)  SET_TIMER_CNT(timer, cnt)


/*!
 *  @param  timer  <b>u8</b> [0..3] Timer
 *  @param  data   <b>u16</b> Starting value
 *
 *  Sets the starting value for the timer. This value will
 *  be reloaded into the timer upon overflow.
 */
#define set_timer_data(timer, data)  SET_TIMER_DATA(timer, data)


/*!
 *  @param   timer  <b>u8</b> [0..3] Timer
 *  @return  <b>u16</b> [TIM] Timer attributes
 *
 *  Returns the attributes for the timer<br>
 *  <br>
 *  @copydoc TIM
 */
#define get_timer_cnt(timer)  GET_TIMER_CNT(timer)


/*!
 *  @param   timer  <b>u8</b> [0..3] Timer
 *  @return  <b>u16</b> Starting value
 *
 *  Returns the starting value for the timer
 */
#define get_timer_data(timer)  GET_TIMER_DATA(timer)


/*!
 *  @param  timer  <b>u8</b> [0..3] Timer
 *  @param  irq    <b>bool</b> [TRUE or FALSE] Enable/Disable IRQ
 */
#define set_timer_irq(timer, irq)  SET_TIMER_IRQ(timer, irq)


/*!
 *  @param   timer  <b>u8</b> [0..3] Timer
 *  @return  <b>bool</b> [TRUE or FALSE] Enable/Disable IRQ
 */
#define get_timer_irq(timer)  GET_TIMER_IRQ(timer)

/*---------------------------------------------------------------------------*
 *  STRUCTURES                                                               *
 *---------------------------------------------------------------------------*/

/*!
 *  Timer Control Structure
 */
typedef struct {
	vu16 data;
	vu16 cnt;
} _timer_t;

#endif

