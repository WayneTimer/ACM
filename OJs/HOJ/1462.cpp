/*This Code is Submitted by Timer for Problem 1462 at 2013-04-25 21:30:10*/
#include <cstdio>

#define MAXN 100000

struct eugin
{
  int x,y;
};

eugin a[MAXN];

inline void init()
{
  int cnt,i,k;
  a[1].x=0;
  a[1].y=0;
  cnt=1;
  k=1;
  while (true)
  {
    cnt++;
    if (cnt==MAXN) return;
    a[cnt]=a[cnt-1];
    a[cnt].y++;
    for (i=1;i<k;i++)
    {
      cnt++;
      if (cnt==MAXN) return;
      a[cnt]=a[cnt-1];
      a[cnt].x--;
      a[cnt].y++;
    }
    for (i=1;i<=k;i++)
    {
      cnt++;
      if (cnt==MAXN) return;
      a[cnt]=a[cnt-1];
      a[cnt].x--;
    }
    for (i=1;i<=k;i++)
    {
      cnt++;
      if (cnt==MAXN) return;
      a[cnt]=a[cnt-1];
      a[cnt].y--;
    }
    for (i=1;i<=k;i++)
    {
      cnt++;
      if (cnt==MAXN) return;
      a[cnt]=a[cnt-1];
      a[cnt].x++;
      a[cnt].y--;
    }
    for (i=1;i<=k;i++)
    {
      cnt++;
      if (cnt==MAXN) return;
      a[cnt]=a[cnt-1];
      a[cnt].x++;
    }
    for (i=1;i<=k;i++)
    {
      cnt++;
      if (cnt==MAXN) return;
      a[cnt]=a[cnt-1];
      a[cnt].y++;
    }
    k++;
  }
}

int main()
{
  int x;
  init();
  while (scanf("%d",&x)==1)
    printf("%d %d\n",a[x].x,a[x].y);
  return 0;
}