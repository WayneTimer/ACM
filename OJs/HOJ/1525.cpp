/*This Code is Submitted by Timer for Problem 1525 at 2012-07-31 18:22:53*/
#include <cstdio>
#include <stack>

using namespace std;

struct cyr
{
  int h;
  int pos;
};

const int maxn=100010;
int b[maxn];
int heigh[maxn];
int n;
stack <cyr> s;

int main()
{
  int i,x,y;
  cyr t;
  long long area,ans;
  scanf("%d",&n);
  while (n)
  {
    ans=0;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&heigh[i]);
      if (s.empty())
      {
        t.h=heigh[i];
        t.pos=1;
        s.push(t);
      }
      else
      {
        x=i;
        y=i-1;
        while (s.top().h>=heigh[i])
        {
          x=s.top().pos;
          area=y-x+1;
          area=area*s.top().h;
          if (area>ans) ans=area;
          s.pop();
          if (s.empty()) break;
        }
        t.h=heigh[i];
        t.pos=x;
        s.push(t);
      }
    }
    y=n;
    while (!s.empty()) 
    {
      x=s.top().pos;
      area=y-x+1;
      area=area*s.top().h;
      if (area>ans) ans=area;
      s.pop();
    }
    printf("%lld\n",ans);
    scanf("%d",&n);
  }
  return 0;
}