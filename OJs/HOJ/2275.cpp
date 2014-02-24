/*This Code is Submitted by Timer for Problem 2275 at 2012-08-01 10:33:37*/
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=32768;
int c[34000];
int a[50006];
int l[50006];
int r[50006];
int n;

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
  while (x<=maxn)
  {
    c[x]+=v;
    x=x+lowbit(x);
  }
}

int main()
{
  long long ans,t;
  int i;
  while (scanf("%d",&n)==1)
  {
    ans=0;
    memset(c,0,sizeof(c));
    for (i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      l[i]=sum(a[i]-1);
      add(a[i],1);
    }
    memset(c,0,sizeof(c));
    for (i=n;i>=1;i--)
    {
      r[i]=sum(a[i]-1);
      add(a[i],1);
      t=l[i];
      t=t*r[i];
      ans+=t;
    }
    printf("%lld\n",ans);
  }
  return 0;
}