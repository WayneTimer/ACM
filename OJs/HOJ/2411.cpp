/*This Code is Submitted by Timer for Problem 2411 at 2011-11-17 23:53:14*/
#include <stdio.h>
#include <string.h>

int main()
{
  int n,i,j,s;
  int a[4];
  int v[4]={25,10,5,1};
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    memset(a,0,sizeof(a));
    scanf("%d",&s);
    for (j=0;j<=3;j++)
      {
      if ((s/v[j])>0) 
      {
        a[j]=s/v[j];
        s=s%v[j];
      }
      }
    printf("%d ",i);
    printf("%d QUARTER(S), ",a[0]);
    printf("%d DIME(S), ",a[1]);
    printf("%d NICKEL(S), ",a[2]);
    printf("%d PENNY(S)\n",a[3]);
  }
  return 0;
}