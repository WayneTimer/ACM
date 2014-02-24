/*This Code is Submitted by Timer for Problem 1365 at 2012-04-30 11:26:57*/
#include <cstdio>
#include <cstring>

using namespace std;

int a[1001];

int main()
{
  long long i,s,m,t;
  bool flag;
  int n;
  while (scanf("%d",&n)==1)
  {
    if (n==0)
    {
      printf("10\n");
      continue;
    }
    if (n<10) 
    {
      printf("%d\n",n);
      continue;
    }
    m=n;
    s=0;
    i=9;
    flag=true;
    memset(a,0,sizeof(a));
    t=-1;
    while (m>=10)
    {
      while ((m%i)==0)
      {
        t++;
        a[t]=i;
        m=m/i;
        if (m<10) break;
      }
      if (m<10) break;
      i--;
      if (i<=1) 
      {
        printf("-1\n");
        flag=false;
        break;
      }
    }
    if (flag) 
    {
      printf("%lld",m);
      for (i=t;i>=0;i--)
        printf("%d",a[i]);
      printf("\n");
    }
  }
  return 0;
}