#include <cstdio>
#include <queue>

using namespace std;

int n,p;
queue<int> q;

int main()
{
    int T,s,x;
    long long ans;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%d%d",&n,&p);
        s = 0;
        ans = 0;
        while (!q.empty()) q.pop();
        for (int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if (s<=p-x)
            {
                q.push(x);
                s+=x;
            }
            else
            {
                while (s>0)
                {
                    ans+=q.size();
                    s-=q.front();
                    q.pop();
                    if (s<=p-x) break;
                }
                if (s<=p-x)
                {
                    q.push(x);
                    s+=x;
                }
            }
        }
        long long tmp;
        tmp = q.size();
        ans+=(tmp+1)*tmp/2;
        printf("Case #%d: %lld\n",o,ans);
    }
    return 0;
}
