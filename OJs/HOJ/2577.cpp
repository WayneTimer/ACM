/*This Code is Submitted by Timer for Problem 2577 at 2013-06-11 01:03:47*/
//HOJ 2577
//数论-容斥原理 (2576加强版)
#include <cstdio>

typedef long long ll;

ll ans,m;
ll a[11];
int n;

inline ll lcm(ll x,ll y) //求最小公倍数
{
  ll t,s;
  s=x*y;
  if (x<y)
  {
    t=x;
    x=y;
    y=t;
  }
  while (y)
  {
    t=x%y;
    x=y;
    y=t;
  }
  s/=x;
  return s;
}

void dfs(ll s,int x,int dep)
{
  ll t;
  if (x>n) return;
  int i;
  for (i=x;i<=n;i++)
  {
    t=lcm(s,a[i]);
    if (dep&1)
      ans+=(m/t)*dep;
    else
      ans-=(m/t)*dep;
    dfs(t,i+1,dep+1);
  }
}

int main()
{
  int T,i;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d%lld",&n,&m);
    for (i=1;i<=n;i++)
      scanf("%lld",&a[i]);
    ans^=ans;
    dfs(1,1,1);
    printf("%lld\n",ans);
  }
  return 0;
}