#include <stdio.h>

int solve_no15439(int n)
{
	return n * (n - 1);
}

#ifndef TEST
#ifdef NO15439
int main()
{
	int n;

	scanf("%d", &n);

	printf("%d", solve_no15439(n));

	return 0;
}
#endif
#endif
