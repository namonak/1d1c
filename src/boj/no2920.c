#include <stdio.h>

#define DIATONIC_SCALE_COUNT 8
#define STR_LEN 11

void solve_no2920(const int arr[], char result[]) {
    for (int i = 1; i < DIATONIC_SCALE_COUNT - 1; i++) {
        if (arr[i + 1] - arr[i] == 1) {
            sprintf(result, "ascending");
        } else if (arr[i + 1] - arr[i] == -1) {
            sprintf(result, "descending");
        } else {
            sprintf(result, "mixed");
            break;
        }
    }
}

#ifndef TEST
#ifdef NO2920
int main() {
    int arr[DIATONIC_SCALE_COUNT];
    char result[STR_LEN];

    for (int i = 0; i < DIATONIC_SCALE_COUNT; i++) {
        scanf("%d", &arr[i]);
    }

    solve_no2920(arr, result);

    printf("%s", result);

    return 0;
}
#endif
#endif
