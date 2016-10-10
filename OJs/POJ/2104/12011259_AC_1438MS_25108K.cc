//可持久化线段树  [正解是用 划分树 做]
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100030

struct eugin
{
  int lson,rson,s;
};

struct IN
{
  int v,p;
};

eugin a[MAXN*33]; //2n*logn
int root[MAXN];
int n,up;
IN in[MAXN];
int wait[MAXN];

bool operator < (IN q,IN w)
{
  return (q.v<w.v);
}

int build(int l,int r)
{
  int t;
  up++;
  t=up;
  if (l==r)
  {
    a[t].lson=0;
    a[t].rson=0;
    a[t].s=0;
    return t;
  }
  int mid;
  mid=l+r>>1;
  a[t].lson=build(l,mid);
  a[t].rson=build(mid+1,r);
  a[t].s=0;
  return t;
}

int insert(int l,int r,int v,int last)
{
  int t;
  up++;
  t=up;
  a[t].s=a[last].s+1;
  if (l==r)
  {
    a[t].lson=0;
    a[t].rson=0;
    return t;
  }
  int mid;
  mid=l+r>>1;
  if (v<=mid)
  {
    a[t].rson=a[last].rson;
    a[t].lson=insert(l,mid,v,a[last].lson);
  }
  else
  {
    a[t].lson=a[last].lson;
    a[t].rson=insert(mid+1,r,v,a[last].rson);
  }
  return t;
}

int query(int l,int r,int now,int last,int k)
{
  if (l==r) return l;
  int mid,t;
  mid=l+r>>1;
  t=a[a[now].lson].s-a[a[last].lson].s;
  if (k<=t)
    return query(l,mid,a[now].lson,a[last].lson,k);
  else
    return query(mid+1,r,a[now].rson,a[last].rson,k-t);
}

int main()
{
  int m,x,y,k,i;
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
  {
    scanf("%d",&in[i].v);
    in[i].p=i;
  }
  sort(in+1,in+1+n);
  for (i=1;i<=n;i++)
    wait[in[i].p]=i;
  up=0;
  root[0]=build(1,n);
  for (i=1;i<=n;i++)
    root[i]=insert(1,n,wait[i],root[i-1]);
  while (m--)
  {
    scanf("%d%d%d",&x,&y,&k);
    i=query(1,n,root[y],root[x-1],k);
    printf("%d\n",in[i].v);
  }
  return 0;
}