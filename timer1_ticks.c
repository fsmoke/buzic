
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include "timer1_ticks.h"

volatile unsigned long timer1_ticks;

ISR (TIMER1_COMPA_vect)
{
    timer1_ticks++;
}

void timer1_ticks_init()
{
    // настройка таймера
    // CTC mode, Clock/8
    TCCR1B |= (1 << WGM12) | (1 << CS11);

    OCR1AH = (uint8_t)(CTC_MATCH_OVERFLOW >> 8);
    OCR1AL = (uint8_t) CTC_MATCH_OVERFLOW;

    // Разрешить прерывание таймера
    TIMSK1 |= (1 << OCIE1A);
}

unsigned long ticks()
{
    unsigned long ticks_return;

    // Ensure this cannot be disrupted
    ATOMIC_BLOCK(ATOMIC_FORCEON)
    {
        ticks_return = timer1_ticks;
    }

    return ticks_return;
}
