
#define MSH_DEBUG
#include <mushroom/mushroom.h>


void EventVbl () {
	key_update();
}


void AgbMain () {
	set_disp_frcblk(TRUE);
	set_disp_mode(0);
	set_disp_frcblk(FALSE);

	set_bgpal_color(0, RGB(25, 25, 25));

	dtext_init(31, 32, 0, 0);

	dtext(2, 1, "KEY TEST");
	dtext(2, 3, "PRESS L OR R TO CLEAR");
	dtext(2, 7, "UP:");
	dtext(2, 8, "DOWN:");
	dtext(2, 9, "LEFT:");
	dtext(2, 10, "RIGHT:");
	dtext(2, 11, "A:");
	dtext(2, 12, "B:");

	set_bg_size(0, BG_SIZE_256x256);
	set_bg_colmod(0, BG_COLMOD_16);
	set_bg_tilebase(0, 0);
	set_bg_mapbase(0, 31);

	set_disp_bg0(TRUE);

	irq_init();
	set_irq_func(IRQ_VBL, EventVbl);
	irq_start(IRQ_VBL);

	while (1) {
		if (any_key_pressed(KEY_L | KEY_R)) {
			dtext(10, 7, "               ");
			dtext(10, 8, "               ");
			dtext(10, 9, "               ");
			dtext(10, 10, "               ");
			dtext(10, 11, "               ");
			dtext(10, 12, "               ");
		}

		if (key_pressed(KEY_UP)) {dtext(10, 7, "PRSD");}
		if (key_down(KEY_UP)) {dtext(15, 7, "DOWN");}
		if (key_released(KEY_UP)) {dtext(20, 7, "RLSD");}

		if (key_pressed(KEY_DOWN)) {dtext(10, 8, "PRSD");}
		if (key_down(KEY_DOWN)) {dtext(15, 8, "DOWN");}
		if (key_released(KEY_DOWN)) {dtext(20, 8, "RLSD");}

		if (key_pressed(KEY_LEFT)) {dtext(10, 9, "PRSD");}
		if (key_down(KEY_LEFT)) {dtext(15, 9, "DOWN");}
		if (key_released(KEY_LEFT)) {dtext(20, 9, "RLSD");}

		if (key_pressed(KEY_RIGHT)) {dtext(10, 10, "PRSD");}
		if (key_down(KEY_RIGHT)) {dtext(15, 10, "DOWN");}
		if (key_released(KEY_RIGHT)) {dtext(20, 10, "RLSD");}

		if (key_pressed(KEY_A)) {dtext(10, 11, "PRSD");}
		if (key_down(KEY_A)) {dtext(15, 11, "DOWN");}
		if (key_released(KEY_A)) {dtext(20, 11, "RLSD");}

		if (key_pressed(KEY_B)) {dtext(10, 12, "PRSD");}
		if (key_down(KEY_B)) {dtext(15, 12, "DOWN");}
		if (key_released(KEY_B)) {dtext(20, 12, "RLSD");}

		if (key_pressed(KEY_START)) {
			assert(0, "Do not press START!");
		}
	}
}

