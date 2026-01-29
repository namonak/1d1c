#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "boj/no30223.h"

#define MAX_LINE_LENGTH 256

static int64_t calculate_doubled_slice_area(const Point *p, int32_t start, int32_t end)
{
	int64_t sum = 0;

	// start부터 end까지 순회하며 변(edge)을 계산
	for (int32_t k = start; k < end; k++) {
		sum += (p[k].x * p[k + 1].y) - (p[k + 1].x * p[k].y);
	}

	// 마지막 점(end)에서 다시 첫 점(start)으로 연결하는 닫는 변 계산
	sum += (p[end].x * p[start].y) - (p[start].x * p[end].y);

	return (sum < 0) ? -sum : sum;
}

double solve_no30223(int32_t n, const Point *points)
{
	// 전체 다각형의 2배 넓이 계산
	int64_t total_doubled = calculate_doubled_slice_area(points, 0, n - 1);
	int64_t min_doubled_diff = -1;

	// 브루트 포스 탐색
	for (int32_t i = 0; i < n; i++) {
		for (int32_t j = i + 2; j < n; j++) {
			// 인접한 점은 스킵 (시작-끝 인접 포함)
			if (i == 0 && j == n - 1)
				continue;

			// i부터 j까지의 조각 넓이 (2배수)
			int64_t sub_doubled = calculate_doubled_slice_area(points, i, j);

			// 두 조각의 넓이 차이의 2배수 계산
			// diff = |sub - (total - sub)| = |2 * sub - total|
			int64_t current_val = 2 * sub_doubled - total_doubled;
			int64_t diff_doubled = (current_val < 0) ? -current_val : current_val;

			// 최솟값 갱신
			if (min_doubled_diff == -1 || diff_doubled < min_doubled_diff) {
				min_doubled_diff = diff_doubled;
			}
		}
	}

	return (double)min_doubled_diff / 2.0;
}

#ifndef TEST
#ifdef NO30223
int main(void)
{
	char buffer[MAX_LINE_LENGTH];
	int32_t n;

	if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		return -1;
	if (sscanf(buffer, "%d", &n) != 1) {
		fprintf(stderr, "Invalid count input\n");
		return -1;
	}

	Point *points = (Point *)malloc(sizeof(Point) * n);
	if (points == NULL)
		return -1;

	for (int32_t i = 0; i < n; i++) {
		if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
			free(points);
			return -1;
		}
		if (sscanf(buffer, "%ld %ld", &points[i].x, &points[i].y) != 2) {
			fprintf(stderr, "Invalid coordinate format at line %d\n", i + 2);
			free(points);
			return -1;
		}
	}

	double min_2diff = solve_no30223(n, points);

	printf("%.1f\n", min_2diff);

	free(points);
	return 0;
}
#endif
#endif
