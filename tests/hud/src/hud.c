
#define MSH_DEBUG
#include <mushroom/mushroom.h>

bool show_hud = TRUE;

void EventVbl () {
	key_update();

	if (key_pressed(KEY_R)) {
		show_hud = !show_hud;
		hud_show(show_hud);
	}
}

void AgbMain () {
	set_disp_frcblk(TRUE);
	set_disp_mode(0);
	set_disp_frcblk(FALSE);

	set_disp_bg0(TRUE);
	set_bgpal_color(0, RGB(25, 25, 25));

	set_disp_objmap(DISP_OBJMAP_1D);

	// Clear OAM
	u32 i;
	for (i = 0; i <= 127; i++) {
		set_oam_y(i, 160);
	}

	set_disp_obj(TRUE);

	hud_init(0, 0, 160 - 64, 0);

	hud_print(0, 0, "..HUD PRINTER ................");
	hud_print(0, 1, ".                            .");
	hud_print(0, 2, ". THIS USES 4 64x64          .");
	hud_print(0, 3, ". SPRITES INSTEAD OF A       .");
	hud_print(0, 4, ". BACKGROUND LAYER.          .");
	hud_print(0, 5, ".                            .");
	hud_print(0, 6, ". PRESS R TO SHOW/HIDE       .");
	hud_print(0, 7, "..............................");

	irq_init();
	set_irq_func(IRQ_VBL, EventVbl);
	irq_start(IRQ_VBL);

	while (1) {
	}
}

