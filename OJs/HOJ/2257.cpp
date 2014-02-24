/*This Code is Submitted by Timer for Problem 2257 at 2013-02-26 20:03:24*/
//最长不下降序列(LIS)，nlogn算法
//最长上升序列见HOJ2544
#include <cstdio>
#include <cstring>

#define MAXN 100010

int n;
int a[MAXN];

int main()
{
  int T,i,l,r,mid,m;
  int x;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d",&n);
    scanf("%d",&a[1]);
    m=1;
    for (i=2;i<=n;i++)
    {
      scanf("%d",&x);
      l=1;
      r=m;
      while (l<r)
      {
        mid=(l+r+1)>>1;
        if (x<a[mid])
          r=mid-1;
        else
          l=mid;
      }
      if (x>=a[l]) 
      {
        a[l+1]=x;
        if (l+1>m) m=l+1;
      }
      else
        a[l]=x;
    }
    printf("%d\n",n-m);
  }
  return 0;
}