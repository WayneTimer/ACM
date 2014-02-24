/*This Code is Submitted by Timer for Problem 2756 at 2012-05-03 18:46:51*/
#include <cstdio>

using namespace std;

int main()
{
  int n,k;
  scanf("%d",&n);
  while (n!=0)
  {
    scanf("%d",&k);
    if (n==1) printf("Bob\n");
      else if (n<=k+1) printf("Tom\n");
    else
      if ((n-1)%(k+1)==0) printf("Bob\n");
        else printf("Tom\n");
    scanf("%d",&n);
  }
  return 0;
}