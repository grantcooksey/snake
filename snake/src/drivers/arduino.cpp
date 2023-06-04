#include "../../include/arduino.h"

#include <Arduino.h>

#include "../../types.h"

snake_length arduino_random(snake_length howbig) {
  return (snake_length)random(howbig);
}
