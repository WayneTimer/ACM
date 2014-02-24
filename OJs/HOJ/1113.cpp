/*This Code is Submitted by Timer for Problem 1113 at 2012-02-11 22:56:20*/
#include <cstdio>
#include <cstring>

#define MAXB 1061109567

using namespace std;

int a[110][110];
int b[110];
bool mark[1001];
int n,p;

void dij(int x)
{
  int i,j,k;
  int min;
  memset(mark,false,sizeof(mark));
  for (i=1;i<=n;i++)
    if (a[x][i]!=0) b[i]=a[x][i];
  for (i=1;i<=n;i++)
  {
    min=MAXB;
    for (j=1;j<=n;j++)
      if ((!mark[j])&&(b[j]<min))
      {
        min=b[j];
        k=j;
      }
    mark[k]=true;
    for (j=1;j<=n;j++)
      if (a[k][j]!=0)
      {
        if ((b[k]+a[k][j])<b[j])
          b[j]=b[k]+a[k][j];
      }
  }
}

int main()
{
  int u,x,y,j,i;
  int max,t;
  bool flag;
  scanf("%d",&n);
  while (n!=0) 
  {
    max=0;
    memset(a,0,sizeof(a));
    for (u=1;u<=n;u++)
    {
      scanf("%d",&p);
      for (j=1;j<=p;j++)
      {
        scanf("%d%d",&x,&y);
        a[u][x]=y;
      }
    }
      for (i=1;i<=n;i++)
      {
        memset(b,0x3f,sizeof(b));
        flag=true;
        dij(i);
        t=0;
        for (j=1;j<=n;j++)
          if (i!=j) 
            if (b[j]==MAXB) 
            {
              flag=false;
              break;
            }
            else
              if (t<b[j]) t=b[j];
        if (flag)
          if ((max==0)||(t<max))
          { 
            max=t;
            y=i;
          }
      }
      if (max==0) printf("disjoint\n");
        else printf("%d %d\n",y,max);    
    scanf("%d",&n);
  }
  return 0;
}