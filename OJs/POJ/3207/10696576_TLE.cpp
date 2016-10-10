#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

#define MAXM 10000
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

cyr e[MAXM];
int n,m;
int mynew,ind;
int dfn[MAXN];
int low[MAXN];
int id[MAXN];
stack <int> sta;
vector <int> my[MAXN];
bool used[MAXN];
bool visit[MAXN];
int top;
bool insta[MAXN];
POI line[MAXN];

inline int qumin(int q,int w)
{
  if (q<=w) return q;
  return w;
}

bool tarjan(int v)
{
  int i,h,k;
  ind++;
  dfn[v]=ind;
  low[v]=ind;
  sta.push(v);
  insta[v]=true;
  h=v;
  while (e[h].y!=-1)
  {
    k=e[h].y;
    if (dfn[k]==0)
    {
      tarjan(k);
      low[v]=qumin(low[v],low[k]);
    }
    else
      if (insta[v])
        low[v]=qumin(low[v],dfn[k]);
    if (e[h].next==-1) break;
      else h=e[h].next;
  }
  if (dfn[v]==low[v])
  {
    memset(visit,false,sizeof(visit));
    mynew++;
    do
    {
      k=sta.top();
      if (visit[k]) return false;
        else visit[k]=true;
      sta.pop();
      insta[v]=false;
      id[k]=mynew;
      my[mynew].push_back(k);
    } while (v!=k);
  }
  return true;
}

bool solve()
{
  int i;
  memset(dfn,0,sizeof(dfn));
  memset(low,0,sizeof(low));
  memset(id,0,sizeof(id));
  memset(insta,false,sizeof(insta));
  for (i=1;i<=m;i++) 
    my[i].clear();
  mynew=0;
  ind=0;
  while (!sta.empty())
    sta.pop();
  for (i=1;i<=m;i++) 
    if (dfn[i]==0)
      if (!tarjan(i)) return false;
  return true;
}

inline void add(int x,int y)
{
  int h;
  h=x;
  while (e[h].next!=-1)
  {
    if (e[h].y==y) return;
    h=e[h].next;
  }
  if (e[h].y==-1)
    e[h].y=y;
  else
  {
    if (e[h].y==y) return;
    top++;
    e[h].next=top;
    e[top].y=y;
  }
}

int main()
{
  int i,x,y,t,yy,j;
  int q,w;
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(e,-1,sizeof(e));
    top=n;
    for (i=1;i<=m;i++)
    {
      scanf("%d%d",&q,&w);
      if (q>w)
      {
        t=q;
        q=w;
        w=t;
      }
      line[i].x=q;
      line[i].y=w;
      for (j=1;j<i;j++)
        if (((q<=line[j].x) && (line[j].x<=w)) || ((q<=line[j].y) && (line[j].y<=w)))
        {
          add(i,j);
          add(j,i);
        }
    }
    if (!solve())
      printf("the evil panda is lying again\n");
    else
      printf("panda is telling the truth...\n");
  }
  return 0;
}