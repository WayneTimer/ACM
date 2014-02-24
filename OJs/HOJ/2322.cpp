/*This Code is Submitted by Timer for Problem 2322 at 2011-12-17 20:16:04*/
#include <stdio.h>

int main()
{
  int a,b,c,d,t,i;
  scanf("%d",&t);
  for (i=1;i<=t;i++)
  {
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if (a>c) a=a-c; 
      else a=c-a;
    if (b>d) b=b-d;
      else b=d-b;
    a=a+b;
    a=a%2;
    printf("Scenario #%d:\n",i);
    printf("%d\n",a);
    printf("\n");
  }
  return 0;
}