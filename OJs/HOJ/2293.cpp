/*This Code is Submitted by Timer for Problem 2293 at 2013-02-05 00:24:54*/
#include <cstdio>
#include <cstring>

#define MAXN 1000000

int g,n;
bool a[MAXN];
int v[MAXN];

int main()
{
  int T,t,i;
  bool flag;
  memset(a,false,sizeof(a));
  while (scanf("%d",&T)==1)
  {
    while (T--)
    {
      scanf("%d",&g);
      flag=true;
      for (i=1;i<=g;i++)
      {
        scanf("%d",&v[i]);
        if (flag)
        {
          t=v[i]%g;
          if (a[t])
          {
            flag=false;
            continue;
          }
          a[t]=true;
        }
      }
      if (flag) 
      {
        printf("%d\n",g);
        while (g--) a[g]=false;
        continue;
      }
      n=g;
      while (true)
      {
        i=g;
        g++;
        while (i--) a[i]=false;
        for (i=1;i<=n;i++)
        {
          t=v[i]%g;
          if (a[t])
          {
            flag=true;
            break;
          }
          a[t]=true;
        }
        if (!flag) break;
        flag=false;
      }
      printf("%d\n",g);
      while (g--) a[g]=false;
    }
  }
  return 0;
}