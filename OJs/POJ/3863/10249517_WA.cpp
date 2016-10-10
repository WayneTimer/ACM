#include <cstdio>

using namespace std;

long long min,n;
int m;

int main()
{
  int i;
  long long x,y,k,q,w,s;
  min=1001;
  scanf("%lld%d",&n,&m);
  for (i=1;i<=m;i++)
  {
    scanf("%lld%lld",&x,&y);
    q=n*y;
    w=x+y;
    k=q/w;
    k++;
    s=k*x-(n-k)*y;
    if (s<min) min=s;
  }
  printf("%lld\n",min);
  return 0;
}