/*This Code is Submitted by Timer for Problem 1562 at 2012-03-18 13:30:35*/
#include <cstdio>
#include <cstring>

using namespace std;

int a[101][101];
long f[101][101];
int n;

int main()
{
  int i,j;
  int x,y;
  scanf("%d",&n);
  while (n!=0)
  {
    memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    for (i=1;i<=n;i++)
    {
      scanf("%d%d",&x,&y);
      a[x][y]++;
    }
    for (i=1;i<=100;i++) 
      for (j=1;j<=100;j++) 
      { 
        f[i][j]=f[i-1][j]; 
        if (f[i][j]<f[i][j-1]) 
          f[i][j]=f[i][j-1]; 
        f[i][j]=f[i][j]+a[i][j]; 
      }
    printf("%ld\n",f[100][100]);
    scanf("%d",&n);
  }
  printf("*\n");
  return 0;
}