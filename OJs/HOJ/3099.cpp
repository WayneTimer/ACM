/*This Code is Submitted by Timer for Problem 3099 at 2013-10-03 01:33:39*/
//简单一维DP
#include <cstdio>

#define MAXN 100000

int n,k,tot;
int a[MAXN];
int dp[MAXN];

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

inline int work()
{
  int i,j,t;
  bool win,lose,draw;
  for (i=1;i<=k;i++)
    dp[i]=1;
  for (i=k+1;i<=n;i++)
  {
    draw=false;
    win=false;
    lose=false;
    for (j=1;j<=tot;j++)
    {
      if (i<=a[j]) break;
      if (dp[i-a[j]]==1) 
        win=true;
      else if (dp[i-a[j]]==0)
        draw=true;
      else
        lose=true;
    }
    if (lose) dp[i]=1;
    else if (draw) dp[i]=0;
    else if (win) dp[i]=-1;
    else dp[i]=0;
  }
  return dp[n];
}

int main()
{
  int ans;
  init();
  while (scanf("%d%d",&n,&k)==2)
  {
    ans=work();
    if (ans==-1) puts("Second");
    else if (ans==1) puts("First");
    else puts("Draw");
  }
  return 0;
}