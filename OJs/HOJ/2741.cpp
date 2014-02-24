/*This Code is Submitted by Timer for Problem 2741 at 2012-04-08 16:35:44*/
#include <cstdio>
#include <cstring>
#include <queue>

#define N 1001

using namespace std;

struct Node
{
  int pre,k;
} pool[N*N];

int v[N],n,m,num;
bool ans[N][N],used[N];

void add(int a,int b)
{
  num++;
  pool[num].pre=v[a];
  pool[num].k=b;
  v[a]=num;
}

void BFS(int x)
{
  int i,j,k,tmp;
  queue <int> q;
  memset(used,false,sizeof(used));
  used[x]=true;
  ans[x][x]=true;
  q.push(x);
  while (!q.empty())
  {
    k=q.front();
    for (tmp=v[k];tmp!=0;tmp=pool[tmp].pre)
      if (!used[pool[tmp].k])
      {
        j=pool[tmp].k;
        ans[x][j]=true;
        used[j]=true;
        q.push(j);
      }
      q.pop();
  }
}

int main()
{
  int i,j,k,a,b,t;
  while (scanf("%d%d",&n,&m)==2)
  {
    num=0;
    memset(ans,false,sizeof(ans));
    memset(v,0,sizeof(v));
    for (i=1;i<=m;i++)
    {
      scanf("%d%d",&a,&b);
      add(a,b);
    }
    for(i=1;i<=n;i++)
      BFS(i);
    scanf("%d",&t);
    for (i=1;i<=t;i++)
    {
      scanf("%d%d",&a,&b);
      if (ans[a][b]) printf("Yes\n");
        else printf("No\n");
    }
  }
  return 0;
}