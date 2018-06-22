
#define MSH_DEBUG
#include <mushroom/mushroom.h>

void AgbMain () {
	sound_on();

	set_sound_leftvol(7);
	set_sound_rightvol(7);

	set_sound2_left(TRUE);
	set_sound2_right(TRUE);

	set_sound_output(SND_OUTPUT_100);

	set_sound2cnt_l(0, SND2_WAVEDUTY_50, 7, SND2_ENVMODE_DEC, 15);
	set_sound2cnt_h(0x400, SND2_TIMED_CONT, TRUE);

	while (1) {
	}
}

