/*This Code is Submitted by Timer for Problem 1450 at 2012-02-15 13:48:28*/
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

struct cyr
{
  int x;
  int y;
};

struct cyr a[201];
double v[201][201];
double b[201];
bool mark[201];
int n;

double max(double x,double y)
{
  if (x>y) return x;
    else return y;
}

void sub()
{
  int i,j,k;
  double t;
  double min;
  mark[1]=true;
  for (i=1;i<=n;i++)
  {
    min=999999999;
    for (j=2;j<=n;j++)
      if ((!mark[j])&&(b[j]<min))
      {
        min=b[j];
        k=j;
      }
    mark[k]=true;
    for (j=2;j<=n;j++)
    {
      t=max(b[k],v[k][j]);
      if (t<b[j]) b[j]=t;
    }
  }
}

int main()
{
  int i,j,x,y,p;
  double q,w;
  p=0;
  scanf("%d",&n);
  while (n!=0)
  {
    p++;
    memset(a,0,sizeof(a));
    memset(v,0,sizeof(v));
    memset(b,0,sizeof(b));
    memset(mark,false,sizeof(mark));
    for (i=1;i<=n;i++)
    {
      scanf("%d%d",&x,&y);
      a[i].x=x;
      a[i].y=y;
      for (j=1;j<i;j++)
      {
        if (j==i) continue;
        q=x-a[j].x;
        w=y-a[j].y;
        q=q*q+w*w;
        v[i][j]=sqrt(q);
        v[j][i]=v[i][j];
        if (j==1) 
          b[i]=v[i][j];
      }
    }
    sub();
    printf("Scenario #%d\n",p);
    printf("Frog Distance = %.3lf\n",b[2]);
    printf("\n");
    scanf("%d",&n);
  }
  return 0;
}