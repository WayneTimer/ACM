/*This Code is Submitted by Timer for Problem 1480 at 2014-03-14 00:08:52*/
#include <cstdio>

int main()
{
  double x1,x2,y1,y2,lx,ly;
  int n;
  while (scanf("%d",&n)==1)
  {
    printf("%d",n);
    n--;
    scanf("%lf%lf",&lx,&ly);
    x1=lx;
    y1=ly;
    while (n--)
    {
      scanf("%lf%lf",&x2,&y2);
      printf(" %.6lf %.6lf",(x1+x2)/2,(y1+y2)/2);
      x1=x2;
      y1=y2;
    }
    printf(" %.6lf %.6lf\n",(x1+lx)/2,(y1+ly)/2);
  }
  return 0;
}
