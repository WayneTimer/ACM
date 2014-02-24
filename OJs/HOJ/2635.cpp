/*This Code is Submitted by Timer for Problem 2635 at 2012-08-22 19:37:52*/
#include <cstdio>

int u=9999997;
long long n,p;

long long miqumo(long long a,long long b,long long c)
{
  long long ans;
  ans=1;
  while (b)
  {
    if (b&1)
      ans=ans*a%c;
    a=a*a%c;
    b=b>>1;
  }
  return ans;
}

int main()
{
  long long t;
  p=u<<1;
  while (scanf("%lld",&n)==1)
  {
    t=miqumo(3,n,p);
    t--;
    while (t<0) t+=p;
    t=t>>1;
    printf("%lld\n",t);
  }
  return 0;
}