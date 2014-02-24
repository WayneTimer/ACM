/*This Code is Submitted by Timer for Problem 1010 at 2011-10-27 00:27:44*/
#include <stdio.h>
int a,b;
float x,y;

int main()
{
  scanf("%d%d",&a,&b);
  while (!((a==0) && (b==0)))
  {
  if (a==12) a=0;
  x=a*30+0.5*b;
  y=b*6;
  if (x<=y) 
  {
    x=y-x;
  } else
  {
    x=x-y;
  }
  if (x>180) x=360-x;
  if (a==0) a=12;
  printf("At %d:",a);
  if (b<10) printf("0");
  printf("%d the angle is %.1f degrees.\n",b,x);
  scanf("%d%d",&a,&b);
  }
  return 0;
}