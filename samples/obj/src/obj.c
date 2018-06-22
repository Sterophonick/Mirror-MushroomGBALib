
#define MSH_DEBUG        // Enable debugging
#include <mushroom/mushroom.h>

extern const unsigned short master_Palette[];
extern const unsigned char spr_8x8x16_Bitmap[];
extern const unsigned char spr_32x32x16_Bitmap[];

void AgbMain () {
	set_disp_frcblk(TRUE);
	set_disp_mode(0);
	set_disp_objmap(DISP_OBJMAP_1D);
	set_disp_obj(TRUE);
	set_disp_bg0(TRUE);
	set_disp_frcblk(FALSE);

	set_bgpal_color(0, RGB(20, 20, 20));

	// OAM must be cleared first
	u32 i;
	for (i = 0; i <= 127; i++) {
		set_oam_y(i, 160);
	}

	// Load OBJ palette
	load_objpal((void *)master_Palette, 0, 16, CPY_DMA3);

	// Load OBJ tiles
	load_objtiles((void *)spr_8x8x16_Bitmap, 0, 1, CPY_DMA3);
	load_objtiles((void *)spr_32x32x16_Bitmap, 1, 16, CPY_DMA3);

	// Set OAM to show some sprites
	set_oam_size(0, OAM_SIZE_8x8);
	set_oam_shape(0, OAM_SHAPE_SQUARE);
	set_oam_colmod(0, OAM_COLMOD_16);
	set_oam_pal(0, 0);
	set_oam_x(0, 150);
	set_oam_y(0, 50);
	set_oam_tile(0, 0);

	set_oam_size(1, OAM_SIZE_32x32);
	set_oam_shape(1, OAM_SHAPE_SQUARE);
	set_oam_colmod(1, OAM_COLMOD_16);
	set_oam_pal(1, 0);
	set_oam_x(1, 50);
	set_oam_y(1, 100);
	set_oam_tile(1, 1);

	while (1) {
	}
}

