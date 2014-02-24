/*This Code is Submitted by Timer for Problem 1225 at 2013-02-01 20:14:21*/
#include <cstdio>
#include <algorithm>

#define MAXN 10002

using namespace std;

struct eugin
{
  int p,d;
};

eugin a[MAXN];
int f[MAXN];
int n;

bool operator < (eugin q,eugin w)
{
  if (q.p>w.p) return true;
  if (q.p<w.p) return false;
  if (q.d<w.d) return true;
  return false;
}

inline int findset(int x)
{
  if (x==f[x]) return x;
  f[x]=findset(f[x]);
  return f[x];
}

int main()
{
  int i,up,t;
  while (scanf("%d",&n)==1)
  {
    up=-1;
    for (i=1;i<=n;i++)
    {
      scanf("%d%d",&a[i].p,&a[i].d);
      if (a[i].d>up) up=a[i].d;
    }
    for (i=1;i<=up;i++)
      f[i]=i;
    sort(a+1,a+1+n);
    up=0;
    for (i=1;i<=n;i++)
    {
      t=findset(a[i].d);
      if (t>0)
      {
        up+=a[i].p;
        f[t]--;
      }
    }
    printf("%d\n",up);
  }
  return 0;
}