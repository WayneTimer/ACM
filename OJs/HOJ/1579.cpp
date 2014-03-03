/*This Code is Submitted by Timer for Problem 1579 at 2014-03-04 00:01:04*/
#include <cstdio>
#include <cstring>

#define MAX 50000000

using namespace std;

typedef long long ll;

int n,k;
int a[5011];
int f[5011][1019];

ll min(ll x,ll y)
{
  if (x<=y) return x;
  return y;
}

int main()
{
  int i,j,T;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d%d",&k,&n);
    k=k+8;
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
    for (i=0;i<=n;i++)
      for (j=1;j<=k;j++)
        f[i][j]=MAX;
    for(i=3;i<=n;i++)
      for (j=1;j<=i/3;j++)
        f[i][j]=min(f[i-1][j],f[i-2][j-1]+(a[n-i+1]-a[n-i+2])*(a[n-i+1]-a[n-i+2]));
    printf("%d\n",f[n][k]);
  }
  return 0;
}
