/*This Code is Submitted by Timer for Problem 2430 at 2013-02-01 21:31:43*/
#include <cstdio>
#include <cstring>

#define MAXN 100002

int a[MAXN<<1];//储存2*N个数
int p[MAXN];//p[i]表示i在第二次出现的位置
int n;
int c[MAXN<<1];

inline int lowbit(int x)
{
  return x&(-x);
}

inline void add(int x,int v)
{
  while (x<=n)
  {
    c[x]+=v;
    x+=lowbit(x);
  }
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

int main()
{
  int x,ans,i;
  while (scanf("%d",&n)==1)
  {
    n<<=1;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      if (p[a[i]]!=-1) p[a[i]]=-1;
        else p[a[i]]=i;
    }
    memset(c,0,sizeof(c));
    ans^=ans;
    for (i=1;i<=n;i++)
      if (a[i])
      {
        x=p[a[i]];
        a[x]=0;
        x=sum(x)-sum(i);
        x=p[a[i]]-i-x;
        ans+=x;
        add(i,1);
        add(p[a[i]],1);
      }
    printf("%d\n",ans);
  }
  return 0;
}