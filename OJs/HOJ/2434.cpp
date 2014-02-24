/*This Code is Submitted by Timer for Problem 2434 at 2013-03-12 01:42:44*/
// SPFA
#include <cstdio>
#include <cstring>

#define MAXN 1010

int m,n;
bool e[MAXN][MAXN];
int dist[MAXN];
int a[MAXN];
int que[MAXN<<1];
bool used[MAXN];

void SPFA(int u)
{
  int i,k;
  int head,tail;
  head=0;
  tail=1;
  que[1]=u;
  memset(dist,0x3f,sizeof(dist));
  dist[u]=0;
  memset(used,false,sizeof(used));
  used[u]=true;
  do
  {
    head++;
    for (k=0;k<n;k++)
      if (e[que[head]][k])
        if (dist[que[head]]<dist[k]-1)
        { 
          dist[k]=dist[que[head]]+1;
          if (!used[k])
          {
            tail++;
            que[tail]=k;
            used[k]=true;
          }
        }
    used[que[head]]=false;
  } while (head<tail);
}

int main()
{
  int i,k,j;
  while (scanf("%d%d",&m,&n)==2)
  {
    if (!(n || m))
      break;
    memset(e,false,sizeof(e));
    while (m--)
    {
      scanf("%d",&k);
      for (i=1;i<=k;i++)
        scanf("%d",&a[i]);
      for (i=1;i<=k;i++)
        for (j=1;j<=k;j++)
          if (i!=j)
          {
            e[a[i]][a[j]]=true;
            e[a[j]][a[i]]=true;
          }
    }
    SPFA(0);
    if (dist[n-1]>2000) puts("I can never know wywcgs!");
    else if (dist[n-1]==1) puts("I do know wywcgs!");
    else printf("I can know wywcgs by at most %d person(s)!\n",dist[n-1]-1);
  }
  return 0;
}