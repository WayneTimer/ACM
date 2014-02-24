/*This Code is Submitted by Timer for Problem 2025 at 2012-08-16 20:14:35*/
#include <cstdio>
#include <cstring>

#define INF 200000000

using namespace std;

struct cyr
{
  int x;
  int y;
};

int n,tm;
cyr h[210],m[210];
int hh,mm;
int map[210][210];
int lx[210],ly[210];
int slack[210];
bool x[210],y[210];
int link[210];

bool find(int v)
{
  int i,k,temp;
  x[v]=true;
  for (i=1;i<=hh;i++)
  {
    if ((!y[i]) && (lx[v]+ly[i]==map[v][i]))
    {
      y[i]=true;
      k=link[i];
      link[i]=v;
      if ((k==0) || (find(k))) return true;
      link[i]=k;
    }
    temp=lx[v]+ly[i]-map[v][i];
    if (temp<slack[i]) slack[i]=temp;
  }
  return false;
}

void solve()
{
  int i,j,d,k;
  memset(lx,-0x3f,sizeof(lx));
  memset(ly,0,sizeof(ly));
  memset(link,0,sizeof(link));
  for (i=1;i<=mm;i++)
    for (j=1;j<=hh;j++)
      if (map[i][j]>lx[i])
        lx[i]=map[i][j];
  for (k=1;k<=mm;k++)
    while (1)
    {
      memset(x,false,sizeof(x));
      memset(y,false,sizeof(y));
      memset(slack,0x3f,sizeof(slack));
      if (find(k)) break;
      d=INF;
      for (i=1;i<=hh;i++)
        if (!y[i])
          if (slack[i]<d) d=slack[i];
      for (i=1;i<=mm;i++)
        if (x[i]) lx[i]=lx[i]-d;
      for (i=1;i<=hh;i++)
        if (y[i]) ly[i]=ly[i]+d;
    }
}

inline int caldis(cyr q,cyr w)
{
  int t1,t2;
  t1=q.x-w.x;
  if (t1<0) t1=-t1;
  t2=q.y-w.y;
  if (t2<0) t2=-t2;
  return (t1+t2);
}

int main()
{
  char str[110];
  int i,j,s;
  scanf("%d%d",&n,&tm);
  while (n|tm)
  {
    getchar();
    hh=0;
    mm=0;
    for (i=1;i<=n;i++)
    {
      gets(str);
      for (j=0;j<tm;j++)
      {
        if (str[j]=='m')
        {
          mm++;
          m[mm].x=i;
          m[mm].y=j+1;
        }
        else
        if (str[j]=='H')
        {
          hh++;
          h[hh].x=i;
          h[hh].y=j+1;
        }
      }
    }
    for (i=1;i<=mm;i++)
      for (j=1;j<=hh;j++)
        map[i][j]=-caldis(m[i],h[j]);
    solve();
    s=0;
    for (i=1;i<=mm;i++)
      s+=map[link[i]][i];
    printf("%d\n",-s);
    scanf("%d%d",&n,&tm);
  }
  return 0;
}