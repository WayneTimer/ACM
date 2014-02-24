/*This Code is Submitted by Timer for Problem 1058 at 2011-11-21 01:25:03*/
#include <stdio.h>
#include <string.h>

int main()
{
  int r,u,i,x,y,j;
  long a[1001][1001];
  long max,s;
  while (scanf("%d",&r)==1)
  {
  memset(a,0,sizeof(a));
  s=0;
  for (i=1;i<=r;i++)
  {
    for (j=1;j<=i;j++)
    {
      max=0;
      scanf("%ld",&a[i][j]);
      x=i-1;
      y=j-1;
      if (y>0) 
        if (a[x][y]>max) max=a[x][y];
      x=i-1;
      y=j;
      if (x>=y) 
        if (a[x][y]>max) max=a[x][y];
      a[i][j]=a[i][j]+max;
      if (a[i][j]>s) s=a[i][j];
    }
  }
  printf("%ld\n",s);
  }
  return 0;
}