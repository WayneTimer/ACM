#include <cstdio>
#include <cstring>

using namespace std;

long long a[10010];
int n,k;

bool check(long long xx)
{
  long long s;
  int i;
  s=0;
  for (i=1;i<=n;i++)
    s+=a[i]/xx;
  if (s>=k) return true;
  return false;
}

int main()
{
  long long r,l,mid,ans;
  int i;
  double x;
  while (scanf("%d%d",&n,&k)==2)
  {
    memset(a,0,sizeof(a));
    l=0;
    r=0;
    for (i=1;i<=n;i++)
    {
      scanf("%lf",&x);
      x=x*100;
      a[i]=(long long) x;
      if (a[i]>r) r=a[i];
    }
    while (l<=r)
    {
      if ((l==0)&&(r==0)) 
      {
        ans=0;
        break;
      }
      mid=(l+r)>>1;
      if (mid==0) mid=r;
      if (check(mid))
      {
        ans=mid;
        l=mid+1;
      }
      else
        r=mid-1;
    }
    x=(double) ans;
    x=x/100;
    printf("%.2lf\n",x);
  }
  return 0;
}