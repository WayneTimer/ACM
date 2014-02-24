/*This Code is Submitted by Timer for Problem 1439 at 2011-11-07 16:09:12*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  double x1,y1,x2,y2,x3,y3;
  double k1,k2,x,y,c,d;
  const double pi=3.141592653589793;
  while (scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
  {
    if ((x2-x1)==0)
    {
      c=x2;
      x2=x3;
      x3=c;
      c=y2;
      y2=y3;
      y3=c;
    } else 
    if ((x3-x2)==0)
    {
      c=x2;
      x2=x1;
      x1=c;
      c=y2;
      y2=y1;
      y1=c;
    }
    if ((x1==x2) && (x2==x3)) 
    {
      y=y1;
      if (y2>y) y=y2;
      if (y3>y) y=y3;
      x=y1;
      if (y2<x) x=y2;
      if (y3<x) x=y3;
      d=y-x;
      c=pi*d;
      printf("%.2lf\n",c);
      continue;
    }
    k1=(y2-y1)/(x2-x1);
    k2=(y3-y2)/(x3-x2);
    x=(k1*(x3+x2)+k1*k2*(y3+y2)-k1*k2*(y1+y2)-k2*(x1+x2))/(2*k1-2*k2);
    if (k1!=0)
      y=(x-((x1+x2)/2))/(-k1)+(y1+y2)/2;
    else 
      y=(x-((x3+x2)/2))/(-k2)+(y3+y2)/2;
    d=(y2-y)*(y2-y)+(x2-x)*(x2-x);
    d=sqrt(d);
    d=d*2;
    c=pi*d;
    printf("%.2lf\n",c);
  }
  return 0;
}