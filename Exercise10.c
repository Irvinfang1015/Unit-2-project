#include <stdio.h>

void main() {
  int a;
  char b[] = "";
  int c;
  double d;
  double e;
  double f;
  printf("Enter Customer IDNO, Name, and unit consumed\n");
  //scanf("%i %s %i", &a, &b, &c); //this is the same as read in bash
  scanf("%d", &a);
  scanf("%s", &b);
  scanf("%i", &c);

  printf("Customer IDNO: %d\n", a);
  printf("Customer Name: %s\n", b);
  printf("Unit consumed: %i\n", c);
  if (c <= 199) {
    d = c * 1.2;
    e = 0;
    f = d;
  } else if (c < 400) {
    d = (c * 1.5);
    e = 0;
    f = d;
  } else if (c < 600){
    d = c * 1.8;
    e = d * 0.15;
    f = d + e;
  } else if (c > 600){
    d = c * 2;
    e = d * 0.15;
    f = d + e;
  }

  printf("Amount Charges per unit: %f\n", d);
  printf("Surcharge Amount: %f\n", e);
  printf("Net Amount Paid By the Customer: %f\n", f);


}
