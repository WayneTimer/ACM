/*This Code is Submitted by Timer for Problem 2244 at 2013-02-26 18:09:28*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct cyr
{
  int x,v;
};

cyr a[10010];
int c[1010];
int n,m;

bool operator < (cyr q,cyr w)
{
  if (q.x<w.x) return true;
  return false;
}

int main()
{
  int i,s,p;
  long long sum,t,mymin;
  while (scanf("%d",&n)==1)
  {
    memset(c,-1,sizeof(c));
    sum^=sum;
    m^=m;
    for (i=1;i<=n;i++)
    {
      scanf("%d%d",&a[i].x,&a[i].v);
      if (c[a[i].v]==-1)
      {
        c[a[i].v]++;
        m++;
      }
    }
    sort(a+1,a+1+n);
    p=1;
    s=1;
    c[a[1].v]++;
    if (s==m) 
    {
      puts("0");
      continue;
    }
    mymin=-1;
    for (i=2;i<=n;i++)
    {
      t=a[i].x;
      t=t-a[i-1].x;
      sum+=t;
      if (!c[a[i].v]) s++;
      c[a[i].v]++;
      while (c[a[p].v]>1)
      {
        c[a[p].v]--;
        t=a[p+1].x;
        t=t-a[p].x;
        sum-=t;
        p++;
      }
      if (s==m)
        if (mymin==-1 || sum<mymin)
          mymin=sum;
    }
    printf("%lld\n",mymin);
  }
  return 0;
}