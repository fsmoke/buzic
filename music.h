#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include "timer1_ticks.h"

#define DIV_MASK (_BV(CS20) | _BV(CS21) |  _BV(CS22))

#define DIV_1024 (_BV(CS20) | _BV(CS21) |  _BV(CS22))
#define DIV_256 (_BV(CS21) |  _BV(CS22))
#define DIV_128 (_BV(CS20) |  _BV(CS22))
#define DIV_64 _BV(CS22)
#define DIV_32 (_BV(CS20) | _BV(CS21))

#define NOTE_1024( x ) ((F_CPU / (1024 * 2) / x) | (DIV_1024 << 8))
#define NOTE_256( x ) ((F_CPU / (256 * 2) / x) | (DIV_256 << 8))
#define NOTE_128( x ) ((F_CPU / (128 * 2) / x) | (DIV_128 << 8))
#define NOTE_64( x ) ((F_CPU / (64 * 2) / x) | (DIV_64 << 8))
#define NOTE_32( x ) ((F_CPU / (32 * 2) / x) | (DIV_32 << 8))

//большая октава
#define DOB NOTE_1024( 65 )
#define DO_B NOTE_1024( 69 )
#define REB NOTE_1024 ( 73 )
#define RE_B NOTE_1024 ( 78 )
#define MIB NOTE_1024 ( 82 )
#define FAB NOTE_1024 ( 87 )
#define FA_B NOTE_1024 ( 93 )
#define SOLB NOTE_1024 ( 98 )
#define SOL_B NOTE_1024 ( 104 )
#define LAB NOTE_1024 ( 110 )
#define LA_B NOTE_1024 ( 116 )
#define SIB NOTE_1024 ( 123 )

//малая октава
#define DOS NOTE_256( 131 )
#define DO_S NOTE_256( 138 )
#define RES NOTE_256 ( 146 )
#define RE_S NOTE_256 ( 155 )
#define MIS NOTE_256 ( 164 )
#define FAS NOTE_256 ( 174 )
#define FA_S NOTE_256 ( 185 )
#define SOLS NOTE_256 ( 196 )
#define SOL_S NOTE_256 ( 207 )
#define LAS NOTE_256 ( 219 )
#define LA_S NOTE_256 ( 233 )
#define SIS NOTE_256 ( 246 )

//первая октава
#define DO1 NOTE_256( 261 )
#define DO_1 NOTE_256( 277 )
#define RE1 NOTE_256 ( 293 )
#define RE_1 NOTE_256 ( 310 )
#define MI1 NOTE_256 ( 329 )
#define FA1 NOTE_256 ( 348 )
#define FA_1 NOTE_256 ( 369 )
#define SOL1 NOTE_256 ( 391 )
#define SOL_1 NOTE_256 ( 414 )
#define LA1 NOTE_256 ( 439 )
#define LA_1 NOTE_256 ( 465 )
#define SI1 NOTE_256 ( 493 )

//вторая октава
#define DO2 NOTE_128( 522 )
#define DO_2 NOTE_128( 553 )
#define RE2 NOTE_128 ( 586 )
#define RE_2 NOTE_128 ( 621 )
#define MI2 NOTE_128 ( 658 )
#define FA2 NOTE_128 ( 697 )
#define FA_2 NOTE_128 ( 738 )
#define SOL2 NOTE_128 ( 782 )
#define SOL_2 NOTE_128 ( 829 )
#define LA2 NOTE_128 ( 878 )
#define LA_2 NOTE_128 ( 930 )
#define SI2 NOTE_128 ( 985 )

//третья октава
#define DO3 NOTE_64( 1047 )
#define DO_3 NOTE_64( 1109 )
#define RE3 NOTE_64 ( 1175 )
#define RE_3 NOTE_64 ( 1245 )
#define MI3 NOTE_64 ( 1319 )
#define FA3 NOTE_64 ( 1397 )
#define FA_3 NOTE_64 ( 1480 )
#define SOL3 NOTE_64 ( 1568 )
#define SOL_3 NOTE_64 ( 1661 )
#define LA3 NOTE_64 ( 1760 )
#define LA_3 NOTE_64 ( 1865 )
#define SI3 NOTE_64 ( 1976 )

//четвертая октава
#define DO4 NOTE_32( 2093 )
#define DO_4 NOTE_32( 2217 )
#define RE4 NOTE_32 ( 2349 )
#define RE_4 NOTE_32 ( 2489 )
#define MI4 NOTE_32 ( 2637 )
#define FA4 NOTE_32 ( 2794 )
#define FA_4 NOTE_32 ( 2960 )
#define SOL4 NOTE_32 ( 3136 )
#define SOL_4 NOTE_32 ( 3322 )
#define LA4 NOTE_32 ( 3520 )
#define LA_4 NOTE_32 ( 3729 )
#define SI4 NOTE_32 ( 3951 )

#define EMPTY_NOTE 0

#define TEMPO( x ) (60000 * MS_DIVIDER * 4 / x)

#define DEL_MINUS_1 0b10000
#define DEL_MUL_3 0b01000

#define DEL_1 0
#define DEL_1N2 1
#define DEL_1N3 (2 | DEL_MINUS_1)
#define DEL_1N4 2
#define DEL_1N5 (1 | DEL_MINUS_1 | DEL_MUL_3)
#define DEL_1N6 (1 | DEL_MUL_3)
#define DEL_1N7 (3 | DEL_MINUS_1)
#define DEL_1N8 3

#define DEL_1N11 (2 | DEL_MUL_3 | DEL_MINUS_1)
#define DEL_1N12 (2 | DEL_MUL_3)

#define DEL_1N15 (4 | DEL_MINUS_1)
#define DEL_1N16 4

#define DEL_1N23 (3 | DEL_MUL_3 | DEL_MINUS_1)
#define DEL_1N24 (3 | DEL_MUL_3)

#define DEL_1N31 (5 | DEL_MINUS_1)
#define DEL_1N32 5

#define DEL_1N47 (4 | DEL_MUL_3 | DEL_MINUS_1)
#define DEL_1N48 (4 | DEL_MUL_3)

#define DEL_1N63 (6 | DEL_MINUS_1)
#define DEL_1N64 6

#define DEL_1N95 (5 | DEL_MUL_3 | DEL_MINUS_1)
#define DEL_1N96 (5 | DEL_MUL_3)

#define DEL_1N127 (7 | DEL_MINUS_1)
#define DEL_1N128 7

#define NOTE(delay, note) (uint16_t)((delay << 11) | note)

void timer2_buzzer_init();
void play_music_note(uint16_t note);
uint16_t calc_note_delay(uint16_t precalced_tempo, uint16_t note);
bool is_playing();

#endif // MUSIC_H_INCLUDED
