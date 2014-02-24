/*This Code is Submitted by Timer for Problem 1030 at 2012-03-11 15:24:58*/
#include <cstdio>
#include <cstring>

using namespace std;

struct QS
{
  int x;
  int y;
};

int T;
int c,r;
QS way[4];
char a[1005][1005];
long max;
int dx,dy;

bool check(int g,int h)
{
  if (g>=r) return false;
  if (g<0) return false;
  if (h>=c) return false;
  if (h<0) return false;
  if (a[g][h]=='#') return false;
  return true;
}

void cyr(int x,int y,long dep)
{
  int i,xx,yy;
  if (dep>max) 
  {
    max=dep;
    dx=x;
    dy=y;
  }
  a[x][y]='#';
  for (i=0;i<4;i++)
  {
    xx=x+way[i].x;
    yy=y+way[i].y;
    if (check(xx,yy))
    {
      cyr(xx,yy,dep+1);
    }
  }
  a[x][y]='.';
}

int main()
{
  int p;
  long i,j;
  bool flag;
  memset(way,0,sizeof(way));
  way[0].y=1;
  way[1].x=1;
  way[2].y=-1;
  way[3].x=-1; 
  scanf("%d",&T);
  for (p=1;p<=T;p++)
  {
    scanf("%d %d",&c,&r);
    memset(a,0,sizeof(a));
    max=0;
    getchar();
    for (i=0;i<r;i++)
      gets(a[i]);
    flag=true;
    for (i=r-1;(i>=0)&&(flag);i--)
      for (j=0;j<c;j++)
        if (a[i][j]=='.')
          {
            cyr(i,j,0);
            cyr(dx,dy,0);
            flag=false;
            break;
          }
      printf("Maximum rope length is %ld.\n",max);
  }
  return 0;
}