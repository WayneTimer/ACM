/*This Code is Submitted by Timer for Problem 2278 at 2012-07-23 14:27:56*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct cyr
{
  long long low;
  long long high;
};

cyr a[1000010];

bool operator < (cyr q,cyr w)
{
  return (q.low<w.low);
}

bool foo(int l,int r,long long x)
{
  int mid;
  mid=(l+r)>>1;
  if (x>=a[mid].low)
    if (x<=a[mid].high) return true;
  if (l>=r) return false;
  if (x<a[mid].low) return foo(l,mid-1,x);
  if (x>a[mid].high) return foo(mid+1,r,x);
  return false;
}

int main()
{
  long long s1,s2,x;
  int p;
  memset(a,0,sizeof(a));
  p=-1;
  while (scanf("%lld",&x)==1)
  {
    s1=x<<24;
    getchar();
    scanf("%lld",&x);
    s1=s1+(x<<16);
    getchar();
    scanf("%lld",&x);
    s1=s1+(x<<8);
    getchar();
    scanf("%lld",&x);
    s1+=x;
    //-----------------------
    getchar();
    scanf("%lld",&x);
    s2=x<<24;
    getchar();
    scanf("%lld",&x);
    s2=s2+(x<<16);
    getchar();
    scanf("%lld",&x);
    s2=s2+(x<<8);
    getchar();
    scanf("%lld",&x);
    s2+=x;
    getchar();
    //-----------------------
    p++;
    if (s1>s2)
    {
      x=s1;
      s1=s2;
      s2=x;
    }
    a[p].low=s1;
    a[p].high=s2;
  }
  sort(a,a+p+1);
  getchar();
  getchar();
  while (scanf("%lld",&x)==1)
  {
    s1=x<<24;
    getchar();
    scanf("%lld",&x);
    s1=s1+(x<<16);
    getchar();
    scanf("%lld",&x);
    s1=s1+(x<<8);
    getchar();
    scanf("%lld",&x);
    s1+=x;
    getchar();
    //----------------------
    if (foo(0,p,s1)) printf("yes\n");
      else printf("no\n");
  }
  return 0;
}