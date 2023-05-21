#include <stdbool.h>

#include "display.h"
#include "logger.h"

void start() {
  display_clear();
  bounds display_bounds = display_get_bounds();
  bounds snake_bounds = {.width = 10, .height = 10};
  display_position new_point = {.x = display_bounds.width - 10,
                                .y = display_bounds.height - 10};
  display_fill_rect(new_point, snake_bounds);

  // init snake block in top left
  // set random food - boundaries?
  // wait for press
  // start snake in direction of press (only down or right)
  while (true) {
  }
  // if head of snake == any position on the snake -> zero out snake blocks
  // if head of snake == food position -> add a block to end, wrap corner if at
  // edge
}
