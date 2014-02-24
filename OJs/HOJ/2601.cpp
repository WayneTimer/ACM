/*This Code is Submitted by Timer for Problem 2601 at 2011-11-17 23:03:36*/
#include <stdio.h>
#include <string.h>

int main()
{
  char a[100];
  int l,s,i,n,f;
  float sum;
  memset(a,0,sizeof(a));
  while (gets(a)!=NULL)
  {
    l=strlen(a);
    s=0;
    i=0;
    n=0;
    f=0;
    while (i<l)
    {
      if (a[i]==' ')
      {
        i++;
        continue;
      }
      if (a[i]=='A')
      {
        s=s+4;
        n++;
        i++;
        continue;
      }
      if (a[i]=='B')
      {
        s=s+3;
        n++;
        i++;
        continue;
      }
      if (a[i]=='C')
      {
        s=s+2;
        n++;
        i++;
        continue;
      }
      if (a[i]=='D')
      {
        s=s+1;
        n++;
        i++;
        continue;
      }
      if (a[i]=='F')
      {
        n++;
        i++;
        continue;
      }
      printf("Unknown letter grade in input\n");
      f=1;
      break;
    }
    if (f) continue;
    sum=s;
    printf("%.2f\n",sum/n);
    memset(a,0,sizeof(a));
  }
  return 0;
}