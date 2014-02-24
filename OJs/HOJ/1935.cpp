/*This Code is Submitted by Timer for Problem 1935 at 2012-04-25 15:27:15*/
#include <cstdio>

using namespace std;

int x1,y1,x2,y2,x3,y3;
long sum;

int deng(double x)
{
  if (x>0.000001) return 1;
  if (x<-0.000001) return -1;
  return 0;
}

double chaji(double a1,double b1,double a2,double b2)
{
  return (a1*b2-b1*a2);
}

long gcd(long b,long r)
{
  if (r==0) return b;
  return gcd(r,b%r);
}

int main()
{
  long s,q,w,sm;
  double mianji,a1,a2,b1,b2;
  scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
  while (x1||y1||x2||y2||x3||y3)
  {
    sum=0;
    a1=x2-x1;
    b1=y2-y1;
    a2=x3-x1;
    b2=y3-y1;
    mianji=chaji(a1,b1,a2,b2)/2;
    if (mianji<0) mianji=-mianji;
    if (x2>=x1) q=x2-x1;
      else q=x1-x2;
    if (y2>=y1) w=y2-y1;
      else w=y1-y2;
    if (q>=w) s=gcd(q,w);
      else s=gcd(w,q);
    sum=sum+s;
    if (x3>=x1) q=x3-x1;
      else q=x1-x3;
    if (y3>=y1) w=y3-y1;
      else w=y1-y3;
    if (q>=w) s=gcd(q,w);
      else s=gcd(w,q);
    sum=sum+s;
    if (x3>=x2) q=x3-x2;
      else q=x2-x3;
    if (y3>=y2) w=y3-y2;
      else w=y2-y3;
    if (q>=w) s=gcd(q,w);
      else s=gcd(w,q);
    sum=sum+s;
    sum=sum/2;
    s=sum;
    sum=mianji-s+1;
    printf("%ld\n",sum);
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
  }
  return 0;
}