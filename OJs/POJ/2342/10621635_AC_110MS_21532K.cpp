#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=6001;

struct cyr
{
  int fa;
  int v;
  int t;
  int c[900];
};

cyr a[maxn];
int max,n;
int f[maxn][2];

inline int fmax(int x,int y)
{
  if (x>=y) return x;
  return y;
}

void DP(int x)
{
  int i;
  for (i=1;i<=a[x].t;i++)
    DP(a[x].c[i]);
  for (i=1;i<=a[x].t;i++)
  {
    f[x][1]+=f[a[x].c[i]][0];
    f[x][0]+=fmax(f[a[x].c[i]][0],f[a[x].c[i]][1]);
  }
  f[x][1]+=a[x].v;
}

int main()
{
  int i,x,y,root;
  memset(a,0,sizeof(a));
  memset(f,0,sizeof(f));
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d",&a[i].v);
  scanf("%d%d",&x,&y);
  while (x||y)
  {
    a[x].fa=y;
    a[y].t++;
    a[y].c[a[y].t]=x;
    scanf("%d%d",&x,&y);
  }
  max=-999999;
  for (i=1;i<=n;i++)
  {
    if (a[i].fa==0)
    {
      root=i;
      break;
    }
  }
  DP(root);
  max=f[root][0];
  if (f[root][1]>max) max=f[root][1];
  printf("%d\n",max);
  return 0;
}