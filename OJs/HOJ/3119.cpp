/*This Code is Submitted by Timer for Problem 3119 at 2012-05-20 21:35:49*/
#include <cstdio>
#include <cstring>

using namespace std;

int a[110][110];
int n,m;

int main()
{
    int T,o,x,t1,t2,i,j;
    scanf("%d",&T);
    for (o=1;o<=T;o++)
    {
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                scanf("%d",&x);
                if (i==1)
                {
                  if (j==1) a[i][j]=x;
                  else
                  {
                      a[i][j]=a[i][j-1]+x;
                  }
                }
                else
                {
                    if (j==1) a[i][j]=a[i-1][j]+x;
                    else
                    {
                        t1=a[i-1][j];
                        t2=a[i][j-1];
                        if (t1>=t2) a[i][j]=t1+x;
                          else a[i][j]=t2+x;
                    }
                }
            }
        }
        printf("%d\n",a[n][m]);
    }
    return 0;
}