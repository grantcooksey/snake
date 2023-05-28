#include "checks.h"

#include "CppUTest/TestHarness.h"
#include "types.h"

void assert_display_position(display_position expected,
                             display_position result) {
  LONGS_EQUAL(expected.x, result.x);
  LONGS_EQUAL(expected.y, result.y);
}
