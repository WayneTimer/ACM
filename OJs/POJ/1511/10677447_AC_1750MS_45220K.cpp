#include <cstdio>
#include <cstring>

#define MAXN 1000010

using namespace std;

struct cyr
{
  int y;
  int v;
  int next;
};

cyr e[MAXN];
int n,m;
long long dist[MAXN];
int que[MAXN<<1];
bool used[MAXN];
int h[MAXN];
cyr e2[MAXN];
int h2[MAXN];

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
    i=h[que[head]];
    while (i!=-1)
    {
      if ((dist[que[head]]+e[i].v)<dist[e[i].y])
        {
          dist[e[i].y]=dist[que[head]]+e[i].v;
          if (!used[e[i].y])
          {
            tail++;
            que[tail]=e[i].y;
            used[e[i].y]=true;
          }
        }
    i=e[i].next;
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
    i=h2[que[head]];
    while (i!=-1)
    {
      if ((dist[que[head]]+e2[i].v)<dist[e2[i].y])
        {
          dist[e2[i].y]=dist[que[head]]+e2[i].v;
          if (!used[e2[i].y])
          {
            tail++;
            que[tail]=e2[i].y;
            used[e2[i].y]=true;
          }
        }
      i=e2[i].next;
    }
    used[que[head]]=false;
    head++;
  } while (head<=tail);
}

int main()
{
  int T,i,x,y,r,t;
  long long sum;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d%d",&n,&m);
    memset(e,-1,(m+1)*sizeof(cyr));
    memset(h,-1,(m+1)*sizeof(int));
    memset(e2,-1,(m+1)*sizeof(cyr));
    memset(h2,-1,(m+1)*sizeof(int));
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%d",&x,&y,&r);
      e[i].y=y;
      e[i].v=r;
      e[i].next=h[x];
      h[x]=i;
      e2[i].y=x;
      e2[i].v=r;
      e2[i].next=h2[y];
      h2[y]=i;
    }
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