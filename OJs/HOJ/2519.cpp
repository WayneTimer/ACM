/*This Code is Submitted by Timer for Problem 2519 at 2011-11-14 00:24:20*/
#include <stdio.h>

int main()
{
  int i,n;
  long s,t,e;
  double p;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%ld",&t);
    s=0;
    p=0;
    while (t>1)
    {
      p=(double)t;
      e=(long) (p/3+0.5);
      t=t-e*2;
      if (e>t) t=e;
      s++;
    }
    printf("%ld\n",s);
  }
  return 0;
}