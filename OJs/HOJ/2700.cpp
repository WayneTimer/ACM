/*This Code is Submitted by Timer for Problem 2700 at 2012-04-14 22:56:53*/
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

long long miqumo(long long a,long long b,long long c)
{
  int p[10001];
  int i,j;
  long long ans;
  i=-1;
  ans=1;
  while (b)
  {
    i++;
    p[i]=b%2;
    b=b>>1;
  }
  for (j=i;j>=0;j--)
  {
    ans=(ans*ans)%c;
    if (p[j]==1) ans=(ans*a)%c;
  }
  return ans;
}

bool check(long long n)
{
  int i;
  for (i=2;i*i<=n;i++)
    if ((n%i)==0) return false;
  return true;
}

int main()
{
  long long p,a,s;
  scanf("%lld%lld",&p,&a);
  while ((p!=0)&&(a!=0))
  {
    s=miqumo(a,p,p);
    if (s==a) 
    {
      if (!check(p))
        printf("yes\n");
      else printf("no\n");
    }
    else 
      printf("no\n");
    scanf("%lld%lld",&p,&a);
  }
  return 0;
}