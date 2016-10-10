#include <cstdio>
#include <cstring>

#define MAXN 3010

typedef long long ll;

struct edge
{
  int y,next;
};

int f[MAXN][MAXN];
int n,m,tot,start;
int d[MAXN][MAXN];
int used[MAXN][MAXN];
edge e[MAXN<<1];
int a[MAXN];
ll sum;

inline void add(int x,int y)
{
  tot++;
  e[tot].y=y;
  e[tot].next=a[x];
  a[x]=tot;
}

inline void prim()
{
  int dist[MAXN];
  int low[MAXN];
  int i,j,k,y;
  sum=0;
  dist[1]=0;
  memset(a,-1,sizeof(a));
  memset(used,false,sizeof(used));
  tot=0;
  for (i=2;i<=n;i++)
  {
    dist[i]=d[1][i];
    low[i]=1;
  }
  for (i=1;i<n;i++)
  {
    k=-1;
    for (j=1;j<=n;j++)
      if (dist[j]>0)
        if (k==-1 || dist[j]<k)
        {
          k=dist[j];
          y=j;
        }
    sum+=k;
    dist[y]=0;
    add(low[y],y);
    add(y,low[y]);
    used[low[y]][y]=true;
    used[y][low[y]]=true;
    for (j=1;j<=n;j++)
      if (d[y][j]!=-1)
        if (dist[j]==-1 || d[y][j]<dist[j])
        {
          dist[j]=d[y][j];
          low[j]=y;
        }
  }
}

void dfs(int x,int fa)
{
  int k,mymin,t;
  k=a[x];
  mymin=-1;
  while (k!=-1)
  {
    if (e[k].y!=fa)
    {
      dfs(e[k].y,x);
      if (f[start][e[k].y]!=-1)
        if (mymin==-1 || f[start][e[k].y]<mymin)
          mymin=f[start][e[k].y];
    }
    k=e[k].next;
  }
  if (x==start) return;
  if (fa!=start)
    if (d[start][x]!=-1)
      if (mymin==-1 || d[start][x]<mymin)
        mymin=d[start][x];
  f[start][x]=mymin;
}

inline void init()
{
  int i;
  for (i=1;i<=n;i++)
  {
    start=i;
    dfs(i,0);
  }
}

ll dfs2(int x,int y,int fa)
{
  int k;
  ll mymin,t;
  k=a[x];
  mymin=f[x][y];
  while (k!=-1)
  {
    if (e[k].y!=fa)
      if (e[k].y!=y)
      {
        t=dfs2(e[k].y,y,x);
        if (mymin==-1 || t<mymin) mymin=t;
      }
    k=e[k].next;
  }
  return mymin;
}

int main()
{
  int x,y,v,i,T,tmp;
  ll s;
  scanf("%d%d",&n,&m);
  while (n||m)
  {
    memset(d,-1,sizeof(d));
    memset(f,-1,sizeof(f));
    while (m--)
    {
      scanf("%d%d%d",&x,&y,&v);
      x++;
      y++;
      if (d[x][y]==-1 || v<d[x][y])
      {
        d[x][y]=v;
        d[y][x]=v;
      }
    }
    prim();
    init();
    scanf("%d",&m);
    T=m;
    s=0;
    while (m--)
    {
      scanf("%d%d%d",&x,&y,&v);
      x++;
      y++;
      if (!used[x][y])
        s+=sum;
      else
      {
        s+=sum;
        s-=d[x][y];
        tmp=dfs2(x,y,0);
        if (v<tmp) tmp=v;
        s+=tmp;
      }
    }
    double ans;
    ans=s;
    ans/=T;
    printf("%.4lf\n",ans);
    scanf("%d%d",&n,&m);
  }
  return 0;
}