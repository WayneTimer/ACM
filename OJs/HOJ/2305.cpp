/*This Code is Submitted by Timer for Problem 2305 at 2013-03-11 22:40:25*/
/*
化简：
n(x+y)=xy
nx+ny=xy
xy-nx-ny+n^2=n^2
(x-n)(y-n)=n^2
又由于当(x-n)、(y-n)都为负数时无解，所以(x-n)、(y-n)都为正数，
所以答案即为求n^2里<=n的因数有多少个

公式：
n=(p1^a1)*(p2^a2)*.......(p1为质因子)
则 n的因子个数=(a1+1)*(a2+1)*........

所以，先求出n^2的因数个数，/2即为ans
*/
#include <cstdio>
#include <cstring>

#define MAXP 46341

int p[10000];
int m,n;

inline void init()
{
  int i,j;
  bool f[MAXP+1];
  memset(f,true,sizeof(f));
  for (i=2;i<=MAXP>>1;i++)
    if (f[i])
      for (j=2;i*j<=MAXP;j++)
        f[i*j]=false;
  m^=m;
  for (i=2;i<=MAXP+1;i++)
    if (f[i])
      p[++m]=i;
}

int main()
{
  int T,i,j;
  long long s,t;
  init();
  scanf("%d",&T);
  for (j=1;j<=T;j++)
  {
    scanf("%d",&n);
    s=1;
    for (i=1;i<=m;i++)
    {
      if (p[i]>n) break;
      t=0;
      while (n%p[i]==0)
      {
        n/=p[i];
        t++;
      }
      t<<=1;//质因子幂指数*2即为n^2的质因子幂指数
      s*=(t+1);
    }
    if (n!=1) s*=3;
    printf("Scenario #%d:\n",j);
    printf("%lld\n\n",s+1>>1);
  }
  return 0;
}