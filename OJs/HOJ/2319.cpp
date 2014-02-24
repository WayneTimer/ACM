/*This Code is Submitted by Timer for Problem 2319 at 2013-02-28 18:03:27*/
// 并查集
// 类似题： HOJ 1371 食物链
#include <cstdio>
#include <cstring>

int n,m;
int f[2010];
int b[2010];

int find(int x)
{
  if (x==f[x]) return x;
  f[x]=find(f[x]);
  return f[x];
}

inline bool work(int x,int y)
{
  int fx,fy;
  fx=find(x);
  fy=find(y);
  if (fx==fy) return true;
  if (b[fx])
  {
    b[fx]=find(b[fx]);
    if (fy<b[fx])
      f[b[fx]]=fy;
    else
      f[fy]=b[fx];
  }
  else b[fx]=fy;
  if (b[fy]) 
  {
    b[fy]=find(b[fy]);
    if (fx<b[fy])
      f[b[fy]]=fx;
    else
      f[fx]=b[fy];
  }
  else b[fy]=fx;
  return false;
}

int main()
{
  int T,o,x,y,i;
  bool flag;
  scanf("%d",&T);
  for (o=1;o<=T;o++)
  {
    flag=false;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
      f[i]=i;
      b[i]=0;
    }
    while (m--)
    {
      scanf("%d%d",&x,&y);
      if (!flag)
      {
        if (work(x,y))
          flag=true;
      }
    }
    printf("Scenario #%d:\n",o);
    if (flag)
      puts("Suspicious bugs found!");
    else
      puts("No suspicious bugs found!");
    puts("");
  }
  return 0;
}