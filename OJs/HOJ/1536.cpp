/*This Code is Submitted by Timer for Problem 1536 at 2011-11-25 20:07:12*/
#include <stdio.h>
#include <string.h>

int main()
{
  char a[500],b[500],v[500];
  char x[500];
  int l,i;
  gets(a);
  gets(b);
  memset(v,0,sizeof(v));
  l=strlen(a);
  printf("%s\n",b);
  printf("%s\n",a);
  for (i=0;i<l;i++)
    v[a[i]]=b[i];
  while (gets(x)!=NULL)
  {
    l=strlen(x);
    for (i=0;i<l;i++)
    {
      if (v[x[i]]!=0)
        printf("%c",v[x[i]]);
      else printf("%c",x[i]);
    }
    printf("\n");
  }
  return 0;
}