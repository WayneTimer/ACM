/*This Code is Submitted by Timer for Problem 1795 at 2012-03-18 14:18:29*/
#include <cstdio>
#include <cstring>

using namespace std;

int dp[1500],trip[1500],a[1500];

int max(int x,int y)
{
  if (x>=y) return x;
    else return y;
}

int main()
{
  int T,i,j,k,n,t,m,ans;
  scanf("%d",&T);
  while(T--)
  {
    memset(dp,-1,sizeof dp);
    memset(trip,0,sizeof trip);
    scanf("%d %d %d",&n,&t,&m);
    dp[0]=-t;
    for(i=1;i<=m;i++)
    {
      scanf("%d",&a[i]);
      if (i==1)
      {
        dp[1]=a[i]+t;
        trip[1]=1;
        continue;
      }
      for(j=max(0,i-n);j<i;j++)
      {
        if (dp[i]==-1)
        {
          dp[i]=max(dp[j]+t,a[i])+t;
          trip[i]=trip[j]+1;
          continue;
        }
        if (max(dp[j]+t,a[i])+t<dp[i])
        {
          dp[i]=max(dp[j]+t,a[i])+t;
          trip[i]=trip[j]+1;
        }
        else
          if(max(dp[j]+t,a[i])+t==dp[i] && trip[j]+1<trip[i])
            trip[i]=trip[j]+1;
      }
    }
    printf("%d %d\n",dp[m],trip[m]);
  }
  return 0;
}