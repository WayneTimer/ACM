/*This Code is Submitted by Timer for Problem 1008 at 2011-11-03 01:32:10*/
#include <stdio.h>
#include <string.h>

int main()
{
  long long sum;
  int n,m,i,f;
  int a[10003];
  while (scanf("%d%d",&n,&m)==2)
  {
    sum=n;
    memset(a,0,sizeof(a));
    i=1;
    f=1;
    if (sum%m==0) 
    {
      printf("%d\n",i);
      f=0;
    }
      else
      while (1) 
      {
        sum=sum*10+n;
        i++;
        if ((sum%m)==0) 
        {
          printf("%d\n",i);
          f=0;
          break;
        }
        sum=sum%m;
        if (a[sum]) break;
          else a[sum]=1;
      }
    if (f) printf("0\n");
  }
  return 0;
}