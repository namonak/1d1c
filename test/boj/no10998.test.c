#include "unity.h"
#include "boj/test_cases.h"

#ifdef TEST
int main() {
    UNITY_BEGIN();
    RUN_TEST(test_no10998);
    UNITY_END();
    return 0;
}

void test_no10998(void) {
    int a = 1;
    int b = 2;
    int expected = 2;
    int result = solve_no10998(a, b);
    TEST_ASSERT_EQUAL_INT(expected, result);
}

void setUp(void) {}

void tearDown(void) {}
#endif
