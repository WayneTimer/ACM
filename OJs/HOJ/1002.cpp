/*This Code is Submitted by Timer for Problem 1002 at 2011-10-02 20:50:04*/
#include <stdio.h>

int main(void)
{
  long long a,b,c,d;
  while (scanf("%lld %lld %lld",&a,&b,&c)==3)
    {
      d=a+b+c;
      printf("%lld\n",d);
    }
  return 0;
}