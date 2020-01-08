#include <stdio.h>

void main() {
  int int1, int2, int3;
  printf("Enter 3 sides of the triangle\n");
  scanf("%i %i %i", &int1, &int2, &int3); //this is the same as read in bash
  if ((int1 == int2) && (int2 == int3)){
    printf("This is an Equilateral triangle");
  }
  if ((int1 == int2) && (int2 < int3)){
    printf("This is an Isoceles triangle");
  }
  if ((int1 != int2) && (int2 != int3)){
    printf("This is an Scalene triangle");
  }
}
