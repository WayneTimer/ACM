/*This Code is Submitted by Timer for Problem 1746 at 2011-11-25 15:51:36*/
#include <stdio.h>

int main()
{
  float q;
  int w,e,f;
  scanf("%f%d%d",&q,&w,&e);
  while (!((q==0)&&(w==0)&&(e==0)))
  {
    f=0;
    if ((q<=4.5)&&(w>=150)&&(e>=200))
    {
      f++;
      printf("Wide Receiver ");
    }
    if ((q<=6.0)&&(w>=300)&&(e>=500))
    {
      f++;
      printf("Lineman ");
    }
    if ((q<=5.0)&&(w>=200)&&(e>=300))
    {
      f++;
      printf("Quarterback ");
    }
    if (f==0) printf("No positions");
    printf("\n");
    scanf("%f%d%d",&q,&w,&e);
  }
  return 0;
}