/*This Code is Submitted by Timer for Problem 1098 at 2012-08-15 19:25:14*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int s;
  int c[110];
};

cyr a[110];
int n,top;
int dfn[110],low[110];
int sum[110];

int qumin(int x,int y)
{
  if (x<=y) return x;
  return y;
}

void dfs(int u,int fa)
{
    int i,temp;
    temp=0;
    top++;
    dfn[u]=top;
    low[u]=top;
    for (i=1;i<=a[u].s;i++)
      if (dfn[a[u].c[i]]==0)
      {
        dfs(a[u].c[i],u);
        temp++;
        low[u]=qumin(low[u],low[a[u].c[i]]);
        if (((fa==0) && (temp>1)) || ((fa!=0) && (dfn[u]<=low[a[u].c[i]])))
          sum[u]=1;
      }
      else 
        if (a[u].c[i]!=fa) 
          low[u]=qumin(low[u],dfn[a[u].c[i]]);
}

void tarjan()
{
  int i,ans;
  top=0;
  memset(dfn,0,sizeof(dfn));
  memset(sum,0,sizeof(sum));
  for (i=1;i<=n;i++)
    if (dfn[i]==0) 
      dfs(i,0);
  ans=0;
  for (i=1;i<=n;i++) 
    ans+=sum[i];
  printf("%d\n",ans);
}

int main()
{
  int x,y;
  scanf("%d",&n);
  while (n)
  {
    memset(a,0,sizeof(a));
    scanf("%d",&x);
    while (x)
    {
      while (getchar()!='\n')
      {
        scanf("%d",&y);
        a[x].s++;
        a[x].c[a[x].s]=y;
        a[y].s++;
        a[y].c[a[y].s]=x;
      } 
      scanf("%d",&x);
    }
    tarjan();
    scanf("%d",&n);
  }
  return 0;
}