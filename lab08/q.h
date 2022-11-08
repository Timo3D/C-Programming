/******************************************************************************
* @filename q.h
* @author   Timothy Wong
* @SIT mail 2201258@sit.singaporetech.edu.sg 
* @course   RSE1201
* @date     26/10/2022
* @brief    This file contains the declaration of the functions initialize, wc,
            and print_freqs. More information can be found below for each
            function.
******************************************************************************/

#include <stdio.h>

void initialize(int latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt); //initializes all values to 0 so we won't get garbage values
void wc(FILE *ifs, int latin_freq[], int *ctrl_cnt, int *non_latin_cnt); //reads from the input file and checks each char and increments its respective counters.
void print_freqs(int const latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt); //prints the formatted outputs.