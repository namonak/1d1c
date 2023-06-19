#include <stdio.h>

int solve_no10807(int n, int arr[], int v) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == v) {
            count++;
        }
    }

    return count;
}

#ifndef TEST
#ifdef NO10807
int main() {
    int n, v;
    int arr[100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &v);

    printf("%d", solve_no10807(n, arr, v));

    return 0;
}
#endif
#endif
