/*This Code is Submitted by Timer for Problem 2989 at 2011-11-29 00:03:01*/
#include <stdio.h>
#include <string.h>

int main()
{
  char x0[5]="---";
  char x1[5]="- -";
  char a[21][5];
  int i,k;
  long long n;
  scanf("%lld%d",&n,&k);
  while (!((n==0)&&(k==0)))
  {
    memset(a,0,sizeof(a));
    i=1;
    while (n!=0)
    {
      if (n%2) strcpy(a[i],x1);
        else strcpy(a[i],x0);
      n=n/2;
      i++;
    }
    for (i=k;i>=1;i--)
    {
      if (a[i][0]=='\0') printf("%s\n",x0);
        else printf("%s\n",a[i]);
    }
    printf("\n");
    scanf("%lld%d",&n,&k);
  }
  return 0;
}