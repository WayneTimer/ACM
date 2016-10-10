#include <cstdio>

using namespace std;

int main()
{
    int n,m,g,a,b,s;
    scanf("%d%d",&n,&m);
    while (!((n==0)&&(m==0)))
    {
        s=0;
        a=n%10;
        b=m%10;
        n=n/10;
        m=m/10;
        g=0;
        while ((a)||(b))
        {
            a=a+b+g;
            g=0;
            if (a>=10)
            {
                g=1;
                a=a-10;
                s++;
            }
            a=n%10;
            b=m%10;
            n=n/10;
            m=m/10;
        }
        if (s==0) printf("No");
          else printf("%d",s);
        if (s<=1) printf(" carry operation.\n");
          else printf(" carry operations.\n");
        scanf("%d%d",&n,&m);
    }
    return 0;
}
