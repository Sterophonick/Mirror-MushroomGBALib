
/*---------------------------------------------------------------------------*
 *  INCLUDES                                                                 *
 *---------------------------------------------------------------------------*/

#include <mushroom/msh_irq.h>

// Array of pointers to funcs for IRQ handling
void (*IntrTable[14])();

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

void clear_irq_funcs () {
	u32 i;

	for (i = 0; i <= 13; i++) {
		IntrTable[i] = NULL;
	}
}


void irq_init () {
	disable_irq();
	clear_irq_funcs();
	REG_IE = 0;  // clear all interrupts
	enable_irq();
}


inline void set_irq_func (u8 type, void (*func)()) {
	IntrTable[type] = func;
}


inline void (*get_irq_func (u8 type))() {
	return IntrTable[type];
}


void set_irq_mode (u8 type, bool enable) {
	disable_irq();

	if (enable) {
		REG_IE |= 1 << type;
	} else {
		REG_IE &= ~(1 << type);
	}

	switch (type) {
		case IRQ_VBL:
			set_disp_vblirq(enable);
			break;
		case IRQ_HBL:
			set_disp_hblirq(enable);
			break;
		case IRQ_VCOUNT:
			set_disp_vcountirq(enable);
			break;
		case IRQ_TIM0:
			set_timer_irq(0, enable);
			break;
		case IRQ_TIM1:
			set_timer_irq(1, enable);
			break;
		case IRQ_TIM2:
			set_timer_irq(2, enable);
			break;
		case IRQ_TIM3:
			set_timer_irq(3, enable);
			break;
		case IRQ_COMM:
			set_comm_irq(enable);
			break;
		case IRQ_DMA0:
			set_dma_irq(0, enable);
			break;
		case IRQ_DMA1:
			set_dma_irq(1, enable);
			break;
		case IRQ_DMA2:
			set_dma_irq(2, enable);
			break;
		case IRQ_DMA3:
			set_dma_irq(3, enable);
			break;
		case IRQ_KEY:
			set_key_irq(enable);
			break;
	}

	enable_irq();
}


void irq_start (u8 type) {
	set_irq_mode(type, TRUE);
}


void irq_stop (u8 type) {
	set_irq_mode(type, FALSE);
}

