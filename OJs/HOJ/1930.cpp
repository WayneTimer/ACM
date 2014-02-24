/*This Code is Submitted by Timer for Problem 1930 at 2013-02-23 14:25:14*/
#include <cstdio>
#include <set>

using namespace std;

set <int> a[100];
int p;

int main()
{
  int x,y,i,s,j;
  while (scanf("%d%d",&p,&y)==2)
  {
    for (i=1;i<=p;i++)
      a[i].clear();
    scanf("%d",&x);
    while (x!=-1)
    {
      scanf("%d",&y);
      a[x].insert(y);
      scanf("%d",&x);
    }
    s=p;
    for (i=1;i<p;i++)
      for (j=i+1;j<=p;j++)
        if (a[i]==a[j])
        {
          s--;
          break;
        }
    printf("%d\n",s);
  }
  return 0;
}