/*This Code is Submitted by Timer for Problem 2081 at 2012-08-13 13:25:15*/
#include <cstdio>
#include <cstring>

#define MAXN 100010
#define EPS 1e-7

using namespace std;

struct cyr
{
  double x;
  double y;
};

struct seg
{
  cyr a;
  cyr b;
};

seg a[MAXN];
bool used[MAXN];
int n;

inline double max(int x,int y)
{
  if (x>=y) return x;
  return y;
}

inline double min(int x,int y)
{
  if (x<=y) return x;
  return y;
}

inline double chaji(cyr q,cyr w,cyr e)
{
  double x1,y1,x2,y2;
  x1=w.x-q.x;
  y1=w.y-q.y;
  x2=e.x-q.x;
  y2=e.y-q.y;
  return ((x1*y2)-(x2*y1));
}

inline bool relation(seg u,seg v)
{
  if (min(u.a.x,u.b.x)>max(v.a.x,v.b.x)) return false;
  if (min(u.a.y,u.b.y)>max(v.a.y,v.b.y)) return false;
  if (min(v.a.x,v.b.x)>max(u.a.x,u.b.x)) return false;
  if (min(v.a.y,v.b.y)>max(u.a.y,u.b.y)) return false;
  if ((chaji(u.a,u.b,v.a)*chaji(u.a,u.b,v.b))>EPS) return false;
  if ((chaji(v.a,v.b,u.a)*chaji(v.a,v.b,u.b))>EPS) return false;
  return true;
}

int main()
{
  int i,j;
  bool flag;
  scanf("%d",&n);
  while (n)
  {
    memset(used,true,sizeof(used));
    for (i=1;i<=n;i++)
      scanf("%lf%lf%lf%lf",&a[i].a.x,&a[i].a.y,&a[i].b.x,&a[i].b.y);
    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
        if (relation(a[i],a[j]))
        {
          used[i]=false;
          break;
        }
    printf("Top sticks: ");
    flag=false;
    for (i=1;i<=n;i++)
    {
      if (used[i])
      {
        if (flag)
          printf(", ");
        else
          flag=true;
        printf("%d",i);
      }
    }
    printf(".\n");
    scanf("%d",&n);
  }
  return 0;
}