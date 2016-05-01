/*
    Bipartite graphs
    Minimum edge cover = |V| - maximum matching

    Maximum matching: Hungarian method

    Problem: Select minimum number of edges that can cover all vertex.
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>

using namespace std;

#define MAXN 1010

int n,c1,c2;
int a[MAXN][MAXN];
map<string,int> w1,w2;
bool cover[MAXN];
int link[MAXN];

bool find(int x)
{
    for (int j=1;j<=c2;j++)
        if (!cover[j] && a[x][j])
        {
            int k;
            k = link[j];
            link[j] = x;
            cover[j] = true;
            if (k==0 || find(k)) return true;
            link[j] = k;
        }
    return false;
}

int main()
{
    int o,T;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        w1.clear();
        w2.clear();
        c1=0;
        c2=0;
        memset(a,0,sizeof(a));
        memset(link,0,sizeof(link));
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            string s1,s2;
            cin >> s1 >> s2;
            if (w1.find(s1)==w1.end())
            {
                c1++;
                w1[s1]=c1;
            }
            if (w2.find(s2)==w2.end())
            {
                c2++;
                w2[s2]=c2;
            }
            a[w1[s1]][w2[s2]]=1;
        }

        for (int i=1;i<=c1;i++)
        {
            memset(cover,false,sizeof(cover));
            find(i);
        }
        int sum;
        sum = 0;
        for (int j=1;j<=c2;j++)
            if (link[j]!=0) sum++;
        //printf("max matching = %d, c1 = %d, c2 = %d, N = %d\n",sum,c1,c2,n);
        printf("Case #%d: %d\n",o,n-(c1+c2-sum));
    }
    return 0;
}
