#include <stdio.h>

char solve_no27866(char S[], int i) {
    return S[i - 1];
}

#ifndef TEST
#ifdef NO27866
int main() {
    char S[1000];
    int i;

    scanf("%s", S);
    scanf("%d", &i);

    printf("%c", solve_no27866(S, i));

    return 0;
}
#endif
#endif
