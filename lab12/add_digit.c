#include <stdio.h>
#include "add_digit.h"
#include "string.h"
#include <stdlib.h>
#define new_max(x,y) (((x) >= (y)) ? (x) : (y))
#define new_min(x,y) (((x) <= (y)) ? (x) : (y))

struct BigNumber {
    BigDigit* digits;
    size_t length;
};

BigNumber* create_BigNumber(const char* text) {
    BigNumber* numba = malloc(sizeof(BigNumber));
    size_t digits = strlen(text);
    numba->digits = malloc(digits);
    numba->length = digits;
    for (int i = 0; i < (int) digits; i++) numba->digits[i] = (unsigned char) text[i] - 48;
    return numba;
}

void destroy_BigNumber(BigNumber* number) {
    free(number->digits);
    free(number);
    return;
}

int getcharval(const char *s, int idx) {
    if (idx < (int) strlen(s)) return s[(int) strlen(s) - idx - 1] - 48; 
    return 0;
}

BigNumber* add_BigNumber(const BigNumber* number1, const BigNumber* number2) {
    BigNumber* sum = malloc(sizeof(BigNumber));
    size_t width = new_max(number1->length, number2->length);
    sum->digits = malloc(width);
    sum->length = width;
    int i = 0;
    for (i = 0; i <= (int) new_max(number1->length, number2->length); i++) sum->digits[i] = 0;
    for (i = 0; i < (int) new_max(number1->length, number2->length); i++) {
        if (i > (int) number1->length) {
            // printf("hello%d %d A\n", 0, number2->digits[number2->length - 1 - i]);
            sum->digits[(int) width - 1 - i] += add_BigDigit(0, number2->digits[(int) number2->length - 1 - i], sum->digits);
        } 
        else if (i > (int) number2->length) {
            // printf("hello%d %d B\n", number1->digits[number1->length - 1 - i], 0);
            sum->digits[(int) width - 1 - i] += add_BigDigit(number1->digits[(int) number1->length - 1 - i], 0, sum->digits);
        } 
        else {
            // printf("hello%d %d C\n", number1->digits[number1->length - 1 - i], number2->digits[number2->length - 1 - i]);
            sum->digits[(int) width - 1 - i] += add_BigDigit(number1->digits[(int) number1->length - 1 - i], number2->digits[(int) number2->length - 1 - i], sum->digits);
        }
    }
    return sum;
}

void print_BigNumber_sum(const BigNumber* number1, const BigNumber* number2, const BigNumber* sum) {
    int allocatedStrLen = (int) new_max(new_max(sum->length, number1->length), number2->length) + 2;
    int lenNum1 = (int) number1->length;
    int lenNum2 = (int) number2->length;
    int lenSum = (int) sum->length;
    for (int i = 0; i < allocatedStrLen - lenNum1; i++) printf(" ");
    for (int i = 0; i < lenNum1; i++) printf("%d", number1->digits[i]);
    printf("\n+");
    for (int i = 0; i < allocatedStrLen - lenNum2 - 1; i++) printf(" ");
    for (int i = 0; i < lenNum2; i++) printf("%d", number2->digits[i]);
    printf("\n");
    for (int i = 0; i < allocatedStrLen; i++) printf("-");
    printf("\n");
    for (int i = 0; i < allocatedStrLen - lenSum; i++) printf(" ");
    for (int i = 0; i < lenSum; i++) printf("%d", sum->digits[i]);
    printf("\n");
    return;
}