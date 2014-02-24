/*This Code is Submitted by Timer for Problem 2476 at 2013-03-16 20:59:20*/
#include <cstdio>

int tl,sl,fl,n,d;
//因为涉及到/2，所以将读入的数据X2处理

int main()
{
  int s,t;
  while (scanf("%d%d%d%d%d",&tl,&sl,&fl,&n,&d)==5)
  {
    tl-=fl+(n-1)*d;
    tl<<=1;
    s^=s;
    fl<<=1;
    fl-=sl;
    sl<<=1;
    t=fl/sl;
    if (fl%sl!=0) t++;
    s=t+1;
    n--;
    if (n)
    {
      d<<=1;
      d-=sl;
      t=d/sl;
      if (d%sl!=0) t++;
      s+=(t+1)*n;
    }
    tl-=(sl>>1);
    if (tl>0)
    {
      t=tl/sl;
      if (tl%sl!=0) t++;
      s+=t;
    }
    printf("%d\n",s);
  }
  return 0;
}