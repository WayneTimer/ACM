/*This Code is Submitted by Timer for Problem 1760 at 2011-11-01 00:31:49*/
#include <stdio.h>

int main()
{
  int t,i,n,max,a,b;
  scanf("%d",&n);
  while (n!=0) 
  {
    a=0;
    max=0;
    for (i=1;i<=n;i++)
      {
        scanf("%d",&b);
        t=a+b;
        if (t>b) a=t;
          else a=b;
        if (a>max) max=a;
      } 
    if (max<=0) printf("Losing streak.\n");
    else
    printf("The maximum winning streak is %d.\n",max);
    scanf("%d",&n);
  }
  return 0;
}