#include "CppUTest/TestHarness.h"
#include "checks.h"
#include "food.h"
#include "types.h"

TEST_GROUP(TestFood){void setup(){}

                     void teardown(){}};

TEST(TestFood, Test_NewFoodSkipsTakenRows) {
  bool snake_board[GRID_ROWS][GRID_COLS] = {0};
  snake_board[0][0] = true;
  snake_board[0][1] = true;
  display_position food = new_food(&snake_board[0]);
  display_position expected = {.x = 0, .y = 5};
  assert_display_position(food, expected);
}

TEST(TestFood, Test_NewFoodNoSkips) {
  bool snake_board[GRID_ROWS][GRID_COLS] = {0};
  display_position food = new_food(&snake_board[0]);
  display_position expected = {.x = 0, .y = 3};
  assert_display_position(food, expected);
}

TEST(TestFood, Test_NewFoodModulo) {
  bool snake_board[GRID_ROWS][GRID_COLS] = {0};
  for (int i = 0; i < GRID_ROWS; i++) {
    for (int j = 0; j < GRID_COLS; j++) {
      if (i == 1 && (j == 0 || j == 1)) {
        continue;
      }
      snake_board[i][j] = true;
    }
  }
  display_position food = new_food(&snake_board[0]);
  display_position expected = {.x = 1, .y = 1};
  assert_display_position(food, expected);
}
