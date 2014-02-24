/*This Code is Submitted by Timer for Problem 2071 at 2011-11-21 16:38:45*/
#include <stdio.h>

int main()
{
  int a,b,c;
  while (scanf("%d%d%d",&a,&b,&c)==3)
  {
    if (a<=168) 
    {
      printf("CRASH %d\n",a);
      continue;
    }
    if (b<=168) 
    {
      printf("CRASH %d\n",b);
      continue;
    }
    if (c<=168) 
    {
      printf("CRASH %d\n",c);
      continue;
    }
    printf("NO CRASH\n");
  }
  return 0;
}