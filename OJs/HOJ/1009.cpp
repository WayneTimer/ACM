/*This Code is Submitted by Timer for Problem 1009 at 2012-02-05 16:52:07*/
#include <cstdio>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct CYR
{
  int x;
  int y;
};

int n,m;
long a[101][101];
int q,w;
CYR way[5];

bool check(int x,int y)
{
  if (x<0) return false;
  if (x>=n) return false;
  if (y<0) return false;
  if (y>=m) return false;
  if (a[x][y]==0) return false;
  return true;
}

int main()
{
  int i,j,g,h,x,y,max,gg,hh;
  long s,sum;
  bool flag;
  memset(way,0,sizeof(way));
  way[1].x=-1;
  way[2].y=1;
  way[3].x=1;
  way[4].y=-1;
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(a,0,sizeof(a));
    for (i=0;i<n;i++)
      for (j=0;j<m;j++)
        scanf("%ld",&a[i][j]);
    scanf("%d%d",&q,&w);
    x=0;
    y=0;
    sum=0;
    flag=true;
    a[0][0]=0;
    do 
    {
      max=-1;
      for (i=1;i<=4;i++)
      {
        g=x+way[i].x;
        h=y+way[i].y;
        if (check(g,h))
        {
          if (a[g][h]>max)
          {
            max=a[g][h];
            gg=g;
            hh=h;
          }
        }
      }
      if (max==-1) break;
      x=gg;
      y=hh;
      a[x][y]=0;
      sum++;
      s=labs(x-q)+labs(y-w);
      if (s<=sum) 
      {
        printf("%ld\n",sum);
        flag=false;
      }
    } while (flag);
    if (flag) printf("impossible\n");
  }
  return 0;
}