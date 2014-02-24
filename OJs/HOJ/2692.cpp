/*This Code is Submitted by Timer for Problem 2692 at 2012-08-02 20:06:29*/
#include <cstdio>

using namespace std;

const int maxn=100010;
int cyr[maxn<<2];
int n;

inline int cyrmax(int x,int y)
{
  if (x>=y) return x;
  return y;
}

void build(int l,int r,int now)
{
  if (l==r)
  {
    scanf("%d",&cyr[now]);
    return;
  }
  int mid;
  mid=(l+r)>>1;
  build(l,mid,now<<1);
  build(mid+1,r,now<<1|1);
  cyr[now]=cyrmax(cyr[now<<1],cyr[now<<1|1]);
}

int query(int l,int r,int now,int x,int y)
{
  if ((x<=l) && (r<=y))
    return cyr[now];
  int mid,a,b;
  mid=(l+r)>>1;
  a=-1;
  b=-1;
  if (x<=mid) a=query(l,mid,now<<1,x,y);
  if (y>mid) b=query(mid+1,r,now<<1|1,x,y);
  return cyrmax(a,b);
}

void add(int l,int r,int now,int x,int v)
{
  if (l==r)
  {
    cyr[now]=v;
    return;
  }
  int mid;
  mid=(l+r)>>1;
  if (x<=mid) add(l,mid,now<<1,x,v);
    else add(mid+1,r,now<<1|1,x,v);
  cyr[now]=cyrmax(cyr[now<<1],cyr[now<<1|1]);
}

int main()
{
  int m,x,y,ans,op;
  while (scanf("%d%d",&n,&m)==2)
  {
    build(1,n,1);
    while (m--)
    {
      scanf("%d%d%d",&op,&x,&y);
      if (op==0)
        add(1,n,1,x,y);
      else
      if (op==1)
      {
        ans=query(1,n,1,x,y);
        printf("%d\n",ans);
      }
    }
  }
  return 0;
}