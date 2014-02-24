/*This Code is Submitted by Timer for Problem 2422 at 2013-03-19 20:11:54*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,k;
int a[1010];

inline bool check()
{
  int t,i,j;
  i=1;
  j=1;
  t^=t;
  while (i<=n)
  {
    t+=a[i];
    if (i%k==0)
    {
      if ((a[j]+2)*(i-j+1)<t) return false;
      if ((a[i]-2)*(i-j+1)>t) return false;
      j=i+1;
      t^=t;
    }
    i++;
  }
  return true;
}

int main()
{
  char e[100];
  int i,T;
  T^=T;
  scanf("%d%d",&n,&k);
  while (n||k)
  {
    for (i=1;i<=n;i++)
    {
      scanf("%s",e);
      a[i]=strlen(e);
    }
    sort(a+1,a+1+n);
    T++;
    if (T>1) puts("");
    printf("Case %d: ",T);
    if (check()) puts("yes");
    else puts("no");
    scanf("%d%d",&n,&k);
  }
  return 0;
}