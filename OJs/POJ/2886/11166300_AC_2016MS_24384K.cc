/*
林毅

题目：http://poj.org/problem?id=2886

关键词：线段树。
题目大意是一个约瑟夫环，每个小孩按一定顺序出圈，第p个出圈的小孩获得f(p)个candies。f(p)是p的约数的个数。
首先是先求出f(p)，反素数相关。因为N不算太大，直接将反素数打表即可。
然后建一棵线段树，存下每个区间剩余的人数和，然后每次找第k个的时候只需要找左儿子或者是右儿子，这里的复杂度就降到 logk 了。
*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int num;
  int sum;
};

const int maxn=500100;
const int thep[35]={1,2,4,6,12,24,36,
                    48,60,120,180,240,360,720,
                    840,1260,1680,2520,5040,7560,10080,
                    15120,20160,25200,27720,45360,50400,55440,
                    83160,110880,166320,221760,277200,332640,498960
                   }; //表示前35个反素数
const int fansushu[35]={1,2,3,4,6,8,9,
                        10,12,16,18,20,24,30,
                        32,36,40,48,60,64,72,
                        80,84,90,96,100,108,120,
                        128,144,160,168,180,192,200
                       }; //表示前35个反素数的约数的个数

int v[maxn],temp,last,k,max,p;
int next_i; //next_i表示当前指向反素数数组的第几项
char name[maxn][13];
char max_name[13];
cyr a[maxn<<2];

void build(int l,int r,int now)
{
  if (l==r)
  {
    temp++;
    a[now].num=temp;
    a[now].sum=1;
    return;
  }
  int mid;
  mid=(l+r)>>1;
  build(l,mid,now<<1);
  build(mid+1,r,now<<1|1);
  a[now].sum=a[now<<1].sum+a[now<<1|1].sum;
}

void kill(int l,int r,int now,int x)
{
  if (l==r)
  {
    a[now].sum=0;
    if (p==thep[next_i])
    {
      max=next_i;
      next_i++;
      strcpy(max_name,name[a[now].num]);
    }
    k=v[a[now].num];
    return;
  }
  int mid;
  mid=(l+r)>>1;
  if (a[now<<1].sum>=x) kill(l,mid,now<<1,x);
    else
    {
      x=x-a[now<<1].sum;
      kill(mid+1,r,now<<1|1,x);
    }
  a[now].sum--;
}

int main()
{
  int n,i;
  while (scanf("%d%d",&n,&k)==2)
  {
    getchar();
    memset(name,0,sizeof(name));
    memset(a,0,sizeof(a));
    memset(v,0,sizeof(v));
    for (i=1;i<=n;i++)
    {
      scanf("%s %d",name[i],&v[i]);
      getchar();
    }
    temp=0;
    build(1,n,1);
    last=k;
    next_i=0;
    max=1;
    p=0;
    while (a[1].sum>0)
    {
      while (last<0) last=last+a[1].sum;
      last=last%a[1].sum;
      if (last==0) last=a[1].sum;
      p++;
      kill(1,n,1,last);
      if (k>=0) last=last+k-1;
        else last=last+k;
    }
    printf("%s %d\n",max_name,fansushu[max]);
  }
  return 0;
}
