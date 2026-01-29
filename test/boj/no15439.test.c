#include "boj/test_cases.h"
#include "unity.h"

#ifdef TEST
void test_no15439(void)
{
	struct test_case {
		int n;
		int expected;
	};

	struct test_case test_cases[] = {{1, 0}, {2, 2}, {5, 20}};

	for (int i = 0; i < sizeof(test_cases) / sizeof(struct test_case); i++) {
		struct test_case test_case = test_cases[i];
		int result = solve_no15439(test_case.n);
		TEST_ASSERT_EQUAL_INT(test_case.expected, result);
	}
};
#endif
