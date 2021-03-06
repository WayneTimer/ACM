#include <cstdio>
#include <cstring>

#define MAXN 10010

struct edge
{
  int x,y;
};

int n,qx,qy;
int h[MAXN];
edge e[MAXN];
int s[MAXN];//set
int fa[MAXN];
bool used[MAXN];
bool f1,f2;

int findset(int x)
{
  if (x==s[x]) return x;
  s[x]=findset(s[x]);
  return s[x];
}

inline void unionset(int x,int y)
{
  s[x]=y;
}

bool TarjanDFS(int u)
{
  s[u]=u;
  used[u]=true;
  if (u==qx) f1=true;
  else if (u==qy) f2=true;
  if (f1 && f2)
  {
    if (qx==u)
    {
      printf("%d\n",findset(s[qy]));
      return true;
    }
    else
    {
      printf("%d\n",findset(s[qx]));
      return true;
    }
  }
  int k,fx,fy;
  k=h[u];
  fy=findset(u);
  while (k!=-1)
  {
    if (TarjanDFS(e[k].x)) return true;
    fx=findset(e[k].x);
    unionset(fx,fy);
    k=e[k].y;
  }
  return false;
}

int main()
{
  int T,i,x,y;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d",&n);
    memset(h,-1,sizeof(h));
    memset(fa,0,sizeof(fa));
    for (i=1;i<n;i++)
    {
      scanf("%d%d",&x,&y);
      e[i].x=y;
      e[i].y=h[x];
      h[x]=i;
      fa[y]=x;
    }
    for (i=1;i<=n;i++)
      if (!fa[i])
	break;
    scanf("%d%d",&qx,&qy);
    memset(used,false,sizeof(used));
    f1=false;
    f2=false;
    TarjanDFS(i);
  }
  return 0;
}