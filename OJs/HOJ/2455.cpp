/*This Code is Submitted by Timer for Problem 2455 at 2013-03-13 21:01:59*/
#include <cstdio>
#include <queue>

using namespace std;

deque <int> q;

int main()
{
  int T,n,x,i;
  scanf("%d",&T);
  while (T--)
  {
    q.clear();
    scanf("%d",&n);
    q.push_front(n);
    n--;
    while (n)
    {
      q.push_front(n);
      for (i=1;i<=n;i++)
      {
        x=q.back();
        q.pop_back();
        q.push_front(x);
      }
      n--;
    }
    x=q.front();
    printf("%d",x);
    q.pop_front();
    while (!q.empty())
    {
      x=q.front();
      q.pop_front();
      printf(" %d",x);
    }
    puts("");
  }
  return 0;
}