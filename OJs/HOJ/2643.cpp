/*This Code is Submitted by Timer for Problem 2643 at 2013-09-26 20:01:14*/
//BFS
#include <cstdio>
#include <cstring>

#define MAXN 1030

struct eugin
{
  int x,y;
};

int a[MAXN][MAXN];
bool b[MAXN][MAXN];
int n,m,s;
int w[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
eugin f[MAXN*MAXN];

inline void init()
{
  int i,j;
  char str[1030];
  for (i=1;i<=n;i++)
  {
    scanf("%s",str);
    for (j=0;j<m;j++)
      if (str[j]=='0')
        a[i][j+1]=0;
      else
        a[i][j+1]=1;
  }
  memset(b,true,sizeof(b));
}

inline bool check(int x,int y)
{
  if (x<1) return false;
  if (x>n) return false;
  if (y<1) return false;
  if (y>m) return false;
  return true;
}

inline void BFS()
{
  int i,j,k,head,tail;
  int x,y;
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      if (!a[i][j] && b[i][j])
      {
        head=0;
        tail=1;
        f[1].x=i;
        f[1].y=j;
        b[i][j]=false;
        do
        {
          head++;
          for (k=0;k<4;k++)
          {
            x=f[head].x+w[k][0];
            y=f[head].y+w[k][1];
            if (check(x,y) && !a[x][y] && b[x][y])
            {
              tail++;
              f[tail].x=x;
              f[tail].y=y;
              b[x][y]=false;
            }
          }
        } while (head<tail);
        if (tail<s)
        {
          while (tail>0)
          {
            a[f[tail].x][f[tail].y]=1;
            tail--;
          }
        }
      }
}

inline void output()
{
  int i,j;
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=m;j++)
      printf("%d",a[i][j]);
    puts("");
  }
  puts("");
}

int main()
{
  scanf("%d",&n);
  while (n)
  {
    scanf("%d%d",&m,&s);
    init();
    BFS();
    output();
    scanf("%d",&n);
  }
  return 0;
}