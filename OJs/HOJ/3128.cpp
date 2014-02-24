/*This Code is Submitted by Timer for Problem 3128 at 2012-12-26 18:54:39*/
#include <cstdio>

#define MAXN 50010

int t[MAXN];
int a[MAXN];
int b[MAXN];
int n,ans;

inline int mymax(int x,int y)
{
  if (x>=y) return x;
  return y;
}

int main()
{
  int T,temp,i;
  a[0]=-10010;
  scanf("%d",&T);
  while (T--)
  {
    ans=-30010;
    scanf("%d",&n);
    b[n+1]=-10010;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&t[i]);
      a[i]=mymax(a[i-1]+t[i],t[i]);
    }
    temp=a[1];
    for (i=2;i<=n;i++)
    {
      if (a[i]>temp) temp=a[i];
      a[i]=temp;
    }
    for (i=n;i>=1;i--)
      b[i]=mymax(b[i+1]+t[i],t[i]);
    temp=b[n];
    for (i=n-1;i>=1;i--)
    {
      if (b[i]>temp) temp=b[i];
      b[i]=temp;
    }
    for (i=1;i<n;i++)
    {
      temp=a[i]+b[i+1];
      if (temp>ans) ans=temp;
    }
    printf("%d\n",ans);
  }
}