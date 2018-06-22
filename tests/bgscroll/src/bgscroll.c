
#define MSH_DEBUG
#include <mushroom/mushroom.h>

void AgbMain () {
	set_disp_frcblk(TRUE);
	set_disp_mode(0);
	set_disp_frcblk(FALSE);

	set_bgpal_color(0, RGB(25, 25, 25));

	dtext_init(31, 32, 0, 0);

	dtext(0, 0, "*0000000001111111111222222222233");
	dtext(0, 1, "01234567890123456789012345678901");
	dtext(0, 2, "02");
	dtext(0, 3, "03");
	dtext(0, 4, "04");
	dtext(0, 5, "05");
	dtext(0, 6, "06");

	dtext(6, 6, "bg0hofs:%u", get_bg_hofs(0));
	dtext(6, 7, "bg0vofs:%u", get_bg_vofs(0));

	set_bg_hofs(0, 512 - 16);
	set_bg_vofs(0, 512 - 8);

	dtext(6, 10, "bg0hofs:%u", get_bg_hofs(0));
	dtext(6, 11, "bg0vofs:%u", get_bg_vofs(0));

	set_bg_size(0, BG_SIZE_256x256);
	set_bg_colmod(0, BG_COLMOD_16);
	set_bg_tilebase(0, 0);
	set_bg_mapbase(0, 31);

	set_disp_bg0(TRUE);

	while (1) {
	}
}

