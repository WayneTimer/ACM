/*This Code is Submitted by Timer for Problem 1495 at 2012-10-07 13:41:18*/
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 50002

using namespace std;

struct rect
{
  int x1,y1,x2,y2;
};

struct cyr
{
  long long area;
  int up;
  int down;
};

int minx,maxx,top;
rect b[1002];
cyr a[MAXN<<2];

bool operator < (rect q,rect w)
{
  if (q.y1<w.y1) return true;
  if (q.y1>w.y1) return false;
  if (q.x1<w.x1) return true;
  return false;
}

void insert(int l,int r,int now,rect in)
{
  if (l==r)
  {
    if (a[now].up==0)
    {
      a[now].down=in.y1;
      a[now].up=in.y2;
      return;
    }
    if (in.y1<=a[now].up)
    {
      if (in.y2>a[now].up)
        a[now].up=in.y2;
      return;
    }
    if (in.y1>a[now].up)
    {
      a[now].area=a[now].area+a[now].up-a[now].down;
      a[now].down=in.y1;
      a[now].up=in.y2;
      return;
    }
    return;
  }
  int mid;
  mid=(l+r)>>1;
  if (in.x1<=mid) insert(l,mid,now<<1,in);
  if (in.x2>mid) insert(mid+1,r,now<<1|1,in);
  return;
}

long long cal(int l,int r,int now)
{
  if (l==r)
  {
    long long temp;
    temp=a[now].area+a[now].up-a[now].down;
    return temp;
  }
  int mid;
  mid=(l+r)>>1;
  long long t1,t2;
  t1=cal(l,mid,now<<1);
  t2=cal(mid+1,r,now<<1|1);
  return t1+t2;
}

int main()
{
  int x1,y1,x2,y2;
  int i;
  while (scanf("%d%d%d%d",&x1,&y1,&x2,&y2)==4)
  {
    if (x1==-1 && y1==-1 && x2==-1 && y2==-1) break;
    minx=MAXN;
    maxx^=maxx;
    top^=top;
    memset(a,0,sizeof(a));
    while (!(x1==-1 && y1==-1 && x2==-1 && y2==-1))
    {
      if (x1<minx) minx=x1;
      if (x2<minx) minx=x2;
      if (x1>maxx) maxx=x1;
      if (x2>maxx) maxx=x2;
      top++;
      b[top].x1=x1;
      b[top].y1=y1;
      b[top].x2=x2-1;
      b[top].y2=y2;
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2)==4;
    }
    sort(b+1,b+1+top);
    for (i=1;i<=top;i++)
      insert(minx,maxx-1,1,b[i]);
    printf("%lld\n",cal(minx,maxx-1,1));
  }
  return 0;
}
 