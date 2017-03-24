#include <avr/io.h>

FUSES = {
    //All bits are clear
    .low = 0xFF,
    .high = HFUSE_DEFAULT,
    .extended = EFUSE_DEFAULT
};
