/*This Code is Submitted by Timer for Problem 1688 at 2011-11-13 00:18:45*/
#include <stdio.h>

int main()
{
  long n,sum,t,v,i,last;
  scanf("%ld",&n);
  while (n!=-1)
  {
    sum=0;
    last=0;
    for (i=0;i<n;i++)
    {
      scanf("%ld",&v);
      scanf("%ld",&t);
      sum=sum+v*(t-last);
      last=t;
    }
    printf("%ld miles\n",sum);
    scanf("%ld",&n);
  }
  return 0;
}