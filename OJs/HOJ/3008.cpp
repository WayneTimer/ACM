/*This Code is Submitted by Timer for Problem 3008 at 2012-07-09 08:47:31*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define X 505
int ym[X],l[X],r[X],h[X],n;
bool use[X],map[X][X];
bool dfs(int u)
{
    for(int v=1;v<=n;v++)
    {
        if(map[u][v]&&!use[v])
        {
            use[v] = true;
            if(ym[v]==-1||dfs(ym[v]))
            {
                ym[v] = u;
                return true;
            }
        }
    }
    return false;
}
void hungry()
{
    memset(ym,-1,sizeof(ym));
    int ret = 0;
    for(int u=1;u<=n;u++)
    {
        memset(use,false,sizeof(use));
        if(dfs(u))
            ret++;
    }
    printf("%d\n",n-ret);
}
int main()
{
    while(scanf("%d",&n),n)
    {
        memset(map,false,sizeof(map));
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&l[i],&r[i],&h[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(l[i]>l[j]&&r[i]>r[j]&&h[i]>h[j])
                    map[i][j] = true;
        hungry();
    }
    return 0;
}