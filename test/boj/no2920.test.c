// https://www.acmicpc.net/problem/2920

#include "boj/test_cases.h"
#include "unity.h"

#define DIATONIC_SCALE_COUNT 8
#define STR_LEN 11

#ifdef TEST
void test_no2920(void) {
    struct test_case {
        int arr[DIATONIC_SCALE_COUNT];
        char expected[STR_LEN];
    };

    struct test_case test_cases[] = {
        {{1, 2, 3, 4, 5, 6, 7, 8}, "ascending"},
        {{8, 7, 6, 5, 4, 3, 2, 1}, "descending"},
        {{8, 1, 7, 2, 6, 3, 5, 4}, "mixed"},
    };

    for (int i = 0; i < sizeof(test_cases) / sizeof(struct test_case); i++) {
        struct test_case test_case = test_cases[i];
        char result[STR_LEN];
        solve_no2920(test_case.arr, result);
        TEST_ASSERT_EQUAL_STRING(test_case.expected, result);
    }
}
#endif
