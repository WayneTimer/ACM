/*This Code is Submitted by Timer for Problem 2682 at 2013-07-29 19:32:47*/
//树状数组解法：0.23s
#include <cstdio>
#include <cstring>

#define MAXN 10010
#define lowbit(x) (x&(-x))

int c[MAXN];
int n;

void add(int x,int v)
{
  while (x<=n)
  {
    c[x]+=v;
    x+=lowbit(x);
  }
}

int sum(int x)
{
  int t;
  t=0;
  while (x>0)
  {
    t+=c[x];
    x-=lowbit(x);
  }
  return t;
}

int main()
{
  int m,x,y,i;
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(c,0,sizeof(int)*(n+4));
    while (m--)
    {
      scanf("%d%d",&x,&y);
      add(x,1);
      add(y+1,-1);
    }
    m=0;
    for (i=1;i<=n;i++)
    {
      x=sum(i);
      if (!(x&1)) m++;
    }
    printf("%d\n",m);
  }
  return 0;
}

/*
线段树解法：0.37s
#include <cstdio>
#include <cstring>

#define MAXN 10010
#define lson now<<1
#define rson now<<1|1

int n,x,y;
int a[MAXN<<2];

void change(int l,int r,int now)
{
  if (x<=l && r<=y)
  {
    a[now]^=1;
    return;
  }
  int mid;
  mid=l+r>>1;
  if (x<=mid) change(l,mid,lson);
  if (y>mid) change(mid+1,r,rson);
}

inline void pushdown(int now)
{
  a[lson]^=a[now];
  a[rson]^=a[now];
  a[now]=0;
}

int query(int l,int r,int now)
{
  if (l==r)
    if (a[now]&1) return 0;
      else return 1;
  int s1,s2,mid;
  mid=l+r>>1;
  pushdown(now);
  s1=query(l,mid,lson);
  s2=query(mid+1,r,rson);
  return s1+s2;
}

int main()
{
  int m;
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(a,0,sizeof(int)*((n<<2)+4));
    while (m--)
    {
      scanf("%d%d",&x,&y);
      change(1,n,1);
    }
    printf("%d\n",query(1,n,1));
  }
  return 0;
}
*/