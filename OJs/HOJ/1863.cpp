/*This Code is Submitted by Timer for Problem 1863 at 2011-10-29 21:38:33*/
#include <stdio.h>

int a[11];

void quick(int l,int r)
{
    int i,j,mid,t;
    i=l;
    j=r;
    mid=a[(l+r)/2];
    do
    {
        while (a[i]<mid) i++;
        while (a[j]>mid) j--;
        if (i<=j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
            j--;
        }
    } while (i<=j);
    if (l<j) quick(l,j);
    if (i<r) quick(i,r);
}

int main()
{
    int p,r,n,e;
    scanf("%d",&n);
    for (r=1;r<=n;r++)
    {
        for (e=1;e<=10;e++)
          scanf("%d",&a[e]);
        quick(1,10);
        printf("%d",a[1]);
        for (e=2;e<=10;e++)
          printf(" %d",a[e]);
        printf("\n");
    }
    return 0;
}
 