//线段树
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 50030
#define lson now<<1
#define rson now<<1|1

struct eugin
{
  int ls,rs,ms;
  int lazy;
  //0表示区间未被全部改变,1表示被占,-1表示为空
};

eugin a[MAXN<<2];
int n,x,y;

inline void pushdown(int l,int r,int now)
{
  if (a[now].lazy)
  {
    int mid;
    mid=l+r>>1;
    if (a[now].lazy==1)
    {
      a[now].lazy=0;
      a[lson].ls=0;
      a[lson].rs=0;
      a[lson].ms=0;
      a[lson].lazy=1;
      a[rson].ls=0;
      a[rson].rs=0;
      a[rson].ms=0;
      a[rson].lazy=1;
    }
    else
    {
      a[now].lazy=0;
      int t;
      t=mid-l+1;
      a[lson].ls=t;
      a[lson].rs=t;
      a[lson].ms=t;
      a[lson].lazy=-1;
      t=r-mid;
      a[rson].ls=t;
      a[rson].rs=t;
      a[rson].ms=t;
      a[rson].lazy=-1;
    }
  }
}

inline void pushup(int l,int r,int now)
{
  int mid;
  mid=l+r>>1;
  a[now].ls=a[lson].ls;
  a[now].rs=a[rson].rs;
  if (a[lson].ls==mid-l+1)
    a[now].ls+=a[rson].ls;
  if (a[rson].rs==r-mid)
    a[now].rs+=a[lson].rs;
  a[now].ms=max(a[lson].ms,a[rson].ms);
  a[now].ms=max(a[now].ms,a[lson].rs+a[rson].ls);
  a[now].ms=max(a[now].ms,a[now].ls);
  a[now].ms=max(a[now].ms,a[now].rs);
}

void modify(int l,int r,int now,int v)
{
  if (x<=l && r<=y)
  {
    a[now].lazy=v;
    if (v==1)
    {
      a[now].ls=0;
      a[now].rs=0;
      a[now].ms=0;
    }
    else
    {
      int t;
      t=r-l+1;
      a[now].ls=t;
      a[now].rs=t;
      a[now].ms=t;
    }
    return;
  }
  pushdown(l,r,now);
  int mid;
  mid=l+r>>1;
  if (x<=mid) modify(l,mid,lson,v);
  if (y>mid) modify(mid+1,r,rson,v);
  pushup(l,r,now);
}

int query(int l,int r,int now,int v)
{
  int mid;
  mid=l+r>>1;
  pushdown(l,r,now);
  if (a[lson].ms>=v)
    return query(l,mid,lson,v);
  if (a[lson].rs+a[rson].ls>=v)
    return mid-a[lson].rs+1;
  return query(mid+1,r,rson,v);
}

int main()
{
  int m,op,v;
  scanf("%d%d",&n,&m);
  a[1].lazy=-1;
  a[1].ms=n;
  while (m--)
  {
    scanf("%d",&op);
    if (op==1)
    {
      scanf("%d",&v);
      if (a[1].ms<v)
      {
        puts("0");
        continue;
      }
      x=query(1,n,1,v);
      printf("%d\n",x);
      y=x+v-1;
      modify(1,n,1,1);
    }
    else
    {
      scanf("%d%d",&x,&y);
      y+=x-1;
      modify(1,n,1,-1);
    }
  }
  return 0;
}