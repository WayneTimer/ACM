/*This Code is Submitted by Timer for Problem 2801 at 2012-02-09 01:04:23*/
#include <cstdio>
#include <string.h>

int v[201],c[201],ma1[201],ma2[201];
int a[201][201];
bool used[201];
int n,m;

void init()
{
  int i,k,q;
  memset(v,0,sizeof(v));
  memset(c,0,sizeof(c));
  memset(ma1,0,sizeof(ma1));
  memset(ma2,0,sizeof(ma2));
  memset(a,0,sizeof(a));
  for (i=1;i<=n;i++)
  {
    v[i]=i;
    scanf("%d",&c[i]);
    for (k=1;k<=c[i];k++)
    {
      scanf("%d",&q);
      a[i][k]=q;
    }
  }
}

bool find(int x)
{
  int i,q;
  used[x]=true;
  for (i=1;i<=c[x];i++)
  {
    q=a[x][i];
    if ((ma2[q]==0)||(!used[ma2[q]])&&(find(ma2[q])))
    {
      ma1[x]=q;
      ma2[q]=x;
      return true;
    }
  }
  return false;
}

void cyr()
{
  int i,s;
  s=0;
  for (i=1;i<=n;i++)
  {
    memset(used,false,sizeof(used));
    if (find(i)) s++;
  }
  printf("%d\n",s);
}

int main()
{
  while (scanf("%d%d",&n,&m)==2)
  {
    init();
    cyr();
  }
  return 0;
}