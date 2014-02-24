/*This Code is Submitted by Timer for Problem 1097 at 2011-12-03 14:33:54*/
#include <stdio.h>
#include <string.h>

typedef struct mmap
{
  int x;
  int y;
  int d;
} MAP;

int main()
{
  int xx,yy,ff,head,tail,i,j,n,m,e,x,y,d;
  MAP f[100000];
  long s[100000];
  int a[51][51],b[51][51][5];
  char r[20];
  int b1,b2,e1,e2;
  scanf("%d%d",&n,&m);
  while (!((n==0)&&(m==0)))
  {
    memset(a,0,sizeof(a));
    memset(r,0,sizeof(r));
    memset(s,0,sizeof(s));
    memset(f,0,sizeof(f));
    memset(b,0,sizeof(b));
    ff=0;
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
        scanf("%d",&e);
        if (e)
        {
          a[i][j]=1;
          a[i-1][j]=1;
          a[i][j-1]=1;
          a[i-1][j-1]=1;
        }
      }
    scanf("%d%d%d%d %s",&b1,&b2,&e1,&e2,r);
    f[1].x=b1;
    f[1].y=b2;
    if (a[e1][e2]==1) 
    {
      printf("-1\n");
      ff=1;
    }
    if (a[b1][b2]==1) 
    {
      printf("-1\n");
      ff=1;
    }
    a[e1][e2]=2;
    if (r[0]=='n') f[1].d=1;
    if (r[0]=='e') f[1].d=2;
    if (r[0]=='s') f[1].d=3;
    if (r[0]=='w') f[1].d=4;
    b[b1][b2][f[1].d]=1;
    head=0;
    tail=1;
    if ((b1==e1)&&(b2==e2))
    {
      printf("0\n");
      ff=1;
    }
    while ((head<tail)&&(ff==0))
    {
      head++;
      for (i=1;i<=5;i++)
      {
        if (i==1)
        {
          e=f[head].d-1;
          if (e<=0) e=4;
          x=f[head].x;
          y=f[head].y;
          if (!(b[x][y][e]))
          {
            tail++;
            s[tail]=s[head]+1;
            b[x][y][e]=1;
            f[tail].x=x;
            f[tail].y=y;
            f[tail].d=e;
          }
        }
        if (i==2)
        {
          e=f[head].d+1;
          if (e>=5) e=1;
          x=f[head].x;
          y=f[head].y;
          if (!(b[x][y][e]))
          {
            tail++;
            s[tail]=s[head]+1;
            b[x][y][e]=1;
            f[tail].x=x;
            f[tail].y=y;
            f[tail].d=e;
          }
        }
        if (i==3)
        {
          e=f[head].d;
          x=f[head].x;
          y=f[head].y;
          if (e==1) x--;
          if (e==2) y++;
          if (e==3) x++;
          if (e==4) y--;
          if ((x<=0)||(x>=n)||(y<=0)||(y>=m)) continue;
          if (a[x][y]==1) continue;
          if (b[x][y][e]==1) continue;
          tail++;
          s[tail]=s[head]+1;
          b[x][y][e]=1;
          f[tail].x=x;
          f[tail].y=y;
          f[tail].d=e;
        }
        if (i==4)
        {
          e=f[head].d;
          x=f[head].x;
          y=f[head].y;
          if (e==1) x=x-2;
          if (e==2) y=y+2;
          if (e==3) x=x+2;
          if (e==4) y=y-2;
          if ((x<=0)||(x>=n)||(y<=0)||(y>=m)) continue;
          if (a[x][y]==1) continue;
          if (b[x][y][e]==1) continue;
          tail++;
          s[tail]=s[head]+1;
          b[x][y][e]=1;
          f[tail].x=x;
          f[tail].y=y;
          f[tail].d=e;
        }
        if (i==5)
        {
          e=f[head].d;
          x=f[head].x;
          y=f[head].y;
          if (e==1) x=x-3;
          if (e==2) y=y+3;
          if (e==3) x=x+3;
          if (e==4) y=y-3;
          if ((x<=0)||(x>=n)||(y<=0)||(y>=m)) continue;
          if (a[x][y]==1) continue;
          if (b[x][y][e]==1) continue;
          xx=x;
          yy=y;
          if (e==1) xx=x+1;
          if (e==2) yy=y-1;
          if (e==3) xx=x-1;
          if (e==4) yy=y+1;
          if (a[xx][yy]==1) continue;
          tail++;
          s[tail]=s[head]+1;
          b[x][y][e]=1;
          f[tail].x=x;
          f[tail].y=y;
          f[tail].d=e;
        }
        x=f[tail].x;
        y=f[tail].y;
        e=f[tail].d;
        if (a[x][y]==2) 
        {
          printf("%ld\n",s[tail]);
          ff=1;
          break;
        }
      }
    }
    if (!(ff)) printf("-1\n");
    scanf("%d%d",&n,&m);
  }
  return 0;
}