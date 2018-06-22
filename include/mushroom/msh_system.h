
#ifndef MSH_SYSTEM_H
#define MSH_SYSTEM_H

/*---------------------------------------------------------------------------*
 *  DEFINES                                                                  *
 *---------------------------------------------------------------------------*/

#ifndef TRUE
#define TRUE true
#endif

#ifndef FALSE
#define FALSE false
#endif

// Creates your variable in external work RAM.
// You must initialize your data when you use this.
// eg. u8 array[12] IN_EWRAM = {0};
#define IN_EWRAM __attribute__((section (".ewram")))

// Creates your variable in internal work RAM.
// You must initialize your data when you use this.
// eg. u8 array[12] IN_IWRAM = {0};
#define IN_IWRAM __attribute__((section (".iwram")))

// Creates your function in internal work RAM.
#define FUNC_IN_IWRAM __attribute__((section (".iwram"), long_call))

// Packs your structure so it only takes the minimum space it needs,
// instead of padding out to the nearest multiple of 4.
// eg. struct somestruct {
// u8 thing0;
// } PACKED; // This struct should now take 1 byte instead of 4
#define PACKED __attribute__((packed))

// Aligns your variable in memory to a 4 byte offset.
// This should make access to your variable faster.
// I think you may need to initialize you data when you use this.
// eg. u8 array[12] ALIGN4 = {0};
#define ALIGN4 __attribute__((aligned (4)))

#define ALWAYS_INLINE __attribute__((always_inline))

/*---------------------------------------------------------------------------*
 *  TYPEDEFS                                                                 *
 *---------------------------------------------------------------------------*/

typedef signed char				s8;
typedef short int				s16;
typedef int						s32;
typedef long long int			s64;

typedef unsigned char			u8;
typedef unsigned short int		u16;
typedef unsigned int			u32;
typedef unsigned long long int	u64;

typedef volatile s8				vs8;
typedef volatile s16			vs16;
typedef volatile s32			vs32;
typedef volatile s64			vs64;

typedef volatile u8				vu8;
typedef volatile u16			vu16;
typedef volatile u32			vu32;
typedef volatile u64			vu64;

// Fixed Point 1.23.8 (sign.integer.fraction)
typedef s32						fixed;

#endif

