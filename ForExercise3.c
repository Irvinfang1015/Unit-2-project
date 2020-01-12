#include <stdio.h>
void main()
{       
  int i,n, f = 1;
	printf("Input number : \n");
  scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		f = f*i; 
	}
  printf("The Factorial of %d is : %i\n", n, f);
}
