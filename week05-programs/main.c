/*
 Week 05 – Arrays
*/

#include <stdio.h>

int main(void) {
    int scores[5] = {10, 20, 30, 40, 50};
    int max_score = scores[0];
    int sum_scores = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", scores[i]);
        if (max_score < scores[i])
        {
            max_score = scores[i];
        }
        sum_scores += scores[i];
    }

    printf("%d\n", max_score);
    printf("%d\n", sum_scores);

    return 0;
}
