
#define MSH_DEBUG
#include <mushroom/mushroom.h>

void AgbMain () {
	set_disp_frcblk(TRUE);
	set_disp_mode(0);
	set_disp_frcblk(FALSE);

	set_bgpal_color(0, RGB(25, 25, 25));
	set_bgpal_color(1, RGB(31, 31, 31));
	set_bgpal_color(2, RGB(0, 0, 0));

	load_bgtiles((void *)font_milkbottle_Bitmap, 0, sizeof(font_milkbottle_Bitmap) >> 5, CPY_DMA3);

	set_bg_size(0, BG_SIZE_256x256);
	set_bg_colmod(0, BG_COLMOD_16);
	set_bg_tilebase(0, 0);
	set_bg_mapbase(0, 31);

	set_map_tile((void *)BG_MAPBASE(31), 32, 10, 8, BG_TILE(34, 0, FALSE, FALSE));
	set_map_tile((void *)BG_MAPBASE(31), 32, 11, 8, BG_TILE(37, 0, FALSE, FALSE));
	set_map_tile((void *)BG_MAPBASE(31), 32, 12, 8, BG_TILE(50, 0, FALSE, TRUE));
	set_map_tile((void *)BG_MAPBASE(31), 32, 13, 8, BG_TILE(51, 0, FALSE, FALSE));
	set_map_tile((void *)BG_MAPBASE(31), 32, 14, 8, BG_TILE(37, 0, FALSE, FALSE));
	set_map_tile((void *)BG_MAPBASE(31), 32, 15, 8, BG_TILE(50, 0, FALSE, TRUE));
	set_map_tile((void *)BG_MAPBASE(31), 32, 16, 8, BG_TILE(43, 0, FALSE, FALSE));
	set_map_tile((void *)BG_MAPBASE(31), 32, 17, 8, BG_TILE(37, 0, FALSE, FALSE));
	set_map_tile((void *)BG_MAPBASE(31), 32, 18, 8, BG_TILE(50, 0, FALSE, TRUE));

	set_disp_bg0(TRUE);

	while (1) {
	}
}

