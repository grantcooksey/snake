// non standard but widely supported version compared to #ifndef
#pragma once

#include <stdint.h>

#include "types.h"

void display_init();
void display_clear();
bounds display_get_bounds();
void display_fill_rect(display_position point, bounds snake_bounds);
