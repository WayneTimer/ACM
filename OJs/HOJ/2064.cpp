/*This Code is Submitted by Timer for Problem 2064 at 2013-10-26 11:35:09*/
//并查集
#include <cstdio>

#define MAXN 1100
#define MAX 900

struct point
{
  int x,y;
};

int f[MAXN];
int s[MAXN];
point a[MAXN];
int n;

inline int dist(point q,point w)
{
  int t1,t2;
  t1=q.x-w.x;
  t1*=t1;
  t2=q.y-w.y;
  t2*=t2;
  t1+=t2;
  return t1;
}

inline void init()
{
  int i;
  for (i=1;i<=n;i++)
  {
    scanf("%d%d%d",&a[i].x,&a[i].y,&s[i]);
    f[i]=i;
  }
}

int findset(int x)
{
  if (x==f[x]) return x;
  f[x]=findset(f[x]);
  return f[x];
}

int main()
{
  int i,j,fx,fy,d;
  point ans;
  scanf("%d",&n);
  while (n)
  {
    init();
    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
      {
        d=dist(a[i],a[j]);
        if (d<=MAX)
        {
          fx=findset(i);
          fy=findset(j);
          if (fx<fy)
          {
            s[fx]+=s[fy];
            f[fy]=fx;
          }
          else if (fy<fx)
          {
            s[fy]+=s[fx];
            f[fx]=fy;
          }
        }
      }
    ans.y=-1;
    for (i=1;i<=n;i++)
    {
      fx=findset(i);
      if (s[fx]>ans.y)
      {
        ans.x=fx;
        ans.y=s[fx];
      }
    }
    printf("%d %d\n",ans.x,ans.y);
    scanf("%d",&n);
  }
  return 0;
}