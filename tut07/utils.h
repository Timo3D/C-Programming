#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>	// size_t

size_t read_total_count(void);

void read_3_numbers(
	int* first,
	int* second,
	int* third);

void swap(
	int* lhs,
	int* rhs);

void sort_3_numbers(
	int* first,
	int* second,
	int* third);

void maintain_3_largest(
	int number,
	int* first,
	int* second,
	int* third);

#endif
