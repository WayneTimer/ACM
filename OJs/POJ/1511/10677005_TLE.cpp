#include <cstdio>
#include <cstring>

#define MAXN 1000010

using namespace std;

struct cyr
{
  int x;
  int y;
  int v;
};

cyr e[MAXN];
int n,m;
long long dist[MAXN];
int que[MAXN<<1];
bool used[MAXN];

void SPFA(int u)
{
  int i,head,tail;
  memset(dist,0x7f,(n+1)*sizeof(long long));
  memset(used,false,(n+1)*sizeof(bool));
  dist[u]=0;
  used[u]=true;
  head=1;
  tail=1;
  que[1]=u;
  do
  {
    for (i=1;i<=m;i++)
      if (e[i].x==que[head])
        if ((dist[e[i].x]+e[i].v)<dist[e[i].y])
        {
          dist[e[i].y]=dist[e[i].x]+e[i].v;
          if (!used[e[i].y])
          {
            tail++;
            que[tail]=e[i].y;
            used[e[i].y]=true;
          }
        }
    used[que[head]]=false;
    head++;
  } while (head<=tail);
}

void SPFA2(int u)
{
  int i,head,tail;
  bool used[MAXN];
  memset(dist,0x7f,(n+1)*sizeof(long long));
  memset(used,false,sizeof(used));
  dist[u]=0;
  used[u]=true;
  head=1;
  tail=1;
  que[1]=u;
  do
  {
    for (i=1;i<=m;i++)
      if (e[i].y==que[head])
        if ((dist[e[i].y]+e[i].v)<dist[e[i].x])
        {
          dist[e[i].x]=dist[e[i].y]+e[i].v;
          if (!used[e[i].x])
          {
            tail++;
            que[tail]=e[i].x;
            used[e[i].x]=true;
          }
        }
    used[que[head]]=false;
    head++;
  } while (head<=tail);
}

int main()
{
  int T,i;
  long long sum;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
      scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].v);
    SPFA(1);
    sum=0;
    for (i=2;i<=n;i++)
      sum+=dist[i];
    SPFA2(1);
    for (i=2;i<=n;i++)
      sum+=dist[i];
    printf("%lld\n",sum);
  }
  return 0;
}