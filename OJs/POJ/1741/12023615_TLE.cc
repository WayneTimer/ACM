#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 10030

struct edge
{
  int y,next,v;
};

struct eugin
{
  int d,son,s,t;
};

int n,limit,tot,ans,size,root;
eugin a[MAXN];
edge e[MAXN<<1];
int b[MAXN];

inline void addedge(int x,int y,int v)
{
  tot++;
  e[tot].y=y;
  e[tot].v=v;
  e[tot].next=a[x].son;
  a[x].son=tot;
}

void findroot(int x,int father) //找重心作为子树根
{
  a[x].s=1;
  a[x].t=0;
  int k;
  k=a[x].son;
  while (k!=-1)
  {
    if (e[k].y!=father)
    {
      findroot(e[k].y,x);
      a[x].s+=a[e[k].y].s;
      a[x].t=max(a[x].t,a[e[k].y].s);
    }
    k=e[k].next;
  }
  a[x].t=max(a[x].t,size-a[x].s);
  if (a[x].t<a[root].t)
    root=x;
}

void dfs(int x,int father,int dis)
{
  a[x].d=dis;
  b[tot]=dis;
  tot++;
  int k;
  k=a[x].son;
  while (k!=-1)
  {
    if (e[k].y!=father)
      dfs(e[k].y,x,dis+e[k].v);
    k=e[k].next;
  }
}

int cal(int r)
{
  int i,j,ret;
  i=0;
  j=r;
  ret=0;
  while (i<j)
  {
    if (b[i]+b[j]<=limit)
    {
      ret+=j-i;
      i++;
    }
    else
      j--;
  }
  return ret;
}

void work(int x,int father)
{
  int i;
  tot=0;
  dfs(x,father,0);
  sort(b,b+tot);
  ans+=cal(tot-1);
  int k;
  k=a[x].son;
  while (k!=-1)
  {
    if (e[k].y!=father)
    {
      tot=0;
      dfs(e[k].y,x,a[x].d);
      sort(b,b+tot);
      ans-=cal(tot-1);
      size=a[e[k].y].s;
      root=0;
      work(e[k].y,x);
    }
    k=e[k].next;
  }
}

int main()
{
  int i,x,y,v;
  scanf("%d%d",&n,&limit);
  while (n || limit)
  {
    tot=0;
    memset(a,-1,sizeof(a));
    ans=0;
    a[0].t=n;
    for (i=1;i<n;i++)
    {
      scanf("%d%d%d",&x,&y,&v);
      addedge(x,y,v);
      addedge(y,x,v);
    }
    size=n;
    root=1;
    findroot(1,0);
    work(root,0);
    printf("%d\n",ans);
    scanf("%d%d",&n,&limit);
  }
  return 0;
}