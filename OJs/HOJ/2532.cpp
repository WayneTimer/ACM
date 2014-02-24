/*This Code is Submitted by Timer for Problem 2532 at 2012-11-15 00:26:05*/
#include <cstdio>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > q;

int n;
long long s;

int main()
{
  int T,i;
  long long t1,t2,x;
  scanf("%d",&T);
  while (T--)
  {
    while (!q.empty()) q.pop();
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      scanf("%lld",&x);
      q.push(x);
    }
    s^=s;
    while (!q.empty()) 
    {
      t1=q.top();
      q.pop();
      if (q.empty()) break;
      t2=q.top();
      q.pop();
      t1+=t2;
      s=s+t1;
      q.push(t1);
    }
    printf("%lld\n",s);
  }
  return 0;
}
 