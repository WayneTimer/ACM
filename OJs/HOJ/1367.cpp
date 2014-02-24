/*This Code is Submitted by Timer for Problem 1367 at 2012-04-15 14:21:10*/
#include <cstdio>

using namespace std;

int main()
{
  int n,a,i;
  int v1,ji;
  while (scanf("%d",&n)==1)
  {
    v1=0;
    ji=0;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&a);
      ji=ji^a;
      if (a>1) v1++;
    }
    if (v1==0)
      if ((n%2)==0)
      {
        printf("Louis\n");
        continue;
      }
      else 
      {
        printf("Lester\n");
        continue;
      }
    if (v1==1)
    {
      printf("Louis\n");
      continue;
    }
    if (v1>1)
    {
      if (ji==0)
      {
        printf("Lester\n");
        continue;
      }
      else 
      {
        printf("Louis\n");
        continue;
      }
    }
  }
  return 0;
}