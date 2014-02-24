/*This Code is Submitted by Timer for Problem 1444 at 2013-04-24 22:34:33*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXA 2000000010

int n;
int a[8000];

inline void init()
{
  int i,j,k,u; 
  int s1,s2,s3,s4;
  n=0;
  s1=0;
  for (i=0;s1<MAXA>>1;i++)
  {
    if (i==0) s1=1;
    else s1<<=1;
    s2=0;
    for (j=0;s2<MAXA/3;j++)
    {
      if (j==0) s2=s1;
      else s2*=3;
      s3=0;
      for (k=0;s3<MAXA/5;k++)
      {
        if (k==0) s3=s2;
        else s3*=5;
        s4=0;
        for (u=0;s4<MAXA/7;u++)
        {
          if (u==0) s4=s3;
          else s4*=7;
          n++;
          a[n]=s4;
        }
      }
    }
  }
  sort(a+1,a+1+n);
}

int main()
{
  init();
  scanf("%d",&n);
  while (n)
  {
    printf("The %d",n);
    if (n%10==1 && n%100!=11) printf("st");
    else if (n%10==2 && n%100!=12) printf("nd");
    else if (n%10==3 && n%100!=13) printf("rd");
    else printf("th");
    printf(" humble number is %d.\n",a[n]);
    scanf("%d",&n);
  }
  return 0;
}