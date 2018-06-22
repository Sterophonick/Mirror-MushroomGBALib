
#define MSH_DEBUG
#include <mushroom/mushroom.h>

extern const unsigned short s16_Palette[];
extern const unsigned short skeletor_16_Map[];
extern const unsigned char skeletor_16_Tiles[];

void AgbMain () {
	set_disp_frcblk(TRUE);
	set_disp_mode(0);
	set_disp_frcblk(FALSE);

	load_bgpal((void *)s16_Palette, 0, 16, CPY_DMA3);
	load_bgtiles((void *)skeletor_16_Tiles, 0, 329, CPY_DMA3);
	load_bgmap((void *)skeletor_16_Map, 31, 32, 0, 0, 30, 20, BG_MAPTYPE_NORMAL, CPY_DMA3);

	set_bg(0, BG_SIZE_256x256, BG_COLMOD_16, 0, 31);
	set_disp_bg0(TRUE);

	while (1) {
	}
}

