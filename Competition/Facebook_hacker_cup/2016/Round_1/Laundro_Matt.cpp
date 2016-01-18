// O( L logN ), actual cost about 1m25s in i5.
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define MAXL 1000010

struct Washer
{
    long long time;
    int w;
};

priority_queue<Washer> wash;
long long dry[MAXL];
int l,n,m,d;

bool operator < (Washer x,Washer y)
{
    if (x.time>y.time) return true;
    return false;
}

int main()
{
    int T;
    long long now;
    Washer g;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%d %d %d %d",&l,&n,&m,&d);
        while (!wash.empty()) wash.pop();
        for (int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            g.time = x;
            g.w = x;
            wash.push(g);
        }
        memset(dry,0,sizeof(dry));
        if (l<m) m = l;

        int j;
        now = 0;
        j = 0;
        for (int i=0;i<l;i++)
        {
            long long t1,t2,ma;
            g = wash.top();
            t1 = g.time;
            wash.pop();
            t2 = dry[j];
            if (t1>t2) ma = t1;
            else ma = t2;
            ma+=d;
            if (ma>now)
            {
                now = ma;
            }
            g.time += g.w;
            wash.push(g);
            dry[j] = ma;
            j++;
            j%=m;
        }
        printf("Case #%d: %lld\n",o,now);
    }
    return 0;
}
