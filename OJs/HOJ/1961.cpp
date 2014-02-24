/*This Code is Submitted by Timer for Problem 1961 at 2012-02-25 19:22:08*/
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

struct cyr 
{
  double x;
  double y;
};

struct clhs
{
  int x;
  int y;
};

double v[250000];
int u,n,m;
cyr a[501];
int mark[501];
clhs w[250000];
double b[250000];

void qsort(int l,int r)
{
  int i,j,d;
  double mid,t;
  i=l;
  j=r;
  mid=v[(l+r)/2];
  do
  {
    while (v[i]<mid) i++;
    while (v[j]>mid) j--;
    if (i<=j)
    {
      t=v[i];
      v[i]=v[j];
      v[j]=t;
      d=w[i].x;
      w[i].x=w[j].x;
      w[j].x=d;
      d=w[i].y;
      w[i].y=w[j].y;
      w[j].y=d;
      i++;
      j--;
    }
  } while (i<=j);
  if (l<j) qsort(l,j);
  if (i<r) qsort(i,r);
}

int find(int x)
{
  if (mark[x]==x) return x;
    else return find(mark[x]);
}

int main()
{
  int p,T,i,j,jj,yy;
  double e;
  scanf("%d",&T);
  for (p=1;p<=T;p++)
  {
    memset(v,0,sizeof(v));
    memset(a,0,sizeof(a));
    memset(w,0,sizeof(w));
    u=0;
    scanf("%d%d",&m,&n);
    for (i=1;i<=n;i++)
      scanf("%lf%lf",&a[i].x,&a[i].y);
    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
      {
        u++;
        e=(a[j].y-a[i].y)*(a[j].y-a[i].y);
        e=e+(a[j].x-a[i].x)*(a[j].x-a[i].x);
        e=sqrt(e);
        v[u]=e;
        w[u].x=i;
        w[u].y=j;
      }
    qsort(1,u);
    memset(b,0,sizeof(b));
    for (i=1;i<=n;i++)
      mark[i]=i;
    j=0;
    for (i=1;i<=u;i++)
    {
      jj=find(w[i].x);
      yy=find(w[i].y);
      if (jj!=yy)
      {
        j++;
        b[j]=v[i];
        mark[yy]=jj;
        if (j>=(n-1)) break;
      }
    }
    printf("%.2lf\n",b[n-m]);
  }
  return 0;
}