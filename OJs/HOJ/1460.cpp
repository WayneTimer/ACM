/*This Code is Submitted by Timer for Problem 1460 at 2012-02-15 14:35:09*/
#include <cstdio>
#include <cstring>

using namespace std;

char name[201][50];
int v[201][201];
int b[201];
bool mark[201];
int n,m,p,o;

int sub(int x,int y)
{
  if (x<y) return x;
    else return y;
}

void cyr(int x,int y)
{
  int i,j,k,t;
  int min;
  memset(mark,false,sizeof(mark));
  mark[x]=true;
  for (i=1;i<=n;i++)
    if (v[x][i]!=0)
      b[i]=v[x][i];
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
    for (j=1;j<=n;j++)
      if (v[k][j]!=0)
      {
        t=sub(b[k],v[k][j]);
        if (t>b[j]) b[j]=t;
      }
  }
}
 
int main()
{
  char e1[50];
  int u,i,x,y,r;
  bool flag;
  p=0;
  scanf("%d%d",&n,&m);
  while (!((n==0)&&(m==0)))
  {
    u=0;
    p++;
    memset(name,0,sizeof(name));
    memset(v,0,sizeof(v));
    memset(b,0,sizeof(b));
    for (o=1;o<=m;o++)
    {
      scanf("%s",e1);
      flag=true;
      for (i=1;i<=u;i++)
        if (strcmp(e1,name[i])==0)
        {
          flag=false;
          x=i;
          break;
        }
      if (flag) 
      {
        u++;
        strcpy(name[u],e1);
        x=u;
      }
      scanf("%s",e1);
      flag=true;
      for (i=1;i<=u;i++)
        if (strcmp(e1,name[i])==0)
        {
          flag=false;
          y=i;
          break;
        }
      if (flag)
      {
        u++;
        strcpy(name[u],e1);
        y=u;
      }
      scanf("%d",&r);
      v[x][y]=r;
      v[y][x]=r;
    }
    scanf("%s",e1);
    for (i=1;i<=n;i++)
      if (strcmp(e1,name[i])==0)
      {
        x=i;
        break;
      }
    scanf("%s",e1);
    for (i=1;i<=n;i++)
      if (strcmp(e1,name[i])==0)
      {
        y=i;
        break;
      }
    cyr(x,y);
    printf("Scenario #%d\n",p);
    printf("%d tons\n",b[y]);
    printf("\n");
    scanf("%d%d",&n,&m);
  }
  return 0;
}