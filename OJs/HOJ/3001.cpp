/*This Code is Submitted by Timer for Problem 3001 at 2012-05-13 21:22:56*/
#include <cstdio>

long long x,y,r,distr;

int check(long long q,long long w)
{
    long long dist;
    dist=q*q+w*w;
    if (dist<distr) return 1;
    return 0;
}

int main()
{
    long long s,sum;

    while (scanf("%lld%lld%lld",&x,&y,&r) == 3)
    {
        if (x == 0 && y == 0 && r == 0) break;
        s = 0;
        sum = 0;
        distr = r*r;
        int y = r - 1;
        for (int i = 0; i < r && y>=0; i++)
        {
            if (check(i,y) == 0)
            {
                s += r-i;
                i--;
                y--;
            }
        }
        sum=(r*r-s)*4;
        printf("%lld\n",sum);
    }
    return 0;

}