/*This Code is Submitted by Timer for Problem 2066 at 2011-11-21 01:39:51*/
#include <stdio.h>
#include <string.h>

int main()
{
  char a[500];
  int t,u,i,l;
  scanf("%d",&t);
  getchar();
  for (u=1;u<=t;u++)
  {
    gets(a);
    l=strlen(a);
    for (i=l-1;i>=0;i--)
    {
      printf("%c",a[i]);
    }
    printf("\n");
  }
  return 0;
}