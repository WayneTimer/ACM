/*This Code is Submitted by Timer for Problem 2942 at 2012-08-08 11:24:32*/
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=500010;
long long a[maxn];
long long sum;
int n;

int main()
{
  int i,head,tail,h,j,wei;
  long long s;
  while (scanf("%d",&n)==1)
  {
    sum=0;
    memset(a,0,sizeof(a));
    head=1;
    tail=0;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&h);
      s=0;
      while ((head<=tail) && (h>a[tail]))
      {
        tail--;
        s++;
      }
      wei=tail;
      while ((head<=wei) && (h==a[wei]))
      {
        wei--;
        s++;
      }
      tail++;
      a[tail]=h;
      sum=sum+s;
      if (head<tail) 
        if (head<=wei)
          sum++;
    }
    printf("%lld\n",sum);
  }
  return 0;
}