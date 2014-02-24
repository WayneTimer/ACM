/*This Code is Submitted by Timer for Problem 2339 at 2013-08-15 10:02:50*/
//DP
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 510
#define INF 1<<30

struct eugin
{
  int w,v;
};

int n,m,r,c;
eugin a[MAXN];
int f[MAXN][MAXN][2];

inline void work()
{
  int i,j,k,y,x;
  for (y=1;y<=r;y++)
    for (i=n;i>=0;i--)
      for (j=m;j>=0;j--)
        for (k=0;k<=1;k++)
        {
          x=max(i-a[y].w,0);
          if (f[x][j][k]!=INF)
            f[i][j][k]=min(f[i][j][k],f[x][j][k]+a[y].v);
          x=max(j-a[y].w,0);
          if (f[i][x][k]!=INF)
            f[i][j][k]=min(f[i][j][k],f[i][x][k]+a[y].v);
          if (a[y].w>=2 && k>=1 && i>=1 && j>=1 && c>=1)
            f[i][j][k]=min(f[i][j][k],f[i-1][j-1][k-1]+a[y].v);
        }
  int ans;
  ans=INF;
  for (k=0;k<=1;k++)
    ans=min(ans,f[n][m][k]);
  if (ans!=INF)
    printf("%d\n",ans);
  else
    puts("Impossible");
}

int main()
{
  int T,i,j,k;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d%d%d%d",&n,&m,&r,&c);
    for (i=1;i<=r;i++)
      scanf("%d%d",&a[i].w,&a[i].v);
    for (i=0;i<=n;i++)
      for (j=0;j<=m;j++)
        for (k=0;k<=1;k++)
          f[i][j][k]=INF;
    for (k=0;k<=1;k++)
      f[0][0][k]=0;
    work();
  }
  return 0;
}