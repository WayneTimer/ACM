/*This Code is Submitted by Timer for Problem 1087 at 2012-04-26 01:18:30*/
#include <cstdio>
#include <cstring>

#define N 1000005

using namespace std;

bool a[N];

int main()
{
  int i,s,k,sum;
  memset(a,true,sizeof(a));
  for (i=1;i<=1000000;i++)
  {
    k=i;
    s=0;
    while (k>0)
    {
      s=s+k%10;
      k=k/10;
    }
    sum=s+i;
    a[sum]=false;
  }
  for (i=1;i<=1000000;i++)
    if (a[i]) printf("%d\n",i);
  return 0;
}