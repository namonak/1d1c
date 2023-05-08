#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void test_multiply(void) {
    int a = 1;
    int b = 2;
    int expected = 2;
    int result = multiply(a, b);
    TEST_ASSERT_EQUAL_INT(expected, result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_multiply);
    return UNITY_END();
}
