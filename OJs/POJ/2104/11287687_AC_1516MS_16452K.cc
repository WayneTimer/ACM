//POJ2104，划分树模板题
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 100010

int n;
int v[20][MAXN];//v[i][j]表示第i层第j个数
int num[20][MAXN];//num[i][j]表示第i层第j个数及其之前在左子树的个数
int c[MAXN];//排序后的数组

void build(int l,int r,int d)
{
  if (l==r) return;
  int mid,lsame,i;
  mid=l+r>>1;
  lsame=mid-l+1;
  for (i=l;i<=r;i++)
    if (v[d][i]<c[mid]) lsame--;
  int lp,rp;
  lp=l;
  rp=mid+1;
  for (i=l;i<=r;i++)
  {
    if (i==l)
      num[d][i]=0;
    else
      num[d][i]=num[d][i-1];
    if (v[d][i]<c[mid])
    {
      v[d+1][lp++]=v[d][i];
      num[d][i]++;
    }
    else if (v[d][i]>c[mid])
      v[d+1][rp++]=v[d][i];
    else if (lsame)
    {
      lsame--;
      v[d+1][lp++]=v[d][i];
      num[d][i]++;
    }
    else
      v[d+1][rp++]=v[d][i];
  }
  build(l,mid,d+1);
  build(mid+1,r,d+1);
}

int query(int l,int r,int d,int x,int y,int k)
{
  if (x==y) return v[d][x];
  int mid,s,ss;//s是[x,y]区间中在左子树的个数，ss是[l,x)区间中在左子树的个数
  //其中ss用来对查询区间x,y进行缩小
  mid=l+r>>1;
  if (x==l)
  {
    ss=0;
    s=num[d][y];
  }
  else
  {
    ss=num[d][x-1];
    s=num[d][y]-ss;
  }
  if (s>=k)
  {
    x=l+ss;//缩小查询区间
    y=l+ss+s-1;
    return query(l,mid,d+1,x,y,k);
  }
  else
  {
    x=mid+1+x-l-ss;//缩小区间
    //初始下一层查找区间左端点为mid+1,
    //再加上本层中[l,x)内已在右子树的个数，
    //才是实际查找区间左端点。下同。
    y=mid+1+y-l-num[d][y];
    return query(mid+1,r,d+1,x,y,k-s);
  }
}

int main()
{
  int m,x,y,k,i;
  memset(v,0,sizeof(v));
  memset(num,0,sizeof(num));
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
  {
    scanf("%d",&c[i]);
    v[1][i]=c[i];
  }
  sort(c+1,c+1+n);
  build(1,n,1);
  while (m--)
  {
    scanf("%d%d%d",&x,&y,&k);
    i=query(1,n,1,x,y,k);
    printf("%d\n",i);
  }
  return 0;
}