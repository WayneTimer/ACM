/*This Code is Submitted by Timer for Problem 2160 at 2012-07-23 09:26:09*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[100010];

int main()
{
  int j,i,n,l,s;
  while (scanf("%d",&n)==1)
  {
    scanf("%d",&l);
    memset(a,0,sizeof(a));
    for (i=0;i<n;i++)
      scanf("%d",&a[i]);
    sort(a,a+n);
    s=0;
    i=0;
    j=n-1;
    while (i<j)
    {
      if ((a[i]+a[j])<=l)
      {
        i++;
        j--;
      }
      else j--;
      s++;
    }
    if (i==j) s++;
    printf("%d\n",s);
  }
  return 0;
}