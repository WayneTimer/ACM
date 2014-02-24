/*This Code is Submitted by Timer for Problem 2683 at 2012-07-23 08:38:37*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int v;
};

const int maxn=10010;
int n,m,n1,n2,n3;
cyr a[maxn<<2];

void change(int l,int r,int now,int x,int y)
{
  if ((x<=l)&&(r<=y))
  {
    a[now].v++;
  }
  else
  {
    int mid;
    mid=(l+r)>>1;
    if (x<=mid) change(l,mid,now<<1,x,y);
    if (y>mid) change(mid+1,r,now<<1|1,x,y);
  }
}

void query(int l,int r,int now)
{
  if (l==r)
  {
    int temp;
    temp=a[now].v%3;
    if (temp==0) n1++;
    else if (temp==1) n2++;
    else if (temp==2) n3++;
    return;
  }
  int s1,s2,mid;
  mid=(l+r)>>1;
  a[now<<1].v+=a[now].v;
  a[now<<1|1].v+=a[now].v;
  query(l,mid,now<<1);
  query(mid+1,r,now<<1|1);
  return;
}

int main()
{
  int x,y,c,s;
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(a,0,sizeof(a));
    n1=0;
    n2=0;
    n3=0;
    while (m--)
    {
      scanf("%d%d",&x,&y);
      change(1,n,1,x,y);
    }
    query(1,n,1);
    printf("%d %d %d\n",n1,n2,n3);
  }
  return 0;
}