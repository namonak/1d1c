// https://www.acmicpc.net/problem/9095

#include "boj/test_cases.h"
#include "unity.h"

#ifdef TEST
void test_no9095(void) {
    struct test_case {
        int t;
        int n[50];
        int expected[50];
    };

    struct test_case test_cases[] = {{3, {4, 7, 10}, {7, 44, 274}}};

    for (int i = 0; i < sizeof(test_cases) / sizeof(struct test_case); i++) {
        struct test_case test_case = test_cases[i];
        for (int j = 0; j < test_case.t; j++) {
            int result = solve_no9095(test_case.n[j]);
            TEST_ASSERT_EQUAL_INT(test_case.expected[j], result);
        }
    }
}
#endif
