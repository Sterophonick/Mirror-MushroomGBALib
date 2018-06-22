
/*---------------------------------------------------------------------------*
 *  INCLUDES                                                                 *
 *---------------------------------------------------------------------------*/

#include <mushroom/msh_bitmap.h>

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

void load_bitmap (void *data, bool frmbuf, u8 channel) {
	u32 size = 0;
	u8 mode = get_disp_mode();

	assert((mode >= 3) && (mode <= 5), "Mode must be 3..5");

	if (mode == 3) {  // 240x160x16
		size = 0x12C00;
	} else if (mode == 4) { // 240x160x8
		size = 0x9600;
	} else if (mode == 5) { // 160x128x16
		size = 0xA000;
	}

	dmemcpy(channel, (void *)(MEM_BG + (frmbuf * 0xA000)), data, size);
}

