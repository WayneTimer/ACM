/*This Code is Submitted by Timer for Problem 1314 at 2013-02-27 21:34:33*/
//贪心思想
//先排序，然后取第一个，把之后能陆续选的都取走，ans=1
//ans++，再取剩余的第一个，把之后能陆续选的都取走，
//重复直到所有都被取走
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct cyr
{
  int x,y;
};

cyr a[5010];
bool b[5010];
int n;

bool operator < (cyr q,cyr w)
{
  if (q.x<w.x) return true;
  if (q.x>w.x) return false;
  if (q.y<w.y) return true;
  return false;
}

int main()
{
  int i,T,ans,p,last,s;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n);
    s=1;
    ans=1;
    p=1;
    last=-1;
    memset(b,true,sizeof(b));
    b[1]=false;
    while (s<n)
    {
      for (i=p+1;i<=n;i++)
        if (b[i])
        {
          if (a[p].y>a[i].y)
          {
            if (last==-1) last=i;
          }
          else
          {
            p=i;
            b[i]=false;
            s++;
          }
        }
      if (s>=n) break;
      p=last;
      last=-1;
      s++;
      ans++;
    }
    printf("%d\n",ans);
  }
  return 0;
}