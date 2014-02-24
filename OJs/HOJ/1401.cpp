/*This Code is Submitted by Timer for Problem 1401 at 2013-01-21 22:34:51*/
#include <cstdio>

int last,a,b,nine;
int n;

int main()
{
  while (scanf("%d",&n)==1)
  {
    nine^=nine;
    scanf("%d%d",&a,&b);
    last=a+b;
    n--;
    while (n--)
    {
      scanf("%d%d",&a,&b);
      a+=b;
      if (a==9)
      {
        nine++;
        continue;
      }
      if (a<9)
      {
        printf("%d",last);
        while (nine--) putchar('9');
        nine^=nine;
      }
      if (a>9)
      {
        printf("%d",last+1);
        while (nine--) putchar('0');
        a-=10;
        nine^=nine;
      }
      last=a;
    }
    printf("%d",last);
    while (nine--) putchar('9');
    puts("");
  }
  return 0;
}