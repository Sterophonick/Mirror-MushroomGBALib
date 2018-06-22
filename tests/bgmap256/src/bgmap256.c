
#define MSH_DEBUG
#include <mushroom/mushroom.h>

extern const unsigned short s256_Palette[];
extern const unsigned short skeletor_256_Map[];
extern const unsigned char skeletor_256_Tiles[];

void AgbMain () {
	set_disp_frcblk(TRUE);
	set_disp_mode(0);
	set_disp_frcblk(FALSE);

	load_bgpal((void *)s256_Palette, 0, 256, 3);
	load_bgtiles((void *)skeletor_256_Tiles, 0, 690, 3);
	load_bgmap((void *)skeletor_256_Map, 31, 32, 0, 0, 30, 20, BG_MAPTYPE_NORMAL, 3);

	set_bg(0, BG_SIZE_256x256, BG_COLMOD_256, 0, 31);
	set_disp_bg0(TRUE);

	while (1) {
	}
}

