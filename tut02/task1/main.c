/* main2.c */
#include <stdio.h>
#include "calc.h"

int main(void) {
    int i = 2;
    printf("Square of %d is %d", i, sq(i));
    printf("Cube of %f is %f", i, cube(i));
    printf("Negative of %f is %f", i, minus(i));
    return 0;
}