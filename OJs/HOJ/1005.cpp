/*This Code is Submitted by Timer for Problem 1005 at 2012-02-22 11:30:10*/
#include <cstdio>
#include <cstring>
#define MAX 99999999

using namespace std;

int p,n,k,t;
long long v[201];
long long f[201][201];
long long cyr[201][201];

long long sub(int x,int y)
{
  int r,i,j;
  long long sum,clhs;
  sum=0;
  r=(y-x)/2;
  r=r+x;
  for (i=x;i<=y;i++)
    if (v[i]>=v[r])
      sum=sum+v[i]-v[r];
    else 
      sum=sum+v[r]-v[i];
  if (((y-x)%2)==0) return sum;
  r++;
  clhs=0;
  for (i=x;i<=y;i++)
    if (v[i]>=v[r])
      clhs=clhs+v[i]-v[r];
    else 
      clhs=clhs+v[r]-v[i];
  if (clhs<sum) return clhs;
    else return sum;
}
  
int main()
{
  int i,j;
  long long min,u;
  p=0;
  scanf("%d%d",&n,&k);
  while (!((n==0)&&(k==0)))
  {
    p++;
    memset(v,0,sizeof(v));
    memset(f,0,sizeof(f));
    memset(cyr,0,sizeof(cyr));
    for (i=1;i<=n;i++)
      scanf("%lld",&v[i]);
    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
        cyr[i][j]=sub(i,j);
    for (j=1;j<=k;j++)
      for (i=j;i<=n;i++)
      {
        if (j==1) 
        {
          f[i][j]=cyr[1][i];
          continue;
        }
        min=MAX;
        for (t=j-1;t<=i-1;t++)
        {
          u=f[t][j-1]+cyr[t+1][i];
          if (u<min) min=u;
        }
        f[i][j]=min;
      }
    printf("Chain %d\n",p);
    printf("Total distance sum = %lld\n",f[n][k]);
    printf("\n");
    scanf("%d%d",&n,&k);
  }
  return 0;
}