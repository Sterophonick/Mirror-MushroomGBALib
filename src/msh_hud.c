
/*---------------------------------------------------------------------------*
 *  INCLUDES                                                                 *
 *---------------------------------------------------------------------------*/

#include <mushroom/msh_hud.h>

/*---------------------------------------------------------------------------*
 *  VARIABLES                                                                *
 *---------------------------------------------------------------------------*/

char _hud_string[256];

struct {
    u8	obj;			// Starting sprite index (uses 4 sprites)
	u8	pal;			// Palette
    u8	y_offset;		// HUD Y Position (in pixels)
	u16	tile_offset;	// Starting sprite tile (uses 256 tiles)
} _hud_vars;

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

void set_hud_y_offset (u8 y_offset) {
    u32 i;

    _hud_vars.y_offset = y_offset;

    for (i = _hud_vars.obj; i < _hud_vars.obj + 4; i++) {
        set_oam_y(i, y_offset);
    }
}


void hud_init (u8 obj, u8 pal, u8 y_offset, u16 tile_offset) {
    u32 i;

    _hud_vars.obj         = obj;
	_hud_vars.pal         = pal;
    _hud_vars.y_offset    = y_offset;
    _hud_vars.tile_offset = tile_offset;

    for (i = obj; i < obj + 4; i++) {
        set_oam_size(i, OAM_SIZE_64x64);
        set_oam_shape(i, OAM_SHAPE_SQUARE);
        set_oam_colmod(i, OAM_COLMOD_16);
        set_oam_x(i, (i - obj) << 6);
        set_oam_y(i, y_offset);
        set_oam_tile(i, tile_offset + ((i - obj) << 6));
		set_oam_prio(i, 0);
    }

	set_objpal_color((pal << 4) + 1, RGB(31, 31, 31));
	set_objpal_color((pal << 4) + 2, RGB(0, 0, 0));

	hud_clear_all();
}


void hud_show (bool show) {
	u32 i;
	u8 y;

	if (show == TRUE) {
		y = _hud_vars.y_offset;
	} else {
		y = 160;
	}

    for (i = _hud_vars.obj; i < _hud_vars.obj + 4; i++) {
        set_oam_y(i, y);
    }
}


void hud_clear_line (u8 y) {
	u32 x;
	void *dst;

	for (x = 0; x < MSH_HUD_WIDTH; x++) {
		dst = (void *)(MEM_OBJ + (_hud_vars.tile_offset << 5) + ((x & 7) << 5) + (y << 8) + ((x >> 3) << 11));
		DMASET32(3, dst, 0, 8);
	}
}


void hud_clear_all () {
	DMASET32(3, (void *)(MEM_OBJ + (_hud_vars.tile_offset << 5)), 0, 0x800);
}


void _hud_print (u8 x, u8 y, char *text) {
	void *dst;
	void *src;

	while ((*text != 0) && (y < MSH_HUD_HEIGHT)) {
		if (*text == '\n') {
			y++;
			x = 0;
		} else {
			// Get address of the required font tile
			src = (void *)(font_milkbottle_Bitmap + (fontmap_milkbottle[(u8)*text] << 5));

			// Determine where it needs to go in VRAM
			dst = (void *)(MEM_OBJ + (_hud_vars.tile_offset << 5) + ((x & 7) << 5) + (y << 8) + ((x >> 3) << 11));

			// Copy tile to VRAM
			DMACPY32(3, dst, src, 8);

			x++;

			if (x >= MSH_HUD_WIDTH) {
				y++;
				x = 0;
			}
		}

		text++;
    }
}

