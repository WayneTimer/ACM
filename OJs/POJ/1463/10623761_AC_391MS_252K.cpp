#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const short maxn=1501;

struct cyr
{
  short t;
  vector <int> c;
};

int n;
short f[maxn][2];
cyr a[maxn];
bool nofa[maxn];

inline int fmin(int x,int y)
{
  if (x<=y) return x;
  return y;
}

void DFS(int u)
{
  int i;
  for (i=0;i<a[u].t;i++)
    DFS(a[u].c[i]);
  for (i=0;i<a[u].t;i++)
  {
    f[u][0]+=f[a[u].c[i]][1];
    f[u][1]+=fmin(f[a[u].c[i]][0],f[a[u].c[i]][1]);
  }
  f[u][1]+=1;
}

int main()
{
  int i,x,y,j,e,root;
  while (scanf("%d",&n)==1)
  {
    for (i=0;i<n;i++)
    {  
      a[i].t^=a[i].t;
      a[i].c.clear();
    }
    memset(f,0,sizeof(f));
    memset(nofa,true,sizeof(nofa));
    for (i=0;i<n;i++)
    {
      scanf("%d:(%d)",&x,&y);
      a[x].t=y;
      for (j=1;j<=y;j++)
      {
        scanf("%d",&e);
        a[x].c.push_back(e);
        nofa[e]=false;
      }
    }
    for (i=0;i<n;i++)
    {
      if (nofa[i])
      {
        root=i;
        break;
      }
    }
    DFS(root);
    x=f[root][0];
    if (f[root][1]<x) x=f[root][1];
    printf("%d\n",x);
  }
  return 0;
}