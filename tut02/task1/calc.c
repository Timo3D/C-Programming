/* calc.c */

/*!
@file tut1.c
@author Timothy Wong (nicolas.pepe@digipen.edu)
@course RSE1201
@tutorial Tutorial 2 Task 2
@date 06/09/2022
@brief This file calculates the square, cube, and negative of x respectively.
*//*_____________________________________________________________*/

#include "calc.h"
int sq(int x) {
return x * x;
}

double cube(double x) {
    return x * x * x;
}

double minus(double x) {
    return -x;
}