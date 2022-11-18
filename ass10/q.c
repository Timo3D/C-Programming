/*
@file       q.h
@author     Timothy Wong
@course     RSE1201 C programming
@section 
@assignment Assignment 10
@date       18/11/2022
@brief      Consist of 9 function definitions
            1. Function read_data used to read string data an return a double array
            2. Function max used to find largest double element in the array
            3. Function min used to find smallest double element in the array
            4. Function average used to find average of elements in the array
            5. Function variance used to find variance of elements in the array
            6. Function std_dev used to find standard deviation of elements in the array
            7. Function median used to find median of elements in the array
            8. Function selection_sort used to find sort the elements in the array in ascending order
            9. Function Itr_grade_pctg get the percentage of each grade


*/ /*___________________________________________________________________________________________________*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "q.h"

/*!
@brief      Function read_data used to read string data an return a double array  
@param word char const *file_name, int *ptr_cnt
@return     double *  
*//*_____________________________________________________________*/

double *read_data(char const *file_name, int *ptr_cnt) {
    FILE *file = fopen(file_name, "r");
    int position = 0, checkspace = 0, totalgrade = 0, c = 0,gradecounter = 0;
    double grade[4], array[1000];
    for (int i = 0; array[i]; i++)
        array[i] = '\0';
    for (int i = 0; grade[i]; i++) 
        grade[i] = '\0';
    while ((c = fgetc(file)) != EOF) {
        checkspace = isspace(c);
        char character = (char) c;
        if (checkspace == 0 && character != '.') {
            int ASCII = (int) character;
            double number = (double) ASCII - 48, num1, num2, num3, num4, sum;
            grade[position] = number;
            if (position == 3) {
                num1 = grade[0] * 10, num2 = grade[1], num3 = grade[2] * 0.1, num4 = grade[3] * 0.01, sum = num1 + num2 + num3 + num4;
                array[totalgrade] = sum;
                totalgrade++;
                position = -1;
            }
            ++position;
        }
    }
    double *p = (double *)calloc(totalgrade*sizeof(double), (sizeof(double)));
    for (int k = 0; array[k] != '\0'; k++) {
        *(p + k) = array[k];
        gradecounter += 1;
    }
    *ptr_cnt = gradecounter;
    fclose(file);
    if (p == NULL) 
        return NULL;
    else 
        return p;
}


/*!
@brief      Function max used to find largest double element in the array   
@param word double const *begin, double const *end
@return     double  
*//*_____________________________________________________________*/

double max(double const *begin, double const *end){
    double max = begin[0];
    for(int i = 1; begin+i != end; i++){
        if (begin[i] > max)
            max = begin[i];
    }
  
    return max;
}

/*!
@brief      Function min used to find smallest double element in the array     
@param word double const *begin, double const *end
@return     double  
*//*_____________________________________________________________*/

double min(double const *begin, double const *end){
    double min = begin[0];
    for(int i = 1; begin+i != end; i++){
        if (begin[i] < min)
            min = begin[i];
    }
    return min;
}

/*!
@brief      Function average used to find average of elements in the array 
@param word double const *begin, double const *end
@return     double  
*//*_____________________________________________________________*/

double average(double const *begin, double const *end){
    double sum = begin[0];
    int i;
    for(i = 1; begin+i != end; i++){
        sum = sum + begin[i];
    }

    return (sum / i);
}

/*!
@brief      Function variance used to find variance of elements in the array     
@param word double const *begin, double const *end
@return     double  
*//*_____________________________________________________________*/

double variance(double const *begin, double const *end){
    double sum = 0;
    int i;
    double mean = average(begin, end);
    for(i = 0; begin+i != end; i++){
        sum = sum + pow((begin[i] - mean),2);
    }

    return (sum / (i-1));
}

/*!
@brief      Function std_dev used to find standard deviation of elements in the array
@param word double const *begin, double const *end
@return     double  
*//*_____________________________________________________________*/

double std_dev(double const *begin, double const *end){
    double vari = variance(begin, end);
    return sqrt(vari);
}

/*!
@brief      Function median used to find median of elements in the array
@param word double *base, int size
@return     double  
*//*_____________________________________________________________*/

double median(double *base, int size){
    double median;
    selection_sort(base, size);
    if ( size % 2 == 0)
        median = ((base[size/2] + base[(size-1)/2])/2)-0.005;
    else
        median = base[size/2];

    return median;
}

/*!
@brief      swap definition 
@param word double *a, double *b
@return     void
*//*_____________________________________________________________*/

void swap(double *a, double *b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}

/*!
@brief      Function selection_sort used to find sort the elements in the array in ascending order   
@param word double *base, int size
@return     void
*//*_____________________________________________________________*/

void selection_sort(double *base, int size){
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
            if (base[i] < base[min_idx])
                min_idx = i;
        swap(&(base[min_idx]), &(base[step]));
    }
}

/*!
@brief      Function Itr_grade_pctg get the percentage of each grade
@param word double const *begin, double const *end, double *ltr_grade
@return     void
*//*_____________________________________________________________*/

void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grade){
    int count[TOT_GRADE], sum = 0;
    double *tmp = (double *)begin;
    for(int i = 0; i < TOT_GRADE; i++){
        count[i] = 0 ;
    }
    for(int i = 0; begin+i != end; i++){
        if(begin[i] >= 90){
            tmp[i] = A_GRADE;
            count[0]++;
        }else if(begin[i] < 90 && begin[i] >= 80){
            tmp[i] = B_GRADE;
            count[1]++;
        }else if(begin[i] < 80 && begin[i] >= 70){
            tmp[i] = C_GRADE;
            count[2]++;
        }else if(begin[i] < 70 && begin[i] >= 60){
            tmp[i] = D_GRADE;
            count[3]++;
        }else{
            tmp[i] = F_GRADE;
            count[4]++;
        }
    }

    for(int i = 0; i < TOT_GRADE; i++){
        sum = sum + count[i] ;
    }
    for(int i = 0; i < TOT_GRADE; i++){
        ltr_grade[i] = (((double)count[i] / sum) * 100);
    }
    
}