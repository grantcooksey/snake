#include "food.h"

#include <Arduino.h>

#include "types.h"

display_position new_food(bool (*snake_slots)[GRID_COLS]) {
  long new_food = random(0, GRID_SPACES);
  uint8_t free_spaces = GRID_SPACES - 1;
  for (uint8_t i = 0; i < GRID_COLS; i++) {
    for (uint8_t j = 0; j < GRID_ROWS; j++) {
      if (snake_slots[i][j]) {
        free_spaces--;
      }
    }
  }
  for (uint8_t i = 0; i < GRID_COLS; i++) {
    for (uint8_t j = 0; j < GRID_ROWS; j++) {
      if (free_spaces == 0) {
        return {.x = i, .y = j};
      }
      if (!snake_slots[i][j]) {
        free_spaces--;
      }
    }
  }
}
