/*This Code is Submitted by Timer for Problem 2909 at 2013-03-01 03:06:43*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct rect
{
  int x1,y1,x2,y2;
};

int n;
bool b[1010][1010];
rect a[1010];
int f[1010];

bool operator < (rect q,rect w)
{
  if (q.x2<w.x2) return true;
  if (q.x2>w.x2) return false;
  if (q.y2<w.y2) return true;
  return false;
}

inline bool check(int q,int w)
{
  if (a[q].x2<a[w].x1)
    if (a[q].y2<a[w].y1)
      return true;
  return false;
}

int main()
{
  int m,i,j,ans;
  while (scanf("%d",&n)==1 && n)
  {
    memset(b,false,sizeof(b));
    for (i=1;i<=n;i++)
      scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    sort(a+1,a+1+n);
    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
        if (check(i,j))
          b[i][j]=true;
    memset(f,0,sizeof(f));
    ans=-1;
    for (i=2;i<=n;i++)
    {
      m=-1;
      for (j=1;j<i;j++)
      {
        if (b[j][i])
          if (f[j]>m) m=f[j];
      }
      f[i]=m+1;
      if (f[i]>ans) ans=f[i];
    }
    if (ans==-1) ans=0;
    printf("%d\n",ans+1);
  }
  return 0;
}