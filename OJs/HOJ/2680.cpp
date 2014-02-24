/*This Code is Submitted by Timer for Problem 2680 at 2012-09-27 17:56:17*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct cyr
{
    int x,y,v;
};

int n,m,k;
int a[50002],b[50002];
priority_queue <cyr> q;
int f[50002];

bool operator < (cyr e,cyr r)
{
    if (e.v>=r.v) return true;
    return false;
}

int main()
{
    int i,j;
    cyr temp,t1;
    bool flag;
    while (scanf("%d%d%d",&n,&m,&k)==3)
    {
        memset(f,0,sizeof(f));
        flag=false;
        for (i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (i=1;i<=m;i++)
            scanf("%d",&b[i]);
        sort(a+1,a+1+n);
        sort(b+1,b+1+m);
        while (!q.empty()) q.pop();
        for (i=1;i<=n;i++)
        {
        temp.x=i;
        temp.y=1;
        temp.v=a[i]+b[1];
        q.push(temp);
        }
        f[1]=1;
        while (k--)
        {
            temp=q.top();
            q.pop();
            if (flag) putchar(' ');
              else flag=true;
            printf("%d",temp.v);
            i=temp.x;
            j=temp.y;
            /*
            if (i+1<=n)
            {
                t1.x=i+1;
                t1.y=j;
                t1.v=a[i+1]+b[j];
                if (f[t1.x]<t1.y)
                {
                  q.push(t1);
                  f[t1.x]=t1.y;
                }
            }
            */
            if (j+1<=m)
            {
                t1.x=i;
                t1.y=j+1;
                t1.v=a[i]+b[j+1];
                if (f[t1.x]<t1.y)
                {
                  q.push(t1);
                  f[t1.x]=t1.y;
                }
            }
        }
        puts("");
    }
    return 0;
}