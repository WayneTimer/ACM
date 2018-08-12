#include <cstdio>
#include <cstring>

char str[60][30];

long long v, x;
int n, k, y, first;

int main()
{
    int T;
    memset(str, 0, sizeof(str));
    scanf("%d", &T);
    for (int o = 1; o <= T; o++)
    {
        scanf("%d %d %lld", &n, &k, &v);
        for (int i = 0; i < n; i++)
          scanf("%s", str[i]);
        x = (v-1)*k%n;
        y = n - x;
        first = k - y;

        int cnt = 0;
        printf("Case #%d:", o);
        for (int i = 0; i < first; i++)
        {
            printf(" %s", str[i]);
            cnt++;
            if (cnt >= k)
                break;
        }
        if (cnt >= k)
        {
            printf("\n");
            continue;
        }
        for (int i = n - y; i < n; i++)
        {
            printf(" %s", str[i]);
            cnt++;
            if (cnt >= k)
                break;
        }
        if (cnt >= k)
        {
            printf("\n");
            continue;
        }
    }
    return 0;
}
