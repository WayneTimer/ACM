/*This Code is Submitted by Timer for Problem 1006 at 2011-10-29 01:19:53*/
#include <stdio.h>
#include <string.h>

int main()
{
  long s,d,i;
  int a[61];
  scanf("%ld%ld",&s,&d);
  while (!((s==0) && (d==0)))
  {
    memset(a,0,sizeof(a));
    i=0;
    a[s]=1;
    while (s!=0) 
    {
      i++;
      s=(s+(s*d)%60)%60;
      if (a[s]) break;
        else a[s]=1;
    }
    if (s==0) printf("%ld\n",i);
      else printf("Impossible\n");
    scanf("%ld%ld",&s,&d);
  }
  return 0;
}