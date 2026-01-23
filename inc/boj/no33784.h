#ifndef INC_1D1C_NO33784_H
#define INC_1D1C_NO33784_H

#include <stdint.h>

typedef struct {
    int64_t x;
    int64_t y;
} Point;

int64_t solve_no33784(int count, const Point *points);
void test_no33784(void);

#endif // INC_1D1C_NO33784_H
