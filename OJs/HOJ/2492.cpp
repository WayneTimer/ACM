/*This Code is Submitted by Timer for Problem 2492 at 2012-08-07 19:52:58*/
#include <cstdio>
#include <cstring>

using namespace std;

int n,m;
double a[550][550];
double f[120][550];

int main()
{
  int i,j,k,p,y;
  double max;
  scanf("%d",&n);
  m=n;
  while (n!=-1)
  {
    n=1<<n;
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        scanf("%lf",&a[i][j]);
    memset(f,0,sizeof(f));
    for (i=1;i<=n;i++)
    {
      if (i&1)
        f[1][i]=a[i][i+1];
      else
        f[1][i]=a[i][i-1];
    }
    for (i=2;i<=m;i++)
    {
      for (j=1;j<n;j=j+(1<<i))
        for (k=j;k<j+(1<<(i-1));k++)
          for (p=j+(1<<(i-1));p<(j+(1<<i));p++)
          {
            f[i][k]+=f[i-1][k]*f[i-1][p]*a[k][p];
            f[i][p]+=f[i-1][p]*f[i-1][k]*a[p][k];
          }
    }
    max=0;
    for (i=1;i<=n;i++)
    {
      if (f[m][i]>max)
      {
        max=f[m][i];
        y=i;
      }
    }
    printf("%d\n",y);
    scanf("%d",&n);
    m=n;
  }
  return 0;
}