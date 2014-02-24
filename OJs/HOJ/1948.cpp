/*This Code is Submitted by Timer for Problem 1948 at 2012-04-10 20:45:23*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

#define MAXN 105

using namespace std;

struct cyr
{
  int t;
  int b;
};

cyr dist[MAXN];
cyr a[MAXN][MAXN];
bool used[MAXN][2];
string name[MAXN];
int n,m;

int qumin(int x,int y)
{
  if (x<y) return x;
    else return y;
}

int dij(int x)
{
  int i,j,temp;
  int min,k,p;
  memset(dist,0x3f,sizeof(dist));
  memset(used,false,sizeof(used));
  dist[1].t=0;
  dist[1].b=0;
  for (i=1;i<=m*2;i++)
  {
    min=10000000;
    k=-1;
    p=-1;
    for (j=1;j<=m;j++)
    {
      if ((!used[j][0]) && (dist[j].t<min))
      {
        min=dist[j].t;
        k=j;
        p=0;
      }
      if ((!used[j][1]) && (dist[j].b<min))
      {
        min=dist[j].b;
        k=j;
        p=1;
      }
    }
    if (k!=-1)
    {
      used[k][p]=true;
      if (p==0)
        for (j=1;j<=m;j++)
        {
          if (k==1) temp=0;
            else temp=3;
          dist[j].t=qumin(dist[j].t,dist[k].t+a[k][j].t+temp);
          if (k==1) temp=0;
            else temp=10;
          dist[j].b=qumin(dist[j].b,dist[k].t+a[k][j].b+temp);
        }
      if (p==1)
        for (j=1;j<=m;j++)
        {
          if (k==1) temp=0;
            else temp=10;
          dist[j].t=qumin(dist[j].t,dist[k].b+a[k][j].t+temp);
          if (k==1) temp=0;
            else temp=3;
          dist[j].b=qumin(dist[j].b,dist[k].b+a[k][j].b+temp);
        }
    }
  }
  if (dist[x].t<dist[x].b) return dist[x].t;
    else return dist[x].b;
}

int main()
{
  string e,x,y,end;
  char ee[25];
  int p,q,w,i,j;
  while (scanf("%s",ee)==1)
  {
    memset(a,0x3f,sizeof(a));
    for (i=0;i<MAXN;i++)
      name[i]="";
    m=1;
    end=ee;
    cin>>n;
    name[m]="Harbin";
    for (i=1;i<=n;i++)
    {
      cin>>e>>x>>y>>p;
      q=-1;
      for (j=1;j<=m;j++)
        if (name[j]==x) 
        {
          q=j;
          break;
        }
      if (q==-1) 
      {
        m++;
        q=m;
        name[q]=x;
      }
      w=-1;
      for (j=1;j<=m;j++)
        if (name[j]==y)
        {
          w=j;
          break;
        }
      if (w==-1)
      {
        m++;
        w=m;
        name[w]=y;
      }
      if (e=="train")
      {
        a[q][w].t=p;
        a[w][q].t=p;
      }
      else
      {
        a[q][w].b=p;
        a[w][q].b=p;
      }
    }
    for (i=1;i<=m;i++)
      if (name[i]==end)
      {
        w=i;
        break;
      }
    p=dij(w);
    printf("%d\n",p);
  }
  return 0;
}