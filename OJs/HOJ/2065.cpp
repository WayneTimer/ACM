/*This Code is Submitted by Timer for Problem 2065 at 2011-11-21 01:34:52*/
#include <stdio.h>

int main()
{
  long long f[46];
  int i,t,n;
  f[0]=0;
  f[1]=1;
  for (i=2;i<=45;i++)
    f[i]=f[i-1]+f[i-2];
  scanf("%d",&t);
  for (i=1;i<=t;i++)
  {
    scanf("%d",&n);
    printf("%lld\n",f[n]);
  }
  return 0;
}