/*This Code is Submitted by Timer for Problem 1711 at 2013-03-13 19:13:45*/
// DP 完全背包
#include <cstdio>
#include <cstring>

#define MAX 50000

int d,n;
long long begin;
long long w[11];
long long v[11];
long long f[MAX+10];

inline void dp()
{
  long long i,t;
  int j;
  memset(f,0,sizeof(f));
  for (i=1;i<=n;i++)
    for (j=w[i];j<=MAX;j++)
    {
        t=f[j-w[i]]+v[i];
        if (t>f[j]) f[j]=t;
    }
}

int main()
{
  int T,i;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%lld%d",&begin,&d);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      scanf("%lld%lld",&w[i],&v[i]);
      w[i]/=1000;
    }
    dp();
    while (d--)
      begin+=f[begin/1000];
    printf("%lld\n",begin);
  }
  return 0;
}