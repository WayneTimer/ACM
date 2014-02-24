/*This Code is Submitted by Timer for Problem 2581 at 2013-09-26 14:18:09*/
//BFS
#include <cstdio>
#include <cstring>

#define MAXN 22

struct eugin
{
  int x,y;
};

int a[MAXN][MAXN];
int n,s1,s2;
int sum1,sum2;
int w[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
eugin b[10000];

inline bool check(int x,int y)
{
  if (x<1) return false;
  if (x>n) return false;
  if (y<1) return false;
  if (y>n) return false;
  return true;
}

inline void BFS()
{
  int i,j,k,head,tail,flag,x,y,t;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      if (!a[i][j])
      {
        head=0;
        tail=1;
        flag=0;
        b[1].x=i;
        b[1].y=j;
        a[i][j]=-1;
        t=1;
        do
        {
          head++;
          for (k=0;k<4;k++)
          {
            x=b[head].x+w[k][0];
            y=b[head].y+w[k][1];
            if (check(x,y))
            {
              if (!a[x][y])
              {
                tail++;
                b[tail].x=x;
                b[tail].y=y;
                a[x][y]=-1;
                t++;
                continue;
              }
              if (flag!=-1 && a[x][y]!=-1)
              {
                if (!flag)
                  flag=a[x][y];
                else
                  if (flag!=a[x][y])
                    flag=-1;
              }
            }
          }
        } while (head<tail);
        if (flag==1) sum1+=t;
        else if (flag==2) sum2+=t;
      }
}

int main()
{
  int i,x,y;
  scanf("%d",&n);
  while (n)
  {
    memset(a,0,sizeof(a));
    scanf("%d%d",&s1,&s2);
    for (i=1;i<=s1;i++)
    {
      scanf("%d%d",&x,&y);
      a[x][y]=1;
    }
    for (i=1;i<=s2;i++)
    {
      scanf("%d%d",&x,&y);
      a[x][y]=2;
    }
    sum1=0;
    sum2=0;
    BFS();
    if (sum1==sum2)
      puts("Draw");
    else if (sum1>sum2)
      printf("Black wins by %d\n",sum1-sum2);
    else
      printf("White wins by %d\n",sum2-sum1);
    scanf("%d",&n);
  }
  return 0;
}