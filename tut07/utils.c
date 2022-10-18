/******************************************************************************
* @filename utils.c
* @author   Timothy Wong
* @SIT mail 2201258@sit.singaporetech.edu.sg 
* @course   RSE1201
* @date     18/10/2022
* @brief    Function definitions for reading total counts, reading 3 numbers,
            swapping, sorting 3 numbers, and maintaining the 3 largest nums.
******************************************************************************/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

size_t read_total_count(void) { //reads the number of integers. if value read is <3, exit with error.
    printf("Please enter the number of integers: ");
    long unsigned int numInts;
    scanf("%zu", &numInts);
    if (numInts >= 3) {
        return numInts;
    }
    else {
        printf("There is no third largest number.\n");
        exit(EXIT_FAILURE);
    }
    
}

void read_3_numbers(int *first, int *second, int *third) { //reads 3 integers
    scanf("%d %d %d", first, second, third);
}

void swap(int* lhs, int* rhs) { //swaps 2 values
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

void sort_3_numbers(int *first, int *second, int *third) { //uses bubble sort to sort 3 integers
    for (int i = 0; i < 3; i++) { 
        if (*first < *second) {
            swap(first, second);
        }
        if (*second < *third) {
            swap(second, third);
        }
    }
}

void maintain_3_largest(int number, int *first, int *second, int *third) { //maintains the largest 3 numbers when a new value is inserted.
    if (number > *third) {
        swap(&number, third);
        sort_3_numbers(first, second, third);
    }
}