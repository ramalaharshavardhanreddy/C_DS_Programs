#include<stdio.h>
#include<string.h>

#define BITS_PER_LONG 32
#define BITS_PER_LONG_LONG 64
#define DIV_ROUND_UP(x, y)  (((x) + (y) - 1) / (y)) 

#define SET_BIT(x,y)   ((x)|=(1UL<<y))
#define RESET_BIT(x,y) ((x)&=(~(1UL)<<y))
#define CHECK_BIT(x,y) ((x)&(1UL<<y))
#define TOOGLE(x,y)    ((x)^=(1UL<<y))

#define BIT(nr)         (1UL << (nr))
#define BIT_ULL(nr)     (1ULL << (nr))
#define BIT_MASK(nr)        (1UL << ((nr) % BITS_PER_LONG))
#define BIT_WORD(nr)        ((nr) / BITS_PER_LONG)
#define BIT_ULL_MASK(nr)    (1ULL << ((nr) % BITS_PER_LONG_LONG))
#define BIT_ULL_WORD(nr)    ((nr) / BITS_PER_LONG_LONG)
#define BITS_PER_BYTE       8
#define BITS_TO_LONGS(nr)   DIV_ROUND_UP(nr, BITS_PER_BYTE * sizeof(long))

/*
 * Create a contiguous bitmask starting at bit position @l and ending at
 * position @h. For example
 * GENMASK_ULL(39, 21) gives us the 64bit vector 0x000000ffffe00000.
 */
#define GENMASK(h, l) \
    (((~0UL) << (l)) & (~0UL >> (BITS_PER_LONG - 1 - (h))))

#define GENMASK_ULL(h, l) \
    (((~0ULL) << (l)) & (~0ULL >> (BITS_PER_LONG_LONG - 1 - (h))))
  
/* 
* Our own sizeof 
*/ 
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)
