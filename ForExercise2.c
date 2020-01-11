#include <stdio.h>
void main()
{       
  int i,n;
	printf("Input number of terms : \n");
  scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		printf("Number is : %d and cube of %d is : %d\n", i, i,(i*i*i));
	}
 
}
