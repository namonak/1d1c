#include <stdio.h>

const char *solve_no1924(const int x, const int y) {
    const char *days[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    const int days_in_month[] = {31, 28, 31, 30, 31, 30,
                                 31, 31, 30, 31, 30, 31};
    int days_passed = 0;

    for (int i = 0; i < x - 1; i++) {
        days_passed += days_in_month[i];
    }

    days_passed += y;

    return (char *)days[days_passed % 7];
}

#ifndef TEST
#ifdef NO1924
int main() {
    int x, y;

    scanf("%d %d", &x, &y);

    printf("%s", solve_no1924(x, y));

    return 0;
}
#endif
#endif
