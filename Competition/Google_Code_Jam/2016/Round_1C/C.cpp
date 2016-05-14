/*
    TODO: brief solution
*/
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct ANS
{
    int j,p,s;
};

int j,p,s,k;
int jp[12][12];
int js[12][12];
int ps[12][12];
bool same[12][12][12];
vector<ANS> a;

void dfs()
{
    for (int x=1;x<=j;x++)
        for (int y=1;y<=p;y++)
            for (int zz=x+y+1;zz<=x+y+s;zz++) // z should begin with x+y+1, but don't know how to prove...
            {
                int z = zz%s;
                if (!z) z=s;
                if (!same[x][y][z])
                    if (jp[x][y]<k && js[x][z]<k && ps[y][z]<k)
                    {
                        same[x][y][z] = true;
                        jp[x][y]++;
                        js[x][z]++;
                        ps[y][z]++;
                        ANS t;
                        t.j = x;
                        t.p = y;
                        t.s = z;
                        a.push_back(t);
                    }
            }
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%d %d %d %d",&j,&p,&s,&k);
        memset(jp,0,sizeof(jp));
        memset(js,0,sizeof(js));
        memset(ps,0,sizeof(ps));
        memset(same,false,sizeof(same));
        a.clear();
        dfs();
        printf("Case #%d: %lu\n",o,a.size());
        int l;
        l = a.size();
        for (int i=0;i<l;i++)
            printf("%d %d %d\n",a[i].j,a[i].p,a[i].s);
    }
    return 0;
}
