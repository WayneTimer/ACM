/*This Code is Submitted by Timer for Problem 1913 at 2013-08-01 10:42:27*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 50010

struct eugin
{
  int x,y;
};

eugin a[MAXN];
int n;

bool operator < (eugin q,eugin w)
{
  if (q.x<w.x) return true;
  return false;
}

int main()
{
  int i;
  while (scanf("%d",&n)==1)
  {
    for (i=1;i<=n;i++)
      scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n);
    for (i=2;i<=n;i++)
    {
      if (a[i].x<=a[i-1].y)
      {
        a[i].x=a[i-1].x;
        if (a[i-1].y>a[i].y)
          a[i].y=a[i-1].y;
      }
      else
        printf("%d %d\n",a[i-1].x,a[i-1].y);
    }
    printf("%d %d\n",a[n].x,a[n].y);
  }
  return 0;
}