/*This Code is Submitted by Timer for Problem 1528 at 2012-12-31 00:04:31*/
#include <cstdio>

long long x;

int main()
{
  long long i;
  while (scanf("%lld",&x)==1 && x>=0)
  {
    i=2;
    do
    {
      while (!(x%i))
      {
        printf("%lld\n",i);
        x=x/i;
      }
      i++;
    } while (i*i<=x);
    if (x) printf("%lld\n",x);
    puts("");
  }
  return 0;
}