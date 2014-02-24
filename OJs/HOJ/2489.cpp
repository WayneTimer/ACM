/*This Code is Submitted by Timer for Problem 2489 at 2012-08-30 16:52:07*/
#include <cstdio>
#include <cstring>

int n,m,start,x,y,xx,yy;
char a[12][12];
int b[12][12];

inline int check(char op)
{
  if (op=='N')
  {
    xx=x-1;
    yy=y;
  }
  else
  if (op=='S')
  {
    xx=x+1;
    yy=y;
  } 
  else
  if (op=='E')
  {
    xx=x;
    yy=y+1;
  }
  else
  if (op=='W')
  {
    xx=x;
    yy=y-1;
  }
  if (xx<0) return 1;
  if (xx>=n) return 1;
  if (yy<0) return 1;
  if (yy>=m) return 1;
  if (b[xx][yy]) return 2;
  return 0;
}

int main()
{
  int i,u;
  scanf("%d%d%d",&n,&m,&start);
  while (n||m||start)
  {
    gets(a[0]);
    for (i=0;i<n;i++)
      gets(a[i]);
    memset(b,0,sizeof(b));
    x=0;
    y=start-1;
    b[x][y]=1;
    u=check(a[x][y]);
    while (u<1)
    {
      b[xx][yy]=b[x][y]+1;
      x=xx;
      y=yy;
      u=check(a[x][y]);
    }
    if (u==1)
      printf("%d step(s) to exit\n",b[x][y]);
    else
      printf("%d step(s) before a loop of %d step(s)\n",b[xx][yy]-1,b[x][y]-b[xx][yy]+1);
    scanf("%d%d%d",&n,&m,&start);
  }
  return 0;
}