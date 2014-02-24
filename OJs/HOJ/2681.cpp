/*This Code is Submitted by Timer for Problem 2681 at 2012-07-21 18:46:42*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int v;
  int dep;
};

const int maxn=10010;
int n,m,p;
cyr a[maxn<<2];

void change(int l,int r,int now,int x,int y,int c)
{
  if ((x<=l)&&(r<=y))
  {
    a[now].dep=p;
    a[now].v=c;
  }
  else
  {
    int mid;
    mid=(l+r)>>1;
    if (x<=mid) change(l,mid,now<<1,x,y,c);
    if (y>mid) change(mid+1,r,now<<1|1,x,y,c);
  }
}

int query(int l,int r,int now)
{
  if (l==r)
    if (a[now].v==0) return 1;
      else return 0;
  if (a[now].dep>a[now<<1].dep) 
  {
    a[now<<1].v=a[now].v;
    a[now<<1].dep=a[now].dep;
  }
  if (a[now].dep>a[now<<1|1].dep) 
  {
    a[now<<1|1].v=a[now].v;
    a[now<<1|1].dep=a[now].dep;
  }
  int s1,s2,mid;
  mid=(l+r)>>1;
  s1=query(l,mid,now<<1);
  s2=query(mid+1,r,now<<1|1);
  return s1+s2;
}

int main()
{
  int x,y,c,s;
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(a,0,sizeof(a));
    p=0;
    while (m--)
    {
      scanf("%d%d%d",&x,&y,&c);
      p++;
      change(1,n,1,x,y,c);
    }
    s=query(1,n,1);
    printf("%d\n",s);
  }
  return 0;
}