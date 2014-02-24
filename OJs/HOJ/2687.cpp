/*This Code is Submitted by Timer for Problem 2687 at 2012-10-07 12:15:33*/
#include <cstdio>

#define MAXN 100002

struct cyr
{
  int l; //取了最左边的
  int r; //取了最右边的
  int s; //区间最大值
  int sum; //区间总和
};

cyr a[MAXN<<2];
int n,q,y,v;

void build(int l,int r,int now)
{
  if (l==r)
  {
    scanf("%d",&a[now].s);
    a[now].l=a[now].s;
    a[now].r=a[now].s;
    a[now].sum=a[now].s;
    return;
  }
  int mid;
  mid=(l+r)>>1;
  build(l,mid,now<<1);
  build(mid+1,r,now<<1|1);
  a[now].sum=a[now<<1].sum+a[now<<1|1].sum;
  int temp;
  temp=a[now<<1].sum+a[now<<1|1].l;
  if (temp>a[now<<1].l)
    a[now].l=temp;
  else 
    a[now].l=a[now<<1].l;
  temp=a[now<<1|1].sum+a[now<<1].r;
  if (temp>a[now<<1|1].r)
    a[now].r=temp;
  else
    a[now].r=a[now<<1|1].r;
  if (a[now].l>temp) temp=a[now].l;
  if (a[now].r>temp) temp=a[now].r;
  if (a[now<<1].r+a[now<<1|1].l>temp) temp=a[now<<1].r+a[now<<1|1].l;
  if (a[now<<1].s>temp) temp=a[now<<1].s;
  if (a[now<<1|1].s>temp) temp=a[now<<1|1].s;
  a[now].s=temp;
  return;
}

void change(int l,int r,int now)
{
  if (l==r)
  {
    a[now].s=v;
    a[now].l=v;
    a[now].r=v;
    a[now].sum=v;
    return;
  }
  int mid;
  mid=(l+r)>>1;
  if (y<=mid) change(l,mid,now<<1);
    else change(mid+1,r,now<<1|1);
  //------------------------------------
  a[now].sum=a[now<<1].sum+a[now<<1|1].sum;
  int temp;
  temp=a[now<<1].sum+a[now<<1|1].l;
  if (temp>a[now<<1].l)
    a[now].l=temp;
  else 
    a[now].l=a[now<<1].l;
  temp=a[now<<1|1].sum+a[now<<1].r;
  if (temp>a[now<<1|1].r)
    a[now].r=temp;
  else
    a[now].r=a[now<<1|1].r;
  if (a[now].l>temp) temp=a[now].l;
  if (a[now].r>temp) temp=a[now].r;
  if (a[now<<1].r+a[now<<1|1].l>temp) temp=a[now<<1].r+a[now<<1|1].l;
  if (a[now<<1].s>temp) temp=a[now<<1].s;
  if (a[now<<1|1].s>temp) temp=a[now<<1|1].s;
  a[now].s=temp;
  return;
}

int main()
{
  while (scanf("%d%d",&n,&q)==2)
  {
    build(1,n,1);
    while (q--)
    {
      scanf("%d%d",&y,&v);
      change(1,n,1);
      printf("%d\n",a[1].s);
    }
  }
  return 0;
}
 