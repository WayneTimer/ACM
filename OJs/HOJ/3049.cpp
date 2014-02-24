/*This Code is Submitted by Timer for Problem 3049 at 2013-07-29 11:34:04*/
//树链剖分+树状数组
#include <cstdio>
#include <cstring>

#define MAXN 50010
#define lowbit(x) (x&(-x))

struct edge
{
  int y,next;
};

struct node
{
  int size,dep,top,fa;
  int mainson;
  int son;
};

int c[MAXN];
int n,up,root,totw;
int ori[MAXN];
edge e[MAXN<<1];
int tot[MAXN]; //点对应在树状数组中的点
node a[MAXN];

inline void add(int x,int v)
{
  while (x<=n)
  {
    c[x]+=v;
    x+=lowbit(x);
  }
}

inline int sum(int x)
{
  int t;
  t^=t;
  while (x>0)
  {
    t+=c[x];
    x-=lowbit(x);
  }
  return t;
}

void dfs1(int x,int father,int d) //求出size,dep,fa,mainson
{
  a[x].size=1;
  a[x].dep=d;
  a[x].fa=father;
  a[x].mainson=-1;
  int k,temp;
  temp=0;
  k=a[x].son;
  while (k!=-1)
  {
    if (e[k].y!=father)
    {
      dfs1(e[k].y,x,d+1);
      a[x].size+=a[e[k].y].size;
      if (a[e[k].y].size>temp)
      {
        a[x].mainson=e[k].y;
        temp=a[e[k].y].size;
      }
    }
    k=e[k].next;
  }
}

void dfs2(int x,int father) //求top
{
  if (a[x].mainson!=-1)
  {
    a[a[x].mainson].top=a[x].top;
    totw++;
    tot[a[x].mainson]=totw;
    add(totw,ori[a[x].mainson]);
    add(totw+1,-ori[a[x].mainson]);
    dfs2(a[x].mainson,x);
  }
  int k;
  k=a[x].son;
  while (k!=-1)
  {
    if (e[k].y!=father && e[k].y!=a[x].mainson)
    {
      a[e[k].y].top=e[k].y;
      totw++;
      tot[e[k].y]=totw;
      add(totw,ori[e[k].y]);
      add(totw+1,-ori[e[k].y]);
      dfs2(e[k].y,x);
    }
    k=e[k].next;
  }
}

inline void work(int x,int y,int v)
{
  int x1,y1;
  x1=a[x].top;
  y1=a[y].top;
  while (x1!=y1)
  {
    if (a[x1].dep>a[y1].dep)
    {
      x^=y;
      y^=x;
      x^=y;
      x1=a[x].top;
      y1=a[y].top;
    }
    add(tot[y1],v);
    add(tot[y]+1,-v);
    y=a[y1].fa;
    y1=a[y].top;
  }
  if (a[x].dep>a[y].dep)
  {
    x^=y;
    y^=x;
    x^=y;
  }
  add(tot[x],v);
  add(tot[y]+1,-v);
}

int main()
{
  int m,p,i,x,y;
  char op[4];
  while (scanf("%d%d%d",&n,&m,&p)==3)
  {
    for (i=1;i<=n;i++)
    {
      scanf("%d",&ori[i]);
      a[i].son=-1;
    }
    up^=up;
    memset(c,0,sizeof(c));
    while (m--)
    {
      scanf("%d%d",&x,&y);
      up++;
      e[up].y=y;
      e[up].next=a[x].son;
      a[x].son=up;
      up++;
      e[up].y=x;
      e[up].next=a[y].son;
      a[y].son=up;
    }
    root=1+n>>1;
    dfs1(root,0,1);
    a[root].top=root;
    totw=1;
    tot[root]=1;
    add(1,ori[root]);
    add(2,-ori[root]);
    dfs2(root,0);
    while (p--)
    {
      scanf("%s",op);
      if (op[0]=='Q')
      {
        scanf("%d",&x);
        printf("%d\n",sum(tot[x]));
      }
      else
      {
        scanf("%d%d%d",&x,&y,&m);
        if (op[0]=='D') m=-m;
        work(x,y,m);
      }
    }
  }
  return 0;
}