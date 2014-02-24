/*This Code is Submitted by Timer for Problem 1987 at 2011-10-25 21:48:21*/
#include <stdio.h>
#include <math.h>

int main()
{
    long long a[10001];
    long long t,i,n,m;
    double y,x;
    scanf("%lld%lld",&n,&m);
    a[0]=0;
    a[1]=1;
    a[2]=2;
    a[3]=3;
    while (!((n==0) && (m==0)))
    {
        for (i=4;i<=n;i++)
        {
            a[i]=(a[i-1]+a[i-3])%m;
        }
        if (n<=0)
        {
            x=(double) (n);
            x=-x;
            y=(double) (m);
            y=x/y;
            t=(int) floor(y+0.5);
            n=n-m*(-t);
            printf("%lld\n",n);
        } else printf("%lld\n",a[n]%m);
        scanf("%lld%lld",&n,&m);
    }
    return 0;
}
 
