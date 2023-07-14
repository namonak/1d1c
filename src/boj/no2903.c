#include <math.h>
#include <stdio.h>

int solve_no2903(const int input) {
    return (int)pow(pow(2, input) + 1, 2);
}

#ifndef TEST
#ifdef NO2903
int main() {
    int input;

    scanf("%d", &input);

    printf("%d", solve_no2903(input));

    return 0;
}
#endif
#endif
