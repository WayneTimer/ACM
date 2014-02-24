/*This Code is Submitted by Timer for Problem 1130 at 2012-08-14 17:17:51*/
#include <cstdio>
#include <cstring>
#include <cmath>

#define MAXN 32
#define INF 1061109567

using namespace std;

struct cyr
{
  int a;
  int b;
};

int n,m;
int dist[MAXN];
double v[MAXN];
cyr e[(MAXN*MAXN)<<1];

void SPFA(int u)
{
  int i,j;
  int que[200];
  bool used[MAXN];
  int head,tail;
  dist[u]=0;
  head=1;
  tail=1;
  que[head]=u;
  memset(used,false,sizeof(used));
  used[u]=true;
  do
  {
    for (j=1;j<=m;j++)
      if (e[j].a==que[head])
        if ((dist[e[j].a]+1)<dist[e[j].b])
        {
          dist[e[j].b]=dist[e[j].a]+1;
          if (!used[e[j].b])
          {
            tail++;
            que[tail]=e[j].b;
            used[e[j].b]=true;
          }
        }
    used[que[head]]=false;
    head++;
  } while (head<=tail);
}

int main()
{
  int i,t,j,u;
  char str[64];
  double in,max;
  while (scanf("%d",&n)==1)
  {
    memset(dist,0x3f,sizeof(dist));
    m=0;
    for (i=1;i<=n;i++)
    {
      scanf("%s",str);
      t=str[0]-'A'+1;
      scanf("%lf",&in);
      v[t]=in;
      scanf("%s",str);
      j=0;
      while (str[j])
      {
        m++;
        e[m].a=t;
        if (str[j]=='*')
        {
         // dist[t]=1;
          e[m].b=0;
          m++;
          e[m].a=0;
          e[m].b=t;
        }
        else
        {
          u=str[j]-'A'+1;
          e[m].b=u; 
        }
        j++;
      }
    }
    SPFA(0);
    max=0;
    for (i=1;i<=26;i++)
    {
      if (dist[i]!=INF)
      {
        if (dist[i]<=1) in=v[i];
          else in=v[i]*pow(0.95,(dist[i]-1));
        if (in>max)
        {
          max=in;
          t=i;
        }
      }
    }
    printf("Import from %c\n",'A'+t-1);
  }
  return 0;
}