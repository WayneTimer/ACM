#include <cstdio>

#define MAXN 100010

int n,a,b;
int c[MAXN];
long long sum;
double ans;

int main()
{
    int T;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%d %d %d",&n,&a,&b);
        ans = 0.0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&c[i]);
            if (i==0) sum = c[i];
            else sum += c[i];
        }

        long long t,down;
        t = a/sum;
        a%=sum;
        b-=sum*t;

        int i,j;
        for (i=0;i<n;i++)
            if (a>=c[i])
            {
                a-=c[i];
                b-=c[i];
            }
            else
                break;

        down = b-a;
        if (a>0)
        {
            double t1,t2,t3,t4;
            long long m;
            if (b<c[i]) m = b;
            else m = c[i];
            t1 = m-a;
            t2 = down;
            t3 = a+m;
            t4 = 2.0;
            ans += t1*t3/t2/t4;
            a = 0;
            b = b-m;
            i++;
            i%=n;
        }
        if (b==0)
        {
            printf("Case #%d: %.9lf\n",o,ans);
            continue;
        }
        j = i; // circle end

        long long cnt,extra;
        cnt = b/sum;
        extra = b%sum;

        do
        {
            double t1,t2,t3;
            t1 = c[i];
            t2 = down;
            t3 = c[i]/2.0;
            if (extra>=c[i])
            {
                ans += t1/t2*t3*(cnt+1);
                extra-=c[i];
            }
            else
            {
                ans += t1/t2*t3*cnt;
                t1 = extra;
                t3 = extra/2.0;
                ans += t1/t2*t3;
                extra = 0;
            }

            i++;
            i%=n;
        } while (i!=j);

        printf("Case #%d: %.9lf\n",o,ans);
    }
    return 0;
}
