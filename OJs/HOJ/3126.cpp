/*This Code is Submitted by Timer for Problem 3126 at 2012-08-09 19:58:26*/
#include <cstdio>
#include <cstring>

using namespace std;

double f[202][202];
double cyr[202];
int n,m,k,l;

int main()
{
  int T,i,j;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d%d%d%d",&n,&m,&k,&l);
    memset(f,0,sizeof(f));
    f[0][0]=1.0;
    for (i=1;i<=m;i++)
      for (j=1;j<=n;j++)
        f[i][j]=f[i-1][j-1]*(n-j+1)/n+f[i-1][j]*j/n;
    printf("%.3lf",f[m][k]);
    memset(cyr,0,sizeof(cyr));
    cyr[1]=1.0;
    for (i=2;i<=l;i++)
    {
      cyr[i]=n-i+1;
      cyr[i]=cyr[i]/n;
      cyr[i]=1/cyr[i];
      cyr[i]=cyr[i-1]+cyr[i];
    }
    printf(" %.3lf\n",cyr[l]);
  }
  return 0;
}