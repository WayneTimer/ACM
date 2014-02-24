/*This Code is Submitted by Timer for Problem 1564 at 2012-08-01 11:20:51*/
#include <cstdio>
#include <cstring>

using namespace std;

int myset[30010];
int sum[30010];
int n,m;

inline void makeset()
{
  int i;
  for (i=0;i<n;i++)
  {
    myset[i]=i; 
    sum[i]=1;
  }
}

int findset(int x)
{
  if (myset[x]==x) return x;
  myset[x]=findset(myset[x]);
  return myset[x];
}

int main()
{
  int k,i,x,x1,y,y1,j,p;
  scanf("%d%d",&n,&m);
  while (n||m)
  {
    makeset();
    for (k=1;k<=m;k++)
    {
      scanf("%d",&p);
      scanf("%d",&x);
      x1=findset(x);
      for (j=2;j<=p;j++)
      {
        scanf("%d",&y);
        y1=findset(y);
        if (x1!=y1)
        {
          myset[y1]=x1;
          sum[x1]+=sum[y1];
        }
      }
    }
    x1=findset(0);
    printf("%d\n",sum[x1]);
    scanf("%d%d",&n,&m);
  }
  return 0;
}