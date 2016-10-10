#include <cstdio>

using namespace std;

struct cyr
{
  int pos;
  int v;
};

const int maxn=200010;
cyr f[maxn<<2];
cyr a[maxn];
int n;

void build(int l,int r,int now)
{
  if (l==r) 
  {
    f[now].pos=1;
    return;
  }
  int mid;
  mid=(l+r)>>1;
  build(l,mid,now<<1);
  build(mid+1,r,now<<1|1);
  f[now].pos=f[now<<1].pos+f[now<<1|1].pos;
}

void insert(int l,int r,int now,int x,int y)
{
  if (l==r)
  {
    f[now].pos=0;
    f[now].v=y;
    return;
  }
  int mid;
  mid=(l+r)>>1;
  if (f[now<<1].pos>=x) 
    insert(l,mid,now<<1,x,y);
  else
    insert(mid+1,r,now<<1|1,x-f[now<<1].pos,y);
  f[now].pos--;
}

void out(int l,int r,int now)
{
  if (l==r)
  {
    if (l!=0) printf(" ");
    printf("%d",f[now].v);
    return;
  }
  int mid;
  mid=(l+r)>>1;
  out(l,mid,now<<1);
  out(mid+1,r,now<<1|1);
}

int main()
{
  int i;
  while (scanf("%d",&n)==1)
  {
    build(0,n-1,1);
    for (i=1;i<=n;i++)
      scanf("%d%d",&a[i].pos,&a[i].v);
    for (i=n;i>=1;i--)
      insert(0,n-1,1,a[i].pos+1,a[i].v);
    out(0,n-1,1);
    printf("\n");
  }
  return 0;
}