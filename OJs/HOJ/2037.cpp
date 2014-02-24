/*This Code is Submitted by Timer for Problem 2037 at 2012-11-23 17:45:58*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 20010

struct cyr
{
  int v;
  bool lazy;
};

struct seg
{
  int x,y;
};

cyr a[MAXN<<2];
seg q[MAXN>>1];
int m[MAXN];
int n,x,y,all,u,sum;
bool hash[MAXN];

int find(int temp)
{
  int l,r,mid;
  l=1;
  r=all;
  while (l!=r)
  {
    mid=(l+r)>>1;
    if (temp<=m[mid])
      r=mid;
    else
      l=mid+1;
  }
  return l;
}

void insert(int l,int r,int now)
{
  if (x<=l && r<=y)
  {
    a[now].v=u;
    a[now].lazy=true;
    return;
  }
  if (a[now].lazy)
  {
    a[now<<1].v=a[now].v;
    a[now<<1].lazy=true;
    a[now<<1|1].v=a[now].v;
    a[now<<1|1].lazy=true;
    a[now].lazy=false;
  }
  int mid;
  mid=(l+r)>>1;
  if (x<=mid) insert(l,mid,now<<1);
  if (y>mid) insert(mid+1,r,now<<1|1);
  return;
}

void query(int l,int r,int now)
{
  if (a[now].lazy || l==r)
  {
    if (!hash[a[now].v])
    {
      hash[a[now].v]=true;
      sum++;
    }
    return;
  }
  int mid;
  mid=(l+r)>>1;
  query(l,mid,now<<1);
  query(mid+1,r,now<<1|1);
  return;
}

int main()
{
  int ca;
  int i,j;
  scanf("%d",&ca);
  while (ca--)
  {
    memset(a,0,sizeof(a));
    memset(hash,false,sizeof(hash));
    sum^=sum;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      scanf("%d%d",&q[i].x,&q[i].y);
      m[(i<<1)-1]=q[i].x;
      m[i<<1]=q[i].y;
    }
    sort(m+1,m+1+(n<<1));
    m[0]=-1;
    j^=j;
    for (i=1;i<=(n<<1);i++)
    {
      if (m[j]!=m[i])
      {
        j++;
        m[j]=m[i];
      }
    }
    all=j;
    for (i=1;i<=n;i++)
    {
      x=find(q[i].x);
      y=find(q[i].y);
      u=i;
      insert(1,all,1);
    }
    query(1,all,1);
    printf("%d\n",sum);
  }
  return 0;
}
 