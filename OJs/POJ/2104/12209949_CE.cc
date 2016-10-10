//可持久化线段树  [正解是用 划分树 做]
/*
线段树的表示：
并不是以 *2,*2+1 来表示区间左儿子和右儿子,
而是用实际的游标指示
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100030

struct eugin
{
  int lson,rson,s;
  //左儿子游标，右儿子游标，该区间被加入的数的个数
};

struct IN //输入的原始数据
{
  int v,p;
  //值，输入时的位置
};

eugin a[(MAXN<<2)+MAXN*17]
/*
空间复杂度O(4n+nlogn)
最初线段树约为4n，每次插入新的数新生成logn个结点
*/
int root[MAXN];
int n,up;
IN in[MAXN];
int wait[MAXN]; //离散化后的输入数列数组

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
  if (v<=mid) //若往左区间插数，则右区间仍为上一版本的右区间
  {
    a[t].rson=a[last].rson;
    a[t].lson=insert(l,mid,v,a[last].lson);
  }
  else //若往右区间插数，则左区间仍为上一版本的左区间
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
  t=a[a[now].lson].s-a[a[last].lson].s; //区间[x,y]内前半部分含有的数的个数
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
  for (i=1;i<=n;i++) //离散化，数据保证了输入的数不重复
    wait[in[i].p]=i;
  up=0;
  root[0]=build(1,n);
  for (i=1;i<=n;i++) //按输入顺序插入各数
    root[i]=insert(1,n,wait[i],root[i-1]);
  while (m--)
  {
    scanf("%d%d%d",&x,&y,&k);
    i=query(1,n,root[y],root[x-1],k);
    printf("%d\n",in[i].v);
  }
  return 0;
}