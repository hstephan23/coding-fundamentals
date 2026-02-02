/*
 Week 04 – Functions
*/

#include <stdio.h>

// TODO:
// Write a function that prints a divider
// Write a function that adds two numbers
float divide(int a, int b);
int add_numbers(int a, int b);
void print_divider(int a, int b, float result);

int main(void) {
    // TODO:
    // Call functions
    // Explain responsibility of each
    int a = 100;
    int b = 33;
    float result;

    // This is in charge of dividing
    result = divide(a, b);
    // this is in charge of adding
    int result_of_addition = add_numbers(a, b);
    // this is in charge of printing (Originally I did a divide and print, but that is not one responsibility)
    print_divider(a, b, result);

    return 0;
}

float divide(int a, int b)
{
    return (float)a / (float)b;
}

int add_numbers(int a, int b)
{
    return a + b;
}

void print_divider(int a, int b, float result)
{
    printf("%d divided by %d is %f\n", a, b, result);
}