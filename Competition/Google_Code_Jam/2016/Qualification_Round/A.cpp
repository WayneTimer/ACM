#include <cstdio>
#include <cstring>

bool a[10];

int main()
{
    int T,n;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%d",&n);
        if (n==0)
        {
            printf("Case #%d: INSOMNIA\n",o);
            continue;
        }
        int cnt = 0;
        memset(a,true,sizeof(a));
        int x = 0;
        while (cnt<10)
        {
            x+=n;
            int y;
            y = x;
            while (y)
            {
                int u;
                u = y%10;
                if (a[u])
                {
                    a[u] = false;
                    cnt++;
                }
                y/=10;
            }
        }
        printf("Case #%d: %d\n",o,x);
    }
    return 0;
}
