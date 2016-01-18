#include <cstdio>

#define MAXN 100010

int n;
int a[MAXN];

int main()
{
    int T,ans,last,cnt;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%d",&n);
        ans = 0;
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        cnt = 0;
        for (int i=0;i<n;i++)
        {
            if (cnt==0)
            {
                last = a[i];
                cnt++;
                continue;
            }
            if (a[i]<=last)
            {
                ans += 4-cnt;
                cnt = 1;
                last = a[i];
            }
            else if (a[i]-last<=10)
            {
                last = a[i];
                cnt++;
                cnt%=4;
            }
            else
            {
                last = last+10;
                cnt++;
                ans++;
                cnt%=4;
                i--;
            }
        }
        if (cnt!=0) ans += 4-cnt;
        printf("Case #%d: %d\n",o,ans);
    }
    return 0;
}
