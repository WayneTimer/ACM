#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

long long miqumo(long long a,long long b,long long c)
{
  int p[501];
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

bool MR(long long n)
{
  long long a,s;
  a=rand()%(n-1)+1;
  s=miqumo(a,n-1,n);
  s=s%n;
  if (s==1) return true;
  return false;
}

bool check(long long n)
{
  bool flag;
  int times=30,i;
  flag=true;
  if (n<=1) flag=false;
    else 
      if (n>3)
      {
        for (i=1;i<=times;i++)
          if (!MR(n)) 
          {
            flag=false;
            break;
          }
      }     
  return flag;
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