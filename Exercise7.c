#include <stdio.h>

void main() {
  int temp;
  printf("Enter Temperature\n");
  scanf("%i", &temp);

  if (temp < 0){
    printf("Freezing weather");
  }
  if (temp <= 10){
    printf("Very Cold weather");
  }
  else if (temp <= 21){
    printf("Cold weather");
  }
  else if (temp <= 31){
    printf("Normal weather");
  }
  else if (temp <= 39){
    printf("Hot weather");
  }
  else if (temp >= 40){
    printf("Very hot weather");
  }
}
