/*This Code is Submitted by Timer for Problem 3137 at 2013-02-05 13:47:50*/
#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];
int n,k;

int main()
{
  int i;
  while (scanf("%d%d",&n,&k)==2)
  {
    for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    printf("%d\n",a[n-k+1]);
  }
  return 0;
}