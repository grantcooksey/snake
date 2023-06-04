#include <stdbool.h>

#include "display.h"
#include "food.h"
#include "logger.h"
#include "types.h"

display_position snake[GRID_SPACES] = {0};
bool snake_slots_index[GRID_ROWS][GRID_COLS] = {0};
bounds block = {.width = SNAKE_WIDTH, .height = SNAKE_HEIGHT};

display_position draw_food(bool (*snake_slots)[GRID_COLS]);
direction wait_for_press();

void start() {
  display_clear();
  snake[0] = {.x = 0, .y = 0};
  snake_slots_index[0][0] = true;
  display_position *snake_head = &snake[0];
  display_position *snake_tail = &snake[0];
  display_fill_rect(*snake_head, block);

  display_position food = draw_food(&snake_slots_index[0]);

  bool is_first_press = true;
  while (true) {
    wait_for_press();
  }
  // if head of snake == any position on the snake -> zero out snake blocks
  // if head of snake == food position -> add a block to end, wrap corner if at
  // edge
}

display_position draw_food(bool (*snake_slots)[GRID_COLS]) {
  display_position food = new_food(snake_slots);
  display_fill_rect(food, block);
  return food;
}

direction wait_for_press() {
  // TODO
  delay(1000);
  return DIRECTION_RIGHT;
}
