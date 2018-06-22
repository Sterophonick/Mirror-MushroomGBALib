
/*---------------------------------------------------------------------------*
 *  INCLUDES                                                                 *
 *---------------------------------------------------------------------------*/

#include <mushroom/msh_sram.h>

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

void save_to_sram (void *data, u8 slot, u16 size, u16 offset) {
	u32 i;
	u8 *data_ptr = (u8 *)data;
	u8 *sram_ptr = (u8 *)MEM_SRAM;

	sram_ptr += (size * slot) + offset;

	for (i = 0; i < size; i++) {
		*sram_ptr = *data_ptr;
		sram_ptr++;
		data_ptr++;
	}
}


u8 sram_exists (char save_id[], u8 id_len, u8 slot, u16 size, u16 offset) {
	u32 i;
	u8 exists = TRUE;
	u8 *sram_ptr = (u8 *)MEM_SRAM;

	sram_ptr += (size * slot) + offset;

	for (i = 0; i < id_len; i++) {
		if (*sram_ptr != save_id[i]) {
			exists = FALSE;
		}

		sram_ptr++;
	}

	return exists;
}


void load_from_sram (void *data, u8 slot, u16 size, u16 offset) {
	u32 i;
	u8 *data_ptr = (u8 *)data;
	u8 *sram_ptr = (u8 *)MEM_SRAM;

	sram_ptr += (size * slot) + offset;

	for (i = 0; i < size; i++) {
		*data_ptr = *sram_ptr;
		sram_ptr++;
		data_ptr++;
	}
}


void erase_sram (u16 num_erasebytes, u8 slot, u16 size, u16 offset) {
	u32 i;
	u8 *sram_ptr = (u8 *)MEM_SRAM;

	sram_ptr += (size * slot) + offset;

	for (i = 0; i < num_erasebytes; i++) {
		*sram_ptr = 0;
		sram_ptr++;
	}
}

