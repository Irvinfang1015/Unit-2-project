#include <stdio.h>
void main()
{       
  int i,n;
  float sum = 0.0;
	printf("Input number : \n");
  scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		if (i<n){
      sum=sum+(1/(float)i); 
      printf("1/%d + ", i);
    }
    if (i == n){
      sum=sum+(1/(float)i);
      printf("1/%d", i);
    }
	}
  printf("\nSum of series up to %d term is : %f\n", n, sum);
}
