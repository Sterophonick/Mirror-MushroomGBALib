
/*---------------------------------------------------------------------------*
 *  INCLUDES                                                                 *
 *---------------------------------------------------------------------------*/

#include <mushroom/msh_math.h>

/*---------------------------------------------------------------------------*
 *  VARIABLES                                                                *
 *---------------------------------------------------------------------------*/

u32 _math_rand_seed = 0x600D5EED;

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

fixed math_atan2 (fixed y, fixed x) {
	fixed xabs, yabs;
	fixed f, g;

	x = x << 8;
	y = y << 8;

	if (x >= 0) {
		xabs = x;
	} else {
		xabs = -x;
	}

	if (y >= 0) {
		yabs = y;
	} else {
		yabs = -y;
	}

	if (yabs <= xabs) {
		f = (yabs << 8) / xabs;
		g = _atan_table[f];
	} else {
		f = (xabs << 8) / yabs;
		g = PI_FIXED2 - _atan_table[f];
	}

	if (x >= 0) {
		if (y >= 0) {
			return (g) >> 2;
		} else {
			return -(g >> 2);
		}
	} else {
		if (y >= 0) {
			return (PI_FIXED - g) >> 2;
		} else {
			return (g - PI_FIXED) >> 2;
		}
	}
}


void math_fastdiv (s32 n, s32 d, s32 *result, s32 *remainder) {
	__asm__ volatile (
		"mov r0,%2 \n"
		"mov r1,%3 \n"
		"swi 0x60000 \n"
		"ldr r2,%0 \n"
		"str r0,[r2] \n"
		"ldr r2,%1 \n"
		"str r1,[r2] \n"
		: "=m" (result), "=m" (remainder)
		: "r" (n), "r" (d)
		: "r0" , "r1" , "r2" , "r3"
	);
}


void math_rand_set_seed (u32 seed) {
	_math_rand_seed = seed;
}


u32 math_rand_get_seed () {
	return _math_rand_seed;
}


u16 math_rand (u16 max) {
	u32 rnd;
	u32 div;

	if (max > 0x7FFF) {
		max = 0x7FFF;
	}

	div = 0x8000 / (max + 1);

	_math_rand_seed = _math_rand_seed * 1103515245 + 12345;
	rnd = (_math_rand_seed >> 16) & 0x7FFF;

	return rnd / div;
}

