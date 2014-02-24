/*This Code is Submitted by Timer for Problem 3015 at 2011-11-28 16:58:30*/
#include <stdio.h>
#include <string.h>

int main()
{
  int n,i;
  long long s,t;
  int k[21];
  char e[10];
  while (scanf("%d",&n)==1)
  {
    getchar();
    memset(k,0,sizeof(k));
    for (i=1;i<=n;i++)
    {
      gets(e);
      if (e[1]=='-') t=0;
        else t=1;
      k[i]=t;
    }
    s=0;
    t=1;
    if (k[n]) s=1;
    for (i=n-1;i>=1;i--)
    {
      t=t*2;
      s=s+k[i]*t;
    }
    printf("%lld\n",s);
  }
  return 0;
}