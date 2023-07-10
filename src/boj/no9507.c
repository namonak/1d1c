#include <stdio.h>

long long dp[68] = {
    1,
    1,
    2,
    4,
};

long long solve_no9507(int number) {
    if (number < 2)
        return 1;
    if (number == 2)
        return 2;
    if (number == 3)
        return 4;
    if (dp[number] != 0)
        return dp[number];

    for (int i = 4; i <= number; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
    }

    return dp[number];
}

#ifndef TEST
#ifdef NO9507
int main() {
    int t;
    int n[68];

    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n[i]);
    }

    for (int i = 0; i < t; i++) {
        printf("%lld\n", solve_no9507(n[i]));
    }

    return 0;
}
#endif
#endif
