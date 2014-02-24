/*This Code is Submitted by Timer for Problem 1143 at 2012-08-10 19:22:23*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int x;
  int y;
};
  
cyr a[110];
int m;

inline int gcd(int x,int y)
{
  int t;
  if (y>x)
  {
    t=y;
    y=x;
    x=t;
  }
  while (y!=0)
  {
    t=y;
    y=x%y;
    x=t;
  }
  return x;
}

inline int chaji(cyr q,cyr w)
{
  return ((q.x*w.y)-(w.x*q.y));
}

inline int calarea()
{
  int i,s;
  cyr q,w;
  s=0;
  for (i=2;i<m;i++)
  {
    q.x=a[i].x-a[1].x;
    q.y=a[i].y-a[1].y;
    w.x=a[i+1].x-a[1].x;
    w.y=a[i+1].y-a[1].y;
    s+=chaji(q,w);
  }
  if (s<0) return -s;
  return s;
}

int main()
{
  int T,i,x,y,p;
  int t1,t2,e,inside;
  int area;
  scanf("%d",&T);
  a[1].x=0;
  a[1].y=0;
  for (p=1;p<=T;p++)
  {
    scanf("%d",&m);
    for (i=1;i<=m;i++)
    {
      scanf("%d%d",&x,&y);
      a[i+1].x=a[i].x+x;
      a[i+1].y=a[i].y+y;
    }
    area=calarea();
    e=0;
    for (i=1;i<m;i++)
    {
      t1=a[i+1].y-a[i].y;
      t2=a[i+1].x-a[i].x;
      if (t1<0) t1=-t1;
      if (t2<0) t2=-t2;
      x=gcd(t1,t2);
      e+=x;
    }
    t1=a[1].y-a[m].y;
    t2=a[1].x-a[m].x;
    if (t1<0) t1=-t1;
    if (t2<0) t2=-t2;
    x=gcd(t1,t2);
    e+=x;
    inside=area+2-e;
    inside=inside/2;
    printf("Scenario #%d:\n",p);
    printf("%d %d ",inside,e);
    if (area&1) 
      printf("%d.5\n",area>>1);
    else
      printf("%d.0\n",area>>1);
    printf("\n");
  }
  return 0;
}