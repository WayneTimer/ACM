/*This Code is Submitted by Timer for Problem 2662 at 2012-07-27 19:17:42*/
#include <cstdio>
#include <cstring>

using namespace std;

int n,m;
long long f[81][256][21];
int v[256];
int kk;

inline int check(int x)
{
  int temp,i;
  temp=3;
  while (temp<256)
  {
    if ((x&temp)==temp)
      return -1;
    temp=temp<<1;
  }
  temp=0;
  while (x>0) 
  {
    temp+=(x&1);
    x=x>>1;
  }
  return temp;
}

void init()
{
  int x,i;
  for (i=1;i<256;i++)
  {
    v[i]=check(i);
  }
}

void cyr()
{
  int i,j,k,r;
  int u;
  f[0][0][0]=1;
  for (i=1;i<=n;i++)
    for (j=0;j<(1<<m);j++)
      if (v[j]>=0)
      for (k=v[j];k<=kk;k++)
      {
          for (r=0;r<(1<<m);r++)
          {
            if (v[r]>=0)
              if ((j&r)==0)
                f[i][j][k]+=f[i-1][r][k-v[j]];
          }
      }
}

int main()
{
  int t,i;
  long long op;
  init();
  while (scanf("%d%d%d",&n,&m,&kk)==3)
  {
    memset(f,0,sizeof(f));
    if (n<m) 
    {
      t=n;
      n=m;
      m=t;
    }
    cyr();
    op=0;
    for (i=0;i<(1<<m);i++)
      op+=f[n][i][kk];
    printf("%lld\n",op);
  }
  return 0;
}