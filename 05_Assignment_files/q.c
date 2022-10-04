/*!
@file       q.c
@author     Timothy Wong
@course     RSE1201
@assignment 05
@date       04 October 2022
@brief      This file contains the function sleeping_bag() which determines the best sleeping bag for the weather condition.
*//*__________________________________________________________________________*/

#include <stdio.h>	// printf
#include <string.h>
void sleeping_bag(signed char temperature, unsigned char humidity) //this function validates user input and determines the bag type and insulation type for the best sleeping bag given the weather conditions.
{
	if ((humidity <= 0 || humidity > 100) || (temperature < -50 || temperature > 100)) {
		printf("Invalid input!\n");
		return;
	}
	else {
		printf("The temperature is %d*C, humidity is %u%%.\n", temperature, humidity);

		if (temperature >= 30) {
			printf("The best sleeping bag is Summer type insulated with ");
		}
		else if (temperature < 15) {
			printf("The best sleeping bag is Winter type insulated with ");
		}
		else {
			printf("The best sleeping bag is 3-Season type insulated with ");
		}
		if (humidity > 40) {
			printf("Synthetic.\n");
		}
		else {
			printf("Down.\n");
		}
	}
}
