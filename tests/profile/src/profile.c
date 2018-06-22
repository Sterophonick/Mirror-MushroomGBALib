
#define MSH_DEBUG
#include <mushroom/mushroom.h>

void AgbMain () {
	set_disp_frcblk(TRUE);
	set_disp_mode(0);
	set_disp_frcblk(FALSE);

	set_bgpal_color(0, RGB(25, 25, 25));

	dtext_init(31, 32, 0, 0);
	set_bg(0, BG_SIZE_256x256, BG_COLMOD_16, 0, 31);

	prf_start();
	dtext(0, 0, "123456789012345678901234567890");
	dtext(0, 1, "x:%u y:%u z:%u", 20, 2600, 13);
	prf_end();
	prf_text(1, 10);
	prf_print("How fast is dtext()?");

	set_disp_bg0(TRUE);

	while (1) {
	}
}

