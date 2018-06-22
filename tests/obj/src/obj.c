
#define MSH_DEBUG
#include <mushroom/mushroom.h>

extern const unsigned short master_Palette[];
extern const unsigned short pal_64x64x16_Palette[];
extern const unsigned char spr_8x32x256_Bitmap[];
extern const unsigned char spr_32x16x256_Bitmap[];
extern const unsigned char spr_8x8x16_Bitmap[];
extern const unsigned char spr_32x32x16_Bitmap[];
extern const unsigned char spr_64x64x16_Bitmap[];

void AgbMain () {
	set_disp_frcblk(TRUE);
	set_disp_mode(0);
	set_disp_objmap(DISP_OBJMAP_1D);
	set_disp_obj(TRUE);
	set_disp_bg0(TRUE); // VBA 1.5.1 bug workaround
	set_disp_frcblk(FALSE);

	set_bgpal_color(0, RGB(20, 20, 20));

	hide_objs(0, 128);

	load_objpal((void *)master_Palette, 0, 256, 3);
	load_objpal((void *)pal_64x64x16_Palette, 128, 16, 3);

	load_objtiles((void *)spr_8x32x256_Bitmap, 0, 8, 3);
	load_objtiles((void *)spr_32x16x256_Bitmap, 8, 16, 3);
	load_objtiles((void *)spr_8x8x16_Bitmap, 24, 1, 3);
	load_objtiles((void *)spr_32x32x16_Bitmap, 25, 16, 3);
	load_objtiles((void *)spr_64x64x16_Bitmap, 41, 64, 3);

	set_oam_size(0, OAM_SIZE_8x32);
	set_oam_shape(0, OAM_SHAPE_TALL);
	set_oam_colmod(0, OAM_COLMOD_256);
	set_oam_x(0, 50);
	set_oam_y(0, 50);
	set_oam_tile(0, 0);

	set_oam_size(1, OAM_SIZE_32x16);
	set_oam_shape(1, OAM_SHAPE_WIDE);
	set_oam_colmod(1, OAM_COLMOD_256);
	set_oam_x(1, 100);
	set_oam_y(1, 50);
	set_oam_tile(1, 8);

	set_oam_size(2, OAM_SIZE_8x8);
	set_oam_shape(2, OAM_SHAPE_SQUARE);
	set_oam_colmod(2, OAM_COLMOD_16);
	set_oam_pal(2, 0);
	set_oam_x(2, 150);
	set_oam_y(2, 50);
	set_oam_tile(2, 24);

	set_oam_size(3, OAM_SIZE_32x32);
	set_oam_shape(3, OAM_SHAPE_SQUARE);
	set_oam_colmod(3, OAM_COLMOD_16);
	set_oam_pal(3, 0);
	set_oam_x(3, 50);
	set_oam_y(3, 100);
	set_oam_tile(3, 25);

	set_oam_size(4, OAM_SIZE_64x64);
	set_oam_shape(4, OAM_SHAPE_SQUARE);
	set_oam_colmod(4, OAM_COLMOD_16);
	set_oam_pal(4, 8);
	set_oam_x(4, 100);
	set_oam_y(4, 80);
	set_oam_tile(4, 41);
	set_oam_rotscale(4, TRUE);
	set_oam_dblsize(4, TRUE);
	set_oam_rotindex(4, 0);

	s16 angle = 45;     // degrees
	u16 x_scale = 300;  // percentage
	u16 y_scale = 300;

	fixed fx_scale = int2fixed(x_scale);
	fixed fy_scale = int2fixed(y_scale);

	fx_scale /= 100;
	fx_scale = fixeddiv(int2fixed(1), fx_scale);

	fy_scale /= 100;
	fy_scale = fixeddiv(int2fixed(1), fy_scale);

	set_rotdata_pa(0, fixedmul(fx_scale, math_cos(angle)));
	set_rotdata_pb(0, fixedmul(fy_scale, math_sin(angle)));
	set_rotdata_pc(0, fixedmul(fx_scale, -math_sin(angle)));
	set_rotdata_pd(0, fixedmul(fy_scale, math_cos(angle)));

	oam_dump(0, 10);

	while (1) {
	}
}

