/*This Code is Submitted by Timer for Problem 2685 at 2013-01-09 02:23:49*/
/*
简单线段树。

题意：
有两个操作：
1、把A—B段涂成颜色C；
2、查询A—B段共有几种颜色。

solution:
注意到颜色最多只有30种，于是可以状态压缩来保存每个区间的颜色状态。

Trick:
A可能大于B。
POJ上的数据比较大，需要将线段树开成N*6的才行。
*/
#include <cstdio>

#define N 100010

struct cyr
{
  int v;
  bool lazy;
};

int n,o,T;
int x,y,c;
cyr a[N*6];

void build(int l,int r,int now)
{
  if (l==r)
  {
    a[now].v=1;
    a[now].lazy=false;
    return;
  }
  int mid;
  mid=(l+r)>>1;
  build(l,mid,now<<1);
  build(mid+1,r,now<<1|1);
  a[now].v=1;
  a[now].lazy=false;
}

void change(int l,int r,int now)
{
  if ((x<=l) && (r<=y))
  {
    a[now].v=c;
    a[now].lazy=true;
    return;
  }
  if (a[now].lazy)
  {
    a[now].lazy=false;
    a[now<<1].v=a[now].v;
    a[now<<1].lazy=true;
    a[now<<1|1].v=a[now].v;
    a[now<<1|1].lazy=true;
  }
  int mid;
  mid=(l+r)>>1;
  if (x<=mid) change(l,mid,now<<1);
  if (y>mid) change(mid+1,r,now<<1|1);
  a[now].v=a[now<<1].v|a[now<<1|1].v;
  return;
}

int query(int l,int r,int now)
{
  if (a[now].lazy)
  {
    a[now].lazy=false;
    a[now<<1].v=a[now].v;
    a[now<<1].lazy=true;
    a[now<<1|1].v=a[now].v;
    a[now<<1|1].lazy=true;
  }
  if ((x<=l) && (r<=y))
    return a[now].v;
  int mid,t1,t2;
  t1^=t1;
  t2^=t2;
  mid=(l+r)>>1;
  if (x<=mid) t1=query(l,mid,now<<1);
  if (y>mid) t2=query(mid+1,r,now<<1|1);
  return t1|t2;
}

int main()
{
  int i,s,temp;
  char op[4];
  while (scanf("%d%d%d",&n,&T,&o)==3)
  {
    build(1,n,1);
    while (o--)
    {
      scanf("%s",op);
      if (op[0]=='C')
      {
        scanf("%d%d%d",&x,&y,&c);
        if (c>T) continue;
        if (x>y)
        {
          temp=x;
          x=y;
          y=temp;
        }
        c=1<<(c-1);
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
        c=query(1,n,1);
        s^=s;
        while (c>0)
        {
          if (c&1) s++;
          c=c>>1;
        }
        printf("%d\n",s);
      }
    }
  }
  return 0;
}
 