/*This Code is Submitted by Timer for Problem 1224 at 2012-08-24 18:32:43*/
#include <cstdio>

int n;

int main()
{
  int T,a;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d",&n);
    a=n>>1;
    n=(n-1)>>1;
    printf("%d\n",a*n);
  }
  return 0;
}