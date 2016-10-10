#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  long long sum;
  long long delta;
};

const int maxn=100100;
cyr a[maxn<<2];

void build(int l,int r,int now)
{
  if (l==r)
  {
    scanf("%lld",&a[now].sum);
  }
  else 
  {
    int mid;
    mid=(l+r)>>1;
    build(l,mid,now<<1);
    build(mid+1,r,now<<1|1);
    a[now].sum=a[now<<1].sum+a[now<<1|1].sum;
  }
}

void Add(int l,int r,int now,int x,int y,long long v)
{
  if ((x<=l)&&(r<=y)) a[now].delta=a[now].delta+v;
  else
  {
    int mid;
    mid=(l+r)>>1;
    if (x<=mid) Add(l,mid,now<<1,x,y,v);
    if (y>mid) Add(mid+1,r,now<<1|1,x,y,v);
    a[now].sum=a[now<<1].sum+a[now<<1].delta*(mid-l+1);
    a[now].sum+=a[now<<1|1].sum+a[now<<1|1].delta*(r-mid);
  }
}

long long querysum(int l,int r,int now,int x,int y)
{
  if ((x<=l)&&(r<=y)) return (a[now].sum+a[now].delta*(r-l+1));
  int mid;
  long long ret=0;
  mid=(l+r)>>1;
  a[now<<1].delta+=a[now].delta;
  a[now<<1|1].delta+=a[now].delta;
  a[now].delta=0;
  if (x<=mid) ret+=querysum(l,mid,now<<1,x,y);
  if (y>mid) ret+=querysum(mid+1,r,now<<1|1,x,y);
  a[now].sum=a[now<<1].sum+a[now<<1].delta*(mid-l+1);
  a[now].sum+=a[now<<1|1].sum+a[now<<1|1].delta*(r-mid);
  return ret;
}

int main()
{
  int n,q,i,x,y;
  char e;
  long long v,s;
  memset(a,0,sizeof(a));
  scanf("%d%d",&n,&q);
  build(1,n,1);
  getchar();
  for (i=1;i<=q;i++)
  {
    scanf("%c",&e);
    if (e=='Q')
    {
      scanf("%d%d",&x,&y);
      s=querysum(1,n,1,x,y);
      printf("%lld\n",s);
    }
    else
    {
      scanf("%d%d%lld",&x,&y,&v);
      Add(1,n,1,x,y,v);
    }
    getchar();
  }
  return 0;
}