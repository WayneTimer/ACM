/*This Code is Submitted by Timer for Problem 2544 at 2012-08-26 18:00:02*/
#include <cstdio>

#define N 50010

int n,up;
int a[N];

int main()
{
  int i,x,l,r,mid;
  while (scanf("%d",&n)==1)
  {
    scanf("%d",&a[1]);
    up=1;
    for (i=2;i<=n;i++)
    {
      scanf("%d",&x); 
      l=1;
      r=up;
      while (l!=r)
      {
        mid=(l+r)>>1;
        if (x>a[mid])
          l=mid+1;
        else
          r=mid;
      }
      if (x>a[l])
      {
        a[l+1]=x;
        if (l+1>up) up=l+1;
      } 
      else
        a[l]=x;
    }
    printf("%d\n",n-up);
  }
  return 0;
}