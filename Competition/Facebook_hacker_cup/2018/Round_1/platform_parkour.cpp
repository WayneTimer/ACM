#include <cstdio>
#include <cstring>

#define EPS 1e-6
#define MAXN 200010
#define MAXX 1000000

struct Node
{
    int up, down;
    int v;
    double l, r;
};

Node h[MAXN];
int w,x,y,z,n,m;
int ud[MAXN << 2][2];  // 0 - up, 1 - down

inline void swap(int &v1, int &v2)
{
    v1 ^= v2;
    v2 ^= v1;
    v1 ^= v2;
}

inline int calc(int i)
{
    if (i <= 2) return h[i].v;
    long long h1 = h[i-2].v;
    long long h2 = h[i-1].v;
    return (int)( (w * h1 + x * h2 + y)%z );
}

inline void update(int root, int up, int down)
{
    if (ud[root][0] == -1 || up < ud[root][0])
        ud[root][0] = up;
    if (ud[root][1] == -1 || down < ud[root][1])
        ud[root][1] = down;
}

void set(int l, int r, int root, int x, int y, int up, int down)
{
    if (x <= l && r <= y)
    {
        update(root, up, down);
        return;
    }
    if (ud[root][0] != -1 && ud[root][1] != -1)
    {
        update(root<<1, ud[root][0], ud[root][1]);
        update(root<<1|1, ud[root][0], ud[root][1]);
    }
    int mid = (l + r) >> 1;
    if (x <= mid) set(l, mid, root<<1, x, y, up, down);
    if (y > mid) set(mid+1, r, root<<1|1, x, y, up, down);
}

void get_ud(int l, int r, int root, int i, int &up, int &down)
{
    if (l == r)
    {
        up = ud[root][0];
        down = ud[root][1];
        return;
    }
    if (ud[root][0] != -1 && ud[root][1] != -1)
    {
        update(root<<1, ud[root][0], ud[root][1]);
        update(root<<1|1, ud[root][0], ud[root][1]);
    }
    int mid = (l + r) >> 1;
    if (i <= mid) get_ud(l, mid, root<<1, i, up, down);
    else get_ud(mid+1, r, root<<1|1, i, up, down);
}

bool test(double t)
{
    h[1].l = h[1].v - h[1].down - t;
    h[1].r = h[1].v + h[1].up + t;
    for (int i = 2; i <= n; i++)
    {
        if (h[i-1].up == -1 || h[i-1].down == -1)
        {
            h[i].l = h[i].v - h[i].down - t;
            h[i].r = h[i].v + h[i].up + t;
            continue;
        }
        double up, down;
        up = h[i].v + t;
        down = h[i].v - t;
        if (h[i-1].l > up || h[i-1].r < down)
            return false;
        h[i].r = up < h[i-1].r ? up : h[i-1].r;
        h[i].l = down > h[i-1].l ? down : h[i-1].l;
        h[i].l -= h[i].down;
        h[i].r += h[i].up;
    }
    return true;
}

double binary_search(double l, double r)
{
    if (r - l < EPS) return (l + r) / 2.0;
    double t = (l + r) / 2.0;
    if (test(t))
    {
        return binary_search(l, t);
    }
    else
    {
        return binary_search(t, r);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int o = 1; o <= T; o++)
    {
        memset(ud, -1, sizeof(ud));
        memset(h, 0, sizeof(h));
        scanf("%d %d", &n, &m);
        scanf("%d %d %d %d %d %d", &h[1].v, &h[2].v, &w, &x, &y, &z);
        for (int i = 0; i < m; i++)
        {
            int t1, t2, u, d;
            scanf("%d %d %d %d", &t1, &t2, &u, &d);
            if (t1 > t2)
            {
                swap(t1, t2);
                swap(u, d);
            }
            set(1, n, 1, t1, t2-1, u, d);
        }

        for (int i = 1; i <= n; i++)
        {
            get_ud(1, n, 1, i, h[i].up, h[i].down);
            h[i].v = calc(i);
            h[i].l = h[i].v;
            h[i].r = h[i].v;
        }

        double ans;
        ans = binary_search(0, MAXX);
        printf("Case #%d: %.6lf\n", o, ans);
    }
    return 0;
}
