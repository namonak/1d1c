#include <stdio.h>

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", multiply(a, b));
    return 0;
}
