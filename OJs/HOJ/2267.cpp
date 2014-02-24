/*This Code is Submitted by Timer for Problem 2267 at 2012-05-01 21:59:22*/
#include <cstdio>

using namespace std;

int main()
{
  int a,b,s;
  scanf("%d%d",&a,&b);
  while ((a!=0)&&(b!=0))
  {
    s=3*a-b;
    printf("%d\n",s);
    scanf("%d%d",&a,&b);
  }
  return 0;
}