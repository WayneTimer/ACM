/*This Code is Submitted by Timer for Problem 3140 at 2013-03-03 00:40:50*/
#include <cstdio>
#include <cstring>

int f[41][41][41][41];
int a[350];
int b[5];
int n,m;

int main()
{
  int i,x,j,k,p;
  int t,w;
  while (scanf("%d%d",&n,&m)==2)
  {
    for (i=0;i<n;i++)
      scanf("%d",&a[i]);
    memset(b,0,sizeof(b));
    for (i=1;i<=m;i++)
    {
      scanf("%d",&x);
      b[x]++;
    }
    for (i=0;i<=b[1];i++)
      for (j=0;j<=b[2];j++)
        for (k=0;k<=b[3];k++)
          for (p=0;p<=b[4];p++)
          {
            if (i==0 && j==0 && k==0 && p==0)
            {
              f[i][j][k][p]=a[0];
              continue;
            }
            f[i][j][k][p]=a[i+(j<<1)+k*3+(p<<2)];
            t=0;
            if (i>0) 
            {
              w=f[i-1][j][k][p];
              if (w>t) t=w;
            }
            if (j>0)
            {
              w=f[i][j-1][k][p];
              if (w>t) t=w;
            }
            if (k>0)
            {
              w=f[i][j][k-1][p];
              if (w>t) t=w;
            }
            if (p>0)
            {
              w=f[i][j][k][p-1];
              if (w>t) t=w;
            }
            f[i][j][k][p]+=t;
          }
    printf("%d\n",f[b[1]][b[2]][b[3]][b[4]]);
  }
  return 0;
}