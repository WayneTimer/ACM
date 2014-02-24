/*This Code is Submitted by Timer for Problem 1031 at 2012-08-19 23:05:48*/
#include <cstdio>
#include <cstring>

#define MAXN 510

long long f[10002];
int n;

int main()
{
  int T,j,i,v,w;
  int e1,e2;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d%d",&e1,&e2);
    scanf("%d",&n);
    memset(f,0,sizeof(f));
    e1=e2-e1;
    for (i=1;i<=n;i++)
    {
      scanf("%d%d",&v,&w);
      for (j=0;j<=e1;j++)
      if (j>=w)
        if ((j==w) || (f[j-w]!=0))
          if ((f[j]==0) || (f[j-w]+v<f[j]))
            f[j]=f[j-w]+v;
    }
    if (f[e1]==0) printf("This is impossible.\n");
      else printf("The minimum amount of money in the piggy-bank is %lld.\n",f[e1]);
  }
  return 0;
}
 