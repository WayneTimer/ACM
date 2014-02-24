/*This Code is Submitted by Timer for Problem 2015 at 2012-01-19 21:33:11*/
#include <stdio.h>
#include <math.h>

double x,y,c,d,min;
double p1,p2,s;

double dps(double t1,double t2)
{
  double sum;
  d=(t1+t2)/2;
  sum=c/(sqrt(x*x-d*d));
  sum=sum+c/(sqrt(y*y-d*d));
  return sum;
}

int main()
{
  while (scanf("%lf%lf%lf",&x,&y,&c)==3)
  {
    min=x;
    if (y<x) min=y;
    p1=0;
    p2=min;
    s=dps(0,min);
    while ((fabs(s-1)>0.000001)&&(floor(p2*1000)!=floor(p1*1000)))
    {
      if (s<1) p1=(p1+p2)/2;
      if (s>1) p2=(p1+p2)/2;
      s=dps(p1,p2);
    }
    printf("%.3lf\n",(p1+p2)/2);
  }
  return 0;
}