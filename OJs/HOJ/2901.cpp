/*This Code is Submitted by Timer for Problem 2901 at 2012-08-22 19:58:53*/
#include <cstdio>

int a,b;

int main()
{
  while (scanf("%d%d",&a,&b)==2)
  {
    if (a&1) puts("0");
      else
      {
        a>>=1;
        if (b==1) printf("%d\n",a);
          else
            if (a&1) printf("%d\n",a);
              else puts("0");
      }
  }
  return 0;
}