// Segment tree
#include <cstdio>
#include <cstring>

#define MAXN 100010
#define MOD 9973

int a[MAXN<<2];
int n;
char str[MAXN];

void build(int l,int r,int now)
{
    if (l==r)
    {
        a[now] = (str[l-1]-28) % MOD;
        return;
    }
    int mid;
    mid = l+r>>1;
    build(l,mid,now<<1);
    build(mid+1,r,now<<1|1);
    a[now] = a[now<<1]*a[now<<1|1] % MOD;
}

int query(int l,int r,int now,int x,int y)
{
    if (x<=l && r<=y)
        return a[now];
    int mid,t1,t2;
    mid = l+r>>1;
    t1 = 1;
    t2 = 1;
    if (x<=mid) t1 = query(l,mid,now<<1,x,y);
    if (y>mid) t2 = query(mid+1,r,now<<1|1,x,y);
    return t1*t2 % MOD;
}

int main()
{
    int T;
    while (scanf("%d",&T)==1)
    {
        int length;
        memset(a,0,sizeof(a));
        scanf("%s",str);
        length = strlen(str);
        build(1,length,1);
        while (T--)
        {
            int x,y,ans;
            scanf("%d %d",&x,&y);
            ans = query(1,length,1,x,y);
            printf("%d\n",ans);
        }
    }
    return 0;
}
