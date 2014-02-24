/*This Code is Submitted by Timer for Problem 1446 at 2012-03-06 17:31:06*/
#include <cstdio>
#include <cmath>

using namespace std;

double s;
long long n,k;

int main()
{
  long long i;
  double t,p;
  scanf("%lld%lld",&n,&k);
  while (!((n==0)&&(k==0)))
  {
    t=n-k;
    if (t>k) k=t;
    s=0;
    for (i=k+1;i<=n;i++)
    {
      s=s+log(i);
    }
    p=0;
    for (i=2;i<=(n-k);i++)
    {
      p=p+log(i);
    }
    s=s-p;
    s=exp(s);
    printf("%.0lf\n",s);
    scanf("%lld%lld",&n,&k);
  }
  return 0;
}