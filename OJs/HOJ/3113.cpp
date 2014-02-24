/*This Code is Submitted by Timer for Problem 3113 at 2012-05-20 21:34:34*/
#include <cstdio>
#include <cstring>

using namespace std;

long long a[1510];
long long f[1510][1510];
int n;

long long findmax(long long x,long long y)
{
    if (x>=y) return x;
    return y;
}

long long cyr(int x,int y)
{
    long long s1=0,s2=0;
    int t;
    if (x==y) return (n*a[x]);
    t=n-(y-x);
    if ((x+1)<=y)
    if (f[x+1][y]!=0) s1=f[x+1][y]+t*a[x];
      else
      {
          f[x+1][y]=cyr(x+1,y);
          s1=f[x+1][y]+t*a[x];
      }
    if ((y-1)>=x)
    if (f[x][y-1]!=0) s2=f[x][y-1]+t*a[y];
      else
      {
          f[x][y-1]=cyr(x,y-1);
          s2=f[x][y-1]+t*a[y];
      }
    if (s1>=s2) return s1;
      else return s2;
}

int main()
{
    int i,q,w,j,t,temp;
    long long xx,yy;
    scanf("%d",&n);
    while (n!=0)
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for (i=1;i<=n;i++)
          scanf("%lld",&a[i]);
        for (i=1;i<=n;i++)
          for (j=i;j<=n;j++)
            f[i][j]=cyr(i,j);
        printf("The Max Value Is %d.\n",f[1][n]);
        scanf("%d",&n);
    }
    return 0;
}