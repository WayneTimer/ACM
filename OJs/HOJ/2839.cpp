/*This Code is Submitted by Timer for Problem 2839 at 2012-08-09 19:53:06*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int p;
  int m;
  int v;
};

long long f[12][10002];
int n,m,k;
cyr a[102];
int ge[11];
int id[11][101];

long long max(long long x,long long y,long long z)
{
  if (x>=y)
    y=x;
  if (y>=z) return y;
  return z;
}

int main()
{
  int u,s,i,x,y,z,j;
  int r;
  while (scanf("%d%d%d",&n,&m,&k)==3)
  {
    memset(ge,0,sizeof(ge));
    for (i=1;i<=n;i++)
    {
      scanf("%d%d%d",&x,&y,&z);
      a[i].p=x;
      a[i].m=y;
      a[i].v=z;
      ge[x]++;
      id[x][ge[x]]=i;
    }
    s=0;
    memset(f,0,sizeof(f));
    for (i=1;i<=k;i++)
    {
      for (j=1;j<=ge[i];j++)
      {
        for (r=m;r>=0;r--)
          if (r>=a[id[i][j]].m)
          {
            if ((i==1) || (f[i-1][r-a[id[i][j]].m]>0))
              f[i][r]=max(f[i][r],f[i-1][r-a[id[i][j]].m]+a[id[i][j]].v,f[i][r-a[id[i][j]].m]+a[id[i][j]].v);
          }
          else
            break;
      }
    }
    if (f[k][m]>0)
    {
      printf("%lld\n",f[k][m]);
    }
    else 
      printf("Impossible\n");
  }
  return 0;
}