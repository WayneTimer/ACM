/*This Code is Submitted by Timer for Problem 1764 at 2011-11-25 16:31:04*/
#include <stdio.h>
#include <string.h>

int main()
{
  char e[100];
  int i,l,y,t;
  char x;
  while (gets(e)!=NULL)
  {
    l=strlen(e);
    for (i=0;i<l;i++)
    {
      x=e[i];
      t=0;
      if ((x=='B')||(x=='F')||(x=='P')||(x=='V'))
        t=1;
      if ((x=='C')||(x=='G')||(x=='J')||(x=='K')||(x=='Q')||(x=='S')||(x=='X')||(x=='Z'))
        t=2;
      if ((x=='D')||(x=='T'))
        t=3;
      if (x=='L')
        t=4;
      if ((x=='M')||(x=='N'))
        t=5;
      if (x=='R')
        t=6;
      if (i!=0) 
        if (t==y)
          continue;
      if (t>0) printf("%d",t);
      y=t;
    }
    printf("\n");
  }
  return 0;
}