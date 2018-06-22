/*!
 *  @file   msh_sound.h
 *  @brief  Sound functions
 */

#ifndef MSH_SOUND_H
#define MSH_SOUND_H

/*---------------------------------------------------------------------------*
 *  DEFINES                                                                  *
 *---------------------------------------------------------------------------*/

/*!
 *  @defgroup  SND_OUTPUT  Sound Output
 *  <b>Sound Output defines:</b><br>
 *  @code
 */
#define SND_OUTPUT_25			0
#define SND_OUTPUT_50			1
#define SND_OUTPUT_100			2
/*! @endcode @{ @} */

/*!
 *  @defgroup  SNDA_OUTPUT  Sound A Output
 *  <b>Sound A Output defines:</b><br>
 *  @code
 */
#define SNDA_OUTPUT_50			0
#define SNDA_OUTPUT_100			1
/*! @endcode @{ @} */

/*!
 *  @defgroup  SNDB_OUTPUT  Sound B Output
 *  <b>Sound B Output defines:</b><br>
 *  @code
 */
#define SNDB_OUTPUT_50			0
#define SNDB_OUTPUT_100			1
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND1_SWPMODE  Sound 1 Sweep Mode
 *  <b>Sound 1 Sweep Mode defines:</b><br>
 *  @code
 */
#define SND1_SWPMODE_INC		0
#define SND1_SWPMODE_DEC		1
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND1_SWPTIME  Sound 1 Sweep Time
 *  <b>Sound 1 Sweep Time defines:</b><br>
 *  @code
 */
#define SND1_SWPTIME_OFF		0
#define SND1_SWPTIME_7_8		1
#define SND1_SWPTIME_15_6		2
#define SND1_SWPTIME_23_4		3
#define SND1_SWPTIME_31_3		4
#define SND1_SWPTIME_39_1		5
#define SND1_SWPTIME_46_9		6
#define SND1_SWPTIME_54_7		7
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND1_WAVEDUTY  Sound 1 Wave Duty
 *  <b>Sound 1 Wave Duty defines:</b><br>
 *  @code
 */
#define SND1_WAVEDUTY_12_5		0
#define SND1_WAVEDUTY_25		1
#define SND1_WAVEDUTY_50		2
#define SND1_WAVEDUTY_75		3
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND1_ENVMODE  Sound 1 Envelope Mode
 *  <b>Sound 1 Envelope Mode defines:</b><br>
 *  @code
 */
#define SND1_ENVMODE_DEC		0
#define SND1_ENVMODE_INC		1
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND1_TIMED  Sound 1 Timed
 *  <b>Sound 1 Timed defines:</b><br>
 *  @code
 */
#define SND1_TIMED_CONT			0
#define SND1_TIMED_TIMED		1
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND2_WAVEDUTY  Sound 2 Wave Duty
 *  <b>Sound 2 Wave Duty defines:</b><br>
 *  @code
 */
#define SND2_WAVEDUTY_12_5		0
#define SND2_WAVEDUTY_25		1
#define SND2_WAVEDUTY_50		2
#define SND2_WAVEDUTY_75		3
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND2_ENVMODE  Sound 2 Envelope Mode
 *  <b>Sound 2 Envelope Mode defines:</b><br>
 *  @code
 */
#define SND2_ENVMODE_DEC		0
#define SND2_ENVMODE_INC		1
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND2_TIMED  Sound 2 Timed
 *  <b>Sound 2 Timed defines:</b><br>
 *  @code
 */
#define SND2_TIMED_CONT			0
#define SND2_TIMED_TIMED		1
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND3_BANKMODE  Sound 3 Bank Mode
 *  <b>Sound 3 Bank Mode defines:</b><br>
 *  @code
 */
#define SND3_BANKMODE_2x32		0
#define SND3_BANKMODE_1x64		1
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND3_OUTPUT  Sound 3 Output
 *  <b>Sound 3 Output defines:</b><br>
 *  @code
 */
#define SND3_OUTPUT_MUTE		0
#define SND3_OUTPUT_100			1
#define SND3_OUTPUT_75			4
#define SND3_OUTPUT_50			2
#define SND3_OUTPUT_25			3
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND3_TIMED  Sound 3 Timed
 *  <b>Sound 3 Timed defines:</b><br>
 *  @code
 */
#define SND3_TIMED_CONT			0
#define SND3_TIMED_TIMED		1
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND4_ENVMODE  Sound 4 Envelope Mode
 *  <b>Sound 4 Envelope Mode defines:</b><br>
 *  @code
 */
#define SND4_ENVMODE_DEC		0
#define SND4_ENVMODE_INC		1
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND4_DIV  Sound 4 Div
 *  <b>Sound 4 Div defines:</b><br>
 *  @code
 */
#define SND4_DIV_Fx2			0
#define SND4_DIV_F				1
#define SND4_DIV_Fd2			2
#define SND4_DIV_Fd3			3
#define SND4_DIV_Fd4			4
#define SND4_DIV_Fd5			5
#define SND4_DIV_Fd6			6
#define SND4_DIV_Fd7			7
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND4_STAGES  Sound 4 Stages
 *  <b>Sound 4 Stages defines:</b><br>
 *  @code
 */
#define SND4_STAGES_15			0
#define SND4_STAGES_7			1
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND4_PRESTEP  Sound 4 Pre-Step
 *  <b>Sound 4 Pre-Step defines:</b><br>
 *  @code
 */
#define SND4_PRESTEP_2			0
#define SND4_PRESTEP_2p2		1
#define SND4_PRESTEP_2p3		2
#define SND4_PRESTEP_2p4		3
#define SND4_PRESTEP_2p5		4
#define SND4_PRESTEP_2p6		5
#define SND4_PRESTEP_2p7		6
#define SND4_PRESTEP_2p8		7
#define SND4_PRESTEP_2p9		8
#define SND4_PRESTEP_2p10		9
#define SND4_PRESTEP_2p11		10
#define SND4_PRESTEP_2p12		11
#define SND4_PRESTEP_2p13		12
#define SND4_PRESTEP_2p14		13
/*! @endcode @{ @} */

/*!
 *  @defgroup  SND4_TIMED  Sound 4 Timed
 *  <b>Sound 4 Timed defines:</b><br>
 *  @code
 */
#define SND4_TIMED_CONT			0
#define SND4_TIMED_TIMED		1
/*! @endcode @{ @} */

/*---------------------------------------------------------------------------*
 *  BIT DEFINES                                                              *
 *---------------------------------------------------------------------------*/

// REG_SOUNDCNT_L

#define _SND_LEFTVOL_POS		0
#define _SND_LEFTVOL_BITS		0x0007    // 0000 0000 0000 0111
#define _SND_LEFTVOL_MASK		0xFFF8    // 1111 1111 1111 1000

#define _SND_RIGHTVOL_POS		4
#define _SND_RIGHTVOL_BITS		0x0070    // 0000 0000 0111 0000
#define _SND_RIGHTVOL_MASK		0xFF8F    // 1111 1111 1000 1111

#define _SND1_LEFT_POS			8
#define _SND1_LEFT_BITS			0x0100    // 0000 0001 0000 0000
#define _SND1_LEFT_MASK			0xFEFF    // 1111 1110 1111 1111

#define _SND2_LEFT_POS			9
#define _SND2_LEFT_BITS			0x0200    // 0000 0010 0000 0000
#define _SND2_LEFT_MASK			0xFDFF    // 1111 1101 1111 1111

#define _SND3_LEFT_POS			10
#define _SND3_LEFT_BITS			0x0400    // 0000 0100 0000 0000
#define _SND3_LEFT_MASK			0xFBFF    // 1111 1011 1111 1111

#define _SND4_LEFT_POS			11
#define _SND4_LEFT_BITS			0x0800    // 0000 1000 0000 0000
#define _SND4_LEFT_MASK			0xF7FF    // 1111 0111 1111 1111

#define _SND1_RIGHT_POS			12
#define _SND1_RIGHT_BITS		0x1000    // 0001 0000 0000 0000
#define _SND1_RIGHT_MASK		0xEFFF    // 1110 1111 1111 1111

#define _SND2_RIGHT_POS			13
#define _SND2_RIGHT_BITS		0x2000    // 0010 0000 0000 0000
#define _SND2_RIGHT_MASK		0xDFFF    // 1101 1111 1111 1111

#define _SND3_RIGHT_POS			14
#define _SND3_RIGHT_BITS		0x4000    // 0100 0000 0000 0000
#define _SND3_RIGHT_MASK		0xBFFF    // 1011 1111 1111 1111

#define _SND4_RIGHT_POS			15
#define _SND4_RIGHT_BITS		0x8000    // 1000 0000 0000 0000
#define _SND4_RIGHT_MASK		0x7FFF    // 0111 1111 1111 1111

// REG_SOUNDCNT_H

#define _SND_OUTPUT_POS			0
#define _SND_OUTPUT_BITS		0x0003    // 0000 0000 0000 0011
#define _SND_OUTPUT_MASK		0xFFFC    // 1111 1111 1111 1100

#define _SNDA_OUTPUT_POS		2
#define _SNDA_OUTPUT_BITS		0x0004    // 0000 0000 0000 0100
#define _SNDA_OUTPUT_MASK		0xFFFB    // 1111 1111 1111 1011

#define _SNDB_OUTPUT_POS		3
#define _SNDB_OUTPUT_BITS		0x0008    // 0000 0000 0000 1000
#define _SNDB_OUTPUT_MASK		0xFFF7    // 1111 1111 1111 0111

#define _SNDA_RIGHT_POS			8
#define _SNDA_RIGHT_BITS		0x0100    // 0000 0001 0000 0000
#define _SNDA_RIGHT_MASK		0xFEFF    // 1111 1110 1111 1111

#define _SNDA_LEFT_POS			9
#define _SNDA_LEFT_BITS			0x0200    // 0000 0010 0000 0000
#define _SNDA_LEFT_MASK			0xFDFF    // 1111 1101 1111 1111

#define _SNDA_TIMER_POS			10
#define _SNDA_TIMER_BITS		0x0400    // 0000 0100 0000 0000
#define _SNDA_TIMER_MASK		0xFBFF    // 1111 1011 1111 1111

#define _SNDA_FIFO_POS			11
#define _SNDA_FIFO_BITS			0x0800    // 0000 1000 0000 0000
#define _SNDA_FIFO_MASK			0xF7FF    // 1111 0111 1111 1111

#define _SNDB_RIGHT_POS			12
#define _SNDB_RIGHT_BITS		0x1000    // 0001 0000 0000 0000
#define _SNDB_RIGHT_MASK		0xEFFF    // 1110 1111 1111 1111

#define _SNDB_LEFT_POS			13
#define _SNDB_LEFT_BITS			0x2000    // 0010 0000 0000 0000
#define _SNDB_LEFT_MASK			0xDFFF    // 1101 1111 1111 1111

#define _SNDB_TIMER_POS			14
#define _SNDB_TIMER_BITS		0x4000    // 0100 0000 0000 0000
#define _SNDB_TIMER_MASK		0xBFFF    // 1011 1111 1111 1111

#define _SNDB_FIFO_POS			15
#define _SNDB_FIFO_BITS			0x8000    // 1000 0000 0000 0000
#define _SNDB_FIFO_MASK			0x7FFF    // 0111 1111 1111 1111

// REG_SOUNDCNT_X

#define _SND1_STAT_POS			0
#define _SND1_STAT_BITS			0x0001    // 0000 0000 0000 0001
#define _SND1_STAT_MASK			0xFFFE    // 1111 1111 1111 1110

#define _SND2_STAT_POS			1
#define _SND2_STAT_BITS			0x0002    // 0000 0000 0000 0010
#define _SND2_STAT_MASK			0xFFFD    // 1111 1111 1111 1101

#define _SND3_STAT_POS			2
#define _SND3_STAT_BITS			0x0004    // 0000 0000 0000 0100
#define _SND3_STAT_MASK			0xFFFB    // 1111 1111 1111 1011

#define _SND4_STAT_POS			3
#define _SND4_STAT_BITS			0x0008    // 0000 0000 0000 1000
#define _SND4_STAT_MASK			0xFFF7    // 1111 1111 1111 0111

#define _SND_ENABLE_POS			7
#define _SND_ENABLE_BITS		0x0080    // 0000 0000 1000 0000
#define _SND_ENABLE_MASK		0xFF7F    // 1111 1111 0111 1111

// REG_SOUND1CNT_L

#define _SND1_SWPSHIFTS_POS		0
#define _SND1_SWPSHIFTS_BITS	0x0007    // 0000 0000 0000 0111
#define _SND1_SWPSHIFTS_MASK	0xFFF8    // 1111 1111 1111 1000

#define _SND1_SWPMODE_POS		3
#define _SND1_SWPMODE_BITS		0x0008    // 0000 0000 0000 1000
#define _SND1_SWPMODE_MASK		0xFFF7    // 1111 1111 1111 0111

#define _SND1_SWPTIME_POS		4
#define _SND1_SWPTIME_BITS		0x0070    // 0000 0000 0111 0000
#define _SND1_SWPTIME_MASK		0xFF8F    // 1111 1111 1000 1111

// REG_SOUND1CNT_H

#define _SND1_LENGTH_POS		0
#define _SND1_LENGTH_BITS		0x003F    // 0000 0000 0011 1111
#define _SND1_LENGTH_MASK		0xFFC0    // 1111 1111 1100 0000

#define _SND1_WAVEDUTY_POS		6
#define _SND1_WAVEDUTY_BITS		0x00C0    // 0000 0000 1100 0000
#define _SND1_WAVEDUTY_MASK		0xFF3F    // 1111 1111 0011 1111

#define _SND1_ENVTIME_POS		8
#define _SND1_ENVTIME_BITS		0x0700    // 0000 0111 0000 0000
#define _SND1_ENVTIME_MASK		0xF8FF    // 1111 1000 1111 1111

#define _SND1_ENVMODE_POS		11
#define _SND1_ENVMODE_BITS		0x0800    // 0000 1000 0000 0000
#define _SND1_ENVMODE_MASK		0xF7FF    // 1111 0111 1111 1111

#define _SND1_ENVINIT_POS		12
#define _SND1_ENVINIT_BITS		0xF000    // 1111 0000 0000 0000
#define _SND1_ENVINIT_MASK		0x0FFF    // 0000 1111 1111 1111

// REG_SOUND1CNT_X

#define _SND1_FREQ_POS			0
#define _SND1_FREQ_BITS			0x07FF    // 0000 0111 1111 1111
#define _SND1_FREQ_MASK			0xF800    // 1111 1000 0000 0000

#define _SND1_TIMED_POS			14
#define _SND1_TIMED_BITS		0x4000    // 0100 0000 0000 0000
#define _SND1_TIMED_MASK		0xBFFF    // 1011 1111 1111 1111

#define _SND1_RESET_POS			15
#define _SND1_RESET_BITS		0x8000    // 1000 0000 0000 0000
#define _SND1_RESET_MASK		0x7FFF    // 0111 1111 1111 1111

// REG_SOUND2CNT_L

#define _SND2_LENGTH_POS		0
#define _SND2_LENGTH_BITS		0x003F    // 0000 0000 0011 1111
#define _SND2_LENGTH_MASK		0xFFC0    // 1111 1111 1100 0000

#define _SND2_WAVEDUTY_POS		6
#define _SND2_WAVEDUTY_BITS		0x00C0    // 0000 0000 1100 0000
#define _SND2_WAVEDUTY_MASK		0xFF3F    // 1111 1111 0011 1111

#define _SND2_ENVTIME_POS		8
#define _SND2_ENVTIME_BITS		0x0700    // 0000 0111 0000 0000
#define _SND2_ENVTIME_MASK		0xF8FF    // 1111 1000 1111 1111

#define _SND2_ENVMODE_POS		11
#define _SND2_ENVMODE_BITS		0x0800    // 0000 1000 0000 0000
#define _SND2_ENVMODE_MASK		0xF7FF    // 1111 0111 1111 1111

#define _SND2_ENVINIT_POS		12
#define _SND2_ENVINIT_BITS		0xF000    // 1111 0000 0000 0000
#define _SND2_ENVINIT_MASK		0x0FFF    // 0000 1111 1111 1111

// REG_SOUND2CNT_H

#define _SND2_FREQ_POS			0
#define _SND2_FREQ_BITS			0x07FF    // 0000 0111 1111 1111
#define _SND2_FREQ_MASK			0xF800    // 1111 1000 0000 0000

#define _SND2_TIMED_POS			14
#define _SND2_TIMED_BITS		0x4000    // 0100 0000 0000 0000
#define _SND2_TIMED_MASK		0xBFFF    // 1011 1111 1111 1111

#define _SND2_RESET_POS			15
#define _SND2_RESET_BITS		0x8000    // 1000 0000 0000 0000
#define _SND2_RESET_MASK		0x7FFF    // 0111 1111 1111 1111

// REG_SOUND3CNT_L

#define _SND3_BANKMODE_POS		5
#define _SND3_BANKMODE_BITS		0x0020    // 0000 0000 0010 0000
#define _SND3_BANKMODE_MASK		0xFFDF    // 1111 1111 1101 1111

#define _SND3_BANK_POS			6
#define _SND3_BANK_BITS			0x0040    // 0000 0000 0100 0000
#define _SND3_BANK_MASK			0xFFBF    // 1111 1111 1011 1111

#define _SND3_ENABLE_POS		7
#define _SND3_ENABLE_BITS		0x0080    // 0000 0000 1000 0000
#define _SND3_ENABLE_MASK		0xFF7F    // 1111 1111 0111 1111

// REG_SOUND3CNT_H

#define _SND3_LENGTH_POS		0
#define _SND3_LENGTH_BITS		0x00FF    // 0000 0000 1111 1111
#define _SND3_LENGTH_MASK		0xFF00    // 1111 1111 0000 0000

#define _SND3_OUTPUT_POS		13
#define _SND3_OUTPUT_BITS		0xE000    // 1110 0000 0000 0000
#define _SND3_OUTPUT_MASK		0x1FFF    // 0001 1111 1111 1111

// REG_SOUND3CNT_X

#define _SND3_FREQ_POS			0
#define _SND3_FREQ_BITS			0x07FF    // 0000 0111 1111 1111
#define _SND3_FREQ_MASK			0xF800    // 1111 1000 0000 0000

#define _SND3_TIMED_POS			14
#define _SND3_TIMED_BITS		0x4000    // 0100 0000 0000 0000
#define _SND3_TIMED_MASK		0xBFFF    // 1011 1111 1111 1111

#define _SND3_RESET_POS			15
#define _SND3_RESET_BITS		0x8000    // 1000 0000 0000 0000
#define _SND3_RESET_MASK		0x7FFF    // 0111 1111 1111 1111

// REG_SOUND4CNT_L

#define _SND4_LENGTH_POS		0
#define _SND4_LENGTH_BITS		0x003F    // 0000 0000 0011 1111
#define _SND4_LENGTH_MASK		0xFFC0    // 1111 1111 1100 0000

#define _SND4_ENVTIME_POS		8
#define _SND4_ENVTIME_BITS		0x0700    // 0000 0111 0000 0000
#define _SND4_ENVTIME_MASK		0xF8FF    // 1111 1000 1111 1111

#define _SND4_ENVMODE_POS		11
#define _SND4_ENVMODE_BITS		0x0800    // 0000 1000 0000 0000
#define _SND4_ENVMODE_MASK		0xF7FF    // 1111 0111 1111 1111

#define _SND4_ENVINIT_POS		12
#define _SND4_ENVINIT_BITS		0xF000    // 1111 0000 0000 0000
#define _SND4_ENVINIT_MASK		0x0FFF    // 0000 1111 1111 1111

// REG_SOUND4CNT_H

#define _SND4_DIV_POS			0
#define _SND4_DIV_BITS			0x0007    // 0000 0000 0000 0111
#define _SND4_DIV_MASK			0xFFF8    // 1111 1111 1111 1000

#define _SND4_STAGES_POS		3
#define _SND4_STAGES_BITS		0x0008    // 0000 0000 0000 1000
#define _SND4_STAGES_MASK		0xFFF7    // 1111 1111 1111 0111

#define _SND4_PRESTEP_POS		4
#define _SND4_PRESTEP_BITS		0x00F0    // 0000 0000 1111 0000
#define _SND4_PRESTEP_MASK		0xFF0F    // 1111 1111 0000 1111

#define _SND4_TIMED_POS			14
#define _SND4_TIMED_BITS		0x4000    // 0100 0000 0000 0000
#define _SND4_TIMED_MASK		0xBFFF    // 1011 1111 1111 1111

#define _SND4_RESET_POS			15
#define _SND4_RESET_BITS		0x8000    // 1000 0000 0000 0000
#define _SND4_RESET_MASK		0x7FFF    // 0111 1111 1111 1111

/*---------------------------------------------------------------------------*
 *  MACROS                                                                   *
 *---------------------------------------------------------------------------*/

// REG_SOUNDCNT_L

#define MAKE_SND_LEFTVOL(leftvol)  \
		((leftvol) << _SND_LEFTVOL_POS)

#define MAKE_SND_RIGHTVOL(rightvol) \
		((rightvol) << _SND_RIGHTVOL_POS)

#define MAKE_SND1_LEFT(enable)  \
		((enable) << _SND1_LEFT_POS)

#define MAKE_SND2_LEFT(enable)  \
		((enable) << _SND2_LEFT_POS)

#define MAKE_SND3_LEFT(enable)  \
		((enable) << _SND3_LEFT_POS)

#define MAKE_SND4_LEFT(enable)  \
		((enable) << _SND4_LEFT_POS)

#define MAKE_SND1_RIGHT(enable)  \
		((enable) << _SND1_RIGHT_POS)

#define MAKE_SND2_RIGHT(enable)  \
		((enable) << _SND2_RIGHT_POS)

#define MAKE_SND3_RIGHT(enable)  \
		((enable) << _SND3_RIGHT_POS)

#define MAKE_SND4_RIGHT(enable)  \
		((enable) << _SND4_RIGHT_POS)

#define MAKE_SOUNDCNT_L(leftvol, rightvol,					\
						left1, left2, left3, left4,			\
						right1, right2, right3, right4)		\
		(													\
		MAKE_SND_LEFTVOL((leftvol)) |						\
		MAKE_SND_RIGHTVOL((rightvol)) |						\
		MAKE_SND1_LEFT((left1)) |							\
		MAKE_SND2_LEFT((left2)) |							\
		MAKE_SND3_LEFT((left3)) |							\
		MAKE_SND4_LEFT((left4)) |							\
		MAKE_SND1_RIGHT((right1)) |							\
		MAKE_SND2_RIGHT((right2)) |							\
		MAKE_SND3_RIGHT((right3)) |							\
		MAKE_SND4_RIGHT((right4))							\
		)

#define GET_SND_LEFTVOL(soundcnt_l)  \
		(((soundcnt_l) & _SND_LEFTVOL_BITS) >> _SND_LEFTVOL_POS)

#define GET_SND_RIGHTVOL(soundcnt_l)  \
		(((soundcnt_l) & _SND_RIGHTVOL_BITS) >> _SND_RIGHTVOL_POS)

#define GET_SND1_LEFT(soundcnt_l)  \
		(((soundcnt_l) & _SND1_LEFT_BITS) >> _SND1_LEFT_POS)

#define GET_SND2_LEFT(soundcnt_l)  \
		(((soundcnt_l) & _SND2_LEFT_BITS) >> _SND2_LEFT_POS)

#define GET_SND3_LEFT(soundcnt_l)  \
		(((soundcnt_l) & _SND3_LEFT_BITS) >> _SND3_LEFT_POS)

#define GET_SND4_LEFT(soundcnt_l)  \
		(((soundcnt_l) & _SND4_LEFT_BITS) >> _SND4_LEFT_POS)

#define GET_SND1_RIGHT(soundcnt_l)  \
		(((soundcnt_l) & _SND1_RIGHT_BITS) >> _SND1_RIGHT_POS)

#define GET_SND2_RIGHT(soundcnt_l)  \
		(((soundcnt_l) & _SND2_RIGHT_BITS) >> _SND2_RIGHT_POS)

#define GET_SND3_RIGHT(soundcnt_l)  \
		(((soundcnt_l) & _SND3_RIGHT_BITS) >> _SND3_RIGHT_POS)

#define GET_SND4_RIGHT(soundcnt_l)  \
		(((soundcnt_l) & _SND4_RIGHT_BITS) >> _SND4_RIGHT_POS)

// REG_SOUNDCNT_H

#define MAKE_SND_OUTPUT(output)  \
		((output) << _SND_OUTPUT_POS)

#define MAKE_SNDA_OUTPUT(output)  \
		((output) << _SNDA_OUTPUT_POS)

#define MAKE_SNDB_OUTPUT(output)  \
		((output) << _SNDB_OUTPUT_POS)

#define MAKE_SNDA_RIGHT(enable)  \
		((enable) << _SNDA_RIGHT_POS)

#define MAKE_SNDA_LEFT(enable)  \
		((enable) << _SNDA_LEFT_POS)

#define MAKE_SNDA_TIMER(timer)  \
		((timer) << _SNDA_TIMER_POS)

#define MAKE_SNDA_FIFO(fifo)  \
		((fifo) << _SNDA_FIFO_POS)

#define MAKE_SNDB_RIGHT(enable)  \
		((enable) << _SNDB_RIGHT_POS)

#define MAKE_SNDB_LEFT(enable)  \
		((enable) << _SNDB_LEFT_POS)

#define MAKE_SNDB_TIMER(timer)  \
		((timer) << _SNDB_TIMER_POS)

#define MAKE_SNDB_FIFO(fifo)  \
		((fifo) << _SNDB_FIFO_POS)

#define MAKE_SOUNDCNT_H(output, a_output, b_output,			\
						a_right, a_left, a_timer, a_fifo,	\
						b_right, b_left, b_timer, b_fifo)	\
		(													\
		MAKE_SND_OUTPUT((output)) |							\
		MAKE_SNDA_OUTPUT((a_output)) |						\
		MAKE_SNDB_OUTPUT((b_output)) |						\
		MAKE_SNDA_RIGHT((a_right)) |						\
		MAKE_SNDA_LEFT((a_left)) |							\
		MAKE_SNDA_TIMER((a_timer)) |						\
		MAKE_SNDA_FIFO((a_fifo)) |							\
		MAKE_SNDB_RIGHT((b_right)) |						\
		MAKE_SNDB_LEFT((b_left)) |							\
		MAKE_SNDB_TIMER((b_timer)) |						\
		MAKE_SNDB_FIFO((b_fifo))							\
		)

#define GET_SND_OUTPUT(soundcnt_h)  \
		(((soundcnt_h) & _SND_OUTPUT_BITS) >> _SND_OUTPUT_POS)

#define GET_SNDA_OUTPUT(soundcnt_h)  \
		(((soundcnt_h) & _SNDA_OUTPUT_BITS) >> _SNDA_OUTPUT_POS)

#define GET_SNDB_OUTPUT(soundcnt_h)  \
		(((soundcnt_h) & _SNDB_OUTPUT_BITS) >> _SNDB_OUTPUT_POS)

#define GET_SNDA_RIGHT(soundcnt_h)  \
		(((soundcnt_h) & _SNDA_RIGHT_BITS) >> _SNDA_RIGHT_POS)

#define GET_SNDA_LEFT(soundcnt_h)  \
		(((soundcnt_h) & _SNDA_LEFT_BITS) >> _SNDA_LEFT_POS)

#define GET_SNDA_TIMER(soundcnt_h)  \
		(((soundcnt_h) & _SNDA_TIMER_BITS) >> _SNDA_TIMER_POS)

#define GET_SNDA_FIFO(soundcnt_h)  \
		(((soundcnt_h) & _SNDA_FIFO_BITS) >> _SNDA_FIFO_POS)

#define GET_SNDB_RIGHT(soundcnt_h)  \
		(((soundcnt_h) & _SNDB_RIGHT_BITS) >> _SNDB_RIGHT_POS)

#define GET_SNDB_LEFT(soundcnt_h)  \
		(((soundcnt_h) & _SNDB_LEFT_BITS) >> _SNDB_LEFT_POS)

#define GET_SNDB_TIMER(soundcnt_h)  \
		(((soundcnt_h) & _SNDB_TIMER_BITS) >> _SNDB_TIMER_POS)

#define GET_SNDB_FIFO(soundcnt_h)  \
		(((soundcnt_h) & _SNDB_FIFO_BITS) >> _SNDB_FIFO_POS)

// REG_SOUNDCNT_X

#define MAKE_SND_ENABLE(enable)  \
		((enable) << _SND_ENABLE_POS)

#define GET_SND1_STAT(soundcnt_x)  \
		(((soundcnt_x) & _SND1_STAT_BITS) >> _SND1_STAT_POS)

#define GET_SND2_STAT(soundcnt_x)  \
		(((soundcnt_x) & _SND2_STAT_BITS) >> _SND2_STAT_POS)

#define GET_SND3_STAT(soundcnt_x)  \
		(((soundcnt_x) & _SND3_STAT_BITS) >> _SND3_STAT_POS)

#define GET_SND4_STAT(soundcnt_x)  \
		(((soundcnt_x) & _SND4_STAT_BITS) >> _SND4_STAT_POS)

#define GET_SND_ENABLE(soundcnt_x)  \
		(((soundcnt_x) & _SND_ENABLE_BITS) >> _SND_ENABLE_POS)

// REG_SOUND1CNT_L

#define MAKE_SND1_SWPSHIFTS(swpshifts)  \
		((swpshifts) << _SND1_SWPSHIFTS_POS)

#define MAKE_SND1_SWPMODE(swpmode)  \
		((swpmode) << _SND1_SWPMODE_POS)

#define MAKE_SND1_SWPTIME(swptime)  \
		((swptime) << _SND1_SWPTIME_POS)

#define MAKE_SOUND1CNT_L(swpshifts, swpmode, swptime)	\
		(												\
		MAKE_SND1_SWPSHIFTS((swpshifts)) |				\
		MAKE_SND1_SWPMODE((swpmode)) |					\
		MAKE_SND1_SWPTIME((swptime))					\
		)

#define GET_SND1_SWPSHIFTS(sound1cnt_l)  \
		(((sound1cnt_l) & _SND1_SWPSHIFTS_BITS) >> _SND1_SWPSHIFTS_POS)

#define GET_SND1_SWPMODE(sound1cnt_l)  \
		(((sound1cnt_l) & _SND1_SWPMODE_BITS) >> _SND1_SWPMODE_POS)

#define GET_SND1_SWPTIME(sound1cnt_l)  \
		(((sound1cnt_l) & _SND1_SWPTIME_BITS) >> _SND1_SWPTIME_POS)

// REG_SOUND1CNT_H

#define MAKE_SND1_LENGTH(length)  \
		((length) << _SND1_LENGTH_POS)

#define MAKE_SND1_WAVEDUTY(waveduty)  \
		((waveduty) << _SND1_WAVEDUTY_POS)

#define MAKE_SND1_ENVTIME(envtime)  \
		((envtime) << _SND1_ENVTIME_POS)

#define MAKE_SND1_ENVMODE(envmode)  \
		((envmode) << _SND1_ENVMODE_POS)

#define MAKE_SND1_ENVINIT(envinit)  \
		((envinit) << _SND1_ENVINIT_POS)

#define MAKE_SOUND1CNT_H(length, waveduty, envtime, envmode, envinit)	\
		(																\
		MAKE_SND1_LENGTH((length)) |									\
		MAKE_SND1_WAVEDUTY((waveduty)) |								\
		MAKE_SND1_ENVTIME((envtime)) |									\
		MAKE_SND1_ENVMODE((envmode)) |									\
		MAKE_SND1_ENVINIT((envinit))									\
		)

#define GET_SND1_LENGTH(sound1cnt_h)  \
		(((sound1cnt_h) & _SND1_LENGTH_BITS) >> _SND1_LENGTH_POS)

#define GET_SND1_WAVEDUTY(sound1cnt_h)  \
		(((sound1cnt_h) & _SND1_WAVEDUTY_BITS) >> _SND1_WAVEDUTY_POS)

#define GET_SND1_ENVTIME(sound1cnt_h)  \
		(((sound1cnt_h) & _SND1_ENVTIME_BITS) >> _SND1_ENVTIME_POS)

#define GET_SND1_ENVMODE(sound1cnt_h)  \
		(((sound1cnt_h) & _SND1_ENVMODE_BITS) >> _SND1_ENVMODE_POS)

#define GET_SND1_ENVINIT(sound1cnt_h)  \
		(((sound1cnt_h) & _SND1_ENVINIT_BITS) >> _SND1_ENVINIT_POS)

// REG_SOUND1CNT_X

#define MAKE_SND1_FREQ(freq)  \
		((freq) << _SND1_FREQ_POS)

#define MAKE_SND1_TIMED(timed)  \
		((timed) << _SND1_TIMED_POS)

#define MAKE_SND1_RESET(reset)  \
		((reset) << _SND1_RESET_POS)

#define MAKE_SOUND1CNT_X(freq, timed, reset)	\
		(										\
		MAKE_SND1_FREQ((freq)) |				\
		MAKE_SND1_TIMED((timed)) |				\
		MAKE_SND1_RESET((reset))				\
		)

#define GET_SND1_FREQ(sound1cnt_x)  \
		(((sound1cnt_x) & _SND1_FREQ_BITS) >> _SND1_FREQ_POS)

#define GET_SND1_TIMED(sound1cnt_x)  \
		(((sound1cnt_x) & _SND1_TIMED_BITS) >> _SND1_TIMED_POS)

#define GET_SND1_RESET(sound1cnt_x)  \
		(((sound1cnt_x) & _SND1_TIMED_BITS) >> _SND1_TIMED_POS)

// REG_SOUND2CNT_L

#define MAKE_SND2_LENGTH(length)  \
		((length) << _SND2_LENGTH_POS)

#define MAKE_SND2_WAVEDUTY(waveduty)  \
		((waveduty) << _SND2_WAVEDUTY_POS)

#define MAKE_SND2_ENVTIME(envtime)  \
		((envtime) << _SND2_ENVTIME_POS)

#define MAKE_SND2_ENVMODE(envmode)  \
		((envmode) << _SND2_ENVMODE_POS)

#define MAKE_SND2_ENVINIT(envinit)  \
		((envinit) << _SND2_ENVINIT_POS)

#define MAKE_SOUND2CNT_L(length, waveduty, envtime, envmode, envinit)	\
		(																\
		MAKE_SND2_LENGTH((length)) |									\
		MAKE_SND2_WAVEDUTY((waveduty)) |								\
		MAKE_SND2_ENVTIME((envtime)) |									\
		MAKE_SND2_ENVMODE((envmode)) |									\
		MAKE_SND2_ENVINIT((envinit))									\
		)

#define GET_SND2_LENGTH(sound2cnt_l)  \
		(((sound2cnt_l) & _SND2_LENGTH_BITS) >> _SND_LENGTH_POS)

#define GET_SND2_WAVEDUTY(sound2cnt_l)  \
		(((sound2cnt_l) & _SND2_WAVEDUTY_BITS) >> _SND_WAVEDUTY_POS)

#define GET_SND2_ENVTIME(sound2cnt_l)  \
		(((sound2cnt_l) & _SND2_ENVTIME_BITS) >> _SND_ENVTIME_POS)

#define GET_SND2_ENVMODE(sound2cnt_l)  \
		(((sound2cnt_l) & _SND2_ENVMODE_BITS) >> _SND_ENVMODE_POS)

#define GET_SND2_ENVINIT(sound2cnt_l)  \
		(((sound2cnt_l) & _SND2_ENVINIT_BITS) >> _SND_ENVINIT_POS)

// REG_SOUND2CNT_H

#define MAKE_SND2_FREQ(freq)  \
		((freq) << _SND2_FREQ_POS)

#define MAKE_SND2_TIMED(timed)  \
		((timed) << _SND2_TIMED_POS)

#define MAKE_SND2_RESET(reset)  \
		((reset) << _SND2_RESET_POS)

#define MAKE_SOUND2CNT_H(freq, timed, reset)	\
		(										\
		MAKE_SND2_FREQ((freq)) |				\
		MAKE_SND2_TIMED((timed)) |				\
		MAKE_SND2_RESET((reset))				\
		)

#define GET_SND2_FREQ(sound2cnt_h)  \
		(((sound2cnt_h) & _SND2_FREQ_BITS) >> _SND2_FREQ_POS)

#define GET_SND2_TIMED(sound2cnt_h)  \
		(((sound2cnt_h) & _SND2_TIMED_BITS) >> _SND2_TIMED_POS)

#define GET_SND2_RESET(sound2cnt_h)  \
		(((sound2cnt_h) & _SND2_RESET_BITS) >> _SND2_RESET_POS)

// REG_SOUND3CNT_L

#define MAKE_SND3_BANKMODE(bankmode)  \
		((bankmode) << _SND3_BANKMODE_POS)

#define MAKE_SND3_BANK(bank)  \
		((bank) << _SND3_BANK_POS)

#define MAKE_SND3_ENABLE(enable)  \
		((enable) << _SND3_ENABLE_POS)

#define MAKE_SOUND3CNT_L(bankmode, bank, enable)	\
		(											\
		MAKE_SND3_BANKMODE((bankmode)) |			\
		MAKE_SND3_BANK((bank)) |					\
		MAKE_SND3_ENABLE((enable))					\
		)

#define GET_SND3_BANKMODE(sound3cnt_l)  \
		(((sound3cnt_l) & _SND3_BANKMODE_BITS) >> _SND3_BANKMODE_POS)

#define GET_SND3_BANK(sound3cnt_l)  \
		(((sound3cnt_l) & _SND3_BANK_BITS) >> _SND3_BANK_POS)

#define GET_SND3_ENABLE(sound3cnt_l)  \
		(((sound3cnt_l) & _SND3_ENABLE_BITS) >> _SND3_ENABLE_POS)

// REG_SOUND3CNT_H

#define MAKE_SND3_LENGTH(length)  \
		((length) << _SND3_LENGTH_POS)

#define MAKE_SND3_OUTPUT(output)  \
		((output) << _SND3_OUTPUT_POS)

#define MAKE_SOUND3CNT_H(length, output)	\
		(									\
		MAKE_SND3_LENGTH((length)) |		\
		MAKE_SND3_OUTPUT((output))			\
		)

#define GET_SND3_LENGTH(sound3cnt_h)  \
		(((sound3cnt_h) & _SND3_LENGTH_BITS) >> _SND3_LENGTH_POS)

#define GET_SND3_OUTPUT(sound3cnt_h)  \
		(((sound3cnt_h) & _SND3_OUTPUT_BITS) >> _SND3_OUTPUT_POS)

// REG_SOUND3CNT_X

#define MAKE_SND3_FREQ(freq)  \
		((freq) << _SND3_FREQ_POS)

#define MAKE_SND3_TIMED(timed)  \
		((timed) << _SND3_TIMED_POS)

#define MAKE_SND3_RESET(reset)  \
		((reset) << _SND3_RESET_POS)

#define MAKE_SOUND3CNT_X(freq, timed, reset)	\
		(										\
		MAKE_SND3_FREQ((freq)) |				\
		MAKE_SND3_TIMED((timed)) |				\
		MAKE_SND3_RESET((reset))				\
		)

#define GET_SND3_FREQ(sound3cnt_x)  \
		(((sound3cnt_x) & _SND3_FREQ_BITS) >> _SND3_FREQ_POS)

#define GET_SND3_TIMED(sound3cnt_x)  \
		(((sound3cnt_x) & _SND3_TIMED_BITS) >> _SND3_TIMED_POS)

#define GET_SND3_RESET(sound3cnt_x)  \
		(((sound3cnt_x) & _SND3_RESET_BITS) >> _SND3_RESET_POS)

// REG_SOUND4CNT_L

#define MAKE_SND4_LENGTH(length)  \
		((length) << _SND4_LENGTH_POS)

#define MAKE_SND4_ENVTIME(envtime)  \
		((envtime) << _SND4_ENVTIME_POS)

#define MAKE_SND4_ENVMODE(envmode)  \
		((envmode) << _SND4_ENVMODE_POS)

#define MAKE_SND4_ENVINIT(envinit)  \
		((envinit) << _SND4_ENVINIT_POS)

#define MAKE_SOUND4CNT_L(length, envtime, envmode, envinit)		\
		(														\
		MAKE_SND4_LENGTH((length)) |							\
		MAKE_SND4_ENVTIME((envtime)) |							\
		MAKE_SND4_ENVMODE((envmode)) |							\
		MAKE_SND4_ENVINIT((envinit))							\
		)

#define GET_SND4_LENGTH(sound4cnt_l)  \
		(((sound4cnt_l) & _SND4_LENGTH_BITS) >> _SND4_LENGTH_POS)

#define GET_SND4_ENVTIME(sound4cnt_l)  \
		(((sound4cnt_l) & _SND4_ENVTIME_BITS) >> _SND4_ENVTIME_POS)

#define GET_SND4_ENVMODE(sound4cnt_l)  \
		(((sound4cnt_l) & _SND4_ENVMODE_BITS) >> _SND4_ENVMODE_POS)

#define GET_SND4_ENVINIT(sound4cnt_l)  \
		(((sound4cnt_l) & _SND4_ENVINIT_BITS) >> _SND4_ENVINIT_POS)

// REG_SOUND4CNT_H

#define MAKE_SND4_DIV(div)  \
		((div) << _SND4_DIV_POS)

#define MAKE_SND4_STAGES(stages)  \
		((stages) << _SND4_STAGES_POS)

#define MAKE_SND4_PRESTEP(prestep)  \
		((prestep) << _SND4_PRESTEP_POS)

#define MAKE_SND4_TIMED(timed)  \
		((timed) << _SND4_TIMED_POS)

#define MAKE_SND4_RESET(reset)  \
		((reset) << _SND4_RESET_POS)

#define MAKE_SOUND4CNT_H(div, stages, prestep, timed, reset)	\
		(														\
		MAKE_SND4_DIV((div)) |									\
		MAKE_SND4_STAGES((stages)) |							\
		MAKE_SND4_PRESTEP((prestep)) |							\
		MAKE_SND4_TIMED((timed)) |								\
		MAKE_SND4_RESET((reset))								\
		)

#define GET_SND4_DIV(sound4cnt_h)  \
		(((sound4cnt_h) & _SND4_DIV_BITS) >> _SND4_DIV_POS)

#define GET_SND4_STAGES(sound4cnt_h)  \
		(((sound4cnt_h) & _SND4_STAGES_BITS) >> _SND4_STAGES_POS)

#define GET_SND4_PRESTEP(sound4cnt_h)  \
		(((sound4cnt_h) & _SND4_PRESTEP_BITS) >> _SND4_PRESTEP_POS)

#define GET_SND4_TIMED(sound4cnt_h)  \
		(((sound4cnt_h) & _SND4_TIMED_BITS) >> _SND4_TIMED_POS)

#define GET_SND4_RESET(sound4cnt_h)  \
		(((sound4cnt_h) & _SND4_RESET_BITS) >> _SND4_RESET_POS)


#define SET_SOUND_LEFTVOL(leftvol)  \
		{REG_SOUNDCNT_L &= _SND_LEFTVOL_MASK;  \
		REG_SOUNDCNT_L |= MAKE_SND_LEFTVOL(leftvol);}

#define SET_SOUND_RIGHTVOL(rightvol)  \
		{REG_SOUNDCNT_L &= _SND_RIGHTVOL_MASK;  \
		REG_SOUNDCNT_L |= MAKE_SND_RIGHTVOL(rightvol);}

#define SET_SOUND1_LEFT(enable)  \
		{REG_SOUNDCNT_L &= _SND1_LEFT_MASK;  \
		REG_SOUNDCNT_L |= MAKE_SND1_LEFT(enable);}

#define SET_SOUND2_LEFT(enable)  \
		{REG_SOUNDCNT_L &= _SND2_LEFT_MASK;  \
		REG_SOUNDCNT_L |= MAKE_SND2_LEFT(enable);}

#define SET_SOUND3_LEFT(enable)  \
		{REG_SOUNDCNT_L &= _SND3_LEFT_MASK;  \
		REG_SOUNDCNT_L |= MAKE_SND3_LEFT(enable);}

#define SET_SOUND4_LEFT(enable)  \
		{REG_SOUNDCNT_L &= _SND4_LEFT_MASK;  \
		REG_SOUNDCNT_L |= MAKE_SND4_LEFT(enable);}

#define SET_SOUND1_RIGHT(enable)  \
		{REG_SOUNDCNT_L &= _SND1_RIGHT_MASK;  \
		REG_SOUNDCNT_L |= MAKE_SND1_RIGHT(enable);}

#define SET_SOUND2_RIGHT(enable)  \
		{REG_SOUNDCNT_L &= _SND2_RIGHT_MASK;  \
		REG_SOUNDCNT_L |= MAKE_SND2_RIGHT(enable);}

#define SET_SOUND3_RIGHT(enable)  \
		{REG_SOUNDCNT_L &= _SND3_RIGHT_MASK;  \
		REG_SOUNDCNT_L |= MAKE_SND3_RIGHT(enable);}

#define SET_SOUND4_RIGHT(enable)  \
		{REG_SOUNDCNT_L &= _SND4_RIGHT_MASK;  \
		REG_SOUNDCNT_L |= MAKE_SND4_RIGHT(enable);}

#define SET_SOUND_OUTPUT(output)  \
		{REG_SOUNDCNT_H &= _SND_OUTPUT_MASK;  \
		REG_SOUNDCNT_H |= MAKE_SND_OUTPUT(output);}

#define SET_SOUNDA_OUTPUT(output)  \
		{REG_SOUNDCNT_H &= _SNDA_OUTPUT_MASK;  \
		REG_SOUNDCNT_H |= MAKE_SNDA_OUTPUT(output);}

#define SET_SOUNDB_OUTPUT(output)  \
		{REG_SOUNDCNT_H &= _SNDB_OUTPUT_MASK;  \
		REG_SOUNDCNT_H |= MAKE_SNDB_OUTPUT(output);}

#define SET_SOUNDA_RIGHT(enable)  \
		{REG_SOUNDCNT_H &= _SNDA_RIGHT_MASK;  \
		REG_SOUNDCNT_H |= MAKE_SNDA_RIGHT(enable);}

#define SET_SOUNDA_LEFT(enable)  \
		{REG_SOUNDCNT_H &= _SNDA_LEFT_MASK;  \
		REG_SOUNDCNT_H |= MAKE_SNDA_LEFT(enable);}

#define SET_SOUNDA_TIMER(timer)  \
		{REG_SOUNDCNT_H &= _SNDA_TIMER_MASK;  \
		REG_SOUNDCNT_H |= MAKE_SNDA_TIMER(timer);}

#define SET_SOUNDA_FIFO(fifo)  \
		{REG_SOUNDCNT_H &= _SNDA_FIFO_MASK;  \
		REG_SOUNDCNT_H |= MAKE_SNDA_FIFO(fifo);}

#define SET_SOUNDB_RIGHT(enable)  \
		{REG_SOUNDCNT_H &= _SNDB_RIGHT_MASK;  \
		REG_SOUNDCNT_H |= MAKE_SNDB_RIGHT(enable);}

#define SET_SOUNDB_LEFT(enable)  \
		{REG_SOUNDCNT_H &= _SNDB_LEFT_MASK;  \
		REG_SOUNDCNT_H |= MAKE_SNDB_LEFT(enable);}

#define SET_SOUNDB_TIMER(timer)  \
		{REG_SOUNDCNT_H &= _SNDB_TIMER_MASK;  \
		REG_SOUNDCNT_H |= MAKE_SNDB_TIMER(timer);}

#define SET_SOUNDB_FIFO(fifo)  \
		{REG_SOUNDCNT_H &= _SNDB_FIFO_MASK;  \
		REG_SOUNDCNT_H |= MAKE_SNDB_FIFO(fifo);}


#define SOUNDA_PLAY(channel, timer, wave) \
	DMA(channel, (void *)&REG_FIFO_A_L, wave, timer, \
	DMA_ENABLE | DMA_START_FIFO | DMA_SIZE_32 | DMA_SRC_INC | \
	DMA_DST_INC | DMA_REPEAT)

#define SOUNDB_PLAY(channel, timer, wave) \
	DMA(channel, (void *)&REG_FIFO_B_L, wave, timer, \
	DMA_ENABLE | DMA_START_FIFO | DMA_SIZE_32 | DMA_SRC_INC | \
	DMA_DST_INC | DMA_REPEAT)

#define SOUNDA_STOP(channel)  set_dma_cnt_h(channel, 0)
#define SOUNDB_STOP(channel)  set_dma_cnt_h(channel, 0)

#define SOUND_START_TIMER(timer, freq) \
	{set_timer_data(timer, 0x10000 - (0x1000000 / freq)); \
	set_timer_cnt(timer, TIM_ENABLE | TIM_IRQ | TIM_FREQ_1);}

#define SOUND_STOP_TIMER(timer)  set_timer_cnt(timer, 0)

#define SET_SOUNDA(output, left, right, timer) \
	{set_sounda_output(output); \
	set_sounda_left(left); \
	set_sounda_right(right); \
	set_sounda_timer(timer); \
	set_sounda_fifo(TRUE);}

#define SET_SOUNDB(output, left, right, timer) \
	{set_soundb_output(output); \
	set_soundb_left(left); \
	set_soundb_right(right); \
	set_soundb_timer(timer); \
	set_soundb_fifo(TRUE);}


/*!
 *  @param  leftvol  <b>u8</b> [0..7] Left Volume
 *
 *  Left volume for sound channels 1 to 4.
 */
#define set_sound_leftvol(leftvol)  SET_SOUND_LEFTVOL(leftvol)


/*!
 *  @param  rightvol  <b>u8</b> [0..7] Right Volume
 *
 *  Right volume for sound channels 1 to 4.
 */
#define set_sound_rightvol(rightvol)  SET_SOUND_RIGHTVOL(rightvol)


/*!
 *  @param  enable  <b>bool</b> [TRUE or FALSE] Enable Left Output
 *
 *  Enable sound channel 1 to output to left speaker.
 */
#define set_sound1_left(enable)  SET_SOUND1_LEFT(enable)


/*!
 *  @param  enable  <b>bool</b> [TRUE or FALSE] Enable Left Output
 *
 *  Enable sound channel 2 to output to left speaker.
 */
#define set_sound2_left(enable)  SET_SOUND2_LEFT(enable)


/*!
 *  @param  enable  <b>bool</b> [TRUE or FALSE] Enable Left Output
 *
 *  Enable sound channel 3 to output to left speaker.
 */
#define set_sound3_left(enable)  SET_SOUND3_LEFT(enable)


/*!
 *  @param  enable  <b>bool</b> [TRUE or FALSE] Enable Left Output
 *
 *  Enable sound channel 4 to output to left speaker.
 */
#define set_sound4_left(enable)  SET_SOUND4_LEFT(enable)


/*!
 *  @param  enable  <b>bool</b> [TRUE or FALSE] Enable Right Output
 *
 *  Enable sound channel 1 to output to right speaker.
 */
#define set_sound1_right(enable)  SET_SOUND1_RIGHT(enable)


/*!
 *  @param  enable  <b>bool</b> [TRUE or FALSE] Enable Right Output
 *
 *  Enable sound channel 2 to output to right speaker.
 */
#define set_sound2_right(enable)  SET_SOUND2_RIGHT(enable)


/*!
 *  @param  enable  <b>bool</b> [TRUE or FALSE] Enable Right Output
 *
 *  Enable sound channel 3 to output to right speaker.
 */
#define set_sound3_right(enable)  SET_SOUND3_RIGHT(enable)


/*!
 *  @param  enable  <b>bool</b> [TRUE or FALSE] Enable Right Output
 *
 *  Enable sound channel 4 to output to right speaker.
 */
#define set_sound4_right(enable)  SET_SOUND4_RIGHT(enable)


/*!
 *  @return  <b>u8</b> [0..7] Left Volume
 *
 *  Left volume for sound channels 1 to 4.
 */
#define get_sound_leftvol()  GET_SND_LEFTVOL(REG_SOUNDCNT_L)


/*!
 *  @return  <b>u8</b> [0..7] Right Volume
 *
 *  Right volume for sound channels 1 to 4.
 */
#define get_sound_rightvol()  GET_SND_RIGHTVOL(REG_SOUNDCNT_L)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable Left Output
 *
 *  Returns TRUE if sound channel 1 output to left speaker is enabled.
 */
#define get_sound1_left()  GET_SND1_LEFT(REG_SOUNDCNT_L)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable Left Output
 *
 *  Returns TRUE if sound channel 2 output to left speaker is enabled.
 */
#define get_sound2_left()  GET_SND2_LEFT(REG_SOUNDCNT_L)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable Left Output
 *
 *  Returns TRUE if sound channel 3 output to left speaker is enabled.
 */
#define get_sound3_left()  GET_SND3_LEFT(REG_SOUNDCNT_L)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable Left Output
 *
 *  Returns TRUE if sound channel 4 output to left speaker is enabled.
 */
#define get_sound4_left()  GET_SND4_LEFT(REG_SOUNDCNT_L)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable Right Output
 *
 *  Returns TRUE if sound channel 1 output to right speaker is enabled.
 */
#define get_sound1_right()  GET_SND1_RIGHT(REG_SOUNDCNT_L)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable Right Output
 *
 *  Returns TRUE if sound channel 2 output to right speaker is enabled.
 */
#define get_sound2_right()  GET_SND2_RIGHT(REG_SOUNDCNT_L)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable Right Output
 *
 *  Returns TRUE if sound channel 3 output to right speaker is enabled.
 */
#define get_sound3_right()  GET_SND3_RIGHT(REG_SOUNDCNT_L)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable Right Output
 *
 *  Returns TRUE if sound channel 4 output to right speaker is enabled.
 */
#define get_sound4_right()  GET_SND4_RIGHT(REG_SOUNDCNT_L)


/*!
 *  @param  output  <b>u8</b> [SND_OUTPUT] Output Ratio
 *
 *  Output ratio for sound channels 1 to 4.<br>
 *  <br>
 *  @copydoc SND_OUTPUT
 */
#define set_sound_output(output)  SET_SOUND_OUTPUT(output)


/*!
 *  @param  output  <b>bool</b> [SNDA_OUTPUT] Output Ratio
 *
 *  Output ratio for Direct Sound A.<br>
 *  <br>
 *  @copydoc SNDA_OUTPUT
 */
#define set_sounda_output(output)  SET_SOUNDA_OUTPUT(output)


/*!
 *  @param  output  <b>bool</b> [SNDB_OUTPUT] Output Ratio
 *
 *  Output ratio for Direct Sound B.<br>
 *  <br>
 *  @copydoc SNDB_OUTPUT
 */
#define set_soundb_output(output)  SET_SOUNDB_OUTPUT(output)


/*!
 *  @param  enable  <b>bool</b> [TRUE or FALSE] Enable Right Output
 *
 *  Enable Direct Sound A to output to right speaker.
 */
#define set_sounda_right(enable)  SET_SOUNDA_RIGHT(enable)


/*!
 *  @param  enable  <b>bool</b> [TRUE or FALSE] Enable Left Output
 *
 *  Enable Direct Sound A to output to left speaker.
 */
#define set_sounda_left(enable)  SET_SOUNDA_LEFT(enable)


/*!
 *  @param  timer  <b>bool</b> [0..1] Sampling Rate Timer
 *
 *  Sampling rate timer 0 or 1.
 */
#define set_sounda_timer(timer)  SET_SOUNDA_TIMER(timer)


/*!
 *  @param  fifo  <b>bool</b> [TRUE or FALSE] FIFO Reset
 */
#define set_sounda_fifo(fifo)  SET_SOUNDA_FIFO(fifo)


/*!
 *  @param  enable  <b>bool</b> [TRUE or FALSE] Enable Right Output
 *
 *  Enable Direct Sound B to output to right speaker.
 */
#define set_soundb_right(enable)  SET_SOUNDB_RIGHT(enable)


/*!
 *  @param  enable  <b>bool</b> [TRUE or FALSE] Enable Left Output
 *
 *  Enable Direct Sound B to output to left speaker.
 */
#define set_soundb_left(enable)  SET_SOUNDB_LEFT(enable)


/*!
 *  @param  timer  <b>bool</b> [0..1] Sampling Rate Timer
 *
 *  Sampling rate timer 0 or 1.
 */
#define set_soundb_timer(timer)  SET_SOUNDB_TIMER(timer)


/*!
 *  @param  fifo  <b>bool</b> [TRUE or FALSE] FIFO Reset
 */
#define set_soundb_fifo(fifo)  SET_SOUNDB_FIFO(fifo)


/*!
 *  @return  <b>u8</b> [SND_OUTPUT] Output Ratio
 *
 *  Output ratio for sound channels 1 to 4.<br>
 *  <br>
 *  @copydoc SND_OUTPUT
 */
#define get_sound_output()  GET_SND_OUTPUT(REG_SOUNDCNT_H)


/*!
 *  @return  <b>bool</b> [SNDA_OUTPUT] Output Ratio
 *
 *  Output ratio for Direct Sound A.<br>
 *  <br>
 *  @copydoc SNDA_OUTPUT
 */
#define get_sounda_output()  GET_SNDA_OUTPUT(REG_SOUNDCNT_H)


/*!
 *  @return  <b>bool</b> [SNDB_OUTPUT] Output Ratio
 *
 *  Output ratio for Direct Sound B.<br>
 *  <br>
 *  @copydoc SNDB_OUTPUT
 */
#define get_soundb_output()  GET_SNDB_OUTPUT(REG_SOUNDCNT_H)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable Right Output
 *
 *  Returns TRUE if Direct Sound A output to right speaker is enabled.
 */
#define get_sounda_right()  GET_SNDA_RIGHT(REG_SOUNDCNT_H)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable Left Output
 *
 *  Returns TRUE if Direct Sound A output to left speaker is enabled.
 */
#define get_sounda_left()  GET_SNDA_LEFT(REG_SOUNDCNT_H)


/*!
 *  @return  <b>bool</b> [0..1] Sampling Rate Timer
 *
 *  Sampling rate timer 0 or 1.
 */
#define get_sounda_timer()  GET_SNDA_TIMER(REG_SOUNDCNT_H)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] FIFO Reset
 */
#define get_sounda_fifo()  GET_SNDA_FIFO(REG_SOUNDCNT_H)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable Right Output
 *
 *  Returns TRUE if Direct Sound B output to right speaker is enabled.
 */
#define get_soundb_right()  GET_SNDB_RIGHT(REG_SOUNDCNT_H)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Enable Left Output
 *
 *  Returns TRUE if Direct Sound B output to left speaker is enabled.
 */
#define get_soundb_left()  GET_SNDB_LEFT(REG_SOUNDCNT_H)


/*!
 *  @return  <b>bool</b> [0..1] Sampling Rate Timer
 *
 *  Sampling rate timer 0 or 1.
 */
#define get_soundb_timer()  GET_SNDB_TIMER(REG_SOUNDCNT_H)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] FIFO Reset
 */
#define get_soundb_fifo()  GET_SNDB_FIFO(REG_SOUNDCNT_H)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Sound 1 Status
 *
 *  Returns TRUE if sound channel 1 is playing.
 */
#define get_sound1_stat()  GET_SND1_STAT(REG_SOUNDCNT_X)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Sound 2 Status
 *
 *  Returns TRUE if sound channel 2 is playing.
 */
#define get_sound2_stat()  GET_SND2_STAT(REG_SOUNDCNT_X)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Sound 3 Status
 *
 *  Returns TRUE if sound channel 3 is playing.
 */
#define get_sound3_stat()  GET_SND3_STAT(REG_SOUNDCNT_X)


/*!
 *  @return  <b>bool</b> [TRUE or FALSE] Sound 4 Status
 *
 *  Returns TRUE if sound channel 4 is playing.
 */
#define get_sound4_stat()  GET_SND4_STAT(REG_SOUNDCNT_X)


/*!
 *  Enable sound
 */
#define sound_on()  REG_SOUNDCNT_X |= MAKE_SND_ENABLE(TRUE);


/*!
 *  Disable sound
 */
#define sound_off()  REG_SOUNDCNT_X &= _SND_ENABLE_MASK;


/*!
 *  @param  leftvol   <b>u8</b> [0..7] Left Volume
 *  @param  rightvol  <b>u8</b> [0..7] Right Volume
 *  @param  left1     <b>bool</b> [TRUE or FALSE] Sound 1 Left Output
 *  @param  left2     <b>bool</b> [TRUE or FALSE] Sound 2 Left Output
 *  @param  left3     <b>bool</b> [TRUE or FALSE] Sound 3 Left Output
 *  @param  left4     <b>bool</b> [TRUE or FALSE] Sound 4 Left Output
 *  @param  right1    <b>bool</b> [TRUE or FALSE] Sound 1 Right Output
 *  @param  right2    <b>bool</b> [TRUE or FALSE] Sound 2 Right Output
 *  @param  right3    <b>bool</b> [TRUE or FALSE] Sound 3 Right Output
 *  @param  right4    <b>bool</b> [TRUE or FALSE] Sound 4 Right Output
 */
#define set_soundcnt_l(leftvol, rightvol, left1, left2, left3, left4, \
						right1, right2, right3, right4)  \
		REG_SOUNDCNT_L = MAKE_SOUNDCNT_L(leftvol, rightvol, \
			left1, left2, left3, left4, right1, right2, right3, right4);


/*!
 *  @param  output    <b>u8</b> [SND_OUTPUT] Sound 1-4 Output Ratio
 *  @param  a_output  <b>u8</b> [SNDA_OUTPUT] Direct Sound A Output Ratio
 *  @param  b_output  <b>u8</b> [SNDB_OUTPUT] Direct Sound B Output Ratio
 *  @param  a_right   <b>bool</b> [TRUE or FALSE] Enable Direct Sound A Right Output
 *  @param  a_left    <b>bool</b> [TRUE or FALSE] Enable Direct Sound A Left Output
 *  @param  a_timer   <b>bool</b> [0..1] Direct Sound A Sampling Rate Timer
 *  @param  a_fifo    <b>bool</b> [TRUE or FALSE] Direct Sound A FIFO Reset
 *  @param  b_right   <b>bool</b> [TRUE or FALSE] Enable Direct Sound B Right Output
 *  @param  b_left    <b>bool</b> [TRUE or FALSE] Enable Direct Sound B Left Output
 *  @param  b_timer   <b>bool</b> [0..1] Direct Sound B Sampling Rate Timer
 *  @param  b_fifo    <b>bool</b> [TRUE or FALSE] Direct Sound B FIFO Reset
 *
 *  @copydoc SND_OUTPUT
 *  <br>
 *  @copydoc SNDA_OUTPUT
 *  <br>
 *  @copydoc SNDB_OUTPUT
 */
#define set_soundcnt_h(output, a_output, b_output,  \
						a_right, a_left, a_timer, a_fifo,  \
						b_right, b_left, b_timer, b_fifo)  \
		REG_SOUNDCNT_H = MAKE_SOUNDCNT_H(output, a_output, b_output,  \
						a_right, a_left, a_timer, a_fifo,  \
						b_right, b_left, b_timer, b_fifo);


/*!
 *  @param  swpshifts  <b>u8</b> [0..7] Sweep Shifts
 *  @param  swpmode    <b>bool</b> [SND1_SWPMODE] Sweep Mode
 *  @param  swptime    <b>u8</b> [SND1_SWPTIME] Sweep Time
 *
 *  @copydoc SND1_SWPMODE
 *  <br>
 *  @copydoc SND1_SWPTIME
 */
#define set_sound1cnt_l(swpshifts, swpmode, swptime)  \
		REG_SOUND1CNT_L = MAKE_SOUND1CNT_L(swpshifts, swpmode, swptime);


/*!
 *  @param  length    <b>u8</b> [0..63] Sound Length
 *  @param  waveduty  <b>u8</b> [SND1_WAVEDUTY] Wave Duty Cycle
 *  @param  envtime   <b>u8</b> [0..7] Envelope Step Time
 *  @param  envmode   <b>bool</b> [SND1_ENVMODE] Envelope Mode
 *  @param  envinit   <b>u8</b> [0..15] Initial Envelope Value
 *
 *  @copydoc SND1_WAVEDUTY
 *  <br>
 *  @copydoc SND1_ENVMODE
 */
#define set_sound1cnt_h(length, waveduty, envtime, envmode, envinit)  \
		REG_SOUND1CNT_H = MAKE_SOUND1CNT_H(length, waveduty, envtime, envmode, envinit);


/*!
 *  @param  freq   <b>u16</b> [0..2047] Frequency
 *  @param  timed  <b>bool</b> [SND1_TIMED] Timed Mode
 *  @param  reset  <b>bool</b> [TRUE or FALSE] Sound Reset
 *
 *  @copydoc SND1_TIMED
 */
#define set_sound1cnt_x(freq, timed, reset)  \
		REG_SOUND1CNT_X = MAKE_SOUND1CNT_X(freq, timed, reset);


/*!
 *  @param  length    <b>u8</b> [0..63] Sound Length
 *  @param  waveduty  <b>u8</b> [SND2_WAVEDUTY] Wave Duty Cycle
 *  @param  envtime   <b>u8</b> [0..7] Envelope Time
 *  @param  envmode   <b>bool</b> [SND2_ENVMODE] Envelope Mode
 *  @param  envinit   <b>u8</b> [0..15] Initial Envelope Mode
 *
 *  @copydoc SND2_WAVEDUTY
 *  <br>
 *  @copydoc SND2_ENVMODE
 */
#define set_sound2cnt_l(length, waveduty, envtime, envmode, envinit)  \
		REG_SOUND2CNT_L = MAKE_SOUND2CNT_L(length, waveduty, envtime, envmode, envinit);


/*!
 *  @param  freq   <b>u16</b> [0..2047] Frequency
 *  @param  timed  <b>bool</b> [SND2_TIMED] Timed Mode
 *  @param  reset  <b>bool</b> [TRUE or FALSE] Sound Reset
 *
 *  @copydoc SND2_TIMED
 */
#define set_sound2cnt_h(freq, timed, reset)  \
		REG_SOUND2CNT_H = MAKE_SOUND2CNT_H(freq, timed, reset);


/*!
 *  @param  bankmode  <b>bool</b> [SND3_BANKMODE] Bank Mode
 *  @param  bank      <b>bool</b> [0..1] Bank
 *  @param  enable    <b>bool</b> [TRUE or FALSE] Enable Sound Channel 3 Output
 *
 *  @copydoc SND3_BANKMODE
 */
#define set_sound3cnt_l(bankmode, bank, enable)  \
		REG_SOUND3CNT_L = MAKE_SOUND3CNT_L(bankmode, bank, enable);


/*!
 *  @param  length  <b>u8</b> [0..255] Sound Length
 *  @param  output  <b>u8</b> [SND3_OUTPUT] Output Ratio
 *
 *  @copydoc SND3_OUTPUT
 */
#define set_sound3cnt_h(length, output)  \
		REG_SOUND3CNT_H = MAKE_SOUND3CNT_H(length, output);


/*!
 *  @param  freq   <b>u16</b> [0..2047] Frequency
 *  @param  timed  <b>bool</b> [SND3_TIMED] Timed Mode
 *  @param  reset  <b>bool</b> Sound Reset
 *
 *  @copydoc SND3_TIMED
 */
#define set_sound3cnt_x(freq, timed, reset)  \
		REG_SOUND3CNT_X = MAKE_SOUND3CNT_X(freq, timed, reset);


/*!
 *  @param  length   <b>u8</b> [0..63] Sound Length
 *  @param  envtime  <b>u8</b> [0..7] Envelope Step Time
 *  @param  envmode  <b>bool</b> [SND4_ENVMODE] Envelope Mode
 *  @param  envinit  <b>u8</b> [0..15] Initial Envelope Value
 *
 *  @copydoc SND4_ENVMODE
 */
#define set_sound4cnt_l(length, envtime, envmode, envinit)  \
		REG_SOUND4CNT_L = MAKE_SOUND4CNT_L(length, envtime, envmode, envinit);


/*!
 *  @param  div      <b>u8</b> [SND4_DIV] Clock Divider Frequency
 *  @param  stages   <b>bool</b> [SND4_STAGES] Counter Stages
 *  @param  prestep  <b>u8</b> [SND4_PRESTEP] Counter Pre-Stepper Frequency
 *  @param  timed    <b>bool</b> [SND4_TIMED] Timed Mode
 *  @param  reset    <b>bool</b> [TRUE or FALSE] Sound Reset
 *
 *  @copydoc SND4_DIV
 *  <br>
 *  @copydoc SND4_STAGES
 *  <br>
 *  @copydoc SND4_PRESTEP
 *  <br>
 *  @copydoc SND4_TIMED
 */
#define set_sound4cnt_h(div, stages, prestep, timed, reset)  \
		REG_SOUND4CNT_H = MAKE_SOUND4CNT_H(div, stages, prestep, timed, reset);


/*!
 *  @param  channel  <b>u8</b> [1..2] DMA Channel
 *  @param  timer    <b>u8</b> [0..1] Timer
 *  @param  wave     <b>void*</b> Wave Data
 *
 *  Starts a DMA to continuously copy wave data to the Direct Sound A channel
 */
#define sounda_play(channel, timer, wave)  SOUNDA_PLAY(channel, timer, wave)


/*!
 *  @param  channel  <b>u8</b> [1..2] DMA Channel
 *  @param  timer    <b>bool</b> [0..1] Sampling Rate Timer
 *  @param  wave     <b>void*</b> Wave Data
 *
 *  Starts a DMA to continuously copy wave data to the Direct Sound B channel
 */
#define soundb_play(channel, timer, wave)  SOUNDB_PLAY(channel, timer, wave)


/*!
 *  @param  channel  <b>u8</b> [1..2] DMA Channel
 *
 *  Stops the DMA from copying wave data to the Direct Sound A channel
 */
#define sounda_stop(channel)  SOUNDA_STOP(channel)


/*!
 *  @param  channel  <b>u8</b> [1..2] DMA Channel
 *
 *  Stops the DMA from copying wave data to the Direct Sound B channel
 */
#define soundb_stop(channel)  SOUNDB_STOP(channel)


/*!
 *  @param  timer  <b>bool</b> [0..1] Sampling Rate Timer
 *  @param  freq   <b>u16</b> Sample Frequency (eg. 16000 = 16khz)
 *
 *  Starts a timer at the specified frequency
 */
#define sound_start_timer(timer, freq)  SOUND_START_TIMER(timer, freq)


/*!
 *  @param  timer  <b>bool</b> [0..1] Sampling Rate Timer
 *
 *  Stops the timer
 */
#define sound_stop_timer(timer)  SOUND_STOP_TIMER(timer)


/*!
 *  @param  output  <b>bool</b> [SNDA_OUTPUT] Output Ratio
 *  @param  left    <b>bool</b> [TRUE or FALSE] Enable Left Output
 *  @param  right   <b>bool</b> [TRUE or FALSE] Enable Right Output
 *  @param  timer   <b>bool</b> [0..1] Sampling Rate Timer
 *
 *  Sets up the Direct Sound A channel
 *
 *  @copydoc SNDA_OUTPUT
 */
#define set_sounda(output, left, right, timer)  SET_SOUNDA(output, left, right, timer)


/*!
 *  @param  output  <b>bool</b> [SNDB_OUTPUT] Output Ratio
 *  @param  left    <b>bool</b> [TRUE or FALSE] Enable Left Output
 *  @param  right   <b>bool</b> [TRUE or FALSE] Enable Right Output
 *  @param  timer   <b>bool</b> [0..1] Sampling Rate Timer
 *
 *  Sets up the Direct Sound B channel
 *
 *  @copydoc SNDB_OUTPUT
 */
#define set_soundb(output, left, right, timer)  SET_SOUNDB(output, left, right, timer)

#endif

