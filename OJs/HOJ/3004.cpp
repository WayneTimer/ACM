/*This Code is Submitted by Timer for Problem 3004 at 2012-07-09 08:43:28*/
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int m, g, z, s, e;
    int i, j, k;
    int ans;
    while(1)
    {
        scanf("%d%d%d%d%d", &m, &g, &z, &s, &e);
        if(!m && !g && !z && !s && !e) break;
        ans=0;
        for(i=0; i*100<=m; i++)
        {
            for(j=0; i*100+j*125<=m && j*50<=g; j++)
            {
                k=min((m-i*100-j*125)/50, (g-j*50)/100);
                ans=max(ans, i*z+j*s+k*e);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}