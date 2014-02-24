/*This Code is Submitted by Timer for Problem 1999 at 2012-07-25 09:14:59*/
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

priority_queue < int,vector<int>,greater<int> > q;

int main()
{
  char e[30];
  int n,x;
  scanf("%d",&n);
  while (n--)
  {
    scanf("%s",e);
    if (e[0]=='a')
    {
      scanf("%d",&x);
      q.push(x);
    }
    else
    if (e[0]=='d')
    {
      if (q.empty()) continue;
      q.pop();
    }
    else 
    if (e[0]=='q')
    {
      if (q.empty()) continue;
      x=q.top();
      printf("%d\n",x);
    }
  }
  return 0;
}