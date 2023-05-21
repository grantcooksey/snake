// non standard but widely supported version compared to #ifndef
#pragma once

#include <stdint.h>

struct bounds {
  int16_t width;
  int16_t height;
};

struct display_position {
  int16_t x;
  int16_t y;
};

void display_init();
void display_clear();
bounds display_get_bounds();
void display_fill_rect(display_position point, bounds snake_bounds);
