/*This Code is Submitted by Timer for Problem 2541 at 2011-11-16 00:00:54*/
#include <stdio.h>

int main()
{
  int m,n,i,j,s,t;
  while (scanf("%d%d",&m,&n)==2)
  {
    s=2*m-1;
    for (i=1;i<=m;i++)
    {
      {
        t=2*i-1;
        for (j=1;j<=((s-t)/2);j++)
          printf(" ");
        for (j=1;j<=t;j++)
          printf(".");
        printf("\n");
      }
    }
    for (j=1;j<=n;j++)
    {
    for (i=1;i<=((s-1)/2);i++)
      printf(" ");
    printf("|");
    printf("\n");
    }
  }
  return 0;
}