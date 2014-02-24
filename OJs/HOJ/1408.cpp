/*This Code is Submitted by Timer for Problem 1408 at 2012-03-15 01:04:05*/
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n;
long a[51];

long gcd(long b,long r)
{
  if (b==0) return r;
    else return gcd(r%b,b);
}

int main()
{
  int i,j;
  long s,sum,t;
  double q,w;
  scanf("%d",&n);
  while (n!=0)
  {
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++)
      scanf("%ld",&a[i]);
    sum=0;
    s=0;
    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
      {
        sum++;
        if (a[i]<=a[j])
          t=gcd(a[i],a[j]);
        else
          t=gcd(a[j],a[i]);
        if (t==1) s++;
      }
    if (s==0) printf("No estimate for this data set.\n");
      else
      {
        sum=sum*6;
        q=sum;
        w=s;
        q=q/w;
        q=sqrt(q);
        printf("%.6lf\n",q);
      }
    scanf("%d",&n);
  }
  return 0;
}