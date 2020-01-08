#include <stdio.h>

void main() {
  int int1;
  printf("Enter number\n");
  scanf("%i", &int1); //this is the same as read in bash
  if (int1%2 == 0)
    printf("This number is even");
  else
    printf("This number is odd");
}
