/*This Code is Submitted by Timer for Problem 2528 at 2011-11-15 00:10:52*/
#include <stdio.h>

int main()
{
  int x,y;
  while (scanf("%d%d",&x,&y)==2)
  {
    if ((x==1)&&(y==2)) printf("3\n");
    if ((x==1)&&(y==3)) printf("2\n");
    if ((x==2)&&(y==1)) printf("3\n");
    if ((x==2)&&(y==3)) printf("1\n");
    if ((x==3)&&(y==1)) printf("2\n");
    if ((x==3)&&(y==2)) printf("1\n");
  }
  return 0;
}