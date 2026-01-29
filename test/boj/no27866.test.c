#include "boj/test_cases.h"
#include "unity.h"

#ifdef TEST
void test_no27866(void)
{
	struct test_case {
		char S[1000];
		int i;
		int expected;
	};

	struct test_case test_cases[] = {
	    {"Sprout", 3, 'r'},
	    {"shiftpsh", 6, 'p'},
	    {"Baekjoon", 4, 'k'},
	};

	for (int i = 0; i < sizeof(test_cases) / sizeof(struct test_case); i++) {
		struct test_case test_case = test_cases[i];
		int result = solve_no27866(test_case.S, test_case.i);
		TEST_ASSERT_EQUAL_CHAR(test_case.expected, result);
	}
}
#endif
