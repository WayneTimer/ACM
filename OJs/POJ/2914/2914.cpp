#include <cstdio>
#include <cstring>
#include <queue>

#define MAXN 504
#define INF 99999999

int n,m;
int a[MAXN][MAXN];
bool combine[MAXN];  // true: combined
bool v[MAXN];  // true: visited
int edge_sum[MAXN];  // sum of direct connected edge of a node

int prim(int& s, int& t, int cnt)  // s: start node
{
    int next_node_y;
    int next_node_val;

    memset(v,false,sizeof(v));
    memset(edge_sum,-1,sizeof(edge_sum));
    edge_sum[0] = 0;

    next_node_y = s = t = -1;

    for (int i=0;i<cnt;i++)  // O(n^2)
    {
        next_node_val = -INF;
        for (int j=0;j<n;j++)
            if (edge_sum[j]>=0 && !combine[j] && !v[j] && edge_sum[j]>next_node_val)
            {
                next_node_y = j;
                next_node_val = edge_sum[j];
            }
        if (next_node_y==t) return 0;  // not fully connected

        s = t;
        t = next_node_y;
        v[t] = true;

        for (int j=0;j<n;j++)
            if (!combine[j] && !v[j] && a[t][j]!=-1)
            {
                if (edge_sum[j]==-1)
                    edge_sum[j] = a[t][j];
                else
                    edge_sum[j] += a[t][j];
            }
    }
    return next_node_val;
}

int main()
{
    int ans, ret;
    while (scanf("%d%d", &n, &m)!=EOF)
    {
        memset(a,-1,sizeof(a));
        memset(combine,false,sizeof(combine));
        ans = INF;
        while (m--)
        {
            int x,y,c;
            scanf("%d%d%d", &x, &y, &c);
            if (a[x][y]==-1)
                a[x][y] = c;
            else
                a[x][y] += c;

            if (a[y][x]==-1)
                a[y][x] = c;
            else
                a[y][x] += c;
        }

        for (int i=0;i<n-1;i++)  // prim + combine,  O(n^3)
        {
            int s,t;
            ret = prim(s,t,n-i);  // O(n^2)
            if (ret<ans) ans = ret;
            if (ans==0) break;
            combine[t] = true;
            for (int j=0;j<n;j++)
            {
                if (s!=j && t!=j && !combine[j])
                {
                    if (a[s][j]==-1 && a[t][j]==-1)
                        continue;
                    else if (a[s][j]==-1 && a[t][j]!=-1)
                    {
                        a[s][j] = a[t][j];
                        a[j][s] = a[j][t];
                    }
                    else if (a[s][j]!=-1 && a[t][j]==-1)
                        continue;
                    else
                    {
                        a[s][j] += a[t][j];
                        a[j][s] += a[j][t];
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}