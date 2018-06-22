
#define MSH_DEBUG
#include <mushroom/mushroom.h>

void AgbMain () {
	sound_on();

	set_sound_leftvol(7);
	set_sound_rightvol(7);

	set_sound1_left(TRUE);
	set_sound1_right(TRUE);

	set_sound_output(SND_OUTPUT_100);

	set_sound1cnt_l(6, SND1_SWPMODE_INC, SND1_SWPTIME_39_1);
	set_sound1cnt_h(0, SND1_WAVEDUTY_50, 7, SND1_ENVMODE_INC, 15);
	set_sound1cnt_x(0x400, SND1_TIMED_CONT, TRUE);

	while (1) {
	}
}

