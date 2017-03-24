#ifndef TIMER1_TICKS_H_INCLUDED
#define TIMER1_TICKS_H_INCLUDED

#define MS_DIVIDER 4
#define CTC_MATCH_OVERFLOW ((F_CPU / 1000) / (8 * MS_DIVIDER))

void timer1_ticks_init();
unsigned long ticks();

#endif // TIMER1_TICKS_H_INCLUDED
