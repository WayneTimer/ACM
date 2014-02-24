/*This Code is Submitted by Timer for Problem 2571 at 2012-04-21 23:44:48*/
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
  const double same=0.00001;
  double a1,a2,a3,b1,b2,b3;
  double a4,b4,a5,b5;
  double s;
  while (scanf("%lf%lf%lf%lf%lf%lf",&a1,&b1,&a2,&b2,&a3,&b3)==6)
  {
    a4=a2-a1;
    b4=b2-b1;
    a5=a3-a1;
    b5=b3-b1;
    s=a4*b5-b4*a5;
    if (fabs(s-0)<same)
    {
      printf("Line\n");
      continue;
    }
    if (s>0)
    {
      printf("Counter Clockwise\n");
      continue;
    }
    if (s<0)
    {
      printf("Clockwise\n");
      continue;
    }
  }
  return 0;
}