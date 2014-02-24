/*This Code is Submitted by Timer for Problem 1003 at 2011-10-08 17:47:24*/
#include <stdio.h>

long long n;
int i,m,p[5001],a[5001];

void sort(int l,int r);

void sub()
{
    long long sum;
    int i;
    sum=0;
    for (i=1;i<=m;i++)
    {
        if (n>=a[i])
        {
            sum=sum+p[i]*a[i];
            n=n-a[i];
        }
        if ((n<a[i]) && (n>0))
        {
            sum=sum+p[i]*n;
            n=n-a[i];
        }
    }
    printf("%d\n",sum);
}

int main()
{
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
      scanf("%d%d",&p[i],&a[i]);
    sort(1,m);
    sub();
    return 0;
}

void sort(int l,int r)
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
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        i++;
        j--;
    }
    } while (i<=j);
    if (l<j) sort(l,j);
    if (i<r) sort(i,r);
}