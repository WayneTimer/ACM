/*This Code is Submitted by Timer for Problem 2995 at 2012-02-20 21:00:42*/
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int UP=740000;

int main()
{
  int t,n,c;
  scanf("%d",&t);
  while (t>0)
  {
    t--;
    scanf("%d",&n);
    int l,r;
    l=1;
    r=UP;
    c=UP;
    while (l<=r)
    {
      int mid,i;
      int tmp;
      tmp=0;
      mid=(l+r)/2;
      for (i=1;i<=mid;++i)
        tmp+=mid/i;
      if(tmp>=n)
      {
        r=mid-1;
        if (mid<c)
          c=mid;
      }
      else
      l=mid+1;
    }
    printf("%.4lf\n",c*log(1.0*c)-c+1);
  }
  return 0;
}