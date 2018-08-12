#include <cstdio>
#include <cstring>

#define MAXN 2010

struct Node
{
    int v, l, r;
};

Node a[MAXN];
int pre[MAXN];
int f[MAXN];    // Node x must be equal to Node f[x]
int p, ans;

void pre_order(int root)
{
    pre[p] = root;
    p++;
    if (a[root].l) pre_order(a[root].l);
    if (a[root].r) pre_order(a[root].r);
}

void post_order(int root)
{
    if (a[root].l) post_order(a[root].l);
    if (a[root].r) post_order(a[root].r);
    f[pre[p]] = root;
    p++;
}

bool set_val(int ptr, int val)
{
    int next = f[ptr];
    if (a[ptr].v && a[ptr].v != val) return false;
    if (a[next].v && a[next].v != val) return false;
    
    if (a[ptr].v == val && a[next].v == val) return true;
    a[ptr].v = val;
    a[next].v = val;
    return set_val(next, val);
}

int main()
{
    int T,K,N;
    scanf("%d", &T);
    for (int o = 1; o <= T; o++)
    {
        memset(a, 0, sizeof(a));
        memset(pre, 0, sizeof(pre));
        memset(f, 0, sizeof(f));
        scanf("%d %d", &N, &K);
        for (int i = 1; i <= N; i++)
        {
            int left,right;
            scanf("%d %d", &left, &right);
            a[i].l = left;
            a[i].r = right;
        }
        
        p = 0;
        pre_order(1);
        p = 0;
        post_order(1);
        
        bool is_ok = true;
        ans = 0;
        for (p = 0; p < N; p++)
        {
            if (!a[pre[p]].v)
            {
                ans++;
                if (!set_val(pre[p], ans))
                {
                    is_ok = false;
                    break;
                }
            }
        }
        printf("Case #%d:", o);
        if (!is_ok || ans < K)
            printf(" Impossible\n");
        else
        {
            for (int i = 1; i <= N; i++)
            {
                if (a[i].v <= K)
                    printf(" %d", a[i].v);
                else
                    printf(" %d", K);
            }
            printf("\n");
        }
    }
    return 0;
}
