/*This Code is Submitted by Timer for Problem 1039 at 2012-08-22 09:59:24*/
#include <cstdio>

int n;

int main()
{
  int ans,x,T;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d",&n);
    x=n;
    ans^=ans;
    while (x)
    {
      ans+=x/5;
      x/=5;
    }
    printf("%d\n",ans);
  }
  return 0;
}