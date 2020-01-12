#include <stdio.h>
void main()
{       
  int i,n;
  long sum = 0.0;
  long t = 1;
	printf("Input number : \n");
  scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		printf("%ld", t);
    if (i<n){
      printf(" + ");
    }
    sum+=t;
    t=(t*10)+1;
	}
  printf("\nSum is : %ld\n", sum);
}
