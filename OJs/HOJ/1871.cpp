/*This Code is Submitted by Timer for Problem 1871 at 2011-11-10 00:33:28*/
#include <stdio.h>
#include <string.h>

int main()
{
  char a[9],e;
  long long n,k,o,t,i;
  scanf("%lld",&n);
  for (o=1;o<=n;o++)
  {
    scanf("%lld",&k);
    for (i=0;i<=7;i++)
      a[i]='0';
    i=8;
    while (k>0)
    {
      t=k%16;
      if (t<=9) e='0'+t;
      if (t==10) e='A';
      if (t==11) e='B';
      if (t==12) e='C';
      if (t==13) e='D';
      if (t==14) e='E';
      if (t==15) e='F';
      i--;
      a[i]=e;
      k=k/16;
    }
    printf("0x%c%c ",a[6],a[7]);
    printf("0x%c%c ",a[4],a[5]);
    printf("0x%c%c ",a[2],a[3]);
    printf("0x%c%c\n",a[0],a[1]);
  }
  return 0;
}