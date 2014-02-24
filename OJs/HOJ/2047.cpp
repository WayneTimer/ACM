/*This Code is Submitted by Timer for Problem 2047 at 2012-02-11 17:00:32*/
#include <cstdio>
#include <cstring>

using namespace std;

double b[101];
double a[101][101];
bool mark[101];
int n,m;

void dij()
{
  int i,j,best_j;
  double best;
  memset(mark,false,sizeof(mark));
  mark[1]=true;
  do
  {
    best_j=0;
    best=0;
    for (i=1;i<=n;i++)
      if (mark[i])
        for (j=1;j<=n;j++)
          if ((!mark[j])&&((a[i][j]-0)>0.000001))
            if ((best_j==0)||(b[i]*a[i][j]>best))
            {
              best_j=j;
              best=b[i]*a[i][j];
            }
    if (best_j!=0)
    {
      b[best_j]=best;
      mark[best_j]=true;
    }
  } while (best_j!=0);
}

int main()
{
  int x,y,i;
  double p;
  scanf("%d",&n);
  while (n!=0)
  {
    scanf("%d",&m);
    for (i=1;i<=n;i++)
      b[i]=1;
    memset(a,0,sizeof(a));
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%lf",&x,&y,&p);
      a[x][y]=p/100;
      a[y][x]=p/100;
    }
    dij();
    printf("%.6lf percent\n",b[n]*100);
    scanf("%d",&n);
  }
  return 0;
}