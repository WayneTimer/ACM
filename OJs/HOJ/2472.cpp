/*This Code is Submitted by Timer for Problem 2472 at 2013-03-18 17:17:34*/
// 二分图最大匹配，貌似 状态压缩DP
#include <cstdio>
#include <cstring>

int n,m;
bool a[22][22];
bool cover[22];
int link[22];

bool find(int v)
{
  int i,k;
  for (i=0;i<m;i++)
    if (!cover[i] && a[v][i])
    {
      k=link[i];
      link[i]=v;
      cover[i]=true;
      if (k==0 || find(k)) return true;
      link[i]=k;
    }
  return false;
}

int main()
{
  int i,x,j;
  bool flag;
  scanf("%d%d",&n,&m);
  while (n||m)
  {
    memset(a,false,sizeof(a));
    memset(link,0,sizeof(link));
    for (i=0;i<m;i++)
    {
      scanf("%d",&j);
      while (j--)
      {
        scanf("%d",&x);
        a[x][i]=true;
      }
    }
    if (n>m)
      puts("no");
    else
    {
      flag=true;
      for (i=0;i<n;i++)
      {
        memset(cover,false,sizeof(cover));
        if (!find(i)) 
        {
          puts("no");
          flag=false;
          break;
        }
      }
      if (flag) puts("yes");
    }
    scanf("%d%d",&n,&m);
  }
  return 0;
}