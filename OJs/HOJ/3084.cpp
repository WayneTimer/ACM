/*This Code is Submitted by Timer for Problem 3084 at 2011-12-25 15:09:28*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void qsort(int p[],int l,int r)
{
    int i,j,mid,t;
    i=l;
    j=r;
    mid=p[(l+r)/2];
    do
    {
        while (p[i]<mid) i++;
        while (p[j]>mid) j--;
        if (i<=j)
        {
            t=p[i];
            p[i]=p[j];
            p[j]=t;
            i++;
            j--;
        }
    } while (i<=j);
    if (l<j) qsort(p,l,j);
    if (i<r) qsort(p,i,r);
}

int main()
{
    int n,i;
    int a[1010],b[1010];
    long long sum;
    while (scanf("%d",&n)==1)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        sum=0;
        for (i=1;i<=n;i++)
          scanf("%d",&a[i]);
        for (i=1;i<=n;i++)
          scanf("%d",&b[i]);
        qsort(a,1,n);
        qsort(b,1,n);
        for (i=1;i<=n;i++)
          sum=sum+abs(a[i]-b[i]);
        printf("%lld\n",sum);
    }
    return 0;
}
 
