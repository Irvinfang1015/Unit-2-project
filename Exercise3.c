#include <stdio.h>

void main() {
  int age;
  printf("Enter age\n");
  scanf("%i", &age); //this is the same as read in bash
  if (age > 18)
    printf("Congratulations! You are eligible for casting your vote");
  else
    printf("Sorry you are not of age yet");
}
