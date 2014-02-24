/*This Code is Submitted by Timer for Problem 3070 at 2011-11-28 16:34:30*/
#include <stdio.h>
#include <string.h>

int s[2001],f[2001];
int n,max;

int dps(int x)
{
  int y;
  if (s[x]!=0) return s[x];
  y=f[x];
  if (y==-1) 
  {
    f[x]=1;
    return 1;
  }
  s[x]=dps(y)+1;
  return s[x];
}

int main()
{
  int i,x;
  while (scanf("%d",&n)==1)
  {
    memset(s,0,sizeof(s));
    memset(f,0,sizeof(f));
    for (i=1;i<=n;i++)
    {
      scanf("%d",&x);
      f[i]=x;
    }
    max=0;
    for (i=1;i<=n;i++)
    {
      s[i]=dps(i);
      if (s[i]>max) max=s[i];
    }
    printf("%d\n",max);
  }
  return 0;
}