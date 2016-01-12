#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 1010

class Point
{
public:
    int x,y;

    Point(int _x,int _y)
    {
        x = _x;
        y = _y;
    }
};

int n;
char str[MAXN];
vector<Point> v; // 1-length segment
int a[2][MAXN]; // segment ID
int id;
int hash[MAXN<<1];

int main()
{
    int T,size;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        v.clear();
        id = 0;
        scanf("%d",&n);
        gets(str);
        for (int i=0;i<2;i++)
        {
            gets(str);
            size = 0;
            for (int j=0;j<n;j++)
            {
                if (str[j]=='.')
                {
                    if (j==0 || str[j-1]=='X')
                    {
                        id++;
                    }
                    a[i][j] = id;
                    size++;
                }
                else
                {
                    if (size==1 && j!=0) v.push_back(Point(i,j-1));
                    size = 0;
                    a[i][j] = -1;
                }
            }
            if (size==1) v.push_back(Point(i,n-1));
        }
        memset(hash,0,sizeof(hash));
        int l,ans;
        l = v.size();
        ans = id;
        for (int i=0;i<l;i++)
        {
            int t1,t2;
            t1 = a[v[i].x][v[i].y];
            t2 = a[v[i].x^1][v[i].y];
            if (hash[t1]==0)
            {
                if (t2!=-1 && hash[t2]==0)
                {
                    ans--;
                    hash[t2] = 1;
                }
            }
        }
        printf("Case #%d: %d\n",o,ans);
    }
    return 0;
}
