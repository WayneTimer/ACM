/*This Code is Submitted by Timer for Problem 3034 at 2012-07-24 19:32:15*/
#include <cstdio>
#include <cstring>

using namespace std;

int n,m,b,min;
int a[10010][55];
bool flag;
int sum;

void cyr()
{
  int i,s;
  s=0;
  for (i=1;i<=7;i++)
  {
    s+=a[i][52];
    if (s>b) break;
  }
  printf("%d\n",i-1);
}

int main()
{
  int i,j;
  while (scanf("%d%d%d",&n,&m,&b)==3)
  {
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++)
    {
      min=1000000000;
      for (j=1;j<=m;j++)
      {
        scanf("%d",&a[i][j]);
        if (i>7)
          a[i][j]+=a[i-7][j];
        if (a[i][j]<min) min=a[i][j];
      }
      a[i][52]=min;
    }
    flag=true;
    sum=0;
    if (n<=7) cyr();
    else
    {
      for (i=0;i<=6;i++)
      {
        sum+=a[n-i][52];
      }
      if (sum<=b) 
      {
        printf("%d\n",n);
        flag=false;
      }
      else
      {
        for (i=n-7;i>=1;i--)
        {
          sum-=a[i+7][52];
          sum+=a[i][52];
          if (sum<=b)
          {
            printf("%d\n",i+6);
            flag=false;
            break;
          }
        }
      }
    }
    if (flag) cyr();
  }
  return 0;
}