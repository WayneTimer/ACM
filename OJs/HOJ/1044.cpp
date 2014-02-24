/*This Code is Submitted by Timer for Problem 1044 at 2013-10-27 10:45:03*/
//DFS+剪枝
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXM 7

struct eugin
{
  int x,y,v,u;
};

int n,m,que;
eugin a[25];
int sum[25];
int b[MAXM+1];
bool used[25];
int ans;

bool operator < (eugin q,eugin w)
{
  return (q.v<w.v);
}

void dfs(int dep,int s)
{
  int i;
  if (s>ans) ans=s;
  for (i=dep-1;i>=1;i--)
    if (s+sum[i]>ans)
    {
      bool flag;
      int j;
      flag=true;
      for (j=a[i].x;j<a[i].y;j++)
        if (b[j]+a[i].u>n)
        {
          flag=false;
          break;
        }
      if (flag)
      {
        for (j=a[i].x;j<a[i].y;j++)
          b[j]+=a[i].u;
        dfs(i,s+a[i].v);
        for (j=a[i].x;j<a[i].y;j++)
          b[j]-=a[i].u;
      }
    }
}

int main()
{
  int i;
  scanf("%d%d%d",&n,&m,&que);
  while (n || m || que)
  {
    for (i=1;i<=que;i++)
    {
      scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
      a[i].u=a[i].v;
      a[i].v*=a[i].y-a[i].x;
    }
    sort(a+1,a+1+que);
    sum[1]=a[1].v;
    for (i=2;i<=que;i++)
      sum[i]=sum[i-1]+a[i].v;
    ans=0;
    memset(b,0,sizeof(b));
    memset(used,true,sizeof(used));
    dfs(que+1,0);
    printf("%d\n",ans);
    scanf("%d%d%d",&n,&m,&que);
  }
  return 0;
}