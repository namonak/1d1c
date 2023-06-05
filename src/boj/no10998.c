#include <stdio.h>

int solve_no10998(int a, int b) {
    return a * b;
}

#ifndef TEST
#ifdef NO10998
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", solve_no10998(a, b));
    return 0;
}
#endif
#endif
