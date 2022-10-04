/*!
@file       qdriver.c 
@author     Swavek Wlodkowski (swavek.wlodkowski)
@course     CSD1120F20
@section    AB
@assignment 4
@date       08/10/2020
@brief      This file contains unit tests that exercise
            the sleeping_bag() function.
            Do not modify or submit this file.
*//*__________________________________________________________________________*/

#include <stdio.h>	// printf

void sleeping_bag(signed char temperature, unsigned char humidity);

int main(void)
{
	// test case 1
	sleeping_bag(100, 101);
	printf("\n");

	// test case 2
	sleeping_bag(35, 101);
	printf("\n");

	// test case 3
	sleeping_bag(30, 101);
	printf("\n");

	// test case 4
	sleeping_bag(20, 101);
	printf("\n");

	// test case 5
	sleeping_bag(15, 101);
	printf("\n");

	// test case 6
	sleeping_bag(12, 101);
	printf("\n");

	// test case 7
	sleeping_bag(-60, 101);
	printf("\n");

	// test case 8
	sleeping_bag(100, 50);
	printf("\n");

	// test case 9
	sleeping_bag(35, 50);
	printf("\n");

	// test case 10
	sleeping_bag(30, 50);
	printf("\n");

	// test case 11
	sleeping_bag(20, 50);
	printf("\n");

	// test case 12
	sleeping_bag(15, 50);
	printf("\n");

	// test case 13
	sleeping_bag(12, 50);
	printf("\n");

	// test case 14
	sleeping_bag(-60, 50);
	printf("\n");
	
	// test case 15
	sleeping_bag(100, 40);
	printf("\n");

	// test case 16
	sleeping_bag(35, 40);
	printf("\n");

	// test case 17
	sleeping_bag(30, 40);
	printf("\n");

	// test case 18
	sleeping_bag(20, 40);
	printf("\n");

	// test case 19
	sleeping_bag(15, 40);
	printf("\n");

	// test case 20
	sleeping_bag(12, 40);
	printf("\n");

	// test case 21
	sleeping_bag(-60, 40);
	printf("\n");
	
	// test case 22
	sleeping_bag(100, 23);
	printf("\n");

	// test case 23
	sleeping_bag(35, 23);
	printf("\n");

	// test case 24
	sleeping_bag(30, 23);
	printf("\n");

	// test case 25
	sleeping_bag(20, 23);
	printf("\n");

	// test case 26
	sleeping_bag(15, 23);
	printf("\n");

	// test case 27
	sleeping_bag(12, 23);
	printf("\n");

	// test case 28
	sleeping_bag(-60, 23);
	return 0;
}
