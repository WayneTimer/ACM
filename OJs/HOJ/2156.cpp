/*This Code is Submitted by Timer for Problem 2156 at 2012-07-27 11:28:41*/
#include <cstdio>
#include <cstring>

using namespace std;

int d[110][32][5];
int a[110];
int n,m;

int cyrmin(int x,int y)
{
    if (x<y) return x;
    return y;
}

int main()
{
    int i,j,k,t,min;
    scanf("%d%d",&n,&m);
    while (n||m)
    {
        memset(d,0x3f,sizeof(d));
        memset(a,0,sizeof(a));
        for (i=1;i<=n;i++)
        {
          scanf("%d",&a[i]);
          a[i]--;
        }
    for (k=0;k<5;k++)
      d[1][1<<k][k]=(a[1]!=k);
    for (i=1;i<=n;i++)
      for (j=1;j<(1<<m);j++)
        for (k=0;k<m;k++)
          if (j&(1<<k))
          {
              d[i][j][k]=cyrmin(d[i][j][k],d[i-1][j][k]+(a[i]!=k));
              for (t=0;t<m;t++)
                if ((j&(1<<t)) && (t!=k))
                {
                    d[i][j][k]=cyrmin(d[i][j][k],d[i-1][j-(1<<k)][t]+(a[i]!=k));
                }
          }
    min=99999999;
    for (j=1;j<(1<<m);j++)
      for (k=0;k<m;k++)
        if (d[n][j][k]<min) min=d[n][j][k];
    printf("%d\n",min);
    scanf("%d%d",&n,&m);
    }
}
 