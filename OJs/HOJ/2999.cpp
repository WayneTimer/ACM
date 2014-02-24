/*This Code is Submitted by Timer for Problem 2999 at 2012-07-09 08:40:36*/
#include <cstdio>
#include <cstring>

int v[1600];

int main()
{

    int n;
    bool f;
    int h1, m1, h2, m2, s, t;
    while(scanf("%d",&n) == 1 && n)
    {
        memset(v,0,sizeof(v));
        f = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d:%d-%d:%d",&h1,&m1,&h2,&m2);
            if(!f){
            s = h1 * 60 + m1;
            t = h2 * 60 + m2;
            for (int j = s; j < t; j++)
            {
                if (v[j])
                {
                    f = 1;
                    break;
                }
                v[j] = 1;
            }
            }
        }
        if (f) printf("conflict\n"); else printf("no conflict\n");
    }

    return 0;
}