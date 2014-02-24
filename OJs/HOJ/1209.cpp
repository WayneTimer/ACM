/*This Code is Submitted by Timer for Problem 1209 at 2011-10-31 01:31:27*/
#include <stdio.h>
#include <string.h>

int main()
{
  int n,k,i,j,t,p;
  float s;
  int a[101];
  memset(a,0,404);
  for (i=1;i<=300;i++)
  {
    p=i;
    t=p;
    while ((p/5)>0) 
    {
      k=p/5;
      t=t+k;
      k=p%5;
      p=p/5+k;
    }
    if (t>100) 
    {
      a[t]=i;
      n=i;
      break;
    }
    a[t]=i;
  }
  for (i=100;i>=1;i--)
  {
    if (a[i]==0) a[i]=n;
      else n=a[i];
  }
  scanf("%d",&n);
  for (j=1;j<=n;j++)
  {
    scanf("%d",&k);
    printf("%d\n",a[k]);
  }
  return 0;
}