#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROBLEM_COUNT 8
#define TOP_SCORES_COUNT 5

int descending_order(const void *a, const void *b)
{
	int int_a = *((int *)a);
	int int_b = *((int *)b);

	if (int_a == int_b)
		return 0;
	else if (int_a > int_b)
		return -1;
	else
		return 1;
}

int ascending_order(const void *a, const void *b)
{
	int int_a = *((int *)a);
	int int_b = *((int *)b);

	if (int_a == int_b)
		return 0;
	else if (int_a < int_b)
		return -1;
	else
		return 1;
}

void solve_no2822(const int scores[], int *const result_int, int result_arr[])
{
	int *sorted_scores = malloc(sizeof(int) * PROBLEM_COUNT);

	memcpy(sorted_scores, scores, sizeof(int) * PROBLEM_COUNT);

	qsort(sorted_scores, PROBLEM_COUNT, sizeof(int), descending_order);

	for (int i = 0; i < TOP_SCORES_COUNT; i++) {
		*result_int += sorted_scores[i];
		for (int j = 0; j < PROBLEM_COUNT; j++) {
			if (sorted_scores[i] == scores[j]) {
				result_arr[i] = j + 1;
				break;
			}
		}
	}

	free(sorted_scores);

	qsort(result_arr, TOP_SCORES_COUNT, sizeof(int), ascending_order);
}

#ifndef TEST
#ifdef NO2822
int main()
{
	int scores[PROBLEM_COUNT];
	int result_int = 0;
	int result_arr[TOP_SCORES_COUNT];

	for (int i = 0; i < PROBLEM_COUNT; i++) {
		scanf("%d", &scores[i]);
	}

	solve_no2822(scores, &result_int, result_arr);

	printf("%d\n", result_int);
	for (int i = 0; i < TOP_SCORES_COUNT; i++) {
		printf("%d ", result_arr[i]);
	}

	return 0;
}
#endif
#endif
