#include <stdio.h>

int solve_no9095(int number)
{
	int dp[11] = {0, 1, 2, 4};

	for (int i = 4; i <= number; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	return dp[number];
}

#ifndef TEST
#ifdef NO9095
int main()
{
	int t, n;

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%d\n", solve_no9095(n));
	}

	return 0;
}
#endif
#endif
