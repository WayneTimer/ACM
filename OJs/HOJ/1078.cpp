/*This Code is Submitted by Timer for Problem 1078 at 2011-11-01 16:22:28*/
#include <stdio.h>

int main()
{
  int i,n,s;
  double e,t;
  e=2.5;
  s=2;
  printf("n e\n");
  printf("- -----------\n");
  printf("0 1\n");
  printf("1 2\n");
  printf("2 2.5\n");
  for (i=3;i<=9;i++)
    {
      s=s*i;
      t=(double) s;
      e=e+1/t;
      printf("%d ",i);
      printf("%.9lf\n",e);
    }
   return 0;
}