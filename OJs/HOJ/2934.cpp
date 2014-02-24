/*This Code is Submitted by Timer for Problem 2934 at 2011-11-29 15:43:28*/
#include <stdio.h>

int main()
{
  long long i,t,s;
  int a,b;
  scanf("%d%d",&a,&b);
  while (!((a==0)&&(b==0)))
  {
    t=1;
    for (i=1;i<=a;i++)
      t=t*i;
    s=t;
    for (i=a+1;i<=b;i++)
    {
      t=t*i;
      s=s+t;
    }  
    printf("%lld\n",s);
    scanf("%d%d",&a,&b);
  }
  return 0;
}