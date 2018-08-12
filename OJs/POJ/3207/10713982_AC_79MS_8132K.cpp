#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

#define MAXM 1002
#define MAXN 2010

struct POI
{
  int x;
  int y;
};

struct cyr
{
  int y;
  int next;
};

cyr e[MAXM*MAXM];
int h[MAXN];
int n,m;
int mynew,ind;
int dfn[MAXN];
int low[MAXN];
int id[MAXN];
stack <int> sta;
int top;
bool insta[MAXN];
POI line[MAXN];

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

bool solve()
{
  int i;
  memset(dfn,0,sizeof(dfn));
  memset(low,0,sizeof(low));
  memset(id,0,sizeof(id));
  memset(insta,false,sizeof(insta));
  mynew=0;
  ind=0;
  while (!sta.empty())
    sta.pop();
  for (i=1;i<=m<<1;i++) 
    if (dfn[i]==0)
      tarjan(i);
  for (i=1;i<=m;i++)
    if (id[i]==id[i+m]) return false;
  return true;
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
  int i,x,y,t,yy,j;
  int q,w;
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(e,-1,sizeof(e));
    memset(h,-1,sizeof(h));
    top=0;
    for (i=1;i<=m;i++)
    {
      scanf("%d%d",&q,&w);
      q++;
      w++;
      if (q>w)
      {
        t=q;
        q=w;
        w=t;
      }
      line[i].x=q;
      line[i].y=w;
      for (j=1;j<i;j++)
        if (!((q>line[j].x&&w<line[j].y)||(line[j].x>q&&line[j].y<w)||w<line[j].x||line[j].y<q))
        {
          add(i,j+m);
          add(j+m,i);
          add(i+m,j);
          add(j,i+m);
        }
    }
    if (!solve())
      printf("the evil panda is lying again\n");
    else
      printf("panda is telling the truth...\n");
  }
  return 0;
}