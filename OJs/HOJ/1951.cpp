/*This Code is Submitted by Timer for Problem 1951 at 2012-04-30 17:20:24*/
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
  const double pi=3.1415926535898;
  double D,V,s,d;
  scanf("%lf%lf",&D,&V);
  while ((D!=0)&&(V!=0))
  {
    s=D*D*D-6.0*V/pi;
    d=pow(s,1.0/3.0);
    printf("%.3lf\n",d);
    scanf("%lf%lf",&D,&V);
  }
  return 0;
}