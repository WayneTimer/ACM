/*This Code is Submitted by Timer for Problem 1370 at 2011-11-13 00:04:56*/
#include <stdio.h>

int main()
{
  long sum,i,n,s;
  long a[100000];
  scanf("%ld",&n);
  while (n!=-1)
  {
    sum=0;
    s=0;
    for (i=0;i<n;i++)
    {
      scanf("%ld",&a[i]);
      sum=sum+a[i];
    }
    if ((sum%n)!=0)
      {
        printf("-1\n");
        scanf("%ld",&n);
        continue;
      } else
      {
        sum=sum/n;
        for (i=0;i<n;i++)
          if (a[i]<sum) s=s+sum-a[i];
        printf("%ld\n",s);
      }
    scanf("%ld",&n);
  }
  return 0;
}