/*
 Week 09 – Architecture
*/

#include "math_utils.h"
#include <stdio.h>

int main(void) {
    // TODO:
    // Use math utilities
    // Explain dependency direction
    int a = 12;
    int b = 13;
    int add, sub, multi;
    double div;
    add = addition(a, b);
    sub = subtract(a, b);
    multi = multiplication(a, b);
    div = division(a, b);

    printf("add: %d \n"
           "sub: %d \n"
           "div: %f \n"
           "multi: %d \n",
           add,
           sub,
           div,
           multi);

    return 0;
}
