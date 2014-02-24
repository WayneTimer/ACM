/*This Code is Submitted by Timer for Problem 1387 at 2012-02-23 16:45:57*/
#include <cstdio>
#include <cmath>

int main()
{
  int a,b,s,m,n;
  double e,r,P;
  P=acos(-1.0);
  scanf("%d%d%d%d%d", &a, &b, &s, &m, &n);
  while (!((a==0)&&(b==0)&&(s==0)&&(m==0)&&(n==0)))
  {
    e=180.0/P*atan(1.0*b*n/a/m);
    r=sqrt(1.0*m*m*a*a+1.0*b*b*n*n)/s;
    printf("%.2lf %.2lf\n",e,r);
    scanf("%d%d%d%d%d", &a, &b, &s, &m, &n);
  }  
  return 0;
}