/*This Code is Submitted by Timer for Problem 1191 at 2012-07-24 13:27:27*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char a[110];

int main()
{
    int l;
    scanf("%s",a);
    while (a[0]!='#')
    {
        l=strlen(a);
        if (next_permutation(a,a+l)) printf("%s\n",a);
          else printf("No Successor\n");
        scanf("%s",a);
    }
    return 0;
}
 