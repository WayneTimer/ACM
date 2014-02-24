/*This Code is Submitted by Timer for Problem 1696 at 2011-10-29 00:49:09*/
#include <stdio.h>

int main()
{
  long a,b,i,n;
  scanf("%ld",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%ld%ld",&a,&b);
    if (a>=b) printf("MMM BRAINS\n");
      else printf("NO BRAINS\n");
  }
  return 0;
}