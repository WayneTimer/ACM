/*This Code is Submitted by Timer for Problem 1653 at 2012-02-11 21:46:55*/
#include <cstdio>
#include <cstring>

using namespace std;

long a[1001][1001];
long b[1001];
bool mark[1001];
long m;
int n,p;

void dij()
{
  int i,j,k;
  long min;
  memset(mark,false,sizeof(mark));
  for (i=1;i<=n;i++)
  {
    min=0;
    for (j=1;j<=n;j++)
      if ((!mark[j])&&(b[j]>min))
      {
        min=b[j];
        k=j;
      }
    mark[k]=true;
    for (j=2;j<=n;j++)
      if (a[k][j]!=0)
      {
        if (a[k][j]>=b[k])
          if (b[j]<b[k]) b[j]=b[k];
        if (a[k][j]<b[k])
          if (b[j]<a[k][j]) b[j]=a[k][j];
      }
  }
}

int main()
{
  int u,i,x,y,j;
  long v;
  while (scanf("%d",&p)==1) 
  {
    for (u=1;u<=p;u++)
    {
      memset(a,0,sizeof(a));
      memset(b,0,sizeof(b));
      b[1]=0;
      scanf("%d%ld",&n,&m);
      for (i=1;i<=m;i++)
      {
        scanf("%d%d%ld",&x,&y,&v);
        a[x][y]=v;
        a[y][x]=v;
        if (x==1) 
          if ((b[y]==0)||(v<b[y]))
            b[y]=v;
        if (y==1)
          if ((b[x]==0)||(v<b[x]))
            b[x]=v;
      }
      dij();
      printf("Scenario #%d:\n",u);
      printf("%ld\n",b[n]);
      printf("\n");
    }
  }
  return 0;
}