#include <stdio.h>

int solve_no3046(const int r1, const int s) {
    return s * 2 - r1;
}

#ifndef TEST
#ifdef NO3046
int main() {
    int r1, s;

    scanf("%d %d", &r1, &s);

    printf("%d", solve_no3046(r1, s));

    return 0;
}
#endif
#endif
