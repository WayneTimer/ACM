/*This Code is Submitted by Timer for Problem 2033 at 2013-02-01 10:05:46*/
#include <cstdio>
#include <cstring>

#define MAXN 50002

int n,m;
int a[MAXN];
int rank[MAXN];

inline int findset(int x)
{
  if (x==a[x]) return x;
  a[x]=findset(a[x]);
  return a[x];
}

inline void unionset(int x,int y)
{
  int fx,fy;
  fx=findset(x);
  fy=findset(y);
  if (fx==fy) return;
  if (rank[fx]>=rank[fy])
  {
    a[fy]=fx;
    if (rank[fx]==rank[fy])
      rank[fx]++;
  }
  else
    a[fx]=fy;
}

int main()
{
  int i,x,y,T;
  T^=T;
  while (scanf("%d%d",&n,&m)==2 && (n || m))
  {
    T++;
    for (i=1;i<=n;i++)
    {
      a[i]=i;
      rank[i]=1;
    }
    while (m--)
    {
      scanf("%d%d",&x,&y);
      unionset(x,y);
    }
    y^=y;
    for (i=1;i<=n;i++)
    {
      x=findset(a[i]);
      if (rank[x]!=-1)
      {
        rank[x]=-1;
        y++;
      }
    }
    printf("Case %d: %d\n",T,y);
  }
  return 0;
}