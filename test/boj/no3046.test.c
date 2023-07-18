// https://www.acmicpc.net/problem/3046

#include "boj/test_cases.h"
#include "unity.h"

#ifdef TEST
void test_no3046(void) {
    struct test_case {
        int r1;
        int s;
        int r2;
    };

    struct test_case test_cases[] = {{11, 15, 19}, {4, 3, 2}};

    for (int i = 0; i < sizeof(test_cases) / sizeof(struct test_case); i++) {
        struct test_case test_case = test_cases[i];
        int result = solve_no3046(test_case.r1, test_case.s);
        TEST_ASSERT_EQUAL_INT(test_case.r2, result);
    }
}
#endif
