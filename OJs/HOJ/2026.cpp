/*This Code is Submitted by Timer for Problem 2026 at 2012-02-06 02:23:55*/
#include <cstdio>

using namespace std;

int main()
{
  long n,t;
  long s1,s2,s3;
  int i;
  for (n=2992;n<=9999;n++)
  {
    s1=0;
    s2=0;
    s3=0;
    t=n;
    for (i=1;i<=4;i++)
    {
      s1=s1+t%10;
      t=t/10;
    }
    t=n;
    while (t!=0)
    {
      s2=s2+t%12;
      t=t/12;
    }
    if (s1!=s2) continue;
    t=n;
    while (t!=0)
    {
      s3=s3+t%16;
      t=t/16;
    }
    if (s1!=s3) continue;
    printf("%ld\n",n);
  }
  return 0;
}