/*This Code is Submitted by Timer for Problem 3120 at 2012-05-20 21:36:14*/
#include <cstdio>

using namespace std;

int main()
{
    int q,p,c,i,t;
    scanf("%d",&t);
    for (i=1;i<=t;i++)
    {
        scanf("%d%d%d",&p,&q,&c);
        if (q==p)
          printf("0\n");
        if (p>q)
        {
            printf("%d\n",p-q);
        }
        if (p<q)
        {
            p=p+c;
            p=p-q;
            printf("%d\n",p%c);
        }
    }
    return 0;
}