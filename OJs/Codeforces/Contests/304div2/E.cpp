// maxflow
#include <cstdio>
#include <cstring>

#define MAXN 203
#define MAXF 100

int nn,n,m,sum;
int limit[MAXN][MAXN];
int flow[MAXN][MAXN];

void maxflow()
{
    int i,j,delta,x;
    int last[MAXN];
    bool check[MAXN];

    do
    {
        memset(last,0,sizeof(last));
        memset(check,false,sizeof(check));
        last[1]=MAXN;
        do
        {
            i=0;
            do
            {
                i++;
                if (i>=n || (last[i]!=0 && !check[i]))
                    break;
            } while (true);
            if (i>=n) break;
            for (j=1;j<n;j++)
                if (last[j]==0)
                    if (flow[i][j]<limit[i][j])
                        last[j]=i;
                    else if (flow[j][i]>0)
                        last[j]=-i;
            check[i]=true;
        } while (last[n-1]==0); // find augmenting path
        if (last[n-1]==0) break;
        delta=99999999;
        i=n-1;
        do
        {
            j=i;
            if (last[j]<0)
                i=-last[j];
            else
                i=last[j];
            if (last[j]>0)
                x=limit[i][j]-flow[i][j];
            else
                x=flow[j][i];
            if (x<delta) delta=x;
        } while (i!=1);
        i=n-1;
        do
        {
            j=i;
            if (last[j]<0)
                i=-last[j];
            else
                i=last[j];
            if (last[j]>0)
                flow[i][j]+=delta;
            else
                flow[j][i]-=delta;
        } while (i!=1);
    } while (true);
}

inline bool check()
{
    int s;
    s=0;
    for (int j=2;j<2+nn;j++)
        if (flow[1][j]>0) s+=flow[1][j];
    if (s==sum) return true;
    return false;
}

inline void print()
{
    for (int i=2;i<2+nn;i++)
    {
        for (int j=2+nn;j<2+(nn<<1);j++)
            if (flow[i][j]>0) printf("%d ",flow[i][j]);
            else printf("0 ");
        puts("");
    }
}

inline bool build()
{
    int s1,s2;

    s1=s2=0;
    memset(limit,0,sizeof(limit));
    memset(flow,0,sizeof(flow));
    scanf("%d%d",&n,&m);
    nn=n;
    for (int j=2;j<=n+1;j++)
    {
        scanf("%d",&limit[1][j]);
        s1+=limit[1][j];
        limit[j][j+n]=MAXF;
    }
    n=(n<<1)+1;
    for (int i=n-nn+1;i<=n;i++)
    {
        scanf("%d",&limit[i][n+1]);
        s2+=limit[i][n+1];
    }
    n+=2;

    if (s1!=s2) return false;
    sum=s1;

    for (int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        limit[x+1][y+1+nn]=MAXF;
        limit[y+1][x+1+nn]=MAXF;
    }
    return true;
}

int main()
{
    if (!build())
        puts("NO");
    else
    {
        maxflow();
        if (check())
        {
            puts("YES");
            print();
        }
        else
            puts("NO");
    }

    return 0;
}
