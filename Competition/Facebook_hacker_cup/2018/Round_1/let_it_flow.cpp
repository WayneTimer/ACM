#include <cstdio>
#include <cstring>

#define MAXN 1010
#define MOD 1000000007

int f[3][MAXN][4];
bool a[3][MAXN];
char str[MAXN];

int main()
{
    int T,N;
    scanf("%d", &T);
    
    for (int o = 1; o <= T; o++)
    {
        memset(f, 0, sizeof(f));
        memset(a, true, sizeof(a));
        scanf("%d", &N);
        gets(str);
        for (int i = 0; i < 3; i++)
        {
            gets(str);
            for (int j = 0; j < N; j++)
                if (str[j] == '#')
                    a[i][j+1] = false;
        }
        
        f[0][0][0] = 1;
        for (int j = 1; j <= N; j++)
        {
            for (int i = 0; i < 3; i++)
                if (a[i][j])
                {
                    f[i][j][2] = f[i][j-1][0] + f[i][j-1][1];
                    f[i][j][2] %= MOD;
                    f[i][j][3] = f[i][j][2];
                    
                    if (i > 0) f[i][j][0] = f[i-1][j][2] % MOD;
                }
            for (int i = 1; i >= 0; i--)
                if (a[i][j])
                    f[i][j][1] = f[i+1][j][3] % MOD;
        }
        printf("Case #%d: %d\n", o, (f[2][N][0] + f[2][N][1]) % MOD);
    }
    return 0;
}
