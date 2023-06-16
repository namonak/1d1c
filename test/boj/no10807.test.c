#include "unity.h"
#include "boj/test_cases.h"

#ifdef TEST
void test_no10807(void) {
    struct test_case {
        int n;
        int arr[100];
        int v;
        int expected;
    };

    struct test_case test_cases[] = {
        {11, {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4}, 2, 3},
        {11, {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4}, 5, 0}
    };

    for (int i = 0; i < sizeof(test_cases) / sizeof(struct test_case); i++) {
        struct test_case test_case = test_cases[i];
        int result = solve_no10807(test_case.n, test_case.arr, test_case.v);
        TEST_ASSERT_EQUAL_INT(test_case.expected, result);
    }
}
#endif
