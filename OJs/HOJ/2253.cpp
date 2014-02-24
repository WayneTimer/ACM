/*This Code is Submitted by Timer for Problem 2253 at 2012-05-03 16:57:13*/
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
  int n,i,u;
  double p;
  const double esp=0.000001;
  while (scanf("%d",&n)==1)
  {
    for (i=1;i<=n;i++)
    {
      scanf("%lf",&p);
      if (p>=0.25) 
      {
        u=p*100+0.5;
        printf("%d%%\n",u);
      }
      else 
      {
        u=(1.0-p)/3.0*100+0.5;
        printf("%d%%\n",u);
      }
    }
  }
  return 0;
}