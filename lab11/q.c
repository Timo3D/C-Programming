#include <stdio.h>
#include "q.h"

void print_data(const void* ptr, size_t size, size_t span) {
    const char* tbl = (const char*) ptr;
    long unsigned int rows = size / span;

    for (long unsigned int x = 0; x < rows; x++) {
        for (long unsigned int i = 0; i < span; i++) {
            if (i % 4 == 0 && i != 0) printf("  ");
            printf("%x ", *(tbl + i + span * x));
        }
        printf("  |  ");
        for (long unsigned int i = 0; i < span; i++) {
            if (i % 4 == 0 && i != 0) printf("  ");
            printf(" %c", *(tbl + i + span * x));
        }
        printf("\n");
    }
    return;
}