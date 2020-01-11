#include <stdio.h>
void main()
{       
  int i,n,sum=0;
	float avg;
	printf("Input the 10 numbers : \n");
	for (i=1;i<=10;i++)
	{
		scanf("%d",&n);
		sum +=n;
	}
	avg=sum/10.0;
	printf("The sum of 10 numbers is : %d\nThe Average is : %f\n",sum,avg);
 
}
