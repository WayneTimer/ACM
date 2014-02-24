/*This Code is Submitted by Timer for Problem 1976 at 2011-10-28 23:26:26*/
#include <stdio.h>

long long n;
int f;
long long month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char week[8][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

int check(long long u)
{
    if (u==0) return 1;
    if (u%4==0)
    {
      if (u%100!=0) return 1;
        else
        {
          if (u%400==0) return 1;
        }
    }
    return 0;
}

int main()
{
  long long tt,x,y,i,t;
  scanf("%lld",&n);
  while (n!=-1)
  {
    tt=(n+6)%7;
    t=0;
    y=366;
    n++;
    while (n>y)
    {
        t++;
        n=n-y;
        if (check(t)) y=366;
          else y=365;
    }
    f=check(t);
    x=t;
    y=n;
    printf("%lld-",2000+x);
    i=1;
    if (check(x)) month[2]=29;
      else month[2]=28;
    while (y>month[i])
      {
        y=y-month[i];
        i++;
      }
    if (i<10) printf("0");
    printf("%lld-",i);
    if (y<10) printf("0");
    printf("%lld",y);
    printf(" %s\n",week[tt]);
    scanf("%lld",&n);
  }
  return 0;
}
 