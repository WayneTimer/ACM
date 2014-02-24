/*This Code is Submitted by Timer for Problem 2651 at 2012-04-15 13:08:06*/
#include <cstdio>
#include <cstring>

#define pi 3.1415926535898

using namespace std;

const double real=0.000001;
int n,f;
int r[10005];
double mid,l,h;

bool check(double x)
{
  int s,t,i;
  s=0;
  for (i=1;i<=n;i++)
  {
    t=r[i]/x;
    s=s+t;
    if (s>=f) return true;
  }
  return false;
}

int main()
{
  int T,i,j;
  while (scanf("%d",&T)==1)
  {
    for (i=1;i<=T;i++)
    {
      memset(r,0,sizeof(r));
      scanf("%d%d",&n,&f);
      l=0.0;
      h=0.0;
      for (j=1;j<=n;j++)
      {
        scanf("%d",&r[j]);
        r[j]=r[j]*r[j];
        if (r[j]>h) h=(double)(r[j]);
      }
      f++;
      while ((h-l)>real)
      {
        mid=l+(h-l)/2;
        if (check(mid)) l=mid;
        else h=mid;
      }
      mid=pi*mid;
      printf("%.4lf\n",mid);
    }
  }
  return 0;
}