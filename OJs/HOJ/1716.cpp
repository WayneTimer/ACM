/*This Code is Submitted by Timer for Problem 1716 at 2012-08-25 01:15:33*/
#include <cstdio>
#include <cmath>

#define INF 500000000.0

double v,t;
int n;

int main()
{
  int i;
  double ans,temp;
  scanf("%d",&n);
  while (n)
  {
    ans=INF;
    for (i=1;i<=n;i++)
    {
      scanf("%lf%lf",&v,&t);
      if (t>=0)
      {
        temp=4.5*3600*1.0/v+t;
        if (temp<ans) ans=temp;
      }
    }
    printf("%.0lf\n",ceil(ans));
    scanf("%d",&n);
  }
  return 0;
}