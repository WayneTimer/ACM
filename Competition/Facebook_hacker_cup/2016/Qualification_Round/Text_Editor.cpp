#include <cstdio>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 310

int n,k;
vector<string> w;
int lcp[MAXN]; // length of longest-common-prefix between w[i],w[i+1]
// The LCP between w[i],w[j] is min(lcp[i],lcp[i+1],..,lcp[j-1])

int f[MAXN][MAXN]; // f[i][j]: {print j words, and the last word is w[i]}'s min operations

void LCP()
{
    for (int i=0;i<n-1;i++)
    {
        int j;
        for (j=0;j<w[i].length();j++)
        {
            if (j>=w[i+1].length()) break;
            if (w[i][j]!=w[i+1][j]) break;
        }
        lcp[i]=j;
    }
}

int get_lcp(int x,int y)
{
    int ret;
    ret = lcp[x];
    for (int i=x+1;i<y;i++)
        if (lcp[i]<ret) ret = lcp[i];
    return ret;
}

void DP()
{
    for (int i=0;i<n;i++)
    {
        f[i][1] = w[i].length()+1; // 1 for printing
    }
    for (int j=2;j<=k;j++)
        for (int i=0;i<n;i++)
        {
            int cost;
            cost = -1;
            for (int u=i-1;u>=0;u--)
            {
                if (f[u][j-1]==-1) continue;
                int t;
                t = get_lcp(u,i);
                t = f[u][j-1] + w[i].length()-t + w[u].length()-t + 1;
                if (cost==-1 || t<cost) cost = t;
            }
            f[i][j] = cost;
        }
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        w.clear();
        scanf("%d%d",&n,&k);
        for (int i=0;i<n;i++)
        {
            string str;
            cin>>str;
            w.push_back(str);
        }
        sort(w.begin(),w.end());
        LCP();
        DP();
        int ans = -1;
        for (int i=0;i<n;i++)
            if (f[i][k]!=-1)
                if (ans==-1 || f[i][k]+w[i].length() < ans)
                    ans = f[i][k]+w[i].length();
        printf("Case #%d: %d\n",o,ans);
    }
    return 0;
}
