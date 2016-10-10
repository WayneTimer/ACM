#include <cstdio>

#define MAX 8010

int a[MAX<<2];
int n,k;
int q[MAX];
int ans[MAX];

void build(int l,int r,int now)
{
  if (l==r)
  {
    a[now]=1;
    return;
  }
  int mid;
  mid=l+r>>1;
  build(l,mid,now<<1);
  build(mid+1,r,now<<1|1);
  a[now]=a[now<<1]+a[now<<1|1];
}

int findk(int l,int r,int now)
{
  a[now]--;
  if (l==r)
    return l;
  int mid;
  mid=l+r>>1;
  if (k<=a[now<<1])
    return findk(l,mid,now<<1);
  else
  {
    k-=a[now<<1];
    return findk(mid+1,r,now<<1|1);
  }
}

int main()
{
  int i;
  scanf("%d",&n);
  build(1,n,1);
  for (i=1;i<n;i++)
    scanf("%d",&q[i]);
  for (i=n-1;i>=1;i--)
  {
    k=q[i]+1;
    ans[i+1]=findk(1,n,1);
  }
  k=1;
  ans[1]=findk(1,n,1);
  for (i=1;i<=n;i++)
    printf("%d\n",ans[i]);
  return 0;
}