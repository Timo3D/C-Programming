/******************************************************************************
* @filename q.c
* @author   Timothy Wong
* @SIT mail 2201258@sit.singaporetech.edu.sg 
* @course   RSE1201
* @date     26/10/2022
* @brief    This file contains the definition of the functions initialize, wc,
            and print_freqs. More information can be found below for each
            function.
******************************************************************************/

#include "q.h"

void initialize(int latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt) { //initializes all values to 0 so we won't get garbage values
    for (int i = 0; i < size; i++) {
        latin_freq[i] = 0;
    }
    *ctrl_cnt = 0;
    *non_latin_cnt = 0;
}

void wc(FILE *ifs, int latin_freq[], int *ctrl_cnt, int *non_latin_cnt) { //reads from the input file and checks each char and increments its respective counters.
    while (1) {
        int ch = (int) fgetc(ifs);
        if (ch == EOF) break;
        if (ch >= 65 && ch <= 90) {
            ch -= 65;
            latin_freq[ch]++;
        }
        else if (ch >= 97 && ch <= 122) {
            ch -= 97;
            latin_freq[ch]++;
        }
        else if (ch == 9 || ch == 11 || ch == 7 || ch == 10 || ch == 8 || ch == 12 || ch == 13) {
            (*ctrl_cnt)++;
        }
        else {
            (*non_latin_cnt)++;
        }
    }
}

void print_freqs(int const latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt) { //prints the formatted outputs.
    int latinCnt = 0;
    for (int i = 97; i <= 122; i++) {
        printf("%5c", i);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        latinCnt += latin_freq[i];
        printf("%5d", latin_freq[i]);
    }
    printf("\nLatin chars             :");
    printf("%6d", latinCnt);
    printf("\nNon-Latin non-ctrl chars:");
    printf("%6d\n", *non_latin_cnt);
    printf("Control chars           :");
    printf("%6d\n", *ctrl_cnt);
}