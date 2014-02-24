/*This Code is Submitted by Timer for Problem 3112 at 2012-05-20 22:43:12*/
#include <cstdio>
#include <cstring>

#define MAX 54381300

using namespace std;

bool f[MAX];
int b[1000010];
int n;

int main()
{
    int i,a,x,j;
    i=1;
    memset(f,false,sizeof(f));
    f[1]=true;
    while ((i<<1|1)<=MAX)
    {
        if (f[i])
        {
            a=i<<1|1;
            if (a<=MAX)
            {
                f[a]=true;
            }
            a=i*3+1;
            if (a<=MAX)
            {
                f[a]=true;
            }
        }
        i++;
    }
    memset(b,0,sizeof(b));
    j=0;
    for (i=1;i<=MAX;i++)
    {
        if (f[i])
        {
            j++;
            b[j]=i;
            if (j>=1000000) break;
        }
    }
    while (scanf("%d",&n)==1)
    {
       printf("%d\n",b[n]);
    }
    return 0;
}
 