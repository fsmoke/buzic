/*
 */

#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "music.h"
#include "project.h"
#include "timer1_ticks.h"

const uint16_t king[] PROGMEM =
{
   NOTE(DEL_1N4, MI3),
   NOTE(DEL_1N4, FA_3),
   NOTE(DEL_1N4, SOL3),
   NOTE(DEL_1N4, LA3),

   NOTE(DEL_1N4, SI3),
   NOTE(DEL_1N4, SOL3),
   NOTE(DEL_1N2, SI3),

   NOTE(DEL_1N4, LA_3),
   NOTE(DEL_1N4, FA_3),
   NOTE(DEL_1N4, LA_3),
   NOTE(DEL_1N4, EMPTY_NOTE),

   NOTE(DEL_1N4, LA3),
   NOTE(DEL_1N4, FA3),
   NOTE(DEL_1N2, LA3),

   NOTE(DEL_1N4, MI3),
   NOTE(DEL_1N4, FA_3),
   NOTE(DEL_1N4, SOL3),
   NOTE(DEL_1N4, LA3),

   NOTE(DEL_1N4, SI3),
   NOTE(DEL_1N4, SOL3),
   NOTE(DEL_1N4, SI3),
   NOTE(DEL_1N4, MI4),

   NOTE(DEL_1N4, RE4),
   NOTE(DEL_1N4, SI3),
   NOTE(DEL_1N4, SOL3),
   NOTE(DEL_1N4, SI3),

   NOTE(DEL_1N2, RE4),
   NOTE(DEL_1N2, EMPTY_NOTE),
};

int main(void)
{
    timer1_ticks_init();
    // разрешаем прерывания
    sei();
    timer2_buzzer_init();

    //в миллисекундах деленных на MS_DIVIDER
    long time_since = ticks();

    //текущая длительность ноты в миллисекундах деленных на MS_DIVIDER
    uint16_t note_delay = 0;
    //текущая позиция в массиве мелодии
    uint16_t note_pos = 0;
    //длина мелодии
    uint16_t length = sizeof(king) / sizeof(king[0]);
    uint16_t tempo = TEMPO(240);

    for(;;)
    {
            unsigned long time_current = ticks();
            if (time_current - time_since > note_delay)
            {
                //читаем элемент массива
                uint16_t note = pgm_read_word(&king[note_pos]);
                //установить частоту ноты
                play_music_note(note);
                //вычислить длительность проигрывания ноты
                note_delay = calc_note_delay(tempo, note);
                //зациклить мелодию
                if (++note_pos >= length)
                    note_pos = 0;
                time_since = time_current;
            }
    }
    return 0;
}
