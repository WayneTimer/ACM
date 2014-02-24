/*This Code is Submitted by Timer for Problem 2490 at 2013-03-18 18:21:20*/
#include <cstdio>
#include <algorithm>

using namespace std;

int r,n,ans;
int a[1010];

int main()
{
  int i,j;
  scanf("%d%d",&r,&n);
  while (!(r==-1 && n==-1))
  {
    ans=0;
    for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    i=1;
    while (i<=n)
    {
      j=i;
      i++;
      while (i<=n && a[j]+r>=a[i]) i++;
      ans++;
      j=i-1;
      while (i<=n && a[j]+r>=a[i]) i++;
    }
    printf("%d\n",ans);
    scanf("%d%d",&r,&n);
  }
  return 0;
}