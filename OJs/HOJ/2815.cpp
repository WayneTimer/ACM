/*This Code is Submitted by Timer for Problem 2815 at 2013-02-26 22:23:58*/
//扩展欧几里得求 gcd(a,b)=xa+yb; (x,y为整数)
//本题有个trick:
//   x+1-x=1   ans=2
#include <cstdio>

int q,w,s1,s2;

int exgcd(int a,int b,int &x,int &y)
{
  if (b==0)
  {
    x=1;
    y=0;
    return a;
  }
  int d;
  d=exgcd(b,a%b,x,y);
  int t;
  t=x;
  x=y;
  y=t-a/b*y;
  return d;
}

int main()
{
  int T,ans;
  int e1,e2;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d%d",&q,&w);
    if (q==w)
    {
      if (q==1) puts("2");        //trick
        else puts("-1");
      continue;
    }
    if (q<w)
    {
      q^=w;
      w^=q;
      q^=w;
    }
    if (w==1)
    {
      if (q==2) puts("1");    //trick
        else puts("2");
      continue;
    }
    if (exgcd(q,w,s1,s2)!=1)
    {
      puts("-1");
      continue;
    }
    if (w==0)
    {
      puts("1");
      continue;
    }
    e1=s1;
    e2=s2;
    if (s1<0) s1=-s1;
    if (s2<0) s2=-s2;
    s1+=s2;
    ans=s1;
    if (e1<0)
    {
      s1=e1+w;
      s2=e2-q;
      if (s1<0) s1=-s1;
      if (s2<0) s2=-s2;
      s1+=s2;
      if (s1<ans) ans=s1;
    }
    else
    {
      s1=e1-w;
      s2=e2+q;
      if (s1<0) s1=-s1;
      if (s2<0) s2=-s2;
      s1+=s2;
      if (s1<ans) ans=s1;
    }
    printf("%d\n",ans-1);
  }
  return 0;
}