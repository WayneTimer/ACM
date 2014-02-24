/*This Code is Submitted by Timer for Problem 2994 at 2013-10-02 22:42:36*/
#include <cstdio>

typedef long long ll;

int main()
{
  ll A,B,f0,f1,fn;
  ll a,b,t;
  int i,n;
  while (scanf("%lld%lld%d%lld%lld",&A,&B,&n,&f0,&fn)==5)
  {
    if (n==1)
    {
      printf("%lld\n",fn);
      continue;
    }
    a=A;
    b=B;
    for (i=n-1;i>=2;i--)
    {
      t=a*B;
      a=a*A+b;
      b=t;
    }
    f1=(fn-b*f0)/a;
    printf("%lld\n",f1);
  }
  return 0;
}