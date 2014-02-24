/*This Code is Submitted by Timer for Problem 2665 at 2012-07-27 22:30:35*/
#include <cstdio>
#include <cstring>

using namespace std;

int f[16][1<<15][16];
int a[16];
int v[16][16];
int n,m;
int s[16];
int p[16][7000];

inline int cal(int x)
{
  int yy;
  yy=0;
  while (x>0)
  {
    yy=yy+(x&1);
    x=x>>1;
  }
  return yy;
}

void init()
{
  int i,tt;
  memset(s,0,sizeof(s));
  for (i=1;i<(1<<15);i++)
  {
    tt=cal(i);
    s[tt]++;
    p[tt][s[tt]]=i;
  }
}

int main()
{
  int i,jj,j,k,x,y,max,r,temp;
  init();
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(f,0,sizeof(f));
    memset(v,0,sizeof(v));
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++)
    {
      scanf("%d%d",&x,&y);
      a[i]=y-x;
    }
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        scanf("%d",&v[i][j]);
    for (k=1;k<=n;k++)
    {
      f[0][0][k]=v[m][k];
      v[0][k]=v[m][k];
    }
    for (i=1;i<=n;i++)
      for (jj=1;jj<=s[i];jj++)
      {
        j=p[i][jj];
        for (k=1;k<=n;k++)
          if (j&(1<<(k-1)))
          {
            max=0;
            for (r=0;r<=n;r++)
              if ((r!=k) && ((r==0)||(j&(1<<(r-1)))))
              {
                temp=f[i-1][j-(1<<(k-1))][r]-v[r][k]+a[k];
                if (temp>max) max=temp;
              }
            f[i][j][k]=max;
          }
      }
    max=0;
    for (k=1;k<=n;k++)
    {
      if (f[n][(1<<n)-1][k]>max)
        max=f[n][(1<<n)-1][k];
    }
    printf("%d\n",max);
  }
  return 0;
}