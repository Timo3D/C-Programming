/*
@file       q.c
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

/*!
@brief      Function read_data used to read string data an return a double array  
@param word char const *file_name, int *ptr_cnt
@return     double *  
*//*_____________________________________________________________*/
double* read_data(char const *file_name, int *ptr_cnt);

/*!
@brief      Function max used to find largest double element in the array   
@param word double const *begin, double const *end
@return     double  
*//*_____________________________________________________________*/
double max(double const *begin, double const *end);

/*!
@brief      Function min used to find smallest double element in the array     
@param word double const *begin, double const *end
@return     double  
*//*_____________________________________________________________*/
double min(double const *begin, double const *end);

/*!
@brief      Function average used to find average of elements in the array 
@param word double const *begin, double const *end
@return     double  
*//*_____________________________________________________________*/
double average(double const *begin, double const *end);

/*!
@brief      Function variance used to find variance of elements in the array     
@param word double const *begin, double const *end
@return     double  
*//*_____________________________________________________________*/
double variance(double const *begin, double const *end);

/*!
@brief      Function std_dev used to find standard deviation of elements in the array
@param word double const *begin, double const *end
@return     double  
*//*_____________________________________________________________*/
double std_dev(double const *begin, double const *end);

/*!
@brief      Function median used to find median of elements in the array
@param word double *base, int size
@return     double  
*//*_____________________________________________________________*/
double median(double *base, int size);

/*!
@brief      Function selection_sort used to find sort the elements in the array in ascending order   
@param word double *base, int size
@return     void
*//*_____________________________________________________________*/
void selection_sort(double *base, int size);

/*!
@brief      Function Itr_grade_pctg get the percentage of each grade
@param word double const *begin, double const *end, double *ltr_grade
@return     void
*//*_____________________________________________________________*/
void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grade);

/*!
@brief      swap definition 
@param word double *a, double *b
@return     void
*//*_____________________________________________________________*/
void swap(double *a, double *b);

enum {
    A_GRADE,
    B_GRADE,
    C_GRADE,
    D_GRADE,
    F_GRADE,
    TOT_GRADE = 5
};