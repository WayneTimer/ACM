/*This Code is Submitted by Timer for Problem 2761 at 2013-02-08 14:10:19*/
/*
g(n)=2^n+(-1)^(n+1)
*/
#include <cstdio>
#include <cmath>

int main()
{
  double x=log10(2);
  int n;
  while (scanf("%d",&n)==1)
    printf("%.0lf\n",ceil(n*x));
  return 0;
}