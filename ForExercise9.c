#include <stdio.h>
int main()
{
   int n;
   char str [100];
   printf("Enter a string to reverse\n");
   scanf("%s", str);
   printf("Reverse of the string: ");
   for (n=strlen(str); n>= 0; n--)
   {
     printf("%c", str[n]);
   }

   return 0;
}
