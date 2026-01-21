// https://www.acmicpc.net/problem/1924

#include "boj/test_cases.h"
#include "unity.h"

#ifdef TEST
void test_no1924(void) {
    struct test_case {
        int x;
        int y;
        const char *expected;
    };

    struct test_case test_cases[] = {
        {1, 1, "MON"}, {3, 14, "WED"}, {9, 2, "SUN"}, {12, 25, "TUE"}};

    for (int i = 0; i < sizeof(test_cases) / sizeof(struct test_case); i++) {
        struct test_case test_case = test_cases[i];
        const char *result;
        result = solve_no1924(test_case.x, test_case.y);
        TEST_ASSERT_EQUAL_STRING(test_case.expected, result);
    }
}
#endif
