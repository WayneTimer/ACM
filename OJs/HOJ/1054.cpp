/*This Code is Submitted by Timer for Problem 1054 at 2012-05-22 00:28:17*/
#include <cstdio>
#include <cstring>

using namespace std;

int m,n;
int a[55];
bool f[1100];

int main()
{
  int p,i,j,t,max,sum;
  p=0;
  scanf("%d%d",&m,&n);
  while (n||m)
  {
    p++;
    memset(f,false,sizeof(f));
    for (i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      f[a[i]]=true;
    }
    for (i=1;i<=n-1;i++)
      for (j=i+1;j<=n;j++)
        if (a[i]<a[j])
        {
          t=a[i]; 
          a[i]=a[j];
          a[j]=t;
        }
    max=n*m;
    sum=0;
    for (i=1;i<=n;i++)
    {
      if (f[max])
        if (max==a[i]) 
          sum++;
        else i--;
      max--;
    }
    printf("Case %d: %d\n",p,sum);
    scanf("%d%d",&m,&n);
  }
  return 0;
}