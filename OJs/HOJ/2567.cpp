/*This Code is Submitted by Timer for Problem 2567 at 2013-03-21 01:22:11*/
#include <cstdio>

int main()
{
  int n,x,y,T;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d%d%d",&n,&x,&y);
    if (y*y*n+1==x*x) puts("yes");
    else puts("no");
  }
  return 0;
}