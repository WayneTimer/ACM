/*This Code is Submitted by Timer for Problem 1941 at 2013-08-01 09:18:01*/
//贪心,排序即可
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[1010];
int ans[2];

int main()
{
  double s;
  int i;
  while (scanf("%d",&n)==1)
  {
    for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    ans[0]=0;
    ans[1]=0;
    s=0.0;
    for (i=1;i<=n;i++)
    {
      s+=ans[i&1];
      ans[i&1]+=a[i];
    }
    printf("%.3lf\n",s/n);
  }
  return 0;
}