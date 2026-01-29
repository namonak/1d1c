// https://www.acmicpc.net/problem/33784

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include "unity.h"

#include "boj/no33784.h"
#include "test_io.h"

#ifdef TEST

void test_no33784(void)
{
	const char *filename = "test/boj/cases_33784.txt";
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
		TEST_FAIL_MESSAGE("Test file not found");

	struct stat sb;
	fstat(fd, &sb);
	const char *mapped = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	const char *cursor = mapped;

	int num_cases = (int)next_int64(&cursor);

	for (int t = 0; t < num_cases; t++) {
		int m = (int)next_int64(&cursor);
		Point *points = (Point *)malloc(sizeof(Point) * m);

		for (int i = 0; i < m; i++) {
			points[i].x = next_int64(&cursor);
			points[i].y = next_int64(&cursor);
		}

		int64_t actual = solve_no33784(m, points);
		int64_t expected = next_int64(&cursor);

		char msg[100];
		sprintf(msg, "Failed at Case #%d", t + 1);
		TEST_ASSERT_EQUAL_INT64_MESSAGE(expected, actual, msg);

		free(points);
	}

	munmap((void *)mapped, sb.st_size);
	close(fd);
}
#endif
