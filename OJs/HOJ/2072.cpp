/*This Code is Submitted by Timer for Problem 2072 at 2012-07-25 19:29:17*/
#include <cstdio>
#include <cstring>

using namespace std;

int n,m;
char a[30][30];

int main()
{
  char e[100];
  int i,j,s;
  scanf("%s",e);
  while (e[3]!='O')
  {
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof(a));
    for (i=0;i<n;i++)
      scanf("%s",a[i]);
    for (i=0;i<(n-1);i++)
    {
      for (j=0;j<(m-1);j++)
      {
        s=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
        s=s>>2;
        a[i][j]=s;
      }
      a[i][m-1]='\0';
      printf("%s\n",a[i]);
    }
    scanf("%s",e);
    scanf("%s",e);
  }
  return 0;
}