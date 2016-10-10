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
  int d,son;
};

int n,limit,tot,ans;
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
  i=1;
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

void dfsfind(int x,int father)
{
  b[tot]=a[x].d;
  tot++;
  int k;
  k=a[x].son;
  while (k!=-1)
  {
    if (e[k].y!=father)
      dfsfind(e[k].y,x);
    k=e[k].next;
  }
}

void work(int x,int father)
{
  int i;
  tot=0;
  dfs(x,father,0);
  sort(b+1,b+tot);
  for (i=1;i<tot;i++)
    if (b[i]>limit)
      break;
  ans+=i-1;
  ans+=cal(tot-1);
  int k;
  k=a[x].son;
  while (k!=-1)
  {
    if (e[k].y!=father)
    {
      tot=0;
      dfsfind(e[k].y,x);
      sort(b+1,b+tot);
      for (i=1;i<tot;i++)
        if (b[i]>limit)
          break;
      ans-=i-1;
      ans-=cal(tot-1);
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
    for (i=1;i<n;i++)
    {
      scanf("%d%d%d",&x,&y,&v);
      addedge(x,y,v);
      addedge(y,x,v);
    }
    work(1,0);
    printf("%d\n",ans);
    scanf("%d%d",&n,&limit);
  }
  return 0;
}