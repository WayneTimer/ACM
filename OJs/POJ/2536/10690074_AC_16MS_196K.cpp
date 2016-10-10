#include <cstdio>
#include <cstring>

#define EPS 1e-7

using namespace std;

struct cyr
{
  double x;
  double y;
};

int n,m,s,v;
cyr g[110];
bool map[110][110];
bool cover[110];
int link[110];

inline bool equ(double q,double w)
{
  double t;
  t=q-w;
  if (t<-EPS) return false;
  if (t>EPS) return false;
  return true;
}

inline double caldis(double x1,double y1,double x2,double y2)
{
  double t1,t2;
  t1=x2-x1;
  t1=t1*t1;
  t2=y2-y1;
  t2=t2*t2;
  return (t1+t2);
}

bool find(int i,int u)
{
  int k,q;
  for (k=1;k<=u;k++)
    if ((map[i][k])&&(!(cover[k])))
    {
      q=link[k];
      link[k]=i;
      cover[k]=true;
      if ((q==0)||(find(q,u))) return true;
      link[k]=q;
    }
  return false;
}

int main()
{
  double dist,q,w,t;
  int i,j,s;
  while (scanf("%d%d%d%d",&n,&m,&s,&v)==4)
  {
    memset(map,false,sizeof(map));
    memset(link,0,sizeof(link));
    dist=s*v;
    dist=dist*dist;
    for (i=1;i<=n;i++)
      scanf("%lf%lf",&g[i].x,&g[i].y);
    for (j=1;j<=m;j++)
    {
      scanf("%lf%lf",&q,&w);
      for (i=1;i<=n;i++)
      {
        t=caldis(g[i].x,g[i].y,q,w);
        if ((t<=dist) || (equ(t,dist)))
          map[i][j]=true;
      }
    }
    for (i=1;i<=n;i++)
    {
      memset(cover,false,sizeof(cover));
      find(i,m);
    }
    s=0;
    for (i=1;i<=m;i++)
      if (link[i]!=0) s++;
    printf("%d\n",n-s);
  }
  return 0;
}