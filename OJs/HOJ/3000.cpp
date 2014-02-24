/*This Code is Submitted by Timer for Problem 3000 at 2012-05-13 21:27:41*/
#include <cstdio>
#include <cstring>

using namespace std;

double a[105][15];
int n,m;

void qsort(int l,int r,int e)
{
    int i,j;
    double mid,t;
    i=l;
    j=r;
    mid=a[(l+r)/2][e];
    do
    {
        while (a[i][e]<mid) i++;
        while (a[j][e]>mid) j--;
        if (i<=j)
        {
            t=a[j][e];
            a[j][e]=a[i][e];
            a[i][e]=t;
            i++;
            j--;
        }
    } while (i<=j);
    if (l<j) qsort(l,j,e);
    if (i<r) qsort(i,r,e);
}

int main()
{
    double s,w;
    int i,j;
    scanf("%d%d",&n,&m);
    while (n||m)
    {
        memset(a,0,sizeof(a));
        for (i=1;i<=n;i++)
          for (j=1;j<=m;j++)
            scanf("%lf",&a[i][j]);
        for (j=1;j<=m;j++)
          qsort(1,n,j);
        s=0;
        for (i=1;i<=n;i++)
        {
            w=1;
            for (j=1;j<=m;j++)
              w=w*a[i][j];
            s=s+w;
        }
        printf("%.4lf\n",s);
        scanf("%d%d",&n,&m);
    }
    return 0;
}