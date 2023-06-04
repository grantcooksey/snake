#include "checks.h"

#include "CppUTest/TestHarness.h"
#include "types.h"

void assert_display_position(display_position result,
                             display_position expected) {
  LONGS_EQUAL(expected.x, result.x);
  LONGS_EQUAL(expected.y, result.y);
}
