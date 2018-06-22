
#define MSH_DEBUG
#include <mushroom/mushroom.h>

void AgbMain () {
	sound_on();

	set_sound_leftvol(7);
	set_sound_rightvol(7);

	set_sound4_left(TRUE);
	set_sound4_right(TRUE);

	set_sound_output(SND_OUTPUT_100);

	set_sound4cnt_l(0, 7, SND4_ENVMODE_DEC, 15);
	set_sound4cnt_h(SND4_DIV_Fd2, SND4_STAGES_7, SND4_PRESTEP_2p8, SND4_TIMED_CONT, TRUE);

	while (1) {
	}
}

