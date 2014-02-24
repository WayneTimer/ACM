/*This Code is Submitted by Timer for Problem 2385 at 2013-02-01 14:17:50*/
//并查集，与 NOI2002-银河英雄传说 基本相同
#include <cstdio>

#define MAXN 30002

int a[MAXN];
int rank[MAXN];
int b[MAXN];

inline int findset(int x)
{
  if (x==a[x]) return x;
  int t;
  t=a[x];
  a[x]=findset(a[x]);
  b[x]+=b[t];
  return a[x];
}

inline void unionset(int x,int y)
{
  int fx,fy;
  fx=findset(x);
  fy=findset(y);
  if (fx==fy) return;
  b[fy]=rank[fx];
  rank[fx]+=rank[fy];
  a[fy]=fx;
}

int main()
{
  char op[10];
  int x,y,p,i;
  while (scanf("%d",&p)==1)
  {
    for (i=1;i<MAXN;i++)
    {
      a[i]=i;
      rank[i]=1;
      b[i]^=b[i];
    }
    while (p--)
    {
      scanf("%s",op);
      scanf("%d",&x);
      if (op[0]=='M')
      {
        scanf("%d",&y);
        unionset(x,y);
      }
      else
      {
        y=findset(x);
        printf("%d\n",rank[y]-b[x]-1);
      }
    }
  }
  return 0;
}