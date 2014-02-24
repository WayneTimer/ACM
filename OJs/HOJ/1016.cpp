/*This Code is Submitted by Timer for Problem 1016 at 2013-01-18 11:23:22*/
#include <cstdio>
#include <cstring>

#define MAX 100000

int a[100000];
int p[3600];
int c[3600];
int ans[3600];
int n,m;

inline int lowbit(int x)
{
  return (x&(-x));
}

inline int sum(int x)
{
  int t;
  t=0;
  while (x>0)
  {
    t=t+c[x];
    x=x-lowbit(x);
  }
  return t;
}

inline void add(int x,int v)
{
  while (x<=n)
  {
    c[x]+=v;
    x=x+lowbit(x);
  }
}

inline void init()
{
  int i,j;
  m^=m;
  memset(a,0,sizeof(a));
  for (i=2;i<MAX;i++)
    if (!a[i])
    {
      for (j=2;i*j<MAX;j++)
        a[i*j]=1;
      m++;
      p[m]=i;
      if (m>3501) break;
    }
}

int main()
{
  int i,u,last;
  init();
  for (n=1;n<=3501;n++)
  {
    memset(c,0,sizeof(c));
    for (i=1;i<=n;i++)
      add(i,1);
    u=n;
    last=0;
    for (i=1;i<n;i++)
    {
      last+=p[i];
      if (last>u) last%=u;
      if (!last) last=u;
      int l,r,mid;
      l=1;
      r=n;
      while (l<r)
      {
        mid=l+r>>1;
        if (last<=sum(mid))
          r=mid;
        else
          l=mid+1;
      }
      add(l,-1);
      u--;
      last--;
    }
    int l,r,mid;
    l=1;
    r=n;
    while (l<r)
    {
      mid=l+r>>1;
      if (1<=sum(mid))
        r=mid;
      else
        l=mid+1;
    }
    /*printf("%d\n",l);*/
    ans[n]=l;
  }
  while (scanf("%d",&n)==1 && n)
    printf("%d\n",ans[n]);
  return 0;
}
 