/*This Code is Submitted by Timer for Problem 2661 at 2013-10-29 00:55:12*/
#include <cstdio>

typedef long long ll;

ll n;
int ans;

void dfs(ll x,int s)
{
  if (ans!=-1 && s>=ans) return;
  if (x==0)
  {
    if (ans==-1 || s<ans)
      ans=s;
    return;
  }
  int t;
  t=x%10;
  dfs(x/10,s+t);
  dfs(x/10+1,s+10-t);
}

int main()
{
  while (scanf("%lld",&n)==1)
  {
    ans=-1;
    dfs(n,0);
    printf("%d\n",ans);
  }
  return 0;
}