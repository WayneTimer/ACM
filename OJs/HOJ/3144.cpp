/*This Code is Submitted by Timer for Problem 3144 at 2013-03-24 17:10:59*/
/*
Timer_AC (ZOJ月赛201211)

BFS+状态压缩
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN (1<<20)

int n,m,up;
char e[20];
int w[70];
int c[MAXN];
bool flag;
int p;
int b[MAXN*10];

inline void init()
{
  int t1,t2,i;
  p=(1<<m)-1;
  t1=0;
  t2=0;
  up=0;
  i=0;
  if (n<=m)
  {
    for (i=0;i<m;i++)
    {
      t1<<=1;
      if (i<n)
        if (e[i]=='*')
          t1|=1;
      t1&=p;
      up++;
      w[up]=t1;
      t2<<=1;
      if (i<n)
        if (e[n-i-1]=='*')
          t2|=1;
      t2&=p;
      up++;
      w[up]=t2;
    }
  }
  else
  {
    for (i=0;i<n;i++)
    {
      t1<<=1;
      if (e[i]=='*')
        t1|=1;
      t1&=p;
      up++;
      w[up]=t1;
      t2<<=1;
      if (e[n-i-1]=='*')
        t2|=1;
      t2&=p;
      up++;
      w[up]=t2;
    }
  }
  sort(w+1,w+1+up);
  i=1;
  while (i<=up && !w[i]) i++;
  if (i>up) 
  {
    up=0;
    return;
  }
  w[1]=w[i];
  t1=1;
  for (i++;i<=up;i++)
    if (w[i]!=w[t1])
      w[++t1]=w[i];
  up=t1;
}

inline void BFS()
{
  int head,tail,i,t;
  bool f;
  head=0;
  tail=1;
  b[1]=0;
  memset(c,0,sizeof(c));
  f=false;
  do
  {
    head++;
    if (head>=MAXN*10)
    {
      head=1;
      f=false;
    }
    for (i=1;i<=up;i++)
    {
      t=b[head]|w[i];
      if (!c[t])
      {
        c[t]=c[b[head]]+1;
        if (t==p)
        {
          printf("%d\n",c[t]);
          flag=false;
          return;
        }
        tail++;
        if (tail>=MAXN*10)
        {
          tail=1;
          f=true;
        }
        b[tail]=t;
      }
    }
  } while (head<tail || f);
}

int main()
{
  while (scanf("%d",&n)==1)
  {
    scanf("%s",e);
    scanf("%d",&m);
    init();
    flag=true;
    BFS();
    if (flag) puts("-1");
  }
  return 0;
}