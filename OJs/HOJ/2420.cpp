/*This Code is Submitted by Timer for Problem 2420 at 2013-04-18 22:06:58*/
/*
1、判断连通性
2、去除度为1的点，再判断剩余是否是一条直线
*/
#include <cstdio>
#include <cstring>

struct eugin
{
  int x,y;
};

int du[110];//记录每个点的度，去掉度为1的点
int h[110];
int n,up;
eugin e[620];

inline bool check()
{
  int q[110];
  bool b[110];
  bool flag;//当去除所有度为1的点后，剩余点的度都是2，则是环
  int head,tail,s,k,i;
  memset(b,true,sizeof(b));
  head=0;
  tail=1;
  s=1;
  q[1]=1;
  b[1]=false;
  do
  {
    head++;
    k=h[q[head]];
    while (k)
    {
      if (b[e[k].x])
      {
        tail++;
        q[tail]=e[k].x;
        b[e[k].x]=false;
        s++;
      }
      k=e[k].y;
    }
  } while (head<tail);
  if (s!=n) return false;//判断连通性，若遍历过的点个数s==n，则是连通图
  flag=false;
  for (i=1;i<=n;i++)
    if (du[i]>1)
    {
      s=0;
      k=h[i];
      while (k)
      {
        if (du[e[k].x]>1)
          s++;
        if (s>2) return false;
        k=e[k].y;
      }
      if (s==1) flag=true;
    }
  return flag;
}

int main()
{
  int i,m,x,y,T;
  T=0;
  scanf("%d",&n);
  while (n)
  {
    T++;
    scanf("%d",&m);
    up=0;
    memset(h,0,sizeof(h));
    memset(du,0,sizeof(du));
    while (m--)
    {
      scanf("%d%d",&x,&y);
      up++;
      e[up].x=y;
      e[up].y=h[x];
      h[x]=up;
      up++;
      e[up].x=x;
      e[up].y=h[y];
      h[y]=up;
      du[x]++;
      du[y]++;
    }
    printf("Graph %d is ",T);
    if (!check()) printf("not ");
    puts("a caterpillar.");
    scanf("%d",&n);
  }
  return 0;
}