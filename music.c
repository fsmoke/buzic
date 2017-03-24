
#include <avr/io.h>
#include "project.h"
#include "music.h"

#define BUZ_PIN PB3

void timer2_buzzer_init()
{
   PORTB=0x00;
   cbi(DDRB, BUZ_PIN);

   TCCR2A = _BV(COM2A0) | _BV(WGM21);
   OCR2A = 0;
}

void play_music_note(uint16_t note)
{
   if (note)
   {
      TCCR2B = (note >> 8) & DIV_MASK;
      OCR2A = note & 0xff;
      sbi(DDRB, BUZ_PIN);
   }
   else
      cbi(DDRB, BUZ_PIN);
}

uint16_t calc_note_delay(uint16_t precalced_tempo, uint16_t note)
{
   note >>= 11;
   uint8_t divider = _BV(note & 0b00111);
   note >>= 3;
   divider *= ((note & 0b01) ? 3 : 1);
   divider -= (note >> 1);
   return (precalced_tempo / divider);
}

bool is_playing()
{
    return (is_high(DDRB, BUZ_PIN) ? true : false);
}
