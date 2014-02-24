/*This Code is Submitted by Timer for Problem 1866 at 2011-11-10 00:11:09*/
#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
  long k,i,s;
  scanf("%ld",&k);
  while (k!=0)
  {
    s=sqrt(k);
    printf("%ld\n",s);
    scanf("%ld",&k);
  }
  return 0;
}