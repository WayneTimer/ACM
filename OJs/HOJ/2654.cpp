/*This Code is Submitted by Timer for Problem 2654 at 2012-08-26 17:06:36*/
#include <cstdio>
#include <queue>

using namespace std;

struct cyr
{
  int v;
  int p;
};

cyr a[10010];
int n,m,s;
priority_queue <int> w;

int main()
{
  int T,x,head,tail,i;
  scanf("%d",&T);
  while (T--)
  {
    while (!w.empty())
      w.pop();
    s^=s;
    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++)
    {
      scanf("%d",&x);
      a[i].v=x;
      a[i].p=i;
      w.push(x);
    }
    head=0;
    tail=n-1;
    while (!((a[head].p==m) && (a[head].v==w.top())))
    {
      x=w.top();
      while (a[head].v<x) 
      {
        tail++;
        a[tail]=a[head];
        head++;
      }
      if (a[head].p==m) break;
      head++;
      w.pop();
      s++;
    }
    printf("%d\n",s+1);
  }
  return 0;
}