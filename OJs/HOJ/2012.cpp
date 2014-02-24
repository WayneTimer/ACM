/*This Code is Submitted by Timer for Problem 2012 at 2012-01-01 17:39:25*/
#include <stdio.h>
#include <string.h>

void qsort(int b[],long l,long r)
{
    long mid,t,i,j;
    i=l;
    j=r;
    mid=b[(l+r)/2];
    do
    {
        while (b[i]<mid) i++;
        while (b[j]>mid) j--;
        if (i<=j)
        {
            t=b[j];
            b[j]=b[i];
            b[i]=t;
            i++;
            j--;
        }
    } while (i<=j);
    if (l<j) qsort(b,l,j);
    if (i<r) qsort(b,i,r);
}

int main()
{
    long N,p,s,t,i,j,sum;
    int a[10001];
    while (scanf("%ld",&N)==1)
    {
        memset(a,0,sizeof(a));
        for (i=1;i<=N;i++)
          scanf("%d",&a[i]);
        scanf("%ld",&sum);
        qsort(a,1,N);
        p=1;
        s=0;
        t=0;
        do
        {
          s=a[p]+a[p+1]-1;
          p++;
          a[p]=s;
          j=p;
          while ((j<N)&&(a[j]<a[j+1]))
          {
              t=a[j];
              a[j]=a[j+1];
              a[j+1]=t;
              j++;
          }
        } while (p<N);
        if (sum==a[p]) printf("GREAT!\n");
          else printf("POOR!\n");
    }
    return 0;
}
 