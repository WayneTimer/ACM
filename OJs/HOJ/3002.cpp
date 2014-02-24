/*This Code is Submitted by Timer for Problem 3002 at 2012-05-13 21:22:04*/
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int a[100002];

void qsort(int l,int r)
{
    int mid,i,j,t;
    i=l;
    j=r;
    mid=a[(l+r)/2];
    do
    {
        while (a[i]<mid) i++;
        while (a[j]>mid) j--;
        if (i<=j)
        {
            t=a[j];
            a[j]=a[i];
            a[i]=t;
            i++;
            j--;
        }
    } while (i<=j);
    if (l<j) qsort(l,j);
    if (i<r) qsort(i,r);
}

int main()
{
    int i,head,tail;
    scanf("%d",&n);
    while (n!=0)
    {
        memset(a,0,sizeof(a));
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        qsort(1,n);
        head=1;
        tail=2;
        while (tail<=n)
        {
            if (a[head]<a[tail])
            {
                head++;
                tail++;
            }
            else
            {
                tail++;
            }
        }
        printf("%d\n",n-head+1);
        scanf("%d",&n);
    }
    return 0;
}