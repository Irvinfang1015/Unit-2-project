#include <stdio.h>

int main()
{
    int i, n, start, end, sum;

    /* Input upper limit to print perfect number */
    printf("Enter starting range of number: ");
    scanf("%d", &start);
    printf("Enter ending range of number: ");
    scanf("%d", &end);

    printf("All Perfect numbers between %d to %d:\n",start, end);
    
    //Loop from starting range to ending range
    for(i=start; i<=end; i++)
    {
        sum = 0;

        // Check whether the current number i is Perfect number or not
        for(n=1; n<i; n++)
        {
            if(i % n == 0)
            {
                sum += n;
            }
        }
 
        // If the current number i is Perfect number
        if(sum == i)
        {
            printf("%d, ", i);
        }
    }

    return 0;
}
