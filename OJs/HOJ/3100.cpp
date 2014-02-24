/*This Code is Submitted by Timer for Problem 3100 at 2013-10-03 02:18:24*/
//简单一维DP
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000000

int n,tot;
int a[MAXN];
int dp[MAXN];
int fa[MAXN];
int b[MAXN];

inline void init()
{
  int head,tail,i;
  int w[2]={4,7};
  a[1]=4;
  a[2]=7;
  head=0;
  tail=2;
  do
  {
    head++;
    for (i=0;i<2;i++)
    {
      tail++;
      a[tail]=a[head]*10+w[i];
      if (a[tail]>MAXN) tail--;
    }
  } while (head<tail);
  tot=tail;
}

inline void work()
{
  int i,t,j;
  dp[0]=0;
  fa[0]=0;
  for (i=1;i<=n;i++)
  {
    dp[i]=-1;
    for (j=1;j<=tot;j++)
    {
      if (a[j]>i) break;
      if (dp[i-a[j]]!=-1)
      {
        t=dp[i-a[j]]+1;
        if (dp[i]==-1 || t<dp[i])
        {
          dp[i]=t;
          fa[i]=i-a[j];
        }
      }
    }
  }
}

inline void output()
{
  int i;
  i=0;
  while (n)
  {
    i++;
    b[i]=n-fa[n];
    n=fa[n];
  }
  sort(b+1,b+1+i);
  n=i;
  printf("%d",b[1]);
  for (i=2;i<=n;i++)
    printf(" %d",b[i]);
  puts("");
}

int main()
{
  init();
  while (scanf("%d",&n)==1)    //数据少，在线直接算更快
  {
    work();
    if (dp[n]==-1) puts("-1");
    else output();
  }
  return 0;
}