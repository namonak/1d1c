// https://www.acmicpc.net/problem/2903

#include "boj/test_cases.h"
#include "unity.h"

#ifdef TEST
void test_no2903(void)
{
	struct test_case {
		int given;
		int expected;
	};

	struct test_case test_cases[] = {{1, 9},	 {2, 25},	  {3, 81},	   {4, 289},
					 {5, 1089},	 {6, 4225},	  {7, 16641},	   {8, 66049},
					 {9, 263169},	 {10, 1050625},	  {11, 4198401},   {12, 16785409},
					 {13, 67125249}, {14, 268468225}, {15, 1073807361}};

	for (int i = 0; i < sizeof(test_cases) / sizeof(struct test_case); i++) {
		struct test_case test_case = test_cases[i];
		int result = solve_no2903(test_case.given);
		TEST_ASSERT_EQUAL_INT(test_case.expected, result);
	}
}
#endif
