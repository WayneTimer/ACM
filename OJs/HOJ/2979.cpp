/*This Code is Submitted by Timer for Problem 2979 at 2012-02-05 02:04:21*/
#include <cstdio>
#include <string.h>

using namespace std;

struct CYR
{
  int x;
  int y;
};

int h,t;
int a[105][105],f[105][105];
CYR b[55500];
int fa[55500];
CYR way[7];
int o;

bool check(int q,int w)
{
  if (q<0) return false;
  if (q>(h-1)) return false;
  if (w<0) return false;
  if (w>q) return false;
  if (a[q][w]==1) return false;
  if (f[q][w]==1) return false;
  return true;
}

void CLHS(int s)
{
  if (s>1) printf("Hurry up, You need %d minutes to escape!\n",s);
  else printf("Hurry up, You need 1 minute to escape!\n");
}

int main()
{
  int i,j,head,tail,x,y;
  char e;
  bool flag;
  memset(way,0,sizeof(way));
  way[1].x=-1;
  way[2].y=1;
  way[3].x=1;
  way[3].y=1;
  way[4].x=1;
  way[5].y=-1;
  way[6].x=-1;
  way[6].y=-1;
  o=0;
  while (scanf("%d%d",&h,&t)==2)
  {
    o++;
    if (o>1) printf("\n");
    printf("Maze #%d :\n",o);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(f,0,sizeof(f));
    memset(fa,0,sizeof(fa));
    for (i=0;i<h;i++)
      for (j=0;j<=i;j++)
      {
        do
        {
          scanf("%c",&e);
        } while ((e==' ')||(e=='\n'));
        if (e=='S')
        {
          a[i][j]=2;
          b[1].x=i;
          b[1].y=j;
          f[i][j]=1;
          continue;
        }
        if (e=='D')
        {
          a[i][j]=3;
          continue;
        }
        if (e=='*')
          a[i][j]=1;
      }
    head=0;
    tail=1;
    flag=true;
    if (t<1) 
    {
      printf("Oh No, I'm afraid that you don't have enough time to escape!\n");
      continue;
    }
    do
    {
      head++;
      for (i=1;i<=6;i++)
      {
        x=b[head].x+way[i].x;
        y=b[head].y+way[i].y;
        if (check(x,y))   
        {
          tail++;
          fa[tail]=fa[head]+1;
          if (a[x][y]==3) 
          {
            CLHS(fa[tail]);
            flag=false;
            break;
          }
          f[x][y]=1;
          b[tail].x=x;
          b[tail].y=y;
        }
      }
    } while ((flag)&&(tail>head)&&(fa[tail]<t));
    if (flag) printf("Oh No, I'm afraid that you don't have enough time to escape!\n");
  }
  return 0;
}