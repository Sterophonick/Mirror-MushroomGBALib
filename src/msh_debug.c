
/*---------------------------------------------------------------------------*
 *  INCLUDES                                                                 *
 *---------------------------------------------------------------------------*/

#include <mushroom/msh_debug.h>

/*---------------------------------------------------------------------------*
 *  VARIABLES                                                                *
 *---------------------------------------------------------------------------*/

char _dbg_string[256];

struct {
	void	*mapdata;
	u8		 pal;
	char	*fontmap;
	u16		 tile_offset;	// The starting tile in VRAM of the font tileset
	u16		 mapwidth;
} _dtext_vars;

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

void _assert (bool cond, char *msg, char *exp, char *file, u32 line) {
	char *fslash;
	char *bslash;
	char *filename;
	u32 i;

	if (cond) {return;}

	// remove the path from the file string
	fslash = strrchr(file, '/');
	bslash = strrchr(file, '\\');
	filename = fslash > bslash ? fslash : bslash;
	if (filename == NULL) {filename = file;} else {filename++;}

	REG_IME = 0;  // disable irq
	set_disp_frcblk(TRUE);
	set_disp_mode(0);
	set_disp_obj(FALSE);
	set_disp_bg0(FALSE);
	set_disp_bg1(FALSE);
	set_disp_bg2(FALSE);
	set_disp_bg3(FALSE);
	set_disp_win0(FALSE);
	set_disp_win1(FALSE);
	set_disp_objwin(FALSE);
	set_bgpal_color(0, RGB(0, 0, 31));
	set_disp_frcblk(FALSE);

	set_bg_hofs(0, 0);
	set_bg_vofs(0, 0);

	dtext_init(31, 32, 0, 0);

	set_bgpal_color(2, RGB(0, 0, 31));

	// Clear the screen
	for (i = 0; i <= 19; i++) {
		dtext(0, i, "                              ");
	}

	dtext(9, 1, "Mushroom %u.%u", MSH_VER_MAJOR, MSH_VER_MINOR);
	dtext(1, 4, "Assert failed");
	dtext(1, 6, "%s", exp);
	dtext(1, 9, "%s", msg);
	dtext(1, 12, "File: %s", filename);
	dtext(1, 13, "Line: %u", line);
	dtext(10, 16, "GAME OVER");

	set_bg_size(0, BG_SIZE_256x256);
	set_bg_colmod(0, BG_COLMOD_16);
	set_bg_tilebase(0, 0);
	set_bg_mapbase(0, 31);
	set_bg_mosaic(0, FALSE);

	set_disp_bg0(TRUE);

	while (1) {
	}
}


void print_vba_thb (char *msg) {
	__asm__ volatile (
		"mov r0, %0;"
		"swi 0xFF;"
		: // no output
		: "r" (msg)
		: "r0"
	);
}


void print_vba_arm (char *msg) {
	__asm__ volatile (
		"mov r0, %0;"
		"swi 0xFF0000;"
		: // no output
		: "r" (msg)
		: "r0"
	);
}


void print_mappy (const char *msg) {
	__asm__ volatile (
		"mov r2, %0;"
		"ldr r0, =0xC0DED00D;"
		"mov r1, #0;"
		"and r0, r0, r0;"
		: // no output
		: "r" (msg)
		: "r0", "r1", "r2"
	);
}


void _dtext (u16 x, u16 y, char *text) {
	u16 *map_dst	= (u16 *)_dtext_vars.mapdata;
	u8 pal			= _dtext_vars.pal;
	char *fontmap	= _dtext_vars.fontmap;
	u16 tile_offset	= _dtext_vars.tile_offset;
	u16 dw			= _dtext_vars.mapwidth;
	u32 i = 0;
	u32 ox = x;
	char c;

	map_dst += (y * dw) + x;

	while (text[i] != 0) {
		c = text[i];

		if (c == '\n') {
			map_dst += dw - ox;
			ox = 0;
		} else {
			*map_dst = BG_TILE(fontmap[(u8)c] + tile_offset, pal, FALSE, FALSE);
			map_dst++;
			ox++;
		}

		i++;
	}
}


inline void set_dtext_mapdata (void *mapdata) {
	_dtext_vars.mapdata = mapdata;
}


inline void set_dtext_pal (u8 pal) {
	_dtext_vars.pal = pal;
}


inline void set_dtext_fontmap (char *fontmap) {
	_dtext_vars.fontmap = fontmap;
}


inline void set_dtext_tile_offset (u16 tile_offset) {
	_dtext_vars.tile_offset = tile_offset;
}


inline void set_dtext_mapwidth (u16 mapwidth) {
	_dtext_vars.mapwidth = mapwidth;
}


inline void *get_dtext_mapdata () {
	return _dtext_vars.mapdata;
}


inline u8 get_dtext_pal () {
	return _dtext_vars.pal;
}


inline char *get_dtext_fontmap () {
	return _dtext_vars.fontmap;
}


inline u16 get_dtext_tile_offset () {
	return _dtext_vars.tile_offset;
}


inline u16 get_dtext_mapwidth () {
	return _dtext_vars.mapwidth;
}


void dtext_init (u8 mapbase, u16 mapwidth, u8 pal, u16 tile_offset) {
	set_bgpal_color((pal << 4) + 1, RGB(31, 31, 31));
	set_bgpal_color((pal << 4) + 2, RGB(0, 0, 0));

	load_bgtiles((void *)font_milkbottle_Bitmap, tile_offset, sizeof(font_milkbottle_Bitmap) >> 5, CPY_DMA3);

	set_dtext_mapdata((void *)BG_MAPBASE(mapbase));
	set_dtext_pal(pal);
	set_dtext_fontmap((char *)fontmap_milkbottle);
	set_dtext_tile_offset(tile_offset);
	set_dtext_mapwidth(mapwidth);
}


u32 get_ewram_avail () {
	void *test;
	u32 cur_max = 0;
	u32 block = 0x40000; // 256k

	while (1) {
		test = (void *)malloc(cur_max + block);

		if (test == NULL) {
			if (block == 1) {
				free(test);
				return cur_max;
			}

			block = block >> 1;
		} else {
			cur_max += block;
		}

		free(test);
	}
}


void hexdump (void *addr, u32 length) {
	u32 i;
	u8 *data;
	char line[81];
	u32 off;

	while (length > 0) {
		data = (u8 *)addr;
		off = 0;

		sprintf(line, "%08X  ", (u32)addr);
		off += 10;

		for (i = 0; i < 16; i++) {
			if (i < length) {
				sprintf(line + off, "%02X ", data[i]);
			} else {
				sprintf(line + off, "   ");
			}

			off += 3;
		}

		for (; off < 59; off++) {
			line[off] = ' ';
		}

		for (i = 0; i < 16; i++) {
			if (i < length) {
				if ((data[i] >= 32) && (data[i] <= 126)) {
					line[off] = data[i];
				} else {
					line[off] = '.';
				}
			} else {
				line[off] = ' ';
			}

			off++;
		}

		line[off] = '\n';
		off++;
		line[off] = '\0';

		dprint(line);

		if (length > 16) {
			length -= 16;
			addr = (void *)((u8 *)addr + 16);
		} else {
			length = 0;
		}
	}
}


void bitdump (void *addr, u32 length) {
	u32 i, j;
	u8 *data;
	char line[81];
	u32 off;

	while (length > 0) {
		data = (u8 *)addr;
		off = 0;

		sprintf(line, "%08X  ", (u32)addr);
		off += 10;

		for (i = 0; i < 4; i++) {
			if (i < length) {
				for (j = 0; j < 8; j++) {
					if (data[i] & (1 << (7 - j))) {
						line[off] = '1';
					} else {
						line[off] = '0';
					}

					off++;

					if (j == 3) {
						line[off] = ' ';
						off++;
					}
				}
			} else {
			}

			line[off] = ' '; off++;
			line[off] = ' '; off++;
		}

		line[off] = '\n';
		off++;
		line[off] = '\0';

		dprint(line);

		if (length > 4) {
			length -= 4;
			addr = (void *)((u8 *)addr + 4);
		} else {
			length = 0;
		}
	}
}

