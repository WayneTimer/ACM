/*This Code is Submitted by Timer for Problem 2686 at 2013-01-30 01:51:00*/
#include <cstdio>
#include <cstring>

#define MAX 200

int c[201][201][201];
int x1,y1,z1,x2,y2,z2;
int v;

inline int lowbit(int x)
{
  return (x&(-x));
}

inline void add(int x,int y,int z)
{
  int t1,t2;
  t1=y;
  t2=z;
  while (x<=MAX)
  {
    y=t1;
    while (y<=MAX)
    {
      z=t2;
      while (z<=MAX)
      {
        c[x][y][z]+=v;
        z+=lowbit(z);
      }
      y+=lowbit(y);
    }
    x+=lowbit(x);
  }
}

inline int sum(int x,int y,int z)
{
  int ans,t1,t2;
  ans^=ans;
  t1=y;
  t2=z;
  while (x>0)
  {
    y=t1;
    while (y>0)
    {
      z=t2;
      while (z>0)
      {
        ans+=c[x][y][z];
        z-=lowbit(z);
      }
      y-=lowbit(y);
    }
    x-=lowbit(x);
  }
  return ans;
}

int main()
{
  char op[10];
  int m;
  while (scanf("%d",&m)==1)
  {
    memset(c,0,sizeof(c));
    while (m--)
    {
      scanf("%s",op);
      scanf("%d%d%d",&x1,&y1,&z1);
      if (op[0]=='A')
      {
        scanf("%d%d%d%d",&x2,&y2,&z2,&v);
        add(x1,y1,z1);
        add(x1,y2+1,z2+1);
        add(x2+1,y2+1,z1);
        add(x2+1,y1,z2+1);
        v=-v;
        add(x1,y1,z2+1);
        add(x1,y2+1,z1);
        add(x2+1,y1,z1);
        add(x2+1,y2+1,z2+1);
      }
      else
        printf("%d\n",sum(x1,y1,z1));
    }
  }
  return 0;
}