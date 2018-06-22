
#define MSH_DEBUG      // Enable debugging
#include <mushroom/mushroom.h>

void AgbMain () {
	set_disp_frcblk(TRUE);
	set_disp_mode(0);
	set_bgpal_color(0, 0);
	set_disp_frcblk(FALSE);

	set_bg(0, BG_SIZE_256x256, BG_COLMOD_16, 0, 31);

	dtext_init(31, 32, 0, 0);
	dtext(1, 1, "Hello World!");

	set_disp_bg0(TRUE);

	while (1) {
	}
}

