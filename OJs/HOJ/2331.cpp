/*This Code is Submitted by Timer for Problem 2331 at 2013-03-04 23:07:38*/
/* 等差数列
  设首项为a,项数为i,则sum=(a+a+i-1)*i/2
  即 2a=2x/i-i+1
  所以枚举i,验证是否存在满足该项数i的首项a即可。
*/
#include <cstdio>

int x,p;

int main()
{
  int s,i,t,T;
  while (scanf("%d",&T)==1)
  {
    while (T--)
    {
      scanf("%d%d",&p,&x);
      s^=s;
      x<<=1;
      for (i=2;;i++)
      {
        t=x/i-i+1;
        if (t<2) break;
        if (x%i) continue;
        if (!(t&1)) s++;
      }
      printf("%d %d\n",p,s);
    }
  }
  return 0;
}