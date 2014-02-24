/*This Code is Submitted by Timer for Problem 3131 at 2013-02-05 13:43:56*/
#include <cstdio>

int main()
{
  long long x;
  while (scanf("%lld",&x)==1)
  {
    if (x<0) x=-x;
    printf("%lld\n",x);
  }
  return 0;
}