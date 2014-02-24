/*This Code is Submitted by Timer for Problem 2443 at 2011-11-19 01:35:21*/
#include <stdio.h>
#include <math.h>

int main()
{
  double b,n,a,x,t;
  long long p,k;
  scanf("%lf%lf",&b,&n);
  while (!((b==0)&&(n==0)))
  {
    x=log(b)/n;
    a=exp(x);
    a=a+0.5;
    p=(long long)a;
    t=fabs(b-pow(p,n));
    k=p;
    if ((p-1)>0) p=p-1;
    if ((fabs(b-pow(p,n)))<t) 
    { 
      k--;
      t=fabs(b-pow(p,n));
    }
    p=p+2;
    if ((fabs(b-pow(p,n)))<t) 
    { 
      k=p;
    }
    printf("%lld\n",k);
    scanf("%lf%lf",&b,&n);
  }
  return 0;
}