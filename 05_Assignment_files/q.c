/*!
@file       @todo
@author     @todo
@course     @todo
@section    @todo
@assignment @todo
@date       @todo
@brief      @todo
*//*__________________________________________________________________________*/

#include <stdio.h>	// printf

void sleeping_bag(signed char temperature, unsigned char humidity)
{
	if ((humidity <= 0 || humidity > 100) || (temperature < -50 || temperature > 100)) {
		printf("Invalid input!\n");
		return;
	}
	else {
		printf("The temperature is %d*C, humidity is %u%%.\n", temperature, humidity);
	}
}
