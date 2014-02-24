/*This Code is Submitted by Timer for Problem 3055 at 2011-12-18 00:31:30*/
#include <stdio.h>
#include <string.h>

int main()
{
  char a[1000010];
  long l,i,s,j;
  while (gets(a)!=NULL)
  {
    l=strlen(a);
    s=0;
    while (l>1)
    {
      if (a[l-1]=='0')
      {
        s++;
        a[l-1]='\0';
        l--;
        continue;
      } else
      {
        s++;
        j=l-1;
        while ((a[j]=='1')&&(j>=0))
        {
          a[j]='0';
          j--;
        }
        a[j]='1';
      }
    }
    if (a[0]=='0') s++;
    printf("%ld\n",s);
  }
  return 0;
}