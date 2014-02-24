/*This Code is Submitted by Timer for Problem 3138 at 2013-02-05 14:43:26*/
//展开式子，先加上sigma(1<=k<=n):(A[1]^2+...+A[n]^2-A[k]^2)*B[k]^2;
//再减去sigma(1<=k<=n):(A[1]*B[1]+...+A[n]*B[n]-A[k]*B[k])*A[k]*B[k];
#include <cstdio>

long long a[1002];
long long b[1002];
long long c[1002];
int n;
long long s1,s2,ans;

int main()
{
  int T,i;
  long long temp;
  scanf("%d",&T);
  while (T--)
  {
    s1^=s1;
    s2^=s2;
    ans^=ans;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      scanf("%lld",&a[i]);
      c[i]=a[i];
      a[i]*=a[i];
      s1+=a[i];
    }
    for (i=1;i<=n;i++)
    {
      scanf("%lld",&b[i]);
      c[i]*=b[i];
      s2+=c[i];
      b[i]*=b[i];
      ans+=(s1-a[i])*b[i];
    }
    temp^=temp;
    for (i=1;i<=n;i++)
      temp+=(s2-c[i])*c[i];
    ans-=temp;
    printf("%lld\n",ans);
  }
  return 0;
}