//HOJ 1956
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[22];
int up,n;

bool DFS(int s,int sum,int v,int y)
  {
    int i;
    if (sum>=4) return true;
    //if (fail[up-s]) return false;
    for (i=y-1;i>=0;i--)
      if (((1<<i)&v)==0)
	if (s+a[i+1]<=up)
	{
	  if ((i<n-1) && (a[i+1]==a[i+2]) && (((1<<(i+1))&v)==0))
	    continue;
          else
	  {
	    if (s+a[i+1]==up)
	      return (DFS(0,sum+1,v|(1<<i),n));
	    else
	      if (DFS(s+a[i+1],sum,v|(1<<i),i))
	        return true;
	    if (s==0) return false;
	  }
	}
    //fail[up-s]=true;
    return false;
  }

int main()
  {
    int T=0;
    int s=0,i;
    bool flag;
    scanf("%d",&T);
    while (T--)
    {
      s^=s;
      scanf("%d",&n);
      for (i=1;i<=n;i++)
      {
	scanf("%d",&a[i]);
	s+=a[i];
      }
      if (s%4!=0) 
      {
	printf("no\n");
	continue;
      }
      s=s/4;
      up=s;
      sort(a+1,a+1+n);
      if (a[n]>s) 
      {
	printf("no\n");
	continue;
      }
      flag=DFS(0,0,0,n);
      if (flag) printf("yes\n");
        else printf("no\n");
    }
  }
