/*This Code is Submitted by Timer for Problem 1973 at 2011-11-23 00:43:24*/
#include <stdio.h>
#include <string.h>

int main()
{
  int x,a,b;
  char e[30];
  scanf("%d",&x);
  while (x!=0)
  {
    a=1;
    b=10;
    getchar();
    gets(e);
    while (e[0]!='r')
    {
      if (e[4]=='h') 
      {
        if ((x-1)<b) b=x-1;
      }
      if (e[4]=='l')
      {
        if ((x+1)>a) a=x+1;
      }
      scanf("%d",&x);
      getchar();
      gets(e);
    }
    if ((x<a)||(x>b)) 
    {
      printf("Stan is dishonest\n");
      scanf("%d",&x);
      continue;
    }
    printf("Stan may be honest\n");
    scanf("%d",&x);
  }
  return 0;
}