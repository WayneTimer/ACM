/*This Code is Submitted by Timer for Problem 2561 at 2013-02-25 11:23:40*/
#include <cstdio>
#include <cstring>

#define UP 47000

int n,m;
bool c[UP];
int p[10000];

inline void init()
{
  int i,j;
  memset(c,true,sizeof(c));
  for (i=2;i<UP>>1;i++)
    if (c[i])
      for (j=2;i*j<UP;j++)
        c[i*j]=false;
  m=0;
  for (i=2;i<UP;i++)
    if (c[i])
    {
      m++;
      p[m]=i;
    }
}

int main()
{
  int i;
  init();
  while (scanf("%d",&n)==1)
  {
    for (i=1;i<=m;i++)
      if (n%p[i]==0) break;
    if (i>m)
    {
      puts("No");
      continue;
    }
    n/=p[i];
    if (n==1)
    {
      puts("No");
      continue;
    }
    for (i=2;i*i<=n;i++)
      if (n%i==0) break;
    if (i*i<=n) puts("No");
      else puts("Yes");
  }
  return 0;
}