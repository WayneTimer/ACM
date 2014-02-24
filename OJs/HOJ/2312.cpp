/*This Code is Submitted by Timer for Problem 2312 at 2012-07-09 10:40:52*/
#include <cstdio>

using namespace std;

int T;
int n,m;

int main()
{
  int i;
  long long s;
  scanf("%d",&T);
  for (i=1;i<=T;i++)
  {
    printf("Scenario #%d:\n",i);
    scanf("%d %d",&n,&m);
    s=m-n+1;
    s=((n+m)*s)>>1;
    printf("%lld\n",s);
    printf("\n");
  }
  return 0;
}