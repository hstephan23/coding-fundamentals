/*
 Week 02 – Variables & Data
*/

#include <stdio.h>

int main(void) {
  int score = 0;
  int lives = 3;

  printf("%d\n", score);
  printf("%d\n", lives);

  // Changes from 0 to 12
  score += 12;
  // Changes from 3 to 1
  lives -= 2;

  printf("%d\n", score);
  printf("%d\n", lives);
  // TODO:
  // 1. Print variables
  // 2. Modify them
  // 3. Predict values at each step

  return 0;
}
