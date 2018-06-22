
#define MSH_DEBUG
#include <mushroom/mushroom.h>

void AgbMain () {
	sound_on();

	set_sound_leftvol(7);
	set_sound_rightvol(7);

	set_sound3_left(TRUE);
	set_sound3_right(TRUE);

	set_sound_output(SND_OUTPUT_100);

	// Switch to bank 1 which selects bank 0 for writing
	set_sound3cnt_l(SND3_BANKMODE_2x32, 1, TRUE);

 	// Load the wave ram bank 0
	REG_WAVE_RAM0 = 0x10325476;
	REG_WAVE_RAM1 = 0x98badcfe;
	REG_WAVE_RAM2 = 0x10325476;
	REG_WAVE_RAM3 = 0x98badcfe;

	// Switch to bank 0
	set_sound3cnt_l(SND3_BANKMODE_2x32, 0, TRUE);

	set_sound3cnt_h(0, SND3_OUTPUT_100);
	set_sound3cnt_x(1046, SND3_TIMED_CONT, TRUE);

	while (1) {
	}
}

