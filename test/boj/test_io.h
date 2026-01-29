#ifndef TEST_BOJ_TEST_IO_H
#define TEST_BOJ_TEST_IO_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

static inline void next_string(const char **cursor, char *buf, size_t buf_size)
{
	while (**cursor && (**cursor == ' ' || **cursor == '\n' || **cursor == '\r')) {
		(*cursor)++;
	}
	size_t i = 0;
	while (**cursor && **cursor != ' ' && **cursor != '\n' && **cursor != '\r' && i < buf_size - 1) {
		buf[i++] = *(*cursor)++;
	}
	buf[i] = '\0';
}

static inline int64_t next_int64(const char **cursor)
{
	char *endptr;
	int64_t val = strtoll(*cursor, &endptr, 10);
	*cursor = endptr;
	return val;
}

static inline double next_double(const char **cursor)
{
	char *endptr;
	double val = strtod(*cursor, &endptr);
	*cursor = endptr;
	return val;
}

#endif
