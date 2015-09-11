/*
 *最大流模板
 * SAP（当前弧优化+GAP优化）非递归形式
 * O(V^2*E)
 * HIT_ACM 2012 Summer Camp
 * by xiaodai
 */

#include <cstring>
#include <iostream>
#include <cstdio>

#define SETZR(a) memset(a,0,sizeof(a))

using namespace std;

//定义常量：边数、点数和无穷
const int MAXM = 1000000;
const int MAXN = 10000;
const int INF = 1000000000;

//边的结构体
//此模板中图以池子法存储

struct record
{
    int v, f, next; //v为边的终点，f是该边的剩余流量
} edge[MAXM];

/*
 * 变量说明：
 * pointer为各点出度头指针
 * dis为距离标号
 * vh记录每个距离标号点的数量，用于GAP优化
 * his记录各点入栈时的流量，用于退栈
 * di记录各点当前弧
 * pre记录各点前驱结点，同样用于退栈
 */
int n, m, s, t, cas, cl;
int pointer[MAXN], dis[MAXN], vh[MAXN];
int his[MAXN], di[MAXN], pre[MAXN];

void connect(int a, int b, int f)
{
    cl++;
    edge[cl].next = pointer[a];
    edge[cl].v = b;
    edge[cl].f = f;
    pointer[a] = cl;
    cl++;
    edge[cl].next = pointer[b];
    edge[cl].v = a;
    edge[cl].f = 0; //若为无向边，则f = f
    pointer[b] = cl;
}

int main()
{
    scanf("%d", &cas);

    while (cas--)
    {
        char op[100];
        getchar();
        gets(op);
        scanf("%d%d%d%d", &n, &m, &s, &t);
        //初始化
        cl = 1;
        SETZR(dis);
        SETZR(vh);
        SETZR(pointer);
        //建图
        for (int i = 0; i < m; i++)
        {
            int p, k, w;
            scanf("%d%d%d", &p, &k, &w);
            connect(p, k, w);
        }
        //最大流过程
        vh[0] = n; //初始化GAP数组（默认所有点的距离标号均为0，则距离标号为0的点数量为n）
        for (int i = 0; i < n; i++) di[i] = pointer[i]; //初始化当前弧
        int i = s, aug = INF, flow = 0; //初始化一些变量，flow为全局流量，aug为当前增广路的流量
        bool flag = 0; //标记变量，记录是否找到了一条增广路（若没有找到则修正距离标号）
        while (dis[s] < n)
        {
            his[i] = aug; //保存当前流量
            flag = 0;
            int p = di[i];
            while (p != 0)
            {
                if ((edge[p].f > 0) && (dis[edge[p].v] + 1 == dis[i]))  //利用距离标号判定可行弧
                {
                    flag = 1; //发现可行弧
                    di[i] = p; //更新当前弧
                    aug = min(aug, edge[p].f); //更新当前流量
                    pre[edge[p].v] = p; //记录前驱结点
                    i = edge[p].v; //在弧上向前滑动
                    if (i == t)  //遇到汇点，发现可增广路
                    {
                        flow += aug; //更新全局流量
                        while (i != s)  //减少增广路上相应弧的容量，并增加其反向边容量
                        {
                            edge[pre[i]].f -= aug;
                            edge[pre[i]^1].f += aug;
                            i = edge[pre[i]^1].v;
                        }
                        aug = INF;
                    }
                    break;
                }
                p = edge[p].next;
            }
            if (flag) continue; //若发现可行弧则继续，否则更新标号
            int min = n - 1;
            p = pointer[i];
            while (p != 0)
            {
                if ((edge[p].f > 0) && (dis[edge[p].v] < min))
                {
                    di[i] = p; //不要忘了重置当前弧
                    min = dis[edge[p].v];
                }
                p = edge[p].next;
            }
            --vh[dis[i]];
            if (vh[dis[i]] == 0) break; //更新vh数组，若发现距离断层，则算法结束（GAP优化）
            dis[i] = min + 1;
            ++vh[dis[i]];
            if (i != s)  //退栈过程
            {
                i = edge[pre[i]^1].v;
                aug = his[i];
            }
        }
        //输出答案
        printf("%d\n", flow);
    }
    return 0;
}
