/*This Code is Submitted by Timer for Problem 1456 at 2012-07-24 16:35:11*/
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int v[1000100];
bool flag[1010];
queue <int> q,cyr[1010];

int main()
{
  int T,n,x,i,j,temp,u;
  char e[50];
  scanf("%d",&T);
  temp=0;
  while (T!=0)
  {
    temp++;
    memset(v,0,sizeof(v));
    memset(flag,true,sizeof(flag));
    printf("Scenario #%d\n",temp);
    while (!q.empty())
      q.pop();
    for (i=1;i<=T;i++)
    {
      scanf("%d",&n);
      for (j=1;j<=n;j++)
      {
        scanf("%d",&x);
        v[x]=i;
      }
    }
    scanf("%s",e);
    while (e[0]!='S')
    {
      if (e[0]=='E') 
      {
        scanf("%d",&x);
        u=v[x];
        cyr[u].push(x);
        if (flag[u])
        {
          flag[u]=false;
          q.push(u);
        }
      }
      if (e[0]=='D')
      {
        u=q.front();
        while (cyr[u].empty()) 
        {
          flag[u]=true;
          q.pop(); 
          u=q.front();
        }
        x=cyr[u].front();
        cyr[u].pop();
        printf("%d\n",x);
      }
      scanf("%s",e);
    }
    for (i=1;i<=n;i++)
      while (!cyr[i].empty()) cyr[i].pop();
    printf("\n");
    scanf("%d",&T);
  }
  return 0;
}