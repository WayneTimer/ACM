/*This Code is Submitted by Timer for Problem 1270 at 2012-08-13 20:16:02*/
#include <cstdio>
#include <cmath>

#define EPS 1e-5

using namespace std;

struct cyr
{
  double x;
  double y;
};

cyr a[12];
cyr b[12];
double ans1,ans2;
double area;

inline bool equ(double q,double w)
{
  double temp;
  temp=q-w;
  if (temp<-EPS) return false;
  if (temp>EPS) return false;
  return true;
}

inline bool checkin()
{
  int i;
  for (i=1;i<=4;i++)
  {
    if (!equ(a[i].x,0)) return true;
    if (!equ(a[i].y,0)) return true;
  }
  return false;
}

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
  double ans;
  ans=0;
  ans+=chaji(a[1],a[2],a[3]);
  ans+=chaji(a[1],a[3],a[4]);
  if (ans<0) ans=-ans;
  ans=ans/2.0;
  return ans;
}

inline double calmianji(int low,int up)
{
  int i;
  double temp;
  temp=0;
  for (i=low+1;i<up;i++)
    temp+=chaji(b[low],b[i],b[i+1]);
  if (temp<0) temp=-temp;
  temp=temp/2.0;
  return temp;
}

inline void solve()
{
  int i,j;
  double min;
  double t1,t2,temp;
  a[5]=a[1];
  for (i=1;i<=4;i++)
  {
    b[((i-1)<<1)+1]=a[i];
    b[((i-1)<<1)+2].x=(a[i].x+a[i+1].x)/2.0;
    b[((i-1)<<1)+2].y=(a[i].y+a[i+1].y)/2.0;
  }
  min=999999999.0;
  for (i=1;i<=6;i++)
    for (j=i+2;j<=8;j++)
    {
      t1=calmianji(i,j);
      t2=area-t1;
      temp=fabs(t2-t1);
      if (temp<min) 
      {
        min=temp;
        ans1=t1;
        ans2=t2;
      }
    }
  if (ans1>ans2)
  {
    temp=ans1;
    ans1=ans2;
    ans2=temp;
  }
  printf("%.3lf %.3lf\n",ans1,ans2);
  return;
}

int main()
{
  int i,T;
  T=0;
  for (i=1;i<=4;i++)
    scanf("%lf%lf",&a[i].x,&a[i].y);
  while (checkin())
  {
    T++;
    area=calarea();
    printf("Cake %d: ",T);
    solve();
    for (i=1;i<=4;i++)
      scanf("%lf%lf",&a[i].x,&a[i].y);
  }
  return 0;
}