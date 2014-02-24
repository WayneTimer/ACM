/*This Code is Submitted by Timer for Problem 3139 at 2013-01-27 20:41:50*/
#include <cstdio>
#include <cstring>

struct eugin
{
  int x,y;
};

int n,ans;
eugin a[102];
int f[102];
bool b[102];

int findset(int x)
{
  if (f[x]==x) return x;
  f[x]=findset(f[x]);
  return f[x];
}

int main()
{
  int i,j,t1,t2;
  while (scanf("%d",&n)==1 && n)
  {
    for (i=1;i<=n;i++)
    {
      scanf("%d%d",&a[i].x,&a[i].y);
      f[i]=i;
    }
    for (i=2;i<=n;i++)
      for (j=1;j<i;j++)
        if (a[i].x==a[j].x || a[i].y==a[j].y)
        {
          t1=findset(i);
          t2=findset(j);
          if (t1<t2) f[t2]=t1;
          if (t1>t2) f[t1]=t2;
        }
    memset(b,false,sizeof(b));
    b[1]=true;
    ans=1;
    for (i=2;i<=n;i++)
    {
      t1=findset(i);
      if (!b[t1])
      {
        b[t1]=true;
        ans++;
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}