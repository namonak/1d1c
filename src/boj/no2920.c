#include <stdio.h>

#define DIATONIC_SCALE_COUNT 8
#define STR_LEN 11

void solve_no2920(const int arr[], char result[])
{
	int is_ascending = 1;
	int is_descending = 1;

	for (int i = 0; i < DIATONIC_SCALE_COUNT - 1; i++) {
		int diff = arr[i + 1] - arr[i];
		if (diff != 1)
			is_ascending = 0;
		if (diff != -1)
			is_descending = 0;
	}

	if (is_ascending)
		sprintf(result, "ascending");
	else if (is_descending)
		sprintf(result, "descending");
	else
		sprintf(result, "mixed");
}

#ifndef TEST
#ifdef NO2920
int main()
{
	int arr[DIATONIC_SCALE_COUNT];
	char result[STR_LEN];

	for (int i = 0; i < DIATONIC_SCALE_COUNT; i++) {
		scanf("%d", &arr[i]);
	}

	solve_no2920(arr, result);

	printf("%s", result);

	return 0;
}
#endif
#endif
