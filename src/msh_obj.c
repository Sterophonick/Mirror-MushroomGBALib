
/*---------------------------------------------------------------------------*
 *  INCLUDES                                                                 *
 *---------------------------------------------------------------------------*/

#include <mushroom/msh_obj.h>

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

u8 get_oam_width_tl (u8 obj) {
	u8 shape = get_oam_shape(obj);
	u8 size = get_oam_size(obj);
	return _oam_size_table[shape][size][0];
}


u8 get_oam_height_tl (u8 obj) {
	u8 shape = get_oam_shape(obj);
	u8 size = get_oam_size(obj);
	return _oam_size_table[shape][size][1];
}


u8 get_oam_width_px (u8 obj) {
	return TL_TO_PX(get_oam_width_tl(obj));
}


u8 get_oam_height_px (u8 obj) {
	return TL_TO_PX(get_oam_height_tl(obj));
}


u8 get_oam_tilevol (u8 obj) {
	u8 shape = get_oam_shape(obj);
	u8 size = get_oam_size(obj);
	bool colmod = get_oam_colmod(obj);

	return (_oam_size_table[shape][size][0] * _oam_size_table[shape][size][1]) << colmod;
}


void hide_objs (u8 start, u8 length) {
	u32 i;
	u32 *oam = ((u32 *)MEM_OAM) + (start << 1);

	for (i = 0; i < length; i++) {
		*oam &= 0xFE00FF00;  // Clear X and Y
		*oam |= 0x00F000A0;  // Set X to 240 and Y to 160
		oam += 2;
	}
}


void oam_dump (u8 start, u8 length) {
	u32 i;
	u8 y; bool rotscale; bool dblsize; u8 bldmod; bool mosaic; bool colmod;
	u16 x; u8 rotindex; bool hflip; bool vflip;
	u16 tile; u8 prio; u8 pal;
	u8 width;
	u8 height;
	char str_colmod[4];
	char str_size[6];
	char str_attr[7];

	for (i = start; i < length; i++) {
		y        = get_oam_y(i);
		rotscale = get_oam_rotscale(i);
		dblsize  = get_oam_dblsize(i);
		bldmod   = get_oam_bldmod(i);
		mosaic   = get_oam_mosaic(i);
		colmod   = get_oam_colmod(i);
		x        = get_oam_x(i);
		rotindex = get_oam_rotindex(i);
		hflip    = get_oam_hflip(i);
		vflip    = get_oam_vflip(i);
		tile     = get_oam_tile(i);
		prio     = get_oam_prio(i);
		pal      = get_oam_pal(i);
		width    = get_oam_width_px(i);
		height   = get_oam_height_px(i);

		if (colmod == OAM_COLMOD_16) {
			strcpy(str_colmod, "16");
		} else {
			strcpy(str_colmod, "256");
		}

		sprintf(str_size, "%ux%u", width, height);

		str_attr[1] = dblsize ? 'd' : '-';
		str_attr[2] = mosaic ? 'm' : '-';

		// If rotate/scale is enabled then hflip and vflip don't apply
		if (rotscale) {
			str_attr[0] = 'r';
			str_attr[3] = '-';
			str_attr[4] = '-';
		} else {
			str_attr[0] = '-';
			str_attr[3] = hflip ? 'h' : '-';
			str_attr[4] = vflip ? 'v' : '-';
		}

		switch (bldmod) {
			case OAM_BLDMOD_NORMAL:
				str_attr[5] = 'n';
				break;
			case OAM_BLDMOD_SEMITRANS:
				str_attr[5] = 's';
				break;
			case OAM_BLDMOD_OBJWIN:
				str_attr[5] = 'o';
				break;
		}

		dprintf("%03u: %-5s  %-3s  (%3u,%3u)  tile:%-4u  pal:%-2u  rot:%-2u  pr:%u  %s\n",
				i, str_size, str_colmod, x, y, tile, pal, rotindex, prio, str_attr);
	}
}

