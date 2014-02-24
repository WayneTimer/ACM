/*This Code is Submitted by Timer for Problem 1833 at 2012-02-25 22:13:37*/
#include <cstdio>
#include <cstring>

using namespace std;

char a[2001][7];
int n;
int d[2001];
int v[2001][2001];

int main()
{
  int i,j,k,e;
  int min,sum;
  scanf("%d",&n);
  while (n!=0)
  {
    memset(a,0,sizeof(a));
    memset(v,0,sizeof(v));
    for (i=1;i<=n;i++)
      scanf("%s",a[i]);
    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
      {
        e=0;
        for (k=0;k<=6;k++)
          if (a[i][k]!=a[j][k]) e++;
        v[i][j]=e;
        v[j][i]=e;
      }
    d[1]=0;
    sum=0;
    for (i=2;i<=n;i++)
      d[i]=v[1][i];
    for (i=1;i<n;i++)
    {
      min=0x3fffffff;
      for (j=1;j<=n;j++)
        if ((d[j]!=0)&&(d[j]<min))
        {
          min=d[j];
          k=j;
        }
      sum=sum+min;
      d[k]=0;
      for (j=1;j<=n;j++)
        if ((d[j]!=0)&&(v[k][j]<d[j]))
          d[j]=v[k][j];
    }
    printf("The highest possible quality is 1/%d.\n",sum);
    scanf("%d",&n);
  }
  return 0;
}