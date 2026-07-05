#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "boj/no30223.h"

#define MAX_LINE_LENGTH 256

static int64_t cross_product(const Point *a, const Point *b)
{
	return (a->x * b->y) - (b->x * a->y);
}

static int64_t abs_int64(int64_t value)
{
	return (value < 0) ? -value : value;
}

static void build_edge_prefix(const Point *p, int32_t n, int64_t edge_prefix[])
{
	edge_prefix[0] = 0;

	for (int32_t i = 0; i < n; i++) {
		int32_t next = (i + 1 == n) ? 0 : i + 1;
		edge_prefix[i + 1] = edge_prefix[i] + cross_product(&p[i], &p[next]);
	}
}

static int64_t calculate_doubled_slice_area(const Point *p, const int64_t edge_prefix[], int32_t start, int32_t end)
{
	int64_t path_sum = edge_prefix[end] - edge_prefix[start];
	int64_t closing_edge = cross_product(&p[end], &p[start]);

	return abs_int64(path_sum + closing_edge);
}

double solve_no30223(int32_t n, const Point *points)
{
	int64_t *edge_prefix = (int64_t *)malloc(sizeof(int64_t) * (n + 1));
	if (edge_prefix == NULL)
		return 0.0;

	build_edge_prefix(points, n, edge_prefix);

	// 전체 다각형의 2배 넓이 계산
	int64_t total_doubled = abs_int64(edge_prefix[n]);
	int64_t min_doubled_diff = -1;

	// 브루트 포스 탐색
	for (int32_t i = 0; i < n; i++) {
		for (int32_t j = i + 2; j < n; j++) {
			// 인접한 점은 스킵 (시작-끝 인접 포함)
			if (i == 0 && j == n - 1)
				continue;

			// i부터 j까지의 조각 넓이 (2배수)
			int64_t sub_doubled = calculate_doubled_slice_area(points, edge_prefix, i, j);

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

	free(edge_prefix);
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
