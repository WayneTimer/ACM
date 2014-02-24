/*This Code is Submitted by Timer for Problem 2719 at 2012-04-15 15:32:10*/
#include <cstdio>
#include <cmath>

using namespace std;

long long n,m;

long long cyr(long long nn,long long mm)
{
  long long i,t1;
  t1=1;
  for (i=1;i<=mm;i++)
  {
    t1=t1*(nn-i+1)/i;
  }
  return t1;
}

int main()
{
  long long s,a,b;
  while (scanf("%lld%lld",&n,&m)==2)
  {
    if (m==0) 
    {
      printf("1\n");
      continue;
    }
    a=cyr(m+n,m);
    if (m==1) b=1;
      else b=cyr(m+n,m-1);
    s=a-b;
    printf("%lld\n",s);
  }
  return 0;
}