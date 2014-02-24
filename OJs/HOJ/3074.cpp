/*This Code is Submitted by Timer for Problem 3074 at 2011-12-04 21:01:08*/
#include <stdio.h>

int main()
{
  long x,n,a,b,s;
  while (scanf("%ld%ld%ld",&n,&a,&b)==3)
  {
    x=a+1;
    if ((n-b)>x) x=n-b;
    s=n-x+1;
    printf("%ld\n",s);
  }
  return 0;
}