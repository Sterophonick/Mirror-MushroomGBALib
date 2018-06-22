
#define MSH_DEBUG
#include <mushroom/mushroom.h>

void AgbMain () {
	set_disp_frcblk(TRUE);
	set_disp_mode(0);
	set_disp_frcblk(FALSE);

	set_bgpal_color(0, RGB(25, 25, 25));
	set_bgpal_color(0, RGB(0, 0, 25));
//	set_bgpal_color(0, 0);

	//assert(0 == 8, "This is not happening!");

	dtext_init(31, 32, 0, 0);

	set_bgpal_color(2, RGB(0, 0, 25));

	dtext(1, 1, "Don't spend $$$!");
	dtext(1, 2, "~10%% more tilde!");
	dtext(1, 4, "if (x*x > 1) && (y < 2)\n   {z = 3 + x; y--;}");
	dtext(1, 7, "[mol@berk gba]#");
	dtext(1, 8, "2^32: 0x100000000");
	dtext(1, 10, "Pipe: ||");
	dtext(1, 11, "__underscore__");
	dtext(1, 13, "`Pants?', asked Mario.");
	dtext(1, 15, "\"/home/molasses/\"");
	dtext(1, 17, "C:\\Molasses\\>");


	set_bg_size(0, BG_SIZE_256x256);
	set_bg_colmod(0, BG_COLMOD_16);
	set_bg_tilebase(0, 0);
	set_bg_mapbase(0, 31);

	set_disp_bg0(TRUE);

	while (1) {
	}
}

