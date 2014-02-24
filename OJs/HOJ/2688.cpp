/*This Code is Submitted by Timer for Problem 2688 at 2013-01-09 02:31:00*/
/*
简单线段树。

题意：略。

solution:
线段树维护4个域:
1、left:区间左端点的颜色
2、right:区间右端点的颜色
3、sum:区间的色带个数
4、lazy:下沉标记

每次改变区间颜色时，左端点右端点颜色都变为改变值，sum值变为1，lazy变为true。然后返回时更新，sum等于它左区间与右区间的sum和，如果左区间的右端点颜色与右区间的左端点颜色相同，则sum--
*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int left;
  int right;
  int sum;
  bool lazy;
};

const int maxn=200010;
int n,m,k,c,x,y;
cyr a[maxn<<2];

void build(int l,int r,int now)
{
  if (l==r)
  {
    a[now].left=1;
    a[now].right=1;
    a[now].sum=1;
    a[now].lazy=false;
    return;
  }
  int mid;
  mid=(l+r)>>1;
  build(l,mid,now<<1);
  build(mid+1,r,now<<1|1);
  a[now].left=1;
  a[now].right=1;
  a[now].sum=1;
  a[now].lazy=false;
}

void change(int l,int r,int now)
{
  if ((x<=l) && (r<=y))
  {
    a[now].left=c;
    a[now].right=c;
    a[now].sum=1;
    a[now].lazy=true;
    return;
  }
  int mid;
  mid=(l+r)>>1;
  if (a[now].lazy)
  {
    a[now<<1].left=a[now].left;
    a[now<<1].right=a[now].left;
    a[now<<1].sum=1;
    a[now<<1].lazy=true;
   
    a[now<<1|1].left=a[now].right;
    a[now<<1|1].right=a[now].right;
    a[now<<1|1].sum=1;
    a[now<<1|1].lazy=true;
   
    a[now].lazy=false;
  }
  if (x<=mid)
  {
    change(l,mid,now<<1);
    a[now].left=a[now<<1].left;
  }
  if (y>mid)
  {
    change(mid+1,r,now<<1|1);
    a[now].right=a[now<<1|1].right;
  }
  a[now].sum=a[now<<1].sum+a[now<<1|1].sum;
  if (a[now<<1].right==a[now<<1|1].left) a[now].sum--;
}

int query(int l,int r,int now)
{
  if ((x<=l) && (r<=y))
    return a[now].sum;
  if (l==r)
    return a[now].sum;
  int mid,t1,t2;
  int le,ri;
  mid=(l+r)>>1;
  t1=0;
  t2=0;
  le=-1;
  ri=-1;
  if (a[now].lazy)
  {
    a[now<<1].left=a[now].left;
    a[now<<1].right=a[now].left;
    a[now<<1].sum=1;
    a[now<<1].lazy=true;
   
    a[now<<1|1].left=a[now].right;
    a[now<<1|1].right=a[now].right;
    a[now<<1|1].sum=1;
    a[now<<1|1].lazy=true;
   
    a[now].lazy=false;
  }
  if (x<=mid)
  {
    t1=query(l,mid,now<<1);
    le=a[now<<1].right;
  }
  if (y>mid)
  {
    t2=query(mid+1,r,now<<1|1);
    ri=a[now<<1|1].left;
  }
  a[now].left=a[now<<1].left;
  a[now].right=a[now<<1|1].right;
  a[now].sum=a[now<<1].sum+a[now<<1|1].sum;
  if (a[now<<1].right==a[now<<1|1].left) a[now].sum--;
  if (le==-1)
    return t2;
  if (ri==-1)
    return t1;
  t1=t1+t2;
  if (le==ri) t1--;
  return t1;
}

int main()
{
  int temp;
  int T,op;
  while (scanf("%d%d%d",&n,&k,&m)==3)
  {
    build(1,n,1);
    while (m--)
    {
      scanf("%d",&op);
      if (op==1)
      {
        scanf("%d%d%d",&x,&y,&c);
        if (x>y)
        {
          temp=x;
          x=y;
          y=temp;
        }
        change(1,n,1);
      }
      else
      {
        scanf("%d%d",&x,&y);
        if (x>y)
        {
          temp=x;
          x=y;
          y=temp;
        }
        temp=query(1,n,1);
        printf("%d\n",temp);
      }
    }
  }
  return 0;
}
 