/*This Code is Submitted by Timer for Problem 1057 at 2011-11-12 00:25:05*/
#include <stdio.h>
#include <string.h>

int main()
{
  char e[100],p;
  int sum,x;
  float t;
  memset(e,0,sizeof(e));
  scanf("%s",e);
  while (e[0]!='#')
  {
    sum=0;
    while (e[0]!='0')
    {
      scanf("%s",e);
      scanf("%d",&x);
      scanf("%c",&p);
      scanf("%c",&p);
      if (p=='F')
      {
        sum=sum+2*x;
      }
      if (p=='B')
      {
        t=(float) x;
        t=t/2;
        t=t+0.5;
        sum=sum+x+(int) t;
      }
      if (p=='Y')
      {
        if (x<=500) sum=sum+500;
        if (x>500) sum=sum+x;
      }
      scanf("%s",e);
    }
    printf("%d\n",sum);
    scanf("%s",e);
  }
  return 0;
}