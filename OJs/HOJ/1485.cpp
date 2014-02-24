/*This Code is Submitted by Timer for Problem 1485 at 2012-02-08 23:59:11*/
#include <cstdio>
#include <string.h>

using namespace std;

int n,m,t;
int v[201];
long f[2][1001];
long sum;

bool sub(int u)
{
  int i;
  for (i=1;i<=t;i++)
  {
    if (v[i]>u) continue;
    if (n>=v[i]) 
    {
      n=n-v[i];
      continue;
    }
    if (m>=v[i])
    {
      m=m-v[i];
      continue;
    }
    return false;
  }
  return true;
}

int main()
{
  bool flag,ff;
  long max,i,j,k,cyr;
  short t1,t2;
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(f,0,sizeof(f));
    memset(v,0,sizeof(v));
    cyr=0;
    sum=0;
    flag=false;
    ff=false;
    if (n>m) max=n;
      else max=m;
    scanf("%d",&t);
    for (i=1;i<=t;i++)
    {
      scanf("%d",&v[i]);
      sum=sum+v[i];
      if (v[i]>cyr) cyr=v[i];
      if (v[i]>max)
        if (flag) ff=true;
          else flag=true;
    }
    if (ff) 
    {
      printf("No\n");
      continue;
    }
    if (flag)
    {
      if (sub(max)) printf("Need a helper\n");
        else printf("No\n");
      continue;
    }
    for (k=1;k<=t;k++)
    {
      if ((k%2)!=0) 
      {
        t1=1;
        t2=0;
      }
      else
      {
        t1=0;
        t2=1;
      }
      for (i=1;i<=n;i++)
      {
          max=0;
          if (v[k]<=i) max=f[t2][i-v[k]]+v[k];
          if (max>f[t2][i]) f[t1][i]=max;
            else f[t1][i]=f[t2][i];
      }
    }
    max=sum-f[t1][n];
    max=max-m;
    if (max<=0) printf("Yes\n");
    else
    {
      max=max-cyr;
      if (max<=0) printf("Need a helper\n");
        else printf("No\n");
    }
  }
  return 0;
}