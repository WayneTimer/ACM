/*This Code is Submitted by Timer for Problem 2920 at 2012-12-18 16:15:44*/
#include <cstdio>
#include <cstring>

const int maxn=100000;
int n,a;
int c[100001];

inline int lowbit(int x)
{
  return (x&(-x));
}

inline int sum(int x)
{
  int t;
  t^=t;
  while (x>0)
  {
    t+=c[x];
    x-=lowbit(x);
  }
  return t;
}

inline void add(int x,int v)
{
  while (x<=maxn)
  {
    c[x]+=v;
    x+=lowbit(x);
  }
}

int find(int l,int r,int u)
{
  int mid;
  mid=(l+r)>>1;
  while (l<r)
  {
    if (sum(mid)>=u)
      r=mid;
    else
      l=mid+1;
    mid=(l+r)>>1;
  }
  return mid;
}

int main()
{
  int m,i,last;
  int temp;
  while (scanf("%d",&n)==1 && n)
  {
    m=n;
    memset(c,0,sizeof(c));
    for (i=1;i<=n;i++)
      add(i,1);
    last^=last;
    while (n--)
    {
      scanf("%d",&a);
      a=a%(n+1);
      if (!a) a=n+1;
      if (a+sum(last)<=sum(m))
      {
        temp=find(1,m,a+sum(last));
        add(temp,-1);
        if (n)
          printf("%d ",temp);
        else
          printf("%d\n",temp);
      }
      else
      {
        temp=find(1,m,a-sum(m)+sum(last));
        add(temp,-1);
        if (n)
          printf("%d ",temp);
        else
          printf("%d\n",temp);
      }
      last=temp;
    }
  }
  return 0;
}