/*This Code is Submitted by Timer for Problem 2965 at 2013-01-09 02:31:21*/
/*
线段树，操作有区间更新，需要用到lazy标记。
每个区间维护这几个值：
1、左端点颜色left；
2、右端点颜色right；
3、该区间被画次数d；
4、区间内连续色带的个数sum；
5、lazy标记（表示是否需要向下扩展）。

代码：（代码写的比较烂，主要是因为开始省时间没打lazy标记，结果TLE，后来加上2个域后写残了，d的意义改了好几次才对）
*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int left;
  int right;
  int d;
  int sum;
  bool lazy;
};

const int maxn=100010;
int n,m,k;
cyr a[maxn<<2];

void build(int l,int r,int now)
{
  if (l==r)
  {
    a[now].left=0;
    a[now].right=0;
    a[now].sum=1;
    a[now].d=0;
    a[now].lazy=false;
    return;
  }
  int mid;
  mid=(l+r)>>1;
  build(l,mid,now<<1);
  build(mid+1,r,now<<1|1);
  a[now].left=0;
  a[now].right=0;
  a[now].sum=1;
  a[now].d=0;
  a[now].lazy=false;
}

void change(int l,int r,int now,int x,int y)
{
  if ((x<=l) && (r<=y))
  {
    a[now].d++;
    a[now].d=a[now].d%k;
    a[now].left+=1;
    a[now].left%=k;
    a[now].right+=1;
    a[now].right%=k;
    a[now].lazy=true;
    return;
  }
  int mid;
  mid=(l+r)>>1;
  if (a[now].lazy)
  {
    a[now<<1].d+=a[now].d;
    a[now<<1].d=a[now<<1].d%k;
    a[now<<1].left+=a[now].d;
    a[now<<1].left%=k;
    a[now<<1].right+=a[now].d;
    a[now<<1].right%=k;
    a[now<<1].lazy=true;
   
    a[now<<1|1].d+=a[now].d;
    a[now<<1|1].d=a[now<<1|1].d%k;
    a[now<<1|1].left+=a[now].d;
    a[now<<1|1].left%=k;
    a[now<<1|1].right+=a[now].d;
    a[now<<1|1].right%=k;
    a[now<<1|1].lazy=true;
   
    a[now].sum=a[now<<1].sum+a[now<<1|1].sum;
    if (a[now<<1].right==a[now<<1|1].left) a[now].sum--;
    a[now].d=0;
    a[now].lazy=false;
  }
  if (x<=mid)
  {
    change(l,mid,now<<1,x,y);
    a[now].left=a[now<<1].left;
  }
  if (y>mid)
  {
    change(mid+1,r,now<<1|1,x,y);
    a[now].right=a[now<<1|1].right;
  }
  a[now].sum=a[now<<1].sum+a[now<<1|1].sum;
  if (a[now<<1].right==a[now<<1|1].left) a[now].sum--;
}

int query(int l,int r,int now,int x,int y)
{
  if ((x<=l) && (r<=y))
    return a[now].sum;
  if (l==r)
  {
    return a[now].sum;
  }
  int mid,t1,t2;
  int le,ri;
  mid=(l+r)>>1;
  t1=0;
  t2=0;
  le=-1;
  ri=-1;
  if (a[now].lazy)
  {
    a[now<<1].d+=a[now].d;
    a[now<<1].d=a[now<<1].d%k;
    a[now<<1].left+=a[now].d;
    a[now<<1].left%=k;
    a[now<<1].right+=a[now].d;
    a[now<<1].right%=k;
    a[now<<1].lazy=true;
   
    a[now<<1|1].d+=a[now].d;
    a[now<<1|1].d=a[now<<1|1].d%k;
    a[now<<1|1].left+=a[now].d;
    a[now<<1|1].left%=k;
    a[now<<1|1].right+=a[now].d;
    a[now<<1|1].right%=k;
    a[now<<1|1].lazy=true;
   
    a[now].left=a[now<<1].left;
    a[now].right=a[now<<1|1].right;
    a[now].sum=a[now<<1].sum+a[now<<1|1].sum;
    if (a[now<<1].right==a[now<<1|1].left) a[now].sum--;
    a[now].d=0;
    a[now].lazy=false;
  }
  if (x<=mid)
  {
    t1=query(l,mid,now<<1,x,y);
    le=a[now<<1].right;
  }
  if (y>mid)
  {
    t2=query(mid+1,r,now<<1|1,x,y);
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
  int x,y,temp,c;
  int T,op;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d%d%d",&n,&k,&m);
    build(1,n,1);
    while (m--)
    {
      scanf("%d%d%d",&op,&x,&y);
      if (x>y)
      {
        c=x;
        x=y;
        y=c;
      }
      if (op==0)
        change(1,n,1,x,y);
      else
      {
        temp=query(1,n,1,x,y);
        printf("%d\n",temp);
      }
    }
  }
  return 0;
}
 