#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

#define MAXM 1002
#define MAXN 20010

struct cyr
{
  int y;
  int next;
};

int out[MAXN];
cyr e[MAXM*MAXM];
int h[MAXN];
int n,ge;
int mynew,ind;
int dfn[MAXN];
int low[MAXN];
int id[MAXN];
stack <int> sta;
int top;
bool insta[MAXN];

inline int qumin(int q,int w)
{
  if (q<=w) return q;
  return w;
}

void tarjan(int v)
{
  int i,k,temp;
  ind++;
  dfn[v]=ind;
  low[v]=ind;
  sta.push(v);
  insta[v]=true;
  temp=h[v];
  while (temp!=-1)
  {
    k=e[temp].y;
    if (dfn[k]==0)
    {
      tarjan(k);
      low[v]=qumin(low[v],low[k]);
    }
    else
      if (insta[k])
        low[v]=qumin(low[v],dfn[k]);
    temp=e[temp].next;
  }
  if (dfn[v]==low[v])
  {
    mynew++;
    do
    {
      k=sta.top();
      sta.pop();
      insta[k]=false;
      id[k]=mynew;
    } while (v!=k);
  }
}

void solve()
{
  int j,i,t,ne,k;
  memset(dfn,0,sizeof(dfn));
  memset(low,0,sizeof(low));
  memset(id,0,sizeof(id));
  memset(insta,false,sizeof(insta));
  mynew=0;
  ind=0;
  while (!sta.empty())
    sta.pop();
  for (i=1;i<=ge;i++) 
    if (dfn[i]==0)
      tarjan(i);
  for (i=1;i<=n;i++)
  {
    ne=h[i];
    t=-1;
    while (ne!=-1)
    {
      k=e[ne].y;
      if (id[i]==id[k])
      {
        t++;
        out[t]=k-n;
      }
      ne=e[ne].next;
    }
    sort(out,out+t+1);
    printf("%d",t+1);
    for (j=0;j<=t;j++)
      printf(" %d",out[j]);
    printf("\n");
  }
  return;
}

inline void add(int x,int y)
{
  top++;
  e[top].y=y;
  if (h[x]==-1)
  {
    h[x]=top;
    return;
  }
  e[top].next=h[x];
  h[x]=top;
  return;
}

int main()
{
  int i,j,up,w;
  while (scanf("%d",&n)==1)
  {
    memset(e,-1,sizeof(e));
    memset(h,-1,sizeof(h));
    ge=0;
    top=0;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&up);
      for (j=1;j<=up;j++)
      {
        scanf("%d",&w);
        add(i,n+w);
        if (n+w>ge) ge=n+w;
      }
    }
    for (i=1;i<=n;i++)
    {
      scanf("%d",&w);
      add(n+w,i);
      if (n+w>ge) ge=n+w;
    }
    solve();
  }
  return 0;
}