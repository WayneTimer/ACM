/*This Code is Submitted by Timer for Problem 1991 at 2012-08-22 11:19:17*/
#include <cstdio>

int n;

int miqumo(int a,int b,int c)
{
  int ans;
  ans=1;
  while (b)
  {
    if (b&1)
      ans=ans*a%c;
    a=a*a%c;
    b=b>>1;
  }
  return ans;
}

int main()
{
  int t,g,p;
  scanf("%d",&n);
  while (n)
  {
    p=1600*29;
    n++;
    t=miqumo(2005,n,p);
    g=miqumo(401,n,p);
    t=t-g;
    while (t<0) t=t+p;
    g=miqumo(5,n,p);
    t=t-g;
    while (t<0) t=t+p;
    t++;
    t=t%p;
    while (t%1600!=0) t+=p;
    t=t/1600;
    printf("%d\n",t);
    scanf("%d",&n);
  }
  return 0;
}