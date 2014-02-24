/*This Code is Submitted by Timer for Problem 2453 at 2012-05-01 22:32:31*/
#include <cstdio>

using namespace std;

int main()
{
  int n,r,e,c,i;
  while (scanf("%d",&n)==1)
  {
    for (i=1;i<=n;i++)
    {
      scanf("%d%d%d",&r,&e,&c);
      e=e-c;
      if (r<e) printf("advertise\n");
        else if (r==e) printf("does not matter\n");
          else printf("do not advertise\n");
    }
  }
  return 0;
}