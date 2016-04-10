// try to filp all "++++..." to input
#include <cstdio>
#include <cstring>

char s[110];

int main()
{
    int T;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%s",s);
        int l,ans,i;
        // ans&1 = 0, top is left; ans&1 = 1, top is right
        l = strlen(s);
        ans = 0;
        i = l-1; // s[] index

        // initial is "++++....."
        while (i>=0)
        {
            if (ans&1) // initial '+' -> '-'
            {
                if (s[i]=='-') // match
                    i--;
                else
                    ans++;
            }
            else // initial '+' -> '+'
            {
                if (s[i]=='+') // match
                    i--;
                else
                    ans++;
            }
        }
        printf("Case #%d: %d\n",o,ans);
    }
    return 0;
}
