/*This Code is Submitted by Timer for Problem 3006 at 2012-07-09 08:44:33*/
#include <cstdio>
#include <cstring>

const int MaxN = 1000011;

struct edge
{
    int x,y,w;
    edge *next;
}*p[MaxN],a[MaxN*2],*pt;

int dis[MaxN],pre[MaxN];
bool v[MaxN];

void add(int x,int y,int w)
{
    pt -> x = x;
    pt -> y = y;
    pt -> w = w;
    pt -> next = p[x];
    p[x] = pt++;
}

void dfs(int now)
{
    v[now] = 1;
    for (edge *tp = p[now]; tp ; tp = tp -> next)
    if (v[tp -> y] == 0)
    {
        dis[tp -> y] = dis[now] + tp -> w;
        pre[tp -> y] = now;
        dfs(tp -> y);
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n)
    {
        memset(p,0,sizeof(p));
        pt = a;
        int x,y,w;
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d%d", &x,&y,&w);
            add(x,y,w);
            add(y,x,w);
        }
        memset(v,0,sizeof(v));
        memset(dis,0,sizeof(dis));
        dfs(1);
        int temp = 0, k = 0;
        for (int i = 1; i <= n; i++)
        if (dis[i] > temp)
        {
            temp = dis[i];
            k = i;
        }
        memset(v,0,sizeof(v));
        memset(dis,0,sizeof(dis));
        pre[k] = -1;
        dfs(k);
        temp = 0;
        for (int i = 1; i <= n; i++)
        if (dis[i] > temp)
        {
            temp = dis[i];
            k = i;
        }
        memset(v,0,sizeof(v));
        for (int i = k; i != -1; i = pre[i])
        {
            v[i] = 1;
        }
        memset(dis,0,sizeof(dis));
        for (int i = 1; i <= n; i++)
        if (v[i])
            dfs(i);

        temp = 0;
        for (int i = 1; i <= n; i++)
        if (dis[i] > temp)
            temp = dis[i];

        printf("%d\n",temp);
    }
    return 0;
}