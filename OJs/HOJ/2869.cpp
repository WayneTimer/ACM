/*This Code is Submitted by Timer for Problem 2869 at 2012-07-11 00:44:44*/
#include <cstdio>

using namespace std;

int main()
{
    int e,f,c,s,t;
    while (scanf("%d%d%d",&e,&f,&c)==3)
    {
        e=e+f;
        s=0;
        while (e>=c)
        {
            t=e/c;
            s+=t;
            e=e%c;
            e+=t;
        }
        printf("%d\n",s);
    }
    return 0;
}
 