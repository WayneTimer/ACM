/*This Code is Submitted by Timer for Problem 1001 at 2012-11-22 23:33:37*/
#include <stdio.h>

int sum(int a,int b)
{
  register int ans;
  __asm__ __volatile__
              (
               "addl %2,%0"
               :"=a"(ans)
               :"0"(a),"b"(b)
              );
  return ans;
}

int main(void)
{
    int a, b;
    while (scanf("%d %d", &a, &b)==2)
        printf("%d\n",sum(a,b));
    return 0;
}