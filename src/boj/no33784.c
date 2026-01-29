#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "boj/no33784.h"

#define MAX_LINE_LENGTH 256

static int64_t calculate_double_area(int count, const Point *points)
{
	int64_t sum = 0;

	for (int i = 0; i < count; i++) {
		const Point *curr = &points[i];
		const Point *next = &points[(i + 1 == count) ? 0 : i + 1];

		sum += (curr->x * next->y) - (next->x * curr->y);
	}

	return (sum < 0) ? -sum : sum;
}

int64_t solve_no33784(int count, const Point *points)
{
	// 최소 삼각형 형태는 갖춰야 함
	if (count < 3)
		return 0;

	int64_t abs_double_area = calculate_double_area(count, points);

	return abs_double_area / 2;
}

#ifndef TEST
#ifdef NO33784
int main(void)
{
	char buffer[MAX_LINE_LENGTH];
	int count;

	if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
		return -1;
	}

	if (sscanf(buffer, "%d", &count) != 1) {
		fprintf(stderr, "Invalid count input\n");
		return -1;
	}

	Point *points = (Point *)malloc(sizeof(Point) * count);
	if (points == NULL) {
		perror("malloc");
		return -1;
	}

	for (int i = 0; i < count; i++) {
		if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
			fprintf(stderr, "Unexpected EOF at line %d\n", i + 2);
			free(points);
			return -1;
		}

		if (sscanf(buffer, "%ld %ld", &points[i].x, &points[i].y) != 2) {
			fprintf(stderr, "Invalid coordinate format at line %d\n", i + 2);
			free(points);
			return -1;
		}
	}

	printf("%ld\n", solve_no33784(count, points));

	free(points);
	return 0;
}
#endif
#endif
