#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 2010

struct Point
{
    int x,y;
};

int s[MAXN][MAXN];
Point a[MAXN];
int n;

int main()
{
    int T,x,y,ans;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        for (int i=0;i<n;i++)
        {
            s[i][i]=0;
            for (int j=i+1;j<n;j++)
            {
                x = a[i].x - a[j].x;
                y = a[i].y - a[j].y;
                s[i][j] = x*x+y*y;
                s[j][i] = s[i][j];
            }
        }
        ans = 0;
        for (int i=0;i<n;i++)
        {
            //sort(s+i*n,s+i*n+n);
            sort(&s[i][0],&s[i][n]);
            int t,temp;
            t = 0;
            temp = 1;
            for (int j=0;j<n;j++)
            {
                if (s[i][j]==0) continue;
                if (t==s[i][j])
                {
                    temp++;
                }
                else
                {
                    ans += temp*(temp-1) / 2;
                    t = s[i][j];
                    temp = 1;
                }
            }
            ans += temp*(temp-1) / 2;
        }
        printf("Case #%d: %d\n",o,ans);
    }
    return 0;
}
