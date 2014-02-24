/*This Code is Submitted by Timer for Problem 1751 at 2012-02-24 23:40:39*/
#include <cstdio>
#include <cstring>

using namespace std;

double v[501][501];
double max;
char name[501][25];
int n,m;
bool cyr[501];
int a[501];

int main()
{
  int i,j,k,u,y;
  char e[25];
  double x,min,s;
  while (scanf("%lf",&max)==1)
  {
    memset(v,0,sizeof(v));
    memset(name,0,sizeof(name));
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%s",name[i]);
    scanf("%d",&m);
    for (i=1;i<=m;i++)
    {
      scanf("%s",e);
      for (j=1;j<=n;j++)
        if (strcmp(e,name[j])==0) break;
      scanf("%s",e);
      for (k=1;k<=n;k++)
        if (strcmp(e,name[k])==0) break;
      scanf("%lf",&x);
      v[j][k]=x;
      v[k][j]=x;
    }
    memset(cyr,false,sizeof(cyr));
    u=0;
    memset(a,0,sizeof(a));
    cyr[1]=true;
    u++;
    a[u]=1;
    s=0;
    while (!((u>=n)||((s-max)>0.000001)))
    {
      min=10000000;
      for (i=1;i<=u;i++)
        for (j=1;j<=n;j++)
          if ((!cyr[j])&&(v[a[i]][j]>0))
            if (v[a[i]][j]<min)
            {
              min=v[a[i]][j];
              y=j;
            }
      u++;
      a[u]=y;
      cyr[y]=true;
      s=s+min;
    }
    if ((s-max)>0.000001) printf("Not enough cable\n");
      else printf("Need %.1lf miles of cable\n",s);
  }
  return 0;
}