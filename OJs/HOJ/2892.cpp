/*This Code is Submitted by Timer for Problem 2892 at 2011-11-13 23:40:33*/
#include <stdio.h>
#include <string.h>

int main()
{  
  char a[200];
  int l,i,s;
  memset(a,0,sizeof(a));
  while (gets(a)!=NULL)
  {
    l=strlen(a);
    s=0;
    for (i=0;i<l;i++)
    {
      if ((a[i]>='A')&&(a[i]<='Z'))
        s=s+a[i]-'A'+1;
      if (s>100) break;
    }
    if (s>100) printf("INVALID\n");
      else printf("%d\n",s);
    memset(a,0,sizeof(a));
  }
  return 0;
}