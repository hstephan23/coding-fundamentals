/*
 Week 03 – Control Flow
*/

#include <stdio.h>

int main(void) {
    int total = 10;

    for (int i = 1; i <= total; i++)
    {
        if (i % 2 == 0)
        {
            printf("No, %d is not odd\n", i);
        } else
        {
            printf("Yes, %d is odd\n", i);
        }
    }
    // TODO:
    // 1. Add if/else logic
    // 2. Add a loop
    // 3. Draw a flowchart FIRST

    return 0;
}
