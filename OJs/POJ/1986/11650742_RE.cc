#include <cstdio>
#include <cstring>

#define MAXN 20010
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
edge fa[MAXN];//父结点

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
      fa[e[i].x].x=u;
      fa[e[i].x].s=e[i].s;
      TarjanDFS(e[i].x,u);
      fx=findset(e[i].x);
      unionset(fx,fy);
    }
    i=e[i].y;
  }
}

inline int cal(int x,int u)
{
  if (x==u) return 0;
  return fa[x].s+cal(fa[x].x,x);
}

inline void output()
{
  int i;
  for (i=1;i<=q;i++)
  {
    printf("%d\n",cal(ans[i].x,ans[i].s)+cal(ans[i].y,ans[i].s));
  }
}

int main()
{
  int x,y,z,i;
  char tmp[5];
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(fa,0,sizeof(fa));
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
    TarjanDFS(1,0);
    output();
  }
  return 0;
}