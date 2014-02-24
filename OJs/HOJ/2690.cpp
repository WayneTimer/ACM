/*This Code is Submitted by Timer for Problem 2690 at 2012-08-02 19:55:13*/
#include <cstdio>

using namespace std;

const int maxn=500010;
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

int main()
{
  int m,x,y,ans;
  while (scanf("%d%d",&n,&m)==2)
  {
    build(1,n,1);
    while (m--)
    {
      scanf("%d%d",&x,&y);
      ans=query(1,n,1,x,y);
      printf("%d\n",ans);
    }
  }
  return 0;
}