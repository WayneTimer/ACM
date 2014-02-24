/*This Code is Submitted by Timer for Problem 1680 at 2012-03-18 14:37:47*/
#include <cstdio>
#include <cstring>

using namespace std;

int f[31][31];
int x,y;

int main()
{
  int i,j,p;
  memset(f,0,sizeof(f));
  for (i=1;i<=30;i++)
  {
    f[i][0]=i;
    for (j=1;j<=30;j++)
    {
      f[i][j]=f[i-1][j-1]+f[i-1][j]+1;
    }
  }
  scanf("%d %d",&x,&y);
  p=0;
  while (!((x==0)&&(y==0)))
  {
    p++;
    printf("Case %d: %d\n",p,f[x][y]);
    scanf("%d %d",&x,&y);
  }
  return 0;
}