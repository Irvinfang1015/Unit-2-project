#include <stdio.h>

void main() {
  int int1;
  printf("Enter number\n");
  scanf("%i", &int1); //this is the same as read in bash
  if (int1 > 0)
    printf("This number is positive");
  else
    if (int1 == 0)
      printf("0 is neither");
    else
      printf("This number is negative");
}
