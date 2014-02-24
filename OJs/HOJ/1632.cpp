/*This Code is Submitted by Timer for Problem 1632 at 2011-11-11 00:54:31*/
#include <stdio.h>
#include <string.h>

int main()
{
  const long maxint=2000000000;
  int n,i,j,m,t,u;
  int f[28],a[28][28],b[28];
  long sum,min;
  char e;
  scanf("%d",&n);
  while (n!=0)
  {
    memset(f,0,sizeof(f));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for (i=1;i<n;i++)
    {
      scanf("%c",&e);
      scanf("%c",&e);
      t=e-'A'+1;
      scanf("%d",&m);
      for (j=1;j<=m;j++)
      {
        scanf("%c",&e);
        scanf("%c",&e);
        scanf("%d",&u);
        a[t][e-'A'+1]=u;
        a[e-'A'+1][t]=u;
      }
    }
    f[1]=1;
    u=1;
    b[1]=1;
    sum=0;
    while (u<n)
    {
      min=maxint;
      m=0;
      for (i=1;i<=u;i++)
      {
        t=f[i];
        for (j=1;j<=n;j++)
        {
          if ((b[j]!=1)&&(a[t][j]>0))
          {
            if (a[t][j]<min) 
            {
              min=a[t][j];
              m=j;
            }
          }
        }
      }
      u++;
      f[u]=m;
      b[m]=1;
      sum=sum+min;
    }
    printf("%ld\n",sum);
    scanf("%d",&n);
  }
  return 0;
}