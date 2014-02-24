/*This Code is Submitted by Timer for Problem 2691 at 2013-01-21 21:19:31*/
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 100002

using namespace std;

struct eugin
{
  int num,x,y,v;
};

int a[MAXN<<2];
int n,m;
int x,y,v;
eugin c[50002];
int ans[50002];

bool operator < (eugin w1,eugin w2)
{
  if (w1.v>w2.v) return true;
  return false;
}

inline int mymax(int q,int w)
{
  if (q>=w) return q;
  return w;
}

void build(int l,int r,int now)
{
  if (l==r)
  {
    scanf("%d",&a[now]);
    return;
  }
  int mid;
  mid=l+r>>1;
  build(l,mid,now<<1);
  build(mid+1,r,now<<1|1);
  a[now]=mymax(a[now<<1],a[now<<1|1]);
}

int query(int l,int r,int now)
{
  if (x<=l && r<=y)
  {
    if (a[now]<=v) 
      return a[now];
    if (l==r)
    {
      a[now]^=a[now];
      return 0;
    }
    int mid,t1,t2;
    mid=l+r>>1;
    t1=query(l,mid,now<<1);
    t2=query(mid+1,r,now<<1|1);
    t1=mymax(t1,t2);
    a[now]=t1;
    return t1;
  }
  int mid,t1,t2;
  mid=l+r>>1;
  t1^=t1;
  t2^=t2;
  if (x<=mid)
    t1=query(l,mid,now<<1);
  if (y>mid)
    t2=query(mid+1,r,now<<1|1);
  t1=mymax(t1,t2);
  return t1;
}

int main()
{
  int i;
  while (scanf("%d%d",&n,&m)==2)
  {
    build(1,n,1);
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].v);
      c[i].num=i;
    }
    sort(c+1,c+m+1);
    for (i=1;i<=m;i++)
    {
      x=c[i].x;
      y=c[i].y;
      v=c[i].v;
      ans[c[i].num]=query(1,n,1);
    }
    for (i=1;i<=m;i++)
      printf("%d\n",ans[i]);
  }
  return 0;
}