#include <stdio.h>

int solve_no2512(int number_of_cities, const int cities[], int budget) {
    int max = 0;

    for (int i = 0; i < number_of_cities; i++) {
        if (max < cities[i]) {
            max = cities[i];
        }
    }

    int left = 0;
    int right = max;

    while (left <= right) {
        int mid = (left + right) / 2;
        int sum = 0;

        for (int i = 0; i < number_of_cities; i++) {
            if (cities[i] > mid) {
                sum += mid;
            } else {
                sum += cities[i];
            }
        }

        if (sum <= budget) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}

#ifndef TEST
#ifdef NO2512
int main() {
    int number_of_cities, budget;
    int cities[10000];

    scanf("%d", &number_of_cities);
    for (int i = 0; i < number_of_cities; i++) {
        scanf("%d", &cities[i]);
    }
    scanf("%d", &budget);

    printf("%d", solve_no2512(number_of_cities, cities, budget));

    return 0;
}
#endif
#endif