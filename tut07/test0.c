#include <stdio.h>
#include "utils.h"

int main(void)
{
	size_t count = read_total_count(); // Tested function
	printf("Input value was %zu.\n", count);
}
