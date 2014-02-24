/*This Code is Submitted by Timer for Problem 1423 at 2011-11-27 00:45:33*/
#include <stdio.h>
#include <string.h>

int main()
{
  char e[100];
  int i,l;
  char a[500];
  gets(e);
  while (e[3]!='O')
  {
    gets(e);
    l=strlen(e);
    for (i=0;i<l;i++)
    {
      if ((e[i]>=70)&&(e[i]<=90))
      {printf("%c",e[i]-5);}
      else
      if ((e[i]>=65)&&(e[i]<=69))
      {printf("%c",e[i]+21);}
      else printf("%c",e[i]);
    }
    printf("\n");
    gets(e);
    gets(e);
  }
  return 0;
}