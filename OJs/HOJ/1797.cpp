/*This Code is Submitted by Timer for Problem 1797 at 2011-11-22 17:57:56*/
#include <stdio.h>
#include <string.h>

int main()
{
  int xx,yy,head,tail,x,y,w,h,i,j;
  int way[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
  int t[1001][2],b[21][21];
  char a[21][21];
  scanf("%d%d",&w,&h);
  while (!((w==0)&&(h==0)))
  {
    memset(a,0,sizeof(a));
    for (i=0;i<h;i++)
    {
      scanf("%s",a[i]);
      for (j=0;j<w;j++)
        if (a[i][j]=='@')
        {
          x=i;
          y=j;
        }
    }
    memset(t,0,sizeof(t));
    memset(b,0,sizeof(b));
    head=-1;
    tail=0;
    t[0][0]=x;
    t[0][1]=y;
    b[x][y]=1;
    do
    {
      head++;
      x=t[head][0];
      y=t[head][1];
      for (i=0;i<=3;i++)
      {
        xx=x+way[i][0];
        yy=y+way[i][1];
        if (xx<0) continue;
        if (yy<0) continue;
        if (xx>=h) continue;
        if (yy>=w) continue;
        if (a[xx][yy]=='#') continue;
        if (a[xx][yy]=='@') continue;
        if (b[xx][yy]) continue;
        tail++;
        t[tail][0]=xx;
        t[tail][1]=yy;
        b[xx][yy]=1;
      }
    }while (head<tail);
    printf("%d\n",head+1);
    scanf("%d%d",&w,&h);
  }
  return 0;
}