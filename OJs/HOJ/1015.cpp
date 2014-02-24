/*This Code is Submitted by Timer for Problem 1015 at 2012-09-17 20:02:21*/
/*
假设存在一个合数m，使得x%m==0,且m不含(2~根号x)的因数，那么m>(根号x)^2，即m>x，所以不存在这种合数m。
所以试除(2~根号x)之间的数，假设x只能被其中一个数整除(可以证明该数一定是质数，因为若是合数，则可被该合数的因数整除)，则其必存在另一个因数x/m，而前面已经证明了这个数不可能为合数，所以也必为一个质数，所以这两质数p1,p2都被找出。
*/
#include <cstdio>

int n;

int main()
{
        int x,t,i;
        while (scanf("%d",&n)==1)
        {
                while (n--)
                {
                        scanf("%d",&x);
                        t^=t;
                        for (i=2;i*i<=x;i++)
                                if (x%i==0)
                                {
                                        t++;
                                        if (t>=2) 
                                        {
                                                puts("No");
                                                break;
                                        }
                                }
                        if (t==1) puts("Yes");
                        if (t==0) puts("No");
                }
        }
        return 0;
}