
#define MSH_DEBUG
#include <mushroom/mushroom.h>

s8 dir = 1;
u8 col = 0;

void UpdateBg() {
	if (col == 0) {dir = 1;}
	if (col == 31) {dir = -1;}

	col += dir;
	set_bgpal_color(0, RGB(col, col, col));
}

void EventVbl () {
	UpdateBg();
}

void AgbMain () {
	set_disp_frcblk(TRUE);
	set_disp_mode(0);
	set_disp_bg0(TRUE); // VBA 1.5.1 bug workaround
	set_disp_frcblk(FALSE);

	irq_init();
	set_irq_func(IRQ_VBL, EventVbl);
	irq_start(IRQ_VBL);

	while (1) {
	}
}

