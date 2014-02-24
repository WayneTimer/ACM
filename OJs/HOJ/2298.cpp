/*This Code is Submitted by Timer for Problem 2298 at 2013-03-09 15:02:23*/
// BFS
#include <cstdio>
#include <cstring>

struct eugin
{
  int x,y;
};

struct cyr
{
  int x,y,r;
  char e[60];
};

eugin w[4];
eugin s,e;
bool wall[7][7][7][7];
bool a[7][7];
cyr b[100];

inline bool check(cyr t1,cyr t2)
{
  if (t2.x<=0 || t2.x>6) return false;
  if (t2.y<=0 || t2.y>6) return false;
  if (!a[t2.x][t2.y]) return false;
  if (!wall[t1.x][t1.y][t2.x][t2.y]) return false;
  return true;
}

inline void BFS()
{
  int i,head,tail;
  cyr t1,t2;
  if (s.x==e.x && s.y==e.y)
  {
    puts("");
    return;
  }
  memset(a,true,sizeof(a));
  a[s.x][s.y]=false;
  b[1].x=s.x;
  b[1].y=s.y;
  b[1].r=0;
  b[1].e[0]='\0';
  head=0;
  tail=1;
  do
  {
    head++;
    t1.x=b[head].x;
    t1.y=b[head].y;
    for (i=0;i<4;i++)
    {
      t2.x=t1.x+w[i].x;
      t2.y=t1.y+w[i].y;
      if (check(t1,t2))
      {
        tail++;
        b[tail].x=t2.x;
        b[tail].y=t2.y;
        b[tail].r=b[head].r;
        strcpy(b[tail].e,b[head].e);
        if (i==0)
          b[tail].e[b[tail].r]='W';
        else if (i==1)
          b[tail].e[b[tail].r]='S';
        else if (i==2)
          b[tail].e[b[tail].r]='E';
        else b[tail].e[b[tail].r]='N';
        b[tail].r++;
        b[tail].e[b[tail].r]='\0';
        a[t2.x][t2.y]=false;
        if (t2.x==e.x && t2.y==e.y)
        {
          printf("%s\n",b[tail].e);
          return;
        }
      }
    }
  } while (head<tail);
}

int main()
{
  int x1,y1,x2,y2,i;
  memset(w,0,sizeof(w));
  w[0].x=-1;
  w[1].y=1;
  w[2].x=1;
  w[3].y=-1;
  scanf("%d%d",&s.x,&s.y);
  while (s.x || s.y)
  {
    scanf("%d%d",&e.x,&e.y);
    memset(wall,true,sizeof(wall));
    for (i=1;i<=3;i++)
    {
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      if (x1==x2)
      {
        if (x1>0 && x1<6)
        {
          if (y1>y2)
          {
            y1^=y2;
            y2^=y1;
            y1^=y2;
          }
          for (y1++;y1<=y2;y1++)
          {
            wall[x1][y1][x1+1][y1]=false;
            wall[x1+1][y1][x1][y1]=false;
          }
        }
      }
      else
      {
        if (y1>0 && y1<6)
        {
          if (x1>x2)
          {
            x1^=x2;
            x2^=x1;
            x1^=x2;
          }
          for (x1++;x1<=x2;x1++)
          {
            wall[x1][y1][x1][y1+1]=false;
            wall[x1][y1+1][x1][y1]=false;
          }
        }
      }
    }
    BFS();
    scanf("%d%d",&s.x,&s.y);
  }
  return 0;
}