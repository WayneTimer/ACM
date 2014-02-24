/*This Code is Submitted by Timer for Problem 1438 at 2013-06-12 12:23:24*/
//简单DP，递推求解
#include <cstdio>
#include <algorithm>

using namespace std;

#define RD(n) scanf("%d",&n)
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<=(n);i++)

#define MAXV 2147483647

struct eugin
{
  int x,y,v;
};

int n,up;
eugin a[100];
int s[100];

bool operator < (eugin q,eugin w)
{
  if (q.x>w.x) return true;
  if (q.x<w.x) return false;
  if (q.y>w.y) return true;
  if (q.y<w.y) return false;
  if (q.v>w.v) return true;
  return false;
}

inline void sw(int &x,int &y)
{
  if (y>x) 
  {
    x^=y;
    y^=x;
    x^=y;
  }
}

inline void work()
{
  int t,ans;
  n=up;
  sort(a+1,a+1+n);
  ans=0;
  rep1(i,n)
  {
    t=0;
    rep(j,i)
    {
      if (a[j].x>a[i].x && a[j].y>a[i].y)
        if (s[j]>t)
          t=s[j];
    }
    s[i]=t+a[i].v;
    if (s[i]>ans) ans=s[i];
  }
  printf("%d\n",ans);
}

int main()
{
  int t,ca;
  ca^=ca;
  s[0]=0;
  a[0].x=MAXV;
  a[0].y=MAXV;
  RD(n);
  while (n)
  {
    up^=up;
    rep1(i,n)
    {
      up++;
      scanf("%d%d%d",&a[up].x,&a[up].y,&a[up].v);
      up++;
      a[up].x=a[up-1].y;
      a[up].y=a[up-1].v;
      a[up].v=a[up-1].x;
      up++;
      a[up].x=a[up-1].y;
      a[up].y=a[up-1].v;
      a[up].v=a[up-1].x;
      sw(a[up-2].x,a[up-2].y);
      sw(a[up-1].x,a[up-1].y);
      sw(a[up].x,a[up].y);
    }
    printf("Case %d: maximum height = ",++ca);
    work();
    RD(n);
  }
  return 0;
}