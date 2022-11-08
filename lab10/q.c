/*!
@file q.c
@author Timothy Wong
@course RSE1201
@week 10
@lab09
@date 28/10/2022
@brief This file contains the definitions of the functions
       build_path, compare_string, describe_string, and find_string
*//*_____________________________________________________________*/

#include "q.h"
#include <string.h>
const char* build_path(const char* parent, const char* separator, const char* const folders[], size_t count) { //The function takes in a path to a parent folder, a path separator sequence (for Linux paths it is "/" , for Windows paths it is "\\" ), and an array of subdirectories with its element count. It combines the parent folder and the subdirectories into a single path using the separator.
    long unsigned int ctr = STRLEN(parent) + STRLEN(separator);
    for (unsigned int i = 0; i < count; i++) ctr += STRLEN(folders[i]) + STRLEN(separator);
    char *str = debug_malloc(ctr);
    STRCPY(str, parent);
    for (unsigned int i = 0; i < count; i++) {
        STRCAT(str, folders[i]);
        STRCAT(str, separator);
    }
    return str;
}

void compare_string(const char* lhs, const char* rhs) { //The function prints out a statement about a 3-way comparison of two strings.
    int result = STRCMP(lhs, rhs);
    if (result < 0) printf("Left string goes first.\n");
    else if (result > 0) printf("Right string goes first.\n");
    else printf("Both strings are equal.\n");
}

void describe_string(const char* text) { //The function prints out the length of a provided string of text.
    printf("The length of the path \"%s\" is %ld.\n", text, STRLEN(text));
}

void find_string(const char* string, const char* substring) { //The function prints out a statement describing a result of searching a string of text ( substring ) within another string of text ( string ).
    char *result = STRSTR(string, substring);
    printf("Searching for a string:\n\tText:     %s\n\tSub-text: %s\n\tResult:   ", string, substring);
    if (result) printf("found %ld characters at a position %ld.\n", STRLEN(substring), result - string);
    else printf("not found\n");
}