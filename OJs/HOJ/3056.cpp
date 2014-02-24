/*This Code is Submitted by Timer for Problem 3056 at 2011-12-23 11:27:05*/
#include <stdio.h>
#include <string.h>

int main()
{
  int n,i;
  long long a[1011];
  long long head[1011],tail[1011],wei[1011];
  long long x,zhong[1011],max,sum;
  while (scanf("%d",&n)==1)
  {
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++)
    {
      scanf("%lld",&a[i]);
    }
    memset(head,0,sizeof(head));
    memset(tail,0,sizeof(tail));
    memset(zhong,0,sizeof(zhong));
    head[0]=-a[0];
    for (i=1;i<=n;i++)
    {
      head[i]=head[i-1]-a[i];
      if (zhong[i-1]>head[i-1]) zhong[i]=zhong[i-1]+a[i];
        else zhong[i]=head[i-1]+a[i];
    }
    for (i=n;i>=1;i--)
    {
      tail[i]=tail[i+1]-a[i];
      if (tail[i+1]>wei[i+1]) wei[i]=tail[i+1]+a[i];
        wei[i]=wei[i+1]+a[i];
    }
    sum=-2000000000;
    for (i=1;i<=n;i++)
    {
      max=head[i];
      if (zhong[i]>max) max=zhong[i];
      x=tail[i+1];
      if (wei[i+1]>x) x=wei[i+1];
      max=max+x;
      if (max>sum) sum=max;
    }
    printf("%lld\n",sum);
  }
  return 0;
}