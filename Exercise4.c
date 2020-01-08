#include <stdio.h>

void main() {
  int int1, int2, int3;
  printf("Enter 3 numbers\n");
  scanf("%i %i %i", &int1, &int2, &int3); //this is the same as read in bash
  printf("1st number=%i\n", int1);
  printf("2nd number=%i\n", int2);
  printf("3rd number=%i\n", int3);
  if ((int1 > int2) && (int1 > int3))
    printf("The first number is the greatest among all three");
  if ((int2 > int1) && (int2 > int3))
    printf("The second number is the greatest among all three");
  if ((int3 > int1) && (int3 > int2))
    printf("The third number is the greatest among all three");
  if ((int1 == int2) && (int1 == int3))
    printf("All three numbers are the same");
    
}
