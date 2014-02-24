/*This Code is Submitted by Timer for Problem 2588 at 2011-12-17 23:51:07*/
#include <stdio.h>
#include <string.h>

int main()
{
  char a[100];
  int i,p,t,l,y;
  scanf("%d",&t);
  for (p=1;p<=t;p++)
  {
    memset(a,0,sizeof(a));
    scanf("%d",&y);
    scanf("%s",a);
    l=strlen(a);
    y--;
    printf("%d ",p);
    for (i=0;i<l;i++)
    {
      if (y==i) continue;
      printf("%c",a[i]);
    }
    printf("\n");
  }
  return 0;
}