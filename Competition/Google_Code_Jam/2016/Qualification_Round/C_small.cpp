#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 32

// for MAXN = 32, sqrt(10^32-1) = 10^16
#define MAXP 65536

vector<int> prime;
int a[MAXN+1];
int n,p_size;

void make_prime()
{
    int p[MAXP+1];
    memset(p,0,sizeof(p));

    for (int i=2;i*i<=MAXP;i++)
    {
        for (int j=i;i*j<=MAXP;j++)
            p[i*j] = 1;
    }

    prime.clear();
    for (int i=2;i<=MAXP;i++)
    {
        if (p[i]==0) prime.push_back(i);
    }
    p_size = prime.size();

    // printf("prime.size() = %d\n",p_size);
}

int check(unsigned long long x) // if x is prime, return 0, else return divisors
{
    for (int i=0;i<p_size;i++)
    {
        unsigned long long t;
        t = prime[i];
        t*=t;
        if (t>x) break;
        if (x%prime[i]==0) return prime[i];
    }
    return 0;
}

bool process() // if all is not prime, then true
{
    int ans[11];
    for (int i=2;i<=10;i++)
    {
        unsigned long long x,t;
        t = 1;
        x = 0;
        for (int j=n-1;j>=0;j--)
        {
            x += t*a[j];
            t*=i;
        }
        ans[i] = check(x);
        if (ans[i]==0)
            return false;
    }
    for (int i=0;i<n;i++)
        printf("%d",a[i]);
    for (int i=2;i<=10;i++)
        printf(" %d",ans[i]);
    puts("");
    return true;
}

int main()
{
    int T,j;
    scanf("%d",&T);
    make_prime();
    for (int o=1;o<=T;o++)
    {
        scanf("%d %d",&n,&j);
        printf("Case #%d:\n",o);

        memset(a,0,sizeof(a));
        a[0] = 1;
        a[n-1] = 1;
        while (j)
        {
            if (process()) j--;
            int k;
            k = n-2;
            a[k]++;
            while (a[k]>1 && k>0)
            {
                a[k]%=2;
                a[k-1]++;
                k--;
            }
        }
    }
    return 0;
}
