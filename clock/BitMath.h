#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define toggle(x, bit) (x = (1 << bit) ^ x)
#define set(x, bit) (x = (x | (1 << bit)))
#define clear(x, bit) (x = (x & (~(1 << bit))))
#define getbit(x, bit) ((x >> bit) & 1)

#endif
