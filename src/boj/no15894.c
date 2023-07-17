#include <stdio.h>

unsigned long solve_no15894(const unsigned long input) {
    return input * 4;
}

#ifndef TEST
#ifdef NO15894
int main() {
    long input;

    scanf("%ld", &input);

    printf("%ld", solve_no15894(input));

    return 0;
}
#endif
#endif