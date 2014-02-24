/*This Code is Submitted by Timer for Problem 2678 at 2013-01-28 20:25:45*/
//二维树状数组_模板题
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 1001

using namespace std;

struct eugin
{
  int x,y,z;
};

int n;
eugin a[15004];
int c[1004][1004];
int ans[15004];

bool operator < (eugin q,eugin w)
{
  if (q.x<w.x) return true;
  if (q.x>w.x) return false;
  return false;
}

inline int lowbit(int x)
{
  return (x&(-x));
}

inline void add(int x,int y,int v)
{
  int temp;
  temp=y;
  while (x<=MAX)
  {
    y=temp;
    while (y<=MAX)
    {
      c[x][y]+=v;
      y=y+lowbit(y);
    }
    x=x+lowbit(x);
  }
}

inline int sum(int x,int y)
{
  int t,temp;
  t^=t;
  temp=y;
  while (x>0)
  {
    y=temp;
    while (y>0)
    {
      t+=c[x][y];
      y-=lowbit(y);
    }
    x-=lowbit(x);
  }
  return t;
}

inline void cal(int i,int j)
{
  int t;
  while (i<=j)
  {
    t=sum(a[i].y,a[i].z);
    ans[t-1]++;
    i++;
  }
}

int main()
{
  int i,t,j;
  while (scanf("%d",&n)==1)
  {
    memset(c,0,sizeof(c));
    memset(ans,0,sizeof(ans));
    for (i=1;i<=n;i++)
    {
      scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
      a[i].x++;
      a[i].y++;
      a[i].z++;
    }
    sort(a+1,a+1+n);
    i=1;
    for (j=1;j<=n;j++)
    {
      if (a[i].x==a[j].x)
        add(a[j].y,a[j].z,1);
      else
      {
        cal(i,j-1);
        i=j;
        add(a[j].y,a[j].z,1);
      }
    }
    cal(i,n);
    printf("%d",ans[0]);
    for (i=1;i<n;i++)
      printf(" %d",ans[i]);
    puts("");
  }
  return 0;
}