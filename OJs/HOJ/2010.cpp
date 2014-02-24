/*This Code is Submitted by Timer for Problem 2010 at 2011-11-22 16:34:08*/
#include <stdio.h>
#include <math.h>

long long gcd(long long a,long long b)
{
  if (a%b==0) return b;
  return gcd(b,a%b);
}

int main()
{
  long long t,g,l,x,a,b,i;
  while (scanf("%lld%lld",&g,&l)==2)
  {
    x=l/g;
    for (i=(sqrt((double)x));i>=1;i--)
    {
      if ((x%i)==0)
      {
        a=i;
        b=x/i;
        if (b>a) 
        {
          t=b;
          b=a;
          a=t;
        }
        if (gcd(a,b)==1) 
        {
          printf("%lld %lld\n",b*g,a*g);
          break;
        }
      }
    }
  }
  return 0;
}