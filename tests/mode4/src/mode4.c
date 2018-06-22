
#define MSH_DEBUG
#include <mushroom/mushroom.h>

extern const unsigned char balk_256_Bitmap[];
extern const unsigned short bg_Palette[];

void AgbMain () {
	set_disp_frcblk(TRUE);
	set_bgpal_color(0, 0);
	set_disp_frcblk(FALSE);

	set_disp_mode(4);

	load_bgpal((void *)bg_Palette, 0, 256, 3);
	load_bitmap((void *)balk_256_Bitmap, 0, 3);

	set_disp_bg2(TRUE);

	while (1) {
	}
}

