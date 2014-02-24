/*This Code is Submitted by Timer for Problem 1157 at 2012-08-11 19:22:31*/
#include <cstdio>
#include <algorithm>

using namespace std;

struct cyr
{
  int x;
  int y;
};

cyr a[5010][110];
int n[5010],s,top;
cyr stack[110];
cyr query[5010];

bool operator < (cyr q,cyr w)
{
  if (q.y<w.y) return true;
  if (q.y==w.y)
    if (q.x<w.x) return true;
  return false;
}

inline int chaji(cyr q,cyr w,cyr e)
{
  int x1,x2,y1,y2;
  x1=w.x-q.x;
  y1=w.y-q.y;
  x2=e.x-q.x;
  y2=e.y-q.y;
  return (x1*y2-x2*y1);
}

void graham(int u)
{
  int i;
  int limit;
  sort(a[u]+1,a[u]+n[u]+1);
  stack[1]=a[u][1];
  stack[2]=a[u][2];
  top=2;
  for (i=3;i<=n[u];i++)
  {
    while ((top>1) && (chaji(stack[top-1],a[u][i],stack[top])>=0))
      top--;
    top++;
    stack[top]=a[u][i];
  }
  limit=top;
  top++;
  stack[top]=a[u][n[u]-1];
  for (i=n[u]-2;i>=1;i--)
  {
    while ((top>limit) && (chaji(stack[top-1],a[u][i],stack[top])>=0))
      top--;
    top++;
    stack[top]=a[u][i];
  }
}

int cal()
{
  int i;
  int y,g;
  g=0;
  for (i=3;i<top;i++)
  {
    y=chaji(stack[1],stack[i-1],stack[i]);
    if (y<0) y=-y;
    g+=y;
  }
  return g;
}

int checkin(cyr r)
{
  int i,y,g;
  g=0;
  for (i=1;i<top;i++)
  {
    y=chaji(r,stack[i],stack[i+1]);
    if (y<0) y=-y;
    g+=y;
  }
  return g;
}

int main()
{
  int i,j;
  int t;
  int T,x,y,u;
  int area;
  int sum,temp;
  T=1;
  scanf("%d",&n[T]);
  while (n[T]!=-1)
  {
    for (i=1;i<=n[T];i++)
      scanf("%d%d",&a[T][i].x,&a[T][i].y);
    T++;
    scanf("%d",&n[T]);
  }
  T--;
  u=0;
  while (scanf("%d%d",&x,&y)==2)
  {
    u++;
    query[u].x=x;
    query[u].y=y;
  }
  sum=0;
  for (i=1;i<=T;i++)
  {
    graham(i);
    area=cal();
    for (j=1;j<=u;j++)
    {
      temp=checkin(query[j]);
      if (area==temp) 
      {
        sum+=area;
        break;
      }
    }
  }
  if (sum&1) printf("%d.50\n",sum>>1);
    else printf("%d.00\n",sum>>1);
  return 0;
}