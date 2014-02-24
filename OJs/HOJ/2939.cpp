/*This Code is Submitted by Timer for Problem 2939 at 2011-12-04 21:15:11*/
#include <stdio.h>

int main()
{
  double n,x,R,r;
  long m;
  char Wen[50]="Yes, Mr. Wendy is a ****ing genius!";
  char Pia[50]="No, Mr. Pian is the real ****ing genius!";
  while (scanf("%lf%lf",&R,&r)==2)
  {
    if (r<R) 
    {
      printf("%s\n",Wen);
      continue;
    }
    if ((r>=R)&&((r-R)<=0.00001)) 
    {
      printf("%s\n",Wen);
      continue;
    }
    printf("%s\n",Pia);
  }
  return 0;
}