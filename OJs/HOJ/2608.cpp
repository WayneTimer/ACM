/*This Code is Submitted by Timer for Problem 2608 at 2012-07-23 17:17:23*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct cyr
{
  char name[100];
  int m;
  int v;
};

int n,money;
long long s;
cyr a[10015];

bool operator < (cyr q,cyr w)
{
  int u;
  u=strcmp(q.name,w.name);
  if (u<0) return true;
  if (u>0) return false;
  return (q.m<w.m);
}

bool check(int x)
{
  int i,j;
  char e[100],temp[100];
  s=0;
  memset(e,0,sizeof(e));
  memset(temp,0,sizeof(temp));
  for (i=0;i<n;i++)
  {
    if (strcmp(temp,a[i].name)!=0)
    {
      if (strcmp(temp,e)!=0) return false;
      strcpy(temp,a[i].name);
    }
    if (strcmp(e,a[i].name)!=0)
    {
      if (a[i].v>=x) 
      {
        s+=a[i].m;
        strcpy(e,a[i].name);
      }
    }
  }
  if (strcmp(temp,a[i].name)!=0)
  {
    if (strcmp(temp,e)!=0) return false;
    strcpy(temp,a[i].name);
  }
  if (s<=money) return true;
    else return false;
}

int main()
{
  int ans,T,i,t,l,r,mid,x,y;
  bool flag;
  char e1[100],e2[100];
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d %d",&n,&money);
    memset(a,0,sizeof(a));
    ans=0;
    t=0;
    l=0;
    r=0;
    for (i=0;i<n;i++)
    {
      scanf("%s %s %d %d",e1,e2,&x,&y);
      if (y>r) r=y;
      strcpy(a[i].name,e1);
      a[i].m=x;
      a[i].v=y;
    }
    sort(a,a+n);
    flag=true;
    while (l<=r)
    {
      mid=(l+r)>>1;
      if (check(mid))
      {
        l=mid+1;
        ans=mid;
      }
      else 
        r=mid-1;
    }
    printf("%d\n",ans);
  }
  return 0;
}