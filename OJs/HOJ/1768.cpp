/*This Code is Submitted by Timer for Problem 1768 at 2012-08-04 12:49:49*/
#include <cstdio>
#include <cstring>

using namespace std;

const int way[8][2]={{-1,0},{0,1},{1,0},{0,-1},
                     {-1,1},{1,1},{1,-1},{-1,-1}};
int n;
char map[15][15];
int a[15][15];
char out[15][15];

inline bool check(int x,int y)
{
  if (x<0) return false;
  if (x>=n) return false;
  if (y<0) return false;
  if (y>=n) return false;
  return true;
}

inline int cal(int x,int y)
{
  if (a[x][y]==-1) return -1;
  int xx,yy,i;
  int t;
  t=0;
  for (i=0;i<8;i++)
  {
    xx=x+way[i][0];
    yy=y+way[i][1];
    if (check(xx,yy))
    {
      if (a[xx][yy]==-1)
        t++;
    }
  }
  return t;
}

int main()
{
  int i,j,temp;
  bool f;
  bool flag;
  char e[15];
  f=false;
  while (scanf("%d",&n)==1)
  {
    if (f) printf("\n");
    f=true;
    getchar();
    memset(a,0,sizeof(a));
    memset(map,0,sizeof(map));
    for (i=0;i<n;i++)
    {
      gets(map[i]);
      for (j=0;j<n;j++)
      {
        if (map[i][j]=='*')
        {
          a[i][j]=-1;
        }
      }
    }
    flag=false;
    memset(out,0,sizeof(out));
    for (i=0;i<n;i++)
    {
      gets(e);
      for (j=0;j<n;j++)
        if (e[j]=='x')
        {
          temp=cal(i,j);
          if (temp==-1)
          {
            out[i][j]='*';
            flag=true;
          }
          else
            out[i][j]=temp+'0';
        }
        else 
          out[i][j]='.';
    }
    if (flag)
    {
      for (i=0;i<n;i++)
      {
        for (j=0;j<n;j++)
          if (map[i][j]=='*')
            out[i][j]='*';
        printf("%s\n",out[i]);
      }
    }
    else
    {
      for (i=0;i<n;i++)
        printf("%s\n",out[i]);
    }
  }
  return 0;
}