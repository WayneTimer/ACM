/*This Code is Submitted by Timer for Problem 2303 at 2013-03-11 18:04:05*/
#include <cstdio>

int n;
long long s,t,x,y;

int main()
{
  while (scanf("%d",&n)==1 && n)
  {
    s^=s;
    scanf("%lld",&t);
    n--;
    while (n--)
    {
      y=t;
      if (y<0) y=-y;
      s+=y;
      scanf("%lld",&x);
      t+=x;
    }
    printf("%lld\n",s);
  }
  return 0;
}