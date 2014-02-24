/*This Code is Submitted by Timer for Problem 1056 at 2012-02-09 00:55:22*/
#include <cstdio>
#include <string.h>

int ma[100];
bool a[100][100];
bool used[100];
int n,m,k;

void init()
{
  int i,x,y,q;
  for (i=0;i<=100;i++)
    ma[i]=-1;
  memset(a,false,sizeof(a));
  memset(used,false,sizeof(used));
  scanf("%d%d",&m,&k);
  for (i=1;i<=k;i++)
  {
    scanf("%d%d%d",&q,&x,&y);
    a[x][y]=true;
  }
}

bool find(int x)
{
  int i;
  if (!used[x])
    for (i=1;i<=m;i++)
      if (a[x][i])
      {
        used[x]=true;
        if ((ma[i]==-1)||(find(ma[i])))
        {
          ma[i]=x;
          return true;
        }
      }
    return false;
}

void sub()
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
  scanf("%d",&n);
  while (n!=0)
  {
    init();
    sub();
    scanf("%d",&n);
  }
  return 0;
}