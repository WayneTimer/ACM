/*This Code is Submitted by Timer for Problem 3069 at 2012-08-16 20:45:20*/
#include <cstdio>
#include <cstring>

char map[201][201];
int dian[201][201];
int link[100];
bool cover[201];

bool find(int i,int u)
{
  int k,q;
  for (k=1;k<=u;k++)
    if ((map[i][k])&&(!(cover[k])))
    {
      q=link[k];
      link[k]=i;
      cover[k]=1;
      if ((q==0)||(find(q,u))) return true;
      link[k]=q;
    }
  return false;
}

int main()
{
  int a[201][201];
  int n,m,i,j,k,x,y,u,s;
  char e;
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(map,0,sizeof(map));
    memset(a,0,sizeof(a));
    memset(link,0,sizeof(link));
    getchar();
    k=0;
    for (i=1;i<=n;i++)
    {
      for (j=1;j<=m;j++)
      {
        e=getchar();
        if (e=='P') a[i][j]=1;
        if (e=='W') 
        {
          a[i][j]=2;
          k++;
          dian[i][j]=k;
        }
      }
      getchar();
    }
    u=k;
    k=0;
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
        if (a[i][j]==1)
        {
          k++;
          x=i-1;
          y=j;
          if (x>=1) 
            if (a[x][y]==2) map[k][dian[x][y]]=1;
          x=i+1;
          if (x<=n)
            if (a[x][y]==2) map[k][dian[x][y]]=1;
          x=i;
          y=j-1;
          if (y>=1)
            if (a[x][y]==2) map[k][dian[x][y]]=1;
          y=j+1;
          if (y<=m)
            if (a[x][y]==2) map[k][dian[x][y]]=1;
        }
      }
    for (i=1;i<=k;i++)
    {
      memset(cover,false,sizeof(cover));
      find(i,u);
    }
    s=0;
    for (i=1;i<=u;i++)
    {
      if (link[i]!=0) s++;
    }
    printf("%d\n",s);
  }
  return 0;
}