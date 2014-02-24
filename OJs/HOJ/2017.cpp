/*This Code is Submitted by Timer for Problem 2017 at 2011-11-21 01:44:40*/
#include <stdio.h>

int main()
{
    long n,k,s,x,y;
    while (scanf("%ld%ld",&n,&k)==2)
    {
        s=0;
        while ((n/k)>0)
        {
            x=n/k;
            y=n%k;
            s=s+n-y;
            n=y;
            n=n+x;
        }
        s=s+n;
        printf("%ld\n",s);
    }
    return 0;
}
 