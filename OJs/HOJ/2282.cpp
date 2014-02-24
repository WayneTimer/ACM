/*This Code is Submitted by Timer for Problem 2282 at 2012-08-22 19:39:13*/
#include <cstdio>
#include <cstring>

int p[400];
int f[440][440];
long long c[440][440];
int top,n,m;
bool b[440];

inline void init()
{
  int i,j;
  memset(b,true,sizeof(b));
  b[0]=false;
  b[1]=false;
  for (i=2;i<=440;i++)
  {
    if (b[i])
    {
      for (j=2;j*i<=440;j++)
        b[i*j]=false;
    }
  }
  top^=top;
  for (i=2;i<=431;i++)
    if (b[i])
    {
      top++;
      p[top]=i;
    }
  return;
}

inline void cyr()
{
  int i,j,k,t;
  memset(f,0,sizeof(f));
  for (i=1;i<=top;i++)
    for (j=2;j<440;j++)
      f[j][i]=j/p[i]+f[j/p[i]][i];
  for (i=2;i<=431;i++)
    for (j=1;j<i;j++)
    {
      c[i][j]=1;
      for (k=1;(k<=top)&&(f[i][k]);k++)
      {
        t=f[i][k]-f[j][k]-f[i-j][k];
        if (t>0) c[i][j]=c[i][j]*(t+1);
      }
    }
  return;
}

int main()
{
  init();
  cyr();
  while (scanf("%d%d",&n,&m)==2)
  {
    if ((n==m) || (m==0)) 
      printf("1\n");
    else
      printf("%lld\n",c[n][m]);
  }
  return 0;
}