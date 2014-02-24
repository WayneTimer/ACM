/*This Code is Submitted by Timer for Problem 2076 at 2011-11-21 16:50:42*/
#include <stdio.h>

int main()
{
  long a,b,c,x;
  while (scanf("%ld%ld%ld",&c,&a,&b)==3)
  {
    x=(b-2*a+c)/2;
    b=a-x-c;
    a=x;
    printf("%ld",9*a+3*b+c);
    printf(" %ld",16*a+4*b+c);
    printf(" %ld\n",25*a+5*b+c);
  }
  return 0;
}