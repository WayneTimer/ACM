/*This Code is Submitted by Timer for Problem 1356 at 2012-04-13 07:08:39*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

long long n;

long long miqumo(long long a,long long b,long long c)
{
  int p[101];
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

bool MR()
{
  long long t,sum;
  t=rand()%(n-1)+1;
  sum=miqumo(t,n-1,n);
  if ((sum%n)!=1) return false;
    else return true;
}

int main()
{
  bool flag;
  int time=10,i;
  while (scanf("%lld",&n)==1)
  {
    flag=true;
    if (n<=1) flag=false;
      else if (n>3)
      {
        for (i=1;i<=time;i++)
          if (!MR()) 
          {
            flag=false;
            break;
          }
      }
    if (flag) printf("YES\n");
      else printf("NO\n");
  }
  return 0;
}