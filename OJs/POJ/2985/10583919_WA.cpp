#include <cstdio>
#include <cstring>

using namespace std;

int myset[200010];
int c[200010];
int pos[200010];
int n,m;
int cyr;

void makeset()
{
  int i;
  for (i=1;i<=n;i++)
  {
    myset[i]=i;
    c[i]=c[i]^c[i];
    pos[i]=1;
  }
}

int findset(int x)
{
  if (myset[x]==x) return x;
  myset[x]=findset(myset[x]);
  return myset[x];
}

inline int lowbit(int x)
{
  return (x&(-x));
}

inline int sum(int x)
{
  int t;
  t=0;
  while (x>0)
  {
    t=t+c[x];
    x=x-lowbit(x);
  }
  return t;
}

inline void add(int x,int v)
{
  while (x<=n)
  {
    c[x]+=v;
    x=x+lowbit(x);
  }
}

int main()
{
  int c,x,y,j,x1,y1,i;
  while (scanf("%d%d",&n,&m)==2)
  {
    makeset();
    cyr=n;
    add(1,n);
    for (i=1;i<=m;i++)
    {
      scanf("%d",&c);
      if (c==0)
      {
        scanf("%d%d",&x,&y);
        x1=findset(x);
        y1=findset(y);
        if (x1!=y1) 
        {
          myset[y1]=x1;
          add(pos[x1],-1);
          add(pos[y1],-1);
          pos[x1]+=pos[y1];
          add(pos[x1],1);
          cyr--;
        }
      }
      else
      {
        scanf("%d",&x);
        x=cyr-x+1;
        int l,r,mid;
        l=1;
        r=cyr;
        while (l<=r)
        {
          mid=(l+r)>>1;
          if (x<=sum(mid))
            r=mid-1;
          else
            l=mid+1;
        }
        printf("%d\n",l);
      }
    }
  }
  return 0;
}