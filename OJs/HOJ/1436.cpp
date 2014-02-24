/*This Code is Submitted by Timer for Problem 1436 at 2013-03-13 21:49:54*/
// 最短路 SPFA
#include <cstdio>
#include <cstring>

#define MAXN 102
#define INF 1061109567

int n;
int a[102][102];

void SPFA(int u)
{
  int i,k,mymax;
  int head,tail;
  bool used[MAXN];
  int dist[MAXN];
  int que[MAXN<<1];
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
    for (k=1;k<=n;k++)
      if (a[que[head]][k]!=-1)
        if (dist[que[head]]<dist[k]-a[que[head]][k])
        { 
          dist[k]=dist[que[head]]+a[que[head]][k];
          if (!used[k])
          {
            tail++;
            que[tail]=k;
            used[k]=true;
          }
        }
    used[que[head]]=false;
  } while (head<tail);
  mymax=-1;
  for (i=2;i<=n;i++)
    if (dist[i]<INF && dist[i]>mymax) mymax=dist[i];
  printf("%d\n",mymax);
}

int main()
{
  char e;
  int x,i,j;
  while (scanf("%d",&n)==1)
  {
    for (i=2;i<=n;i++)
      for (j=1;j<i;j++)
      {
        e=getchar();
        if (e=='x') x=-1;
        else
        {
          ungetc(e,stdin);
          scanf("%d",&x);
        }
        a[i][j]=x;
        a[j][i]=x;
        getchar();
      }
    SPFA(1);
  }
  return 0;
}