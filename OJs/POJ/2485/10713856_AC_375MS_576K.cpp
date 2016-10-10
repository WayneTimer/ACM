#include <cstdio>
#include <cstring>

#define MAXN 510
#define INF 20000000

using namespace std;

int n;
int d[MAXN][MAXN];
bool used[MAXN];
int mymin;
int que[MAXN];
int ans;

inline int qumin(int q,int w)
{
  if (q<=w) return q;
  return w;
}

inline void makeMST()
{
  int i,j,k;
  int tail;
  memset(used,false,sizeof(used));
  ans^=ans;
  que[1]=1;
  tail=1;
  used[1]=true;
  while (tail<n)
  {
    mymin=INF;
    for (i=1;i<=tail;i++)
      for (j=1;j<=n;j++)
        if ((!used[j]) && (que[i]!=j))
        {
          if (d[que[i]][j]<mymin)
          {
            k=j;
            mymin=d[que[i]][j];
          }
        }
    if (mymin!=INF)
      if (mymin>ans) ans=mymin;
    tail++;
    que[tail]=k;
    used[k]=true;
  }
}

int main()
{
  int T,i,j;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        scanf("%d",&d[i][j]);
    makeMST();
    printf("%d\n",ans);
  }
  return 0;
}