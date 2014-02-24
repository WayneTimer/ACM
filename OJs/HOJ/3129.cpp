/*This Code is Submitted by Timer for Problem 3129 at 2013-02-05 13:40:14*/
#include <cstdio>

int main()
{
  int T;
  long long r,a,b;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%lld%lld%lld",&r,&a,&b);
    if (a*a+b*b<=4*r*r)
      puts("Good, I can wash my face!");
    else
      puts("Sir, Your face is too big!");
  }
  return 0;
}