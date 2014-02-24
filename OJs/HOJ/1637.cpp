/*This Code is Submitted by Timer for Problem 1637 at 2011-11-25 18:42:04*/
#include <stdio.h>

int main()
{
  int s,i;
  float c,v;
  scanf("%f",&c);
  while (c!=0.00)
  {
    i=1;
    v=0;
    while (v<c)
    {
      i++;
      v=v+1/((float)i);
    }
    printf("%d card(s)\n",i-1);
    scanf("%f",&c);
  }
  return 0;
}