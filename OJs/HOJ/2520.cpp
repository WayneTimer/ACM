/*This Code is Submitted by Timer for Problem 2520 at 2011-11-15 00:02:48*/
#include <stdio.h>
#include <string.h>

int n,m,k,x;

int box()
{
  int a,b;
  a=k*(x-1)+1;
  b=k*x;
  if (b>n) b=n;
  if (a>n) 
  {
    a=-1;
    b=-1;
  }
  printf("%d %d\n",a,b);
  return 0;
}

int ba()
{
  int a;
  a=x/k;
  if ((x%k)>0) a++;
  printf("%d\n",a);
  return 0;
}

int main()
{
  int c,i,j,q;
  char e[6];
  scanf("%d",&c);
  for (i=1;i<=c;i++)
  {
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d",&q);
    for (j=1;j<=q;j++)
    {
      memset(e,0,sizeof(e));
      scanf("%s",e);
      scanf("%d",&x);
      if (strcmp(e,"ball")>0) box();
        else ba();
    }
  }
  return 0;
}