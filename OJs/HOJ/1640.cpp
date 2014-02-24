/*This Code is Submitted by Timer for Problem 1640 at 2013-02-02 16:32:10*/
//二维树状数组
#include <cstdio>
#include <cstring>

#define MAXN 1026

int c[MAXN][MAXN];
int n;

inline int lowbit(int x)
{
  return x&(-x);
}

inline void add(int x,int y,int v)
{
  int j;
  for (;x<=n;x+=lowbit(x))
    for (j=y;j<=n;j+=lowbit(j))
      c[x][j]+=v;
}

inline int sum(int x,int y)
{
  int j,t;
  t^=t;
  for (;x>0;x-=lowbit(x))
    for (j=y;j>0;j-=lowbit(j))
      t+=c[x][j];
  return t;
}

int main()
{
  int x1,y1,x2,y2;
  int t,op;
  while (scanf("%d",&op)==1)
  {
    scanf("%d",&n);
    memset(c,0,sizeof(c));
    while (scanf("%d",&op)==1 && op!=3)
    {
      if (op==1)
      {
        scanf("%d%d%d",&x1,&y1,&t);
        x1++;
        y1++;
        add(x1,y1,t);
      }
      else
      {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1++;
        y1++;
        x2++;
        y2++;
        t=sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);
        printf("%d\n",t);
      }
    }
  }
  return 0;
}