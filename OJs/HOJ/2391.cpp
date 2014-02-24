/*This Code is Submitted by Timer for Problem 2391 at 2013-03-11 21:13:01*/
// 二分
#include <cstdio>
#include <algorithm>

using namespace std;

int a[100100];
int n,c;

int main()
{
  int x,l,r,mid,i,s,t;
  bool flag;
  while (scanf("%d%d",&n,&c)==2)
  {
    for (i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      if (i>1)
      {
        t=a[i]-a[i-1];
        if (t>r) r=t;
      }
    }
    sort(a+1,a+1+n);
    l=0;
    r=a[n]-a[1];
    while (l<r)
    {
      mid=l+r+1>>1;
      s=1;
      x=a[1]+mid;
      flag=false;
      for (i=2;i<=n;i++)
      {
        if (a[i]>=x)
        {
          s++;
          if (s>=c) 
          {
            flag=true;
            break;
          }
          x=a[i]+mid;
        }
      }
      if (flag)
        l=mid;
      else
        r=mid-1;
    }
    printf("%d\n",l);
  }
  return 0;
}