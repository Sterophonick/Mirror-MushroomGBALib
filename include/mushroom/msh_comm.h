/*!
 *  @file   msh_comm.h
 *  @brief  Communcation functions for link play
 */

#ifndef MSH_COMM_H
#define MSH_COMM_H

/*---------------------------------------------------------------------------*
 *  DEFINES                                                                  *
 *---------------------------------------------------------------------------*/

#define _COMM_IRQ_POS		14
#define _COMM_IRQ_BITS		0x0000    // 0100 0000 0000 0000
#define _COMM_IRQ_MASK		0xFFFF    // 1011 1111 1111 1111

/*---------------------------------------------------------------------------*
 *  MACROS                                                                   *
 *---------------------------------------------------------------------------*/

#define SET_COMM_IRQ(irq) \
	{REG_SCCNT_L &= _COMM_IRQ_MASK; \
	REG_SCCNT_L |= (irq) << _COMM_IRQ_POS;}

#define GET_COMM_IRQ()  ((REG_SCCNT_L & _COMM_IRQ_BITS) >> _COMM_IRQ_POS)

/*!
 *  @param  irq  <b>bool</b> [TRUE or FALSE] Enable IRQ
 */
#define set_comm_irq(irq)  SET_COMM_IRQ(irq)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable IRQ
 */
#define get_comm_irq()  GET_COMM_IRQ()

#endif

