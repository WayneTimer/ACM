/*This Code is Submitted by Timer for Problem 1725 at 2012-12-31 21:26:55*/
#include <cstdio>
#include <queue>

using namespace std;

struct cyr
{
  int x,y,t;
};

priority_queue <cyr> a;

bool operator < (cyr q,cyr w)
{
  if (q.t>w.t) return true;
  if (q.t==w.t) 
    if (q.x>w.x) return true;
  return false;
}

int main()
{
  char str[20];
  cyr temp;
  int n;
  scanf("%s",str);
  while (str[0]!='#')
  {
    scanf("%d%d",&temp.x,&temp.y);
    temp.t=temp.y;
    a.push(temp);
    scanf("%s",str);
  }
  scanf("%d",&n);
  while (n--)
  {
    temp=a.top();
    a.pop();
    printf("%d\n",temp.x);
    temp.t+=temp.y;
    a.push(temp);
  }
  return 0;
}