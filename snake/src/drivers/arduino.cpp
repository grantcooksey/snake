#include "../../include/arduino.h"

#include <Arduino.h>

#include "../../types.h"

snake_length arduino_random(snake_length howbig) {
  return (snake_length)random(howbig);
}

avr_ulong arduino_millis() { return (avr_ulong)millis(); }

void arduino_delay(avr_ulong delay_ms) { delay(delay_ms); }
