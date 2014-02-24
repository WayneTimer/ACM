/*This Code is Submitted by Timer for Problem 2085 at 2012-04-18 13:24:12*/
#include <cstdio>
#include <string.h>

using namespace std;

int n;
int a[10001],inc[10001],dec[10001];
int b[10001];
int max;

int main()
{
  int i,j,s,t;
  while (scanf("%d",&n)==1)
  {
    memset(a,0,sizeof(a));
    memset(inc,0,sizeof(inc));
    memset(dec,0,sizeof(dec));
    memset(b,0,sizeof(b));
    for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
    inc[1]=1;
    max=1;
    b[1]=a[1];
    b[0]=-100001;
    for (i=2;i<=n;i++)
    {
      inc[i]=1;
      for (j=max;j>=0;j--)
      {
        if (b[j]<a[i])
        {
          if (j==max)
          {
            max++;
            inc[i]=max;
            b[max]=a[i];
            break;
          }
          else
          {
            if (a[i]<b[j+1])
              b[j+1]=a[i];
            inc[i]=j+1;
            break;
          }
        }
      }
    }
    dec[n]=1;
    s=1;
    memset(b,0,sizeof(b));
    b[1]=a[n];
    max=1;
    b[0]=-100001;
    for (i=n-1;i>=1;i--)
    {
      dec[i]=1;
      for (j=max;j>=0;j--)
      {
        if (b[j]<a[i])
        {
          if (j==max)
          {
            max++;
            dec[i]=max;
            b[max]=a[i];
            break;
          }
          else
          {
            if (a[i]<b[j+1])
              b[j+1]=a[i];
            dec[i]=j+1;
            break;
          }
        }
      }
      t=dec[i];
      if (inc[i]<t) t=inc[i];
      if (t!=1)
      {
        if (t>s) s=t;
      }
    }
    s=2*s-1;
    printf("%d\n",s);
  }
  return 0;
}