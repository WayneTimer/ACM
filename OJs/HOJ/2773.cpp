/*This Code is Submitted by Timer for Problem 2773 at 2013-05-29 00:49:43*/
#include <cstdio>
#include <cmath>

int n;

inline void work(int x)
{
  int i,j,k;
  for (i=1;i<=x;i+=2)
  {
    for (j=1;j<=x-i>>1;j++)
      printf(" ");
    for (k=1;k<=i;k++)
      printf("X");
    puts("");
  }
}

int main()
{
  int a;
  while (scanf("%d",&n)==1)
  {
    while (n)
    {
      a=sqrt(n<<2);
      if (a&1) a--;
      work(a-1);
      n-=a*a>>2;
    }
    puts("");
  }
  return 0;
}