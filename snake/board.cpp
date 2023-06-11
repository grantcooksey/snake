#include "board.h"

#include "types.h"

display_position snake[GRID_SPACES] = {0};

void board_init() {
  snake[0] = {.x = 0, .y = 0};
  display_position *snake_head = &snake[0];
  uint16_t snake_head_index = 0;
  display_position *snake_tail = &snake[0];
  uint16_t snake_tail_index = 0;
}

display_position *board_get_snake_head() {}
