#include <cstdio>
#include <cstring>

#define MAXN 40010
#define MAXQ 10010

struct edge
{
  int x,y,s;
};

int n,q,up,up2,m;
int h[MAXN];//每个结点边的情况
int que[MAXN];//每个结点的query情况
edge e[MAXN<<1];//边
edge q1[MAXQ<<1];//query
int f[MAXN];//并查集
bool vi[MAXN];//是否访问过
edge ans[MAXN];//对应每一个query的答案
int dis[MAXN<<1];//点到根的距离

int findset(int x)
{
  if (f[x]==x) return x;
  f[x]=findset(f[x]);
  return f[x];
}

inline void unionset(int x,int y)
{
  f[x]=y;
}

void TarjanDFS(int u,int father)
{
  int i;
  f[u]=u;
  i=que[u];
  while (i)
  {
    if (vi[q1[i].x]) ans[q1[i].s].s=findset(f[q1[i].x]);
    i=q1[i].y;
  }
  int fy,fx;
  i=h[u];
  vi[u]=true;
  fy=findset(u);
  while (i)
  {
    if (e[i].x!=father)
    {
      dis[e[i].x]=dis[u]+e[i].s;
      TarjanDFS(e[i].x,u);
      fx=findset(e[i].x);
      unionset(fx,fy);
    }
    i=e[i].y;
  }
}

inline void output()
{
  int i;
  for (i=1;i<=q;i++)
  {
    printf("%d\n",dis[ans[i].x]+dis[ans[i].y]-(dis[ans[i].s]<<1));
  }
}

int main()
{
  int x,y,z,i;
  char tmp[5];
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(h,0,sizeof(h));
    memset(que,0,sizeof(que));
    up=0;
    while (m--)
    {
      scanf("%d %d %d %s",&x,&y,&z,tmp);
      up++;
      e[up].x=y;
      e[up].s=z;
      e[up].y=h[x];
      h[x]=up;
      up++;
      e[up].x=x;
      e[up].s=z;
      e[up].y=h[y];
      h[y]=up;
    }
    scanf("%d",&q);
    up2=0;
    for (i=1;i<=q;i++)
    {
      scanf("%d%d",&x,&y);
      ans[i].x=x;
      ans[i].y=y;
      up2++;
      q1[up2].x=y;
      q1[up2].y=que[x];
      q1[up2].s=i;
      que[x]=up2;
      up2++;
      q1[up2].x=x;
      q1[up2].y=que[y];
      q1[up2].s=i;
      que[y]=up2;
    }
    dis[1]=0;
    TarjanDFS(1,0);
    output();
  }
  return 0;
}