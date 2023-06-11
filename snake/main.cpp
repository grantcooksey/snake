#include <stdbool.h>

#include "board.h"
#include "controls.h"
#include "display.h"
#include "food.h"
#include "include/arduino.h"
#include "logger.h"
#include "types.h"

bool game_grid[GRID_ROWS][GRID_COLS] = {0};

direction wait_for_first_press();
void draw(display_position point);

void start() {
  display_clear();
  game_grid[0][0] = true;
  board_init();
  display_position food = new_food(game_grid);

  draw(*board_get_snake_head());
  draw(food);

  wait_for_first_press();

  bool is_first_press = true;

  while (true) {
    avr_ulong now = arduino_millis();
    // direction = get press(direction)  <-  fixed_timing
    // next_position = next_block(snake head,press_direction)
    // if (collision(next_position))
    //    game over
    // Add new head to snake > *next_head = snake + 1; next_head = position
    // draw head
    // if (can_eat_food(food, next_position))
    //    reset_food()
    // else
    //    clear_display(snake_tail)
    //    game_grid[snake_tail] = false
    //    snake_tail = snake_tail[+1]
    //
    //
    direction pressed_direction = wait_for_first_press();
  }
  // if head of snake == any position on the snake -> zero out snake blocks
  // if head of snake == food position -> add a block to end, wrap corner if at
  // edge
}

direction wait_for_first_press() {
  direction pressed = DIRECTION_NONE;
  do {
    direction pressed = controls_check_press();
    if (pressed == DIRECTION_NONE) {
      arduino_delay(20);
    }
  } while (pressed == DIRECTION_NONE);

  return pressed;
}

void draw(display_position point) {
  display_fill_rect(*board_get_snake_head(),
                    {.width = SNAKE_WIDTH, .height = SNAKE_HEIGHT});
}
