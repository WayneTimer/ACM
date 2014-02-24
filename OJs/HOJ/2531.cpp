/*This Code is Submitted by Timer for Problem 2531 at 2013-03-21 00:52:28*/
#include <cstdio>
#include <cmath>

struct eugin
{
  int x,y;
};

int n,m;
eugin a[1010];
int ans;

inline int dist(eugin q,eugin w)
{
  int t1,t2;
  t1=q.x-w.x;
  t1*=t1;
  t2=q.y-w.y;
  t2*=t2;
  return t1+t2;
}

int main()
{
  int T,i,j,t;
  eugin b;
  double out;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
      scanf("%d%d",&a[i].x,&a[i].y);
    for (i=1;i<=m;i++)
    {
      scanf("%d%d",&b.x,&b.y);
      ans=-1;
      for (j=1;j<=n;j++)
      {
        t=dist(a[j],b);
        if (ans==-1 || t<ans) ans=t;
      }
      out=ans;
      out=sqrt(out);
      printf("%.3lf\n",out);
    }
    puts("");
  }
  return 0;
}