/*
计算出满足每个岛的最左边的圆和最右边的圆，再贪心选择
*/
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct CIR
{
  double lx,rx;
};

CIR a[1010];
int n,d;

bool operator < (CIR q,CIR w)
{
  if (q.lx<w.lx) return true;
  if (q.lx>w.lx) return false;
  if (q.rx<w.rx) return true;
  return false;
}

inline int work()
{
  int i,ret;
  double now;
  now=a[1].rx;
  ret=1;
  for (i=2;i<=n;i++)
    if (a[i].lx>now)
    {
      now=a[i].rx;
      ret++;
    }
    else if (a[i].rx<now)
      now=a[i].rx;
  return ret;
}

int main()
{
  int i,o,x,y,d2;
  bool flag;
  double t;
  o=0;
  while (scanf("%d%d",&n,&d)==2 && (n || d))
  {
    d2=d*d;
    printf("Case %d: ",++o);
    flag=true;
    for (i=1;i<=n;i++)
    {
      scanf("%d%d",&x,&y);
      if (y>d)
	flag=false;
      else
      {
	t=sqrt(d2-y*y);
	a[i].lx=x-t;
	a[i].rx=x+t;
      }
    }
    if (!flag)
    {
      puts("-1");
      continue;
    }
    sort(a+1,a+1+n);
    printf("%d\n",work());
  }
  return 0;
}
