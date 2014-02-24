/*This Code is Submitted by Timer for Problem 1848 at 2011-11-25 00:41:32*/
#include <stdio.h>
#include <string.h>

int main()
{
  long long i,f,n,x,y,t;
  int a[3001];
  while (scanf("%lld",&n)==1)
  {
    f=1;
    memset(a,0,sizeof(a));
    scanf("%lld",&x);
    for (i=2;i<=n;i++)
      {
        scanf("%lld",&y);
        if (f) 
        {
          if (x>y)
            t=x-y;
          else t=y-x;
          if (t<1) f=0;
          if (t>=n) f=0;
          if (a[t]) f=0;
            else a[t]=1;
          x=y;
        }
      }
    if (f) printf("Jolly\n");
      else printf("Not jolly\n");
  }
  return 0;
}