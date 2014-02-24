/*This Code is Submitted by Timer for Problem 3072 at 2011-11-28 15:16:55*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
  char e[200];
  int i,f,l;
  while (gets(e)!=NULL)
  {
    l=strlen(e);
    f=1;
    for (i=1;i<l;i++)
      if ((e[i]>=97)&&(e[i]<=122)) 
      {
        f=0;
        break;
      }
    if (f)
    {
      if (islower(e[0]))
        printf("%c",e[0]-32);
      else printf("%c",e[0]+32);
      for (i=1;i<l;i++)
      {
        if (islower(e[i])) printf("%c",e[i]);
        else 
        printf("%c",e[i]+32);
      }
      printf("\n");
      continue;
    }
    printf("%s\n",e);
  }
  return 0;
}
