/*This Code is Submitted by Timer for Problem 2782 at 2013-05-29 00:25:35*/
#include <cstdio>

int r,a,b;

int main()
{
  int T;
  T=0;
  scanf("%d",&r);
  while (r)
  {
    scanf("%d%d",&a,&b);
    r*=r;
    r<<=2;
    a*=a;
    b*=b;
    a+=b;
    T++;
    printf("Pizza %d ",T);
    if (r>=a) printf("fits");
    else printf("does not fit");
    puts(" on the table.");
    scanf("%d",&r);
  }
  return 0;
}