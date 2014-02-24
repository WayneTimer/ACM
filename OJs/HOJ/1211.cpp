/*This Code is Submitted by Timer for Problem 1211 at 2012-02-09 21:54:58*/
#include <cstdio>
#include <cstring>
#define MAXV 5000000

using namespace std;

int T,o;
long v[101][101];
int n,e;

int main()
{
  int i,j,k,x,y;
  long s,t;
  while (scanf("%d",&T)==1)
  {
    for (o=1;o<=T;o++)
    {
      scanf("%d%d",&n,&e);
      for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
          v[i][j]=MAXV;
          v[j][i]=MAXV;
        }
      for (i=1;i<=e;i++)
      {
        scanf("%d%d%ld",&x,&y,&s);
        v[x][y]=s;
        v[y][x]=s;
      }
      for (k=0;k<n;k++)
        for (j=0;j<n;j++)
          for (i=0;i<n;i++)
          {
            if ((i!=j)&&(i!=k)&&(j!=k))
            {
              if (v[i][k]==MAXV) continue;
              if (v[j][k]==MAXV) continue;
              if (v[i][j]==MAXV) 
              {
                v[i][j]=v[i][k]+v[j][k];
                v[j][i]=v[i][j];
                continue;
              }
              t=v[i][k]+v[j][k];
              if (t<v[i][j]) 
              {
                v[i][j]=t;
                v[j][i]=t;
              }
            }
          }
      s=MAXV;
      for (i=0;i<n;i++)
      {
        t=0;
        for (j=0;j<n;j++)
          if (i!=j) 
          {
            t=t+v[i][j];
          }
        if (t<s) 
        {
          s=t;
          y=i;
        }
      }
      printf("%d %ld\n",y,s);
    }
  }
  return 0;
}