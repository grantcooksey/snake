#pragma once

#include <stdint.h>

// dependant on a 128 X 128 tf, how should we scale this?

#define GRID_ROWS 15
#define GRID_COLS 15
#define SNAKE_WIDTH 8
#define SNAKE_HEIGHT 8
#define GRID_SPACES GRID_ROWS* GRID_COLS

struct bounds {
  int16_t width;
  int16_t height;
};

struct display_position {
  int16_t x;
  int16_t y;
};

enum direction {
  DIRECTION_UP,
  DIRECTION_RIGHT,
  DIRECTION_DOWN,
  DIRECTION_LEFT,
  DIRECTION_NONE
};

typedef uint8_t snake_length;

// From the avr docs
// signed char / unsigned char -> int8_t / uint8_t -> 8-bit
// signed int / unsigned int -> int16_t / uint16_t -> 16-bit
// signed long / unsigned long -> int32_t / uint32_t -> 32-bit
// signed long long / unsigned long long -> int64_t / uint64_t -> 64-bit
typedef uint32_t avr_ulong;
