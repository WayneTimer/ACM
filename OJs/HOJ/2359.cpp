/*This Code is Submitted by Timer for Problem 2359 at 2012-12-31 15:51:34*/
#include <cstdio>

int n,g;
long long sum;
long long x,y;

int main()
{
  int i;
  long long last;
  while (scanf("%d%d",&n,&g)==2)
  {
    scanf("%lld%lld",&x,&y);
    sum=x*y;
    last=x;
    for (i=2;i<=n;i++)
    {
      scanf("%lld%lld",&x,&y);
      if (last+g<x) x=last+g;
      sum+=x*y;
      last=x;
    }
    printf("%lld\n",sum);
  }
  return 0;
}