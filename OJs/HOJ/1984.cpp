/*This Code is Submitted by Timer for Problem 1984 at 2012-04-18 13:07:06*/
#include <stdio.h>
#include <string.h>

int main()
{
  char s[501];
  long sum,t;
  int l,i;
  char e;
  while (gets(s)!=NULL)
  {
    l=strlen(s);
    sum=0;
    e='A';
    i=0;
    t=0;
    while (i<l)
    {
      if (s[i]!=e)
      {
        sum++;
        e=s[i];
        i++;
        t=1;
      } 
      else 
      {
        t++;
        i++;
        if (t<=5) continue; 
        sum++;
        t=1;
      }
    }
    printf("%ld\n",sum);
  }
  return 0;
}