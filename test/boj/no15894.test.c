// https://www.acmicpc.net/problem/15894

#include "boj/test_cases.h"
#include "unity.h"

#ifdef TEST
void test_no15894(void) {
    struct test_case {
        unsigned long given;
        unsigned long expected;
    };

    struct test_case test_cases[] = {{1, 4},         {2, 8},
                                     {3, 12},        {4, 16},
                                     {5, 20},        {6, 24},
                                     {7, 28},        {8, 32},
                                     {9, 36},        {10, 40},
                                     {100, 400},     {1000, 4000},
                                     {10000, 40000}, {1000000000, 4000000000}};

    for (int i = 0; i < sizeof(test_cases) / sizeof(struct test_case); i++) {
        struct test_case test_case = test_cases[i];
        unsigned long result = solve_no15894(test_case.given);
        TEST_ASSERT_EQUAL_INT32(test_case.expected, result);
    }
}
#endif
