/*This Code is Submitted by Timer for Problem 2264 at 2013-03-09 19:10:22*/
#include <cstdio>
#include <algorithm>

using namespace std;

char str[60];
long long a[100100];
int n;
long long s;

int main()
{
  int T;
  long long t,i;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      scanf("%s",str);
      scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    s=0;
    for (i=1;i<=n;i++)
    {
      t=i-a[i];
      if (t<0) t=-t;
      s+=t;
    }
    printf("%lld\n",s);
  }
  return 0;
}