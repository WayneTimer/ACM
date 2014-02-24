/*This Code is Submitted by Timer for Problem 2603 at 2011-12-18 00:12:18*/
#include <stdio.h>
#include <string.h>

int main()
{
  int i,T,p,l,s;
  char a[2001];
  char x;
  scanf("%d",&T);
  for (p=1;p<=T;p++)
  {
    scanf("%s",a);
    l=strlen(a);
    x=a[0];
    s=1;
    for (i=1;i<l;i++)
    {
      if (x==a[i]) 
      {
        s++;
        continue;
      } else
      {
        printf("%d%c",s,x);
        x=a[i]; 
        s=1;
      }
    }
    printf("%d%c\n",s,x);
  }
  return 0;
}