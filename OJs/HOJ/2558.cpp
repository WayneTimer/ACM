/*This Code is Submitted by Timer for Problem 2558 at 2012-07-27 19:20:52*/
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int a[101][101],cyr[101][101];
int f[101];

int main()
{
  int i,j,k;
  int s,temp,max;
  while (scanf("%d",&n)==1)
  {
    memset(a,0,sizeof(a));
    memset(cyr,0,sizeof(cyr));
    max=-1;
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
      {
        scanf("%d",&a[i][j]);
        cyr[i][j]=a[i][j];
        if (i>1) cyr[i][j]+=cyr[i-1][j];
      }
    for (i=1;i<=n;i++)
      for (j=i;j<=n;j++)
      {
        memset(f,0,sizeof(f));
        s=0;
        for (k=1;k<=n;k++)
        {
          temp=cyr[j][k]-cyr[i-1][k];
          if ((s+temp)>temp) f[k]=s+temp;
            else f[k]=temp;
          s=f[k];
          if (s>max) max=s;
        }
      }
    printf("%d\n",max);
  }
  return 0;
}