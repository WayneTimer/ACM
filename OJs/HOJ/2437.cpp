/*This Code is Submitted by Timer for Problem 2437 at 2011-11-18 00:13:49*/
#include <stdio.h>
#include <string.h>

int main()
{
  char x[1000];
  int l,i;
  long long s,t;
  gets(x);
  while (x[0]!='#')
  {
    l=strlen(x);
    s=0;
    t=0;
    for (i=0;i<l;i++)
    {
      if (x[i]==' ') t=0;
        else t=x[i]-'A'+1;
      s=s+t*(i+1);
    }
    printf("%lld\n",s);
    memset(x,0,sizeof(x));
    gets(x);
  }
  return 0;
}