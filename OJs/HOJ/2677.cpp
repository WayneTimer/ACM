/*This Code is Submitted by Timer for Problem 2677 at 2013-03-08 14:21:01*/
// Huffman-tree
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > q;
long long s;
int n;
char str[1000];

int main()
{
  long long x,t;
  bool flag;
  while (scanf("%d",&n)==1)
  {
    s^=s;
    if (n==1) flag=true;
      else flag=false;
    while (!q.empty()) q.pop();
    while (n--)
    {
      scanf("%s",str);
      t=strlen(str);
      scanf("%lld",&x);
      q.push(x);
      s+=t*x;
    }
    printf("%lld ",s);
    if (flag)
    {
      printf("%lld\n",q.top());
      continue;
    }
    s^=s;
    t=q.top();
    q.pop();
    while (!q.empty())
    {
      x=q.top();
      q.pop();
      t+=x;
      s+=t;
      q.push(t);
      t=q.top();
      q.pop();
    }
    printf("%lld\n",s);
  }
  return 0;
}