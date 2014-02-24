/*This Code is Submitted by Timer for Problem 2111 at 2011-11-11 01:16:55*/
#include <stdio.h>

int main()
{
  int n,u,i,k,a,sum;
  scanf("%d",&n);
  for (u=1;u<=n;u++)
  {
    scanf("%d",&k);
    sum=0;
    for (i=1;i<=k;i++)
    {
      scanf("%d",&a);
      sum=sum+a;
    }
    sum=sum-(k-1);
    printf("%d\n",sum);
  }
  return 0;
}