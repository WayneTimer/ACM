/*This Code is Submitted by Timer for Problem 1459 at 2011-11-12 01:14:53*/
#include <stdio.h>
#include <string.h>

int main()
{
  long a[1000001],n,i,j;
  memset(a,0,sizeof(a));
  a[0]=1;
  a[1]=1;
  for (i=2;i<=500000;i++)
    if (a[i]!=1)
    for (j=2;j<(1000000/i);j++)
      a[i*j]=1;
  scanf("%ld",&n);
  while (n!=0)
  {
    printf("%ld = ",n); 
    for (i=3;i<=10000000;i++)
      if (a[i]!=1)
      {
        if (a[n-i]!=1)
        {
          printf("%ld + %ld\n",i,n-i);
          break;
        }
      }
    scanf("%ld",&n);
  }
  return 0;
}