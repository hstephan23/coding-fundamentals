/*
 Week 06 – Memory
*/

#include <stdio.h>

int main(void) {
  int value = 42;
  int *ptr = &value;

  printf("%d\n", value);
  printf("%p\n", ptr);
  // TODO:
  // 1. Print value
  // 2. Print address
  // 3. Draw memory diagram
  //  Address      Value        Meaning
  // --------     --------     ------------------------
  //  0x1000       42           value
  //  0x2000       0x1000       ptr
  return 0;
}
