/*
求第k小的数的具体应用。

思考后可以发现，从后往前推可以逐一确定出数列中的所有元素。
由于最后一个元素的前面包含了整个数列中的其他元素，所以知道最后一个数前有k个元素即可知道最后一个元素是数列中的第k+1小，同理，可以一次推出其余元素。

关于用线段树求第k小的方法，先将数据离散化，然后维护一棵线段树，树中只有一个域，即为该子树的结点个数。找第k小时，若k<=当前结点的左子树的结点个数，即递归往左子树找；若大于，则将k减去左子树的个数，再递归往右子树找。
*/
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
