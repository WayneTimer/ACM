/*This Code is Submitted by Timer for Problem 2507 at 2012-08-15 19:20:04*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define MAXN 2010
#define EPS 1e-6

using namespace std;

struct cyr
{
  double x;
  double y;
};

int n,m;
double d[MAXN][MAXN];
cyr a[MAXN];
double dist[MAXN];
bool used[MAXN];
double dd[MAXN];
double mymin;
int que[MAXN];

inline bool equ(double q,double w)
{
  double t;
  t=q-w;
  if (t<-EPS) return false;
  if (t>EPS) return false;
  return true;
}

inline double caldis(cyr q,cyr w)
{
  double t,t1;
  t=w.x-q.x;
  t=t*t;
  t1=w.y-q.y;
  t1=t1*t1;
  t=sqrt(t+t1);
  return t;
}

inline double qumin(double q,double w)
{
  if (q<=w) return q;
  return w;
}

inline void makeMST()
{
  int i,j,k;
  int tail;
  memset(used,false,sizeof(used));
  que[1]=1;
  tail=1;
  used[1]=true;
  while (tail<m)
  {
    mymin=20000000000.0;
    for (i=1;i<=tail;i++)
      for (j=1;j<=m;j++)
        if ((!used[j]) && (que[i]!=j))
        {
          if (d[que[i]][j]<mymin)
          {
            k=j;
            mymin=d[que[i]][j];
          }
        }
    dd[tail-1]=mymin;
    tail++;
    que[tail]=k;
    used[k]=true;
  }
}

int main()
{
  int T,i,j;
  double x,y;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d",&n);
    i=0;
    scanf("%lf",&x);
    while (x!=-1)
    {
      scanf("%lf",&y);
      i++;
      a[i].x=x;
      a[i].y=y;
      for (j=1;j<i;j++)
      {
        d[i][j]=caldis(a[i],a[j]);
        d[j][i]=d[i][j];
      }
      scanf("%lf",&x);
    }
    m=i;
    makeMST();
    sort(dd,dd+m-1);
    printf("%.0lf\n",ceil(dd[m-n-1]));
  }
  return 0;
}