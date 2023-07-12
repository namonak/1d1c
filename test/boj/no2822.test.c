// https://www.acmicpc.net/problem/2822

#include "boj/test_cases.h"
#include "unity.h"

#define PROBLEM_COUNT 8
#define TOP_SCORES_COUNT 5

#ifdef TEST
void test_no2822(void) {
    struct test_case {
        int score[PROBLEM_COUNT];
        int expected_int;
        int expected_arr[TOP_SCORES_COUNT];
    };

    struct test_case test_cases[] = {
        {{20, 30, 50, 48, 33, 66, 0, 64}, 261, {3, 4, 5, 6, 8}},
        {{20, 0, 50, 80, 77, 110, 56, 48}, 373, {3, 4, 5, 6, 7}},
        {{20, 30, 50, 80, 110, 11, 0, 85}, 355, {2, 3, 4, 5, 8}}};

    for (int i = 0; i < sizeof(test_cases) / sizeof(struct test_case); i++) {
        struct test_case test_case = test_cases[i];
        int result_int = 0;
        int result_arr[TOP_SCORES_COUNT];
        solve_no2822(test_case.score, &result_int, result_arr);
        TEST_ASSERT_EQUAL_INT(test_case.expected_int, result_int);
        TEST_ASSERT_EQUAL_INT_ARRAY(test_case.expected_arr, result_arr,
                                    TOP_SCORES_COUNT);
    }
}
#endif
