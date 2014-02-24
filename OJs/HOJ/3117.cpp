/*This Code is Submitted by Timer for Problem 3117 at 2012-05-20 21:35:21*/
#include <cstdio>
#include <cstring>

using namespace std;

int n1,n2;
int a[105],b[105];

int main()
{
    int T,o,i,temp,x;
    int s,max;
    bool flag;
    scanf("%d",&T);
    for (o=1;o<=T;o++)
    {
        memset(a,false,sizeof(a));
        memset(b,false,sizeof(b));
        scanf("%d%d",&n1,&n2);
        for (i=1;i<=n1;i++)
        {
          scanf("%d",&x);
          a[x]=true;
        }
        for (i=1;i<=n2;i++)
        {
          scanf("%d",&x);
          b[x]=true;
        }
        max=0;
        flag=false;
        for (i=0;i<=100;i++)
          if (a[i]&&b[i])
          {
              max=max+i;
              flag=true;
          }
        if (flag) printf("%d\n",max);
          else printf("NONE\n");
    }
    return 0;
}