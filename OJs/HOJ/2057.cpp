/*This Code is Submitted by Timer for Problem 2057 at 2013-01-17 14:53:26*/
#include <cstdio>

int n;
char a[100000];

int main()
{
  int i;
  char c;
  while (scanf("%d",&n)==1 && n)
  {
    getchar();
    while (n--)
    {
      i^=i;
      c=getchar();
      while (c!='\n')
      {
        if (c!=' ')
          a[i++]=c;
        else
        {
          while (--i>=0)
            putchar(a[i]);
          putchar(' ');
          i^=i;
        }
        c=getchar();
      }
      while (--i>=0)
        putchar(a[i]);
      putchar('\n');
    }
  }
  return 0;
}