
#define MSH_DEBUG
#include <mushroom/mushroom.h>

void EventVbl () {
	key_update();

	if (key_pressed(KEY_A)) {
		dtext(1, 2, "rand: %-3u", math_rand(255));
	}

	if (key_pressed(KEY_B)) {
		math_rand_set_seed(get_timer_data(3));
		dtext(1, 1, "seed: %-10u", math_rand_get_seed());
	}
}

void AgbMain () {
	set_disp_frcblk(TRUE);
	set_disp_mode(0);
	set_disp_frcblk(FALSE);

	dtext_init(31, 32, 0, 0);

	set_bg(0, BG_SIZE_256x256, BG_COLMOD_16, 0, 31);
	set_bgpal_color(0, RGB(25, 25, 25));
	set_disp_bg(0, TRUE);

	math_rand_set_seed(12345);
	dtext(1, 1, "seed: %-10u", math_rand_get_seed());
	dtext(1, 2, "rand: %-3u", math_rand(255));

	set_timer_cnt(3, 0);
	set_timer_data(3, 0);
	set_timer_cnt(3, TIM_FREQ_1024 | TIM_ENABLE);

	irq_init();
	set_irq_func(IRQ_VBL, EventVbl);
	irq_start(IRQ_VBL);

	while (1) {
	}
}

