
#define MSH_DEBUG
#include <mushroom/mushroom.h>

extern const u32 _binary_lo1234_pcm_start[];  // The sample, 8bit signed, 16Khz


void EventTimer1 () {
	// Sample finished! Stop Direct sound

	set_timer_cnt(0, 0);  // Disable Timer 0
	set_dma_cnt_h(1, 0);  // Stop DMA
}


void AgbMain () {
	// Play a mono sound at 16khz
	// Uses timer 0 as sampling rate source
	// Uses timer 1 to count the samples played in order to stop the sound

	irq_init();
	set_irq_func(IRQ_TIM1, EventTimer1);

	sound_on();

	set_sound_leftvol(7);
	set_sound_rightvol(7);

	set_sounda_output(SNDA_OUTPUT_100);
	set_sounda_left(TRUE);
	set_sounda_right(TRUE);
	set_sounda_timer(0);     // Use Timer 0 as the sample rate timer
	set_sounda_fifo(TRUE);

	dma(1, (void *)&REG_FIFO_A_L, (void *)_binary_lo1234_pcm_start, 0,
		DMA_ENABLE | DMA_START_FIFO | DMA_SIZE_32 | DMA_SRC_INC | DMA_DST_INC | DMA_REPEAT);

	set_timer_data(1, 0x7098);    // 0xFFFF - the number of samples to play
	set_timer_cnt(1, TIM_ENABLE | TIM_IRQ | TIM_CASCADE);

	irq_start(IRQ_TIM1);

	// Formula for playback frequency is: 0xFFFF - round(cpuFreq / playbackFreq)
	set_timer_data(0, 0xFBE8);    // 16khz playback freq
	set_timer_cnt(0, TIM_ENABLE);

	while (1) {
	}
}

