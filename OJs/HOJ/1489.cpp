/*This Code is Submitted by Timer for Problem 1489 at 2012-08-10 13:53:36*/
#include <cstdio>
#include <cmath>

using namespace std;

struct cyr
{
  double x;
  double y;
};

int n;
double max;
cyr a[6000];

inline double dist(int x,int y)
{
  double temp,u;
  temp=a[x].x-a[y].x;
  temp=temp*temp;
  u=a[x].y-a[y].y;
  u=u*u;
  temp=temp+u;
  return temp;
}

int main()
{
  int i,j;
  double t;
  while (scanf("%d",&n)==1)
  {
    max=0;
    for (i=1;i<=n;i++)
    {
      scanf("%lf%lf",&a[i].x,&a[i].y);
      for (j=i-1;j>0;j--)
      {
        t=dist(j,i);
        if (t>max) max=t;
      }
    }
    printf("%.2lf\n",sqrt(max));
  }
  return 0;
}