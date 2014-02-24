/*This Code is Submitted by Timer for Problem 1289 at 2013-10-25 22:24:02*/
#include <cstdio>
#include <cstring>

typedef long long ll;

#define MAXN 36

bool a[MAXN+1][MAXN+1];
bool b[MAXN+1];
int ans;

inline void init()
{
  int m,x,y;
  memset(a,false,sizeof(a));
  scanf("%d",&m);
  while (m--)
  {
    scanf("%d%d",&x,&y);
    a[x][y]=true;
  }
}

void dfs(int x,int dep)
{
  int i,t,j;
  bool c[MAXN+1];
  t=0;
  for (i=1;i<=MAXN;i++)
  {
    b[i]&=a[x][i];
    if (b[i]) t++;
    c[i]=b[i];
  }
  if (t<=ans) return;
  if (dep<t) t=dep;
  if (t>ans) ans=t;
  for (i=x+1;i<=MAXN;i++)
  {
    dfs(i,dep+1);
    for (j=1;j<=MAXN;j++)
      b[j]=c[j];
  }
}

int main()
{
  int T,i;
  scanf("%d",&T);
  while (T--)
  {
    init();
    ans=0;
    for (i=1;i<=MAXN;i++)
    {
      memset(b,true,sizeof(b));
      dfs(i,1);
    }
    printf("%d\n",ans);
  }
  return 0;
}