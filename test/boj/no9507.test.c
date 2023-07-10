#include "boj/test_cases.h"
#include "unity.h"

#ifdef TEST
void test_no9507(void) {
    struct test_case {
        int t;
        int n[68];
        long long expected[68];
    };

    struct test_case test_cases[] = {
        8,
        {0, 1, 2, 3, 4, 5, 30, 67},
        {1, 1, 2, 4, 8, 15, 201061985, 7057305768232953720}};

    for (int i = 0; i < sizeof(test_cases) / sizeof(struct test_case); i++) {
        struct test_case test_case = test_cases[i];
        for (int j = 0; j < test_case.t; j++) {
            long long result = solve_no9507(test_case.n[j]);
            TEST_ASSERT_EQUAL_INT(test_case.expected[j], result);
        }
    }
}
#endif
