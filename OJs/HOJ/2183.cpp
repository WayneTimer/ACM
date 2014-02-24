/*This Code is Submitted by Timer for Problem 2183 at 2012-08-13 10:43:50*/
#include <cstdio>
#include <cstring>

#define N 10005

using namespace std;

struct cyr
{
  double x;
  double y;
};

cyr a[N];
int n;
double v,l;

inline double chaji(cyr q,cyr w,cyr e)
{
  double x1,y1,x2,y2;
  x1=w.x-q.x;
  y1=w.y-q.y;
  x2=e.x-q.x;
  y2=e.y-q.y;
  return (x1*y2-x2*y1);
}

inline double calarea()
{
  int i;
  double sum,temp;
  sum=0.0;
  for (i=n;i>=1;i--)
  {
    temp=chaji(a[n],a[i],a[i-1]);
    sum+=temp;
  }
  return sum;
}

int main()
{
  int i;
  double area;
  scanf("%d",&n);
  while (n)
  {
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++)
      scanf("%lf%lf",&a[i].x,&a[i].y);
    a[0]=a[n];
    scanf("%lf",&v);
    area=calarea();
    if (area<0) area=-area;
    area=area/2.0;
    l=v/area;
    printf("BAR LENGTH: %.2lf\n",l);
    scanf("%d",&n);
  }
  return 0;
}