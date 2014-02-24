/*This Code is Submitted by Timer for Problem 3057 at 2011-11-28 17:24:52*/
#include <stdio.h>

int main()
{
  int u,w,l,t,p,l1,l2,i,s,x;
  scanf("%d",&t);
  for (u=1;u<=t;u++)
  {
    scanf("%d",&p);
    s=p;
    for (i=1;i<=4;i++)
    {
      scanf("%d",&x);
      s=s+x;
    }
    l1=s/5;
    s=0;
    for (i=1;i<=5;i++)
    {
      scanf("%d",&x);
      s=s+x;
    }
    l2=s/5;
    s=0;
    s=(l2-l1)*10+100;
    if (s>200) s=200;
    if (s<20) s=20;
    w=(l1-p)*10+s;
    if (w>200) w=200;
    if (w<1) w=1;
    s=0;
    s=100-(l2-l1)*10;
    if (s>200) s=200;
    if (s<20) s=20;
    l=s+(p-l1)*10;
    if (l>200) l=200;
    if (l<1) l=1;
    printf("%d %d\n",w,l);
  }
  return 0;
}