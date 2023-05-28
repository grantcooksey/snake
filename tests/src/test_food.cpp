#include "CppUTest/TestHarness.h"
#include "checks.h"
#include "food.h"
#include "types.h"

TEST_GROUP(TestFood){void setup(){}

                     void teardown(){}};

// Test with small grid, never issues on top of snake
TEST(TestFood, Test_NewFood) {
  display_position snake[] = {{.x = 0, .y = 0}};
  display_position expected = {.x = 1, .y = 2};
  display_position result = new_food(&snake[0], 1);
  assert_display_position(result, expected);
}
