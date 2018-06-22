/*!
 *  @file   msh_math.h
 *  @brief  Math functions
 */

#ifndef MSH_MATH_H
#define MSH_MATH_H

/*---------------------------------------------------------------------------*
 *  DEFINES                                                                  *
 *---------------------------------------------------------------------------*/

#define PI_FIXED		3217
#define PI_FIXED2		1608

/*---------------------------------------------------------------------------*
 *  MACROS                                                                   *
 *---------------------------------------------------------------------------*/

#define MIN(a, b)       (((a) < (b)) ? (a) : (b))
#define MAX(a, b)       (((a) > (b)) ? (a) : (b))

#define ABS(n)          (((n) < 0) ? -(n) : (n))
#define SGN(n)          (((n) < 0) ? -1 : 1)

#define ABS_FIXED(n)    ((((n) >> 8) < 0) ? -(n) : (n))
#define SGN_FIXED(n)    ((((n) >> 8) < 0) ? (-1 << 8) : (1 << 8))

#define fixed2int(a)    ((a) >> 8)
#define int2fixed(a)    ((a) << 8)
#define fixedmul(a, b)  (((a) * (b)) >> 8)
#define fixeddiv(a, b)  (((a) << 8) / (b))

#define deg2byte(deg)   ((u8)((((u32)(deg) % 360) << 8) / 360))
#define byte2deg(b)     ((u16)((((u32)(b) & 0x000000FF) * 360) >> 8))

/*!
 *  Returns num if it is in between min and max, otherwise num is
 *  clipped to min or max
 */
#define BOUNDS(num, min, max) \
		((num) < (min) ? (min) : ((num) > (max) ? (max) : (num)))


/*!
 *  @param   deg  <b>s16</b> [-359..359] Angle in degrees
 *  @return  <b>fixed</b> Sine of angle
 */
#define math_sin(deg)  ((deg) >= 0 ? _sin_table[deg] : -_sin_table[-(deg)])


/*!
 *  @param   deg  <b>s16</b> [-359..359] Angle in degrees
 *  @return  <b>fixed</b> Cosine of angle
 */
#define math_cos(deg)  ((deg) >= 0 ? _cos_table[deg] : _cos_table[-(deg)])

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

/*!
 *  @param  y  Y
 *  @param  x  X
 *
 *  @return  Result
 */
fixed math_atan2 (fixed y, fixed x);


/*!
 *  @param  n          Numerator
 *  @param  d          Denomenator
 *  @param  result     Result
 *  @param  remainder  Remainder
 *
 *  Uses the GBA BIOS divide function. The result and remainder get
 *  placed in the addresses specified.<br>
 *  eg. math_fastdiv(129, 10, &result, &remainder);
 */
void math_fastdiv (s32 n, s32 d, s32 *result, s32 *remainder);


/*!
 *  @param  seed  Start seed value
 *
 *  Sets the starting seed value for the math_rand() function.<br>
 *  A good way to set this is to run a timer and then use the value
 *  of the timer when the user presses a button.<br>
 *  This only needs to be set once.
 */
void math_rand_set_seed (u32 seed);


/*!
 *  @return  Seed value
 *
 *  This returns the current random seed value.<br>
 *  This value will change each time you call math_rand().
 */
u32 math_rand_get_seed ();


/*!
 *  @param   max  Maximum number
 *  @return  [0..max] Random number
 *
 *  Returns a random from 0 to max.<br>
 *  Eg. math_rand(255) will return a random number from 0 to 255.<br>
 *  math_rand_set_seed() should be called before using this.
 */
u16 math_rand (u16 max);

#endif

