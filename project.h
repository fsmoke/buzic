#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED

#include <stdbool.h>

//set bit - using bitwise OR operator
#define sbi(x,y) x |= _BV(y)
//clear bit - using bitwise AND operator
#define cbi(x,y) x &= ~(_BV(y))
//toggle bit - using bitwise XOR operator
#define tbi(x,y) x ^= _BV(y)
//check if the y'th bit of register 'x' is high ... test if its AND with 1 is 1
#define is_high(x,y) ((x & _BV(y)) == _BV(y))

#endif // PROJECT_H_INCLUDED
