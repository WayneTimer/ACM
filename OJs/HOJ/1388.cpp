/*This Code is Submitted by Timer for Problem 1388 at 2012-02-09 18:45:03*/
#include <cstdio>
#include <string.h>
#define MAXV 300000

using namespace std;

int n;
long f[22][20002];
int h[300];
int v[300];

long minx(long x,long y)
{
  if (x<y) return x;
    else return y;
}

void cyr()
{
  int i,k;
  long j;
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
  int i,c;
  long j,t,m,min,max;
  bool flag;
  flag=false;
  while (scanf("%d",&n)==1)
  {
    memset(h,0,sizeof(h));
    memset(v,0,sizeof(v));
    if (flag) printf("\n");
      else flag=true;
    for (i=1;i<=n;i++)
      scanf("%d%d",&h[i],&v[i]);
    cyr();
    scanf("%d",&c);
    for (i=1;i<=c;i++)
    {
      scanf("%ld%ld%ld",&m,&min,&max);
      if (min>max)
      {
        printf("impossible\n");
        continue;
      }
      min=min*m;
      max=max*m;
      if (min>20000) 
      {
        printf("impossible\n");
        continue;
      }
      if (max>20000) max=20000;
      t=f[m][min];
      for (j=min+1;j<=max;j++)
        if (f[m][j]<t) t=f[m][j];
      if (t<MAXV) printf("%ld\n",t);
        else printf("impossible\n");
    }
  }
  return 0;
}