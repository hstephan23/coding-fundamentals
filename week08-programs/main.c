/*
 Week 08 – Algorithms
*/

#include <stdio.h>

int main(void) {
    const int values[5] = {3, 1, 4, 1, 5};
    const int size = 5;
    int min = values[0];
    // First -> start with the first value as your "smallest"
    // Then -> compare with the next value
    // IF smaller, replace
    // ELSE continue
    // Finally -> return that value

    for (int i = 1; i < size; i++)
    {
        if (min > values[i])
        {
            min = values[i];
        }
    }

    printf("value: %d\n", min);


    // TODO:
    // 1. Write pseudocode
    // 2. Implement smallest value
    // 3. Explain complexity in English

    return 0;
}
