/*This Code is Submitted by Timer for Problem 2597 at 2011-11-16 00:17:05*/
#include <stdio.h>

int main()
{
  float a,b,c,t;
  int i;
  while (scanf("%f%f%f",&a,&b,&c)==3)
  {
    b=(b+100)/100;
    t=b;
    i=1;
    while ((a*b)<c)
    {
      b=b*t;
      i++;
    }
    printf("%d\n",i);
  }
  return 0;
}