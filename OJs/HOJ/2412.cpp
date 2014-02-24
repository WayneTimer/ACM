/*This Code is Submitted by Timer for Problem 2412 at 2011-11-18 00:02:16*/
#include <stdio.h>

int main()
{
  long long s,i,n,m,j;
  scanf("%lld",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%lld",&m);
    s=0;
    for (j=1;j<=m;j++)
      s=s+j*(j+2)*(j+1)/2;
    printf("%lld %lld %lld\n",i,m,s);
  }
  return 0;
}