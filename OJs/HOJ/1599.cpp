/*This Code is Submitted by Timer for Problem 1599 at 2011-11-25 20:22:00*/
#include <stdio.h>

int main()
{
  int n,i,s,x,c;
  int a[101];
  scanf("%d",&n);
  c=1;
  while (n!=0)
  {
    s=0;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      s=s+a[i];
    }
    x=s/n;
    s=0;
    for (i=1;i<=n;i++)
      if (a[i]>x) s=s+a[i]-x;
    printf("Set #%d\n",c);
    printf("The minimum number of moves is %d.\n",s);
    printf("\n");
    scanf("%d",&n);
    c++;
  }
  return 0;
}