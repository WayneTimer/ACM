/*This Code is Submitted by Timer for Problem 1655 at 2011-11-25 19:03:32*/
#include <stdio.h>
#include <math.h>

int main()
{
  int n,c,i;
  float R,r,x,e;
  scanf("%d",&c);
  for (i=1;i<=c;i++)
  {
    scanf("%f%d",&R,&n);
    e=2*3.14159265/((float)n);
    e=e/2;
    x=sin(e);
    r=(R*x)/(1+x);
    printf("Scenario #%d:\n",i);
    printf("%.3f\n",r);
    printf("\n");
  }
  return 0;
}