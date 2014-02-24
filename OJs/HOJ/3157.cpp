/*This Code is Submitted by Timer for Problem 3157 at 2013-12-15 20:47:12*/
#include <cstdio>
#include <cstring>

#define MAXN 55

struct MON
{
  int v,a,b,fb;
  int type;
};

struct MAGE
{
  int v,type,x;
};

MON my[MAXN];
MON en[MAXN];
int ans,enHP,myHP;
int enmon,mymon,myhand,m;
MAGE h[MAXN];
bool hu[MAXN];
bool mu[MAXN];
bool alive[MAXN];

void dfs(int hp,int w,int u,int p,bool nomon)
{
  if (hp<=0)
  {
    if (nomon)
    {
      if (ans==-1 || w>ans) ans=w;
      return;
    }
    int i;
    bool flag;
    flag=true;
    for (i=1;i<=enmon;i++)
      if (en[i].b>0)
      {
        flag=false;
        break;
      }
    if (flag)
    {
      if (ans==-1 || w>ans) ans=w;
      return;
    }
  }
  int i,j;
  for (i=u;i<=mymon;i++)
    if (mu[i])
    {
      mu[i]=false;
      dfs(hp-my[i].a,w,i+1,p,false);
      mu[i]=true;
      for (j=1;j<=enmon;j++)
        if (en[j].b>0)
        {
          en[j].b-=my[i].a;
          my[i].b-=en[j].a;
          mu[i]=false;
          dfs(hp,w,i+1,p,false);
          mu[i]=true;
          en[j].b+=my[i].a;
          my[i].b+=en[j].a;
        }
    }
  for (i=p;i<=myhand;i++)
    if (hu[i] && w-h[i].v>=0)
    {
      if (h[i].type==1)
      {
        hu[i]=false;
        dfs(hp-h[i].x,w-h[i].v,u,i+1,nomon);
        hu[i]=true;
        for (j=1;j<=enmon;j++)
          if (en[j].b>0)
          {
            en[j].b-=h[i].x;
            hu[i]=false;
            dfs(hp,w-h[i].v,u,i+1,nomon);
            en[j].b+=h[i].x;
            hu[i]=true;
          }
      }
      else
      {
        hu[i]=false;
        for (j=1;j<=enmon;j++)
          en[j].b-=h[i].x;
        dfs(hp,w-h[i].v,u,i+1,nomon);
        hu[i]=true;
        for (j=1;j<=enmon;j++)
          en[j].b+=h[i].x;
      }
    }
}

int main()
{
  int i;
  while (scanf("%d%d",&enmon,&enHP)==2)
  {
    for (i=1;i<=enmon;i++)
    {
      scanf("%d%d",&en[i].a,&en[i].fb);
      en[i].b=en[i].fb;
    }
    scanf("%d%d%d",&mymon,&myhand,&m);
    for (i=1;i<=mymon;i++)
    {
      scanf("%d%d",&my[i].a,&my[i].fb);
      my[i].b=my[i].fb;
    }
    for (i=1;i<=myhand;i++)
      scanf("%d%d%d",&h[i].v,&h[i].type,&h[i].x);
    memset(hu,true,sizeof(hu));
    memset(mu,true,sizeof(mu));
    memset(alive,true,sizeof(alive));
    ans=-1;
    dfs(enHP,m,1,1,true);
    if (ans==-1)
      puts("-1");
    else
      printf("%d\n",m-ans);
  }
  return 0;
}