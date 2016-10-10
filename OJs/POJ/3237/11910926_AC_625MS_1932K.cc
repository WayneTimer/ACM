//树链剖分+线段树(单点更新,区间修改,区间查询)
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 10030
#define lson now<<1
#define rson now<<1|1

struct cyr
{
  int ma,mi;
  int lazy;
};

struct edge
{
  int y,next,id;
};

struct eugin
{
  int size,fa,dep,top,w;
  int mainson;
  int son;
};

struct BIAN
{
  int v,w;
};

cyr b[MAXN<<2];
edge e[MAXN<<1];
eugin a[MAXN];
BIAN bian[MAXN];
int n,totw;
int wait[MAXN];

void dfs1(int x,int father,int d)
{
  int k,mx;
  a[x].fa=father;
  a[x].dep=d;
  a[x].size=1;
  a[x].mainson=-1;
  mx=0;
  k=a[x].son;
  while (k!=-1)
  {
    if (e[k].y!=father)
    {
      a[e[k].y].w=e[k].id;
      dfs1(e[k].y,x,d+1);
      a[x].size+=a[e[k].y].size;
      if (a[e[k].y].size>mx)
      {
        mx=a[e[k].y].size;
        a[x].mainson=e[k].y;
      }
    }
    k=e[k].next;
  }
}

void dfs2(int x,int father)
{
  int k;
  k=a[x].mainson;
  if (k!=-1)
  {
    a[k].top=a[x].top;
    totw++;
    wait[totw]=a[k].w;
    a[k].w=totw;
    dfs2(k,x);
  }
  k=a[x].son;
  while (k!=-1)
  {
    if (e[k].y!=father && e[k].y!=a[x].mainson)
    {
      a[e[k].y].top=e[k].y;
      totw++;
      wait[totw]=a[e[k].y].w;
      a[e[k].y].w=totw;
      dfs2(e[k].y,x);
    }
    k=e[k].next;
  }
}

inline void init()
{
  int i,up,x,y,v,root;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    a[i].son=-1;
  up=0;
  for (i=1;i<n;i++)
  {
    scanf("%d%d%d",&x,&y,&v);
    bian[i].v=v;
    up++;
    e[up].y=y;
    e[up].id=i;
    e[up].next=a[x].son;
    a[x].son=up;
    up++;
    e[up].y=x;
    e[up].id=i;
    e[up].next=a[y].son;
    a[y].son=up;
  }
  root=1+n>>1;
  dfs1(root,0,1);
  a[root].top=root;
  a[root].w=0;
  totw=0;
  dfs2(root,0);
}

inline void update(int now)
{
  b[now].lazy^=b[now].lazy;
  b[now].mi=min(b[lson].mi,b[rson].mi);
  b[now].ma=max(b[lson].ma,b[rson].ma);
}

inline void change(int now)
{
  int t;
  b[now].lazy^=1;
  t=b[now].mi;
  b[now].mi=-b[now].ma;
  b[now].ma=-t;
}

inline void pushdown(int now)
{
  int t;
  if (b[now].lazy)
  {
    change(lson);
    change(rson);
    b[now].lazy=0;
  }
}

void build(int l,int r,int now)
{
  if (l==r)
  {
    b[now].mi=bian[wait[l]].v;
    bian[wait[l]].w=l;
    b[now].ma=b[now].mi;
    b[now].lazy=0;
    return;
  }
  int mid;
  mid=l+r>>1;
  build(l,mid,lson);
  build(mid+1,r,rson);
  update(now);
}

void modify(int l,int r,int now,int x,int y)
{
  if (l==r)
  {
    b[now].mi=y;
    b[now].ma=y;
    return;
  }
  pushdown(now);
  int mid;
  mid=l+r>>1;
  if (x<=mid) modify(l,mid,lson,x,y);
  else modify(mid+1,r,rson,x,y);
  update(now);
}

void negate(int l,int r,int now,int x,int y)
{
  if (x<=l && r<=y)
  {
    change(now);
    return;
  }
  pushdown(now);
  int mid;
  mid=l+r>>1;
  if (x<=mid) negate(l,mid,lson,x,y);
  if (y>mid) negate(mid+1,r,rson,x,y);
  update(now);
}

int query(int l,int r,int now,int x,int y)
{
  if (x<=l && r<=y)
    return b[now].ma;
  pushdown(now);
  int mid,t1,t2;
  bool f1,f2;
  f1=false;
  f2=false;
  mid=l+r>>1;
  if (x<=mid) 
  {
    t1=query(l,mid,lson,x,y);
    f1=true;
  }
  if (y>mid)
  {
    t2=query(mid+1,r,rson,x,y);
    f2=true;
  }
  if (f1 && f2)
  {
    if (t1>t2) return t1;
    return t2;
  }
  if (f1) return t1;
  return t2;
}

inline int sub(int x,int y,int op)
{
  if (x==y) return 0;
  int x1,y1,ans,t;
  bool flag;
  flag=true;
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
    if (op)
    {
      t=query(1,totw,1,a[y1].w,a[y].w);
      if (flag)
      {
        ans=t;
        flag=false;
      }
      else
        if (t>ans) ans=t;
    }
    else
      negate(1,totw,1,a[y1].w,a[y].w);
    y=a[y1].fa;
    y1=a[y].top;
  }
  if (x==y) return ans;
  if (a[x].dep>a[y].dep)
  {
    x^=y;
    y^=x;
    x^=y;
  }
  if (op)
  {
    t=query(1,totw,1,a[x].w+1,a[y].w);
    if (flag)
    {
      ans=t;
      flag=false;
    }
    else
      if (t>ans) ans=t;
    return ans;
  }
  negate(1,totw,1,a[x].w+1,a[y].w);
  return 0;
}

inline void work()
{
  int x,y,ans;
  char op[10];
  build(1,totw,1);
  scanf("%s",op);
  while (op[0]!='D')
  {
    scanf("%d%d",&x,&y);
    if (op[0]=='C')
      modify(1,totw,1,bian[x].w,y);
    else if (op[0]=='N')
      sub(x,y,0);
    else
    {
      ans=sub(x,y,1);
      printf("%d\n",ans);
    }
    scanf("%s",op);
  }
}

int main()
{
  int T;
  scanf("%d",&T);
  while (T--)
  {
    init();
    work();
  }
  return 0;
}