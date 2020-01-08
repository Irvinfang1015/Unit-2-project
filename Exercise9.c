#include <stdio.h>

void main() {
  int a, b, c;
  printf("Enter 3 sides of the triangle\n");
  scanf("%i %i %i", &a, &b, &c); //this is the same as read in bash
  if ((a + b > c) && (a + c > b) && (b + c > a)){
    printf("This triangle is valid");
  }
  else{
    printf("This triangle is not valid");
  }
}
