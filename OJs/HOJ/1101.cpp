/*This Code is Submitted by Timer for Problem 1101 at 2012-04-18 13:19:57*/
#include <stdio.h>
#include <string.h>

int main()
{
  char e[500];
  int n1,n2,i,l;
  n1=0;
  n2=0;
  while (gets(e)!=NULL)
  {
    l=strlen(e);
    i=0; 
    while (i<l)
    {
    if (e[i]=='\"')
    {
      n1++;
      n1=n1%2;
      if (n1==0)
        printf("\'\'");
      else 
        printf("``");
      i++;
    }
    else
    {
      printf("%c",e[i]);
      i++;
    }
    }
    printf("\n");
  }
  return 0;
}