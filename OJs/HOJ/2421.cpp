/*This Code is Submitted by Timer for Problem 2421 at 2013-04-16 21:55:10*/
#include <cstdio>
#include <cstring>

#define MAXN (1<<11)

struct eugin
{
  int x,y,s;//x-状态,y-停在第y个点,s-路程长度
};

int a[11][11];
int n;
int h[MAXN][11];//记录在某一状态下到达某一点的最短路程长度
eugin b[MAXN*20];

inline void BFS()
{
  int i,head,tail;
  eugin t;
  memset(h,0,sizeof(h));
  head=0;
  tail=1;
  b[1].x=0;
  b[1].y=0;
  b[1].s=0;
  do
  {
    head++;
    for (i=0;i<=n;i++)
      if (i!=b[head].y)
      {
        t.x=b[head].x|(1<<i);
        t.y=i;
        t.s=b[head].s+a[b[head].y][i];
        if (h[t.x][t.y]==0 || t.s<h[t.x][t.y])
        {
          tail++;
          b[tail]=t;
          h[t.x][t.y]=t.s;
        }
      }
  } while (head<tail);
  printf("%d\n",h[t.x][0]);
}

int main()
{
  int i,j;
  scanf("%d",&n);
  while (n)
  {
    for (i=0;i<=n;i++)
      for (j=0;j<=n;j++)
        scanf("%d",&a[i][j]);
    BFS();
    scanf("%d",&n);
  }
  return 0;
}