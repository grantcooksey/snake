#include "food.h"

#include "include/arduino.h"
#include "types.h"

display_position new_food(bool (*snake_slots)[GRID_COLS]) {
  snake_length new_food_count = arduino_random(GRID_SPACES - 1);
  display_position new_food_position = {.x = 0, .y = 0};
  while (new_food_count > 0) {
    for (uint8_t i = 0; i < GRID_COLS; i++) {
      for (uint8_t j = 0; j < GRID_ROWS; j++) {
        if (snake_slots[i][j]) {
          continue;
        } else if (new_food_count == 0) {
          return {.x = i, .y = j};
        }
        new_food_count--;
      }
    }
  }

  return new_food_position;
}
