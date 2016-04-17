// O(n^2)
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

char s[2010];
string ans;

int main()
{
    int T;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        memset(s,0,sizeof(s));
        scanf("%s",s);
        ans="";
        int l;
        l = strlen(s);
        for (int i=0;i<l;i++)
        {
            if (ans.size()==0) ans = ans+ s[i];
            else
            {
                int j,r;
                r = ans.size();
                for (j=0;j<r;j++)
                    if (ans[j]!=s[i]) break;
                if (j==r || ans[j]>s[i])
                    ans = ans + s[i];
                else
                    ans = s[i] + ans;
            }
        }
        cout << "Case #" << o << ": " << ans << endl;
    }
    return 0;
}
