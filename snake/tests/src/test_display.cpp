#include "CppUTest/TestHarness.h"

extern "C" {
    #include "display.h"
}

TEST_GROUP(TestMySum) {
    void setup() {}

    void teardown() {}
};

TEST(TestMySum, Test_MySumBasic) {
    LONGS_EQUAL(7, my_sum(3, 4));
}
