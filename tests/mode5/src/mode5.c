
#define MSH_DEBUG
#include <mushroom/mushroom.h>

extern const unsigned char balkhalf_256_Bitmap[];

void AgbMain () {
	set_disp_frcblk(TRUE);
	set_bgpal_color(0, 0);
	set_disp_frcblk(FALSE);

	set_disp_mode(5);

	load_bitmap((void *)balkhalf_256_Bitmap, 0, 3);

	set_disp_bg2(TRUE);

	while (1) {
	}
}

