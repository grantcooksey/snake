#pragma once

#include <stdint.h>

// dependant on a 128 X 128 tf, how should we scale this?

#define GRID_ROWS 16
#define GRID_COLS 16
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

typedef uint8_t snake_length;
