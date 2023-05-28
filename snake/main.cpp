#include <stdbool.h>

#include "display.h"
#include "food.h"
#include "logger.h"
#include "types.h"

void start() {
  display_clear();
  bounds display_bounds = display_get_bounds();

  bounds block = {.width = SNAKE_WIDTH, .height = SNAKE_HEIGHT};
  display_position snake[GRID_SPACES] = {0};
  snake[0] = {.x = 0, .y = 0};
  display_position *snake_head = &snake[0];
  display_position *snake_tail = &snake[0];
  display_fill_rect(*snake_head, block);
  uint8_t snake_length = 1;

  display_position food = new_food(snake_head, snake_length);
  display_fill_rect(food, block);
  // wait for press
  // start snake in direction of press (only down or right)
  while (true) {
  }
  // if head of snake == any position on the snake -> zero out snake blocks
  // if head of snake == food position -> add a block to end, wrap corner if at
  // edge
}
