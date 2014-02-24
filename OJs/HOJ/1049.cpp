/*This Code is Submitted by Timer for Problem 1049 at 2012-08-24 11:51:13*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1010

int n,sum,x,ans;
int a[N];
bool used[N];

bool DFS(int k,int now)
{
  if (now==x)
  {
    k++;
    now^=now;
  }
  if (k==ans) return true;
  int i;
  for (i=n;i>=1;i--)
    if (!used[i])
      if (now+a[i]<=x)
      {
        used[i]=true;
        if (now==0)
        {
          if (!DFS(k,now+a[i]))
          {
            used[i]=false;
            return false;
          }
          else return true;
        }
        else
        {
          if (now+a[i]==x)
          {
            if (!DFS(k,now+a[i]))
            {
              used[i]=false;
              return false;
            }
            else return true;
          }
          else
          {
            if (DFS(k,now+a[i])) return true;
            used[i]=false;
          }
        }
      }
  return false;
}

int main()
{
  int i,low;
  scanf("%d",&n);
  while (n)
  {
    memset(used,false,sizeof(used));
    sum^=sum;
    low^=low;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      sum+=a[i];
      if (a[i]>low) low=a[i];
    }
    sort(a+1,a+n+1);
    for (x=low;x<=sum;x++)
    {
      if (sum%x==0)
      {
        ans=sum/x;
        if (DFS(0,0))
          printf("%d\n",x);
      }
    }
    scanf("%d",&n);
  }
  return 0;
}