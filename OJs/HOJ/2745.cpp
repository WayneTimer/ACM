/*This Code is Submitted by Timer for Problem 2745 at 2013-09-26 16:59:58*/
//并查集
#include <cstdio>
#include <cstring>

#define MAXN 610

int n;
int f[MAXN];
int s[MAXN];

int findset(int x)
{
  if (x==f[x]) return x;
  f[x]=findset(f[x]);
  return f[x];
}

int main()
{
  int i,x,y,fx,fy,k,j;
  int sum;
  while (scanf("%d",&n)==1)
  {
    for (i=0;i<n;i++)
      f[i]=i;
    for (i=0;i<n;i++)
    {
      scanf("%d",&k);
      for (j=0;j<k;j++)
      {
        scanf("%d",&x);
        fx=findset(x);
        fy=findset(i);
        if (fx<fy)
          f[fy]=fx;
        else if (fy<fx)
          f[fx]=fy;
      }
    }
    memset(s,0,sizeof(s));
    sum=0;
    for (i=0;i<n;i++)
    {
      fx=findset(i);
      s[fx]++;
    }
    for (i=0;i<n;i++)
      if (s[i]>1)
        sum+=(s[i]*(s[i]-1))>>1;
    printf("%d\n",sum);
  }
  return 0;
}