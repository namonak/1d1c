#include "boj/test_cases.h"
#include "unity.h"

#ifdef TEST
void test_no2512(void)
{
	struct test_case {
		int number_of_cities;
		int cities[10000];
		int budget;
		int expected;
	};

	struct test_case test_cases[] = {{4, {120, 110, 140, 150}, 485, 127}, {5, {70, 80, 30, 40, 100}, 450, 100}};

	for (int i = 0; i < sizeof(test_cases) / sizeof(struct test_case); i++) {
		struct test_case test_case = test_cases[i];
		int result = solve_no2512(test_case.number_of_cities, test_case.cities, test_case.budget);
		TEST_ASSERT_EQUAL_INT(test_case.expected, result);
	}
}
#endif
