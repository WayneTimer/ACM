/*
  1. find the bigest ring/circle in direct graph
  2. consist of a set of pairs (two kids like each other) and some nodes link to these pairs
  Compare 2 situation above, choose the best one.
*/
#include <cstdio>
#include <cstring>

#define MAXN 1010

int n;
int a[MAXN];
int bigest_ring,pairs_cnt;
int v[MAXN]; // 0 -- no visit yet, >=1 -- visited (iter no.), -1 -- in a ring

int mark_ring(int x)
{
    int y,ret;
    v[x] = -1;
    y = x;
    ret = 1;
    while (a[y]!=x)
    {
        ret++;
        y = a[y];
        v[y] = -1;
    }
    return ret;
}

void bfs()
{
    bool flag;
    int iter;
    memset(v,0,sizeof(v));

    iter = 0;
    do
    {
        flag = false;
        for (int i=1;i<=n;i++)
            if (v[i]==0)
            {
                iter++;
                flag = true;
                v[i] = iter;
                int j;
                j = a[i];
                while (v[j]==0)
                {
                    v[j] = iter;
                    j = a[j];
                }
                if (v[j]==iter) // find a new ring
                {
                    int cnt;
                    cnt = mark_ring(j);
                    if (cnt>bigest_ring) bigest_ring = cnt;
                    if (cnt==2) pairs_cnt++;
                }
            }
    } while (flag);
}

void link_to_pairs()
{
    int s[MAXN];
    memset(s,0,sizeof(s));
    for (int i=1;i<=n;i++)
        if (v[i]!=-1)
        {
            int j,cnt;
            j = i;
            cnt = 0;
            do
            {
                j = a[j];
                cnt++;
            } while (v[j]!=-1);
            if (cnt>s[j]) s[j] = cnt;
        }
    for (int i=1;i<=n;i++)
        if (a[a[i]]==i) // is a pair
            pairs_cnt += s[i];
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            a[i] = x;
        }
        bigest_ring = pairs_cnt = 0;
        bfs();
        pairs_cnt<<=1;
        link_to_pairs();
        int ans = bigest_ring;
        if (pairs_cnt>ans) ans = pairs_cnt;
        printf("Case #%d: %d\n",o,ans);
    }
    return 0;
}
