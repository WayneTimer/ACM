#include <cstdio>
#include <string.h>
#define MAXV 300000

using namespace std;


int n;
long f[21][20001];
int h[201];
int v[201];

long minx(long x,long y)
{
  if (x<y) return x;
    else return y;
}

void cyr()
{
  int i,j,k;
  memset(f,0,sizeof(f));
  for (i=0;i<=20;i++)
    for (j=0;j<=20000;j++)
      f[i][j]=MAXV;
  f[0][0]=0;
  for (k=1;k<=n;k++)
    for (i=20;i>=1;i--)
      for (j=20000;j>=h[k];j--)
        f[i][j]=minx(f[i][j],f[i-1][j-h[k]]+v[k]);
}

int main()
{
  int j,i,c,m,min,max;
  long t;
  while (scanf("%d",&n)==1)
  {
    for (i=1;i<=n;i++)
      scanf("%d%d",&h[i],&v[i]);
    cyr();
    scanf("%d",&c);
    for (i=1;i<=c;i++)
    {
      scanf("%d%d%d",&m,&min,&max);
      min=min*m;
      max=max*m;
      t=f[m][min];
      for (j=min+1;j<=max;j++)
        if (f[m][j]<t) t=f[m][j];
      if (t!=MAXV) printf("%ld\n",t);
        else printf("impossible\n");
    }
  }
  return 0;
}