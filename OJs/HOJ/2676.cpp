/*This Code is Submitted by Timer for Problem 2676 at 2012-07-11 00:08:46*/
#include <cstdio>
#include <cstring>

using namespace std;

int set[5050];
int n,m,q;

int findset(int x)
{
    if (set[x]==x) return x;
    else
      set[x]=findset(set[x]);
    return set[x];
}

void unionset(int x,int y)
{
    int fx,fy;
    fx=findset(x);
    fy=findset(y);
    set[fy]=fx;
}

int main()
{
    int i,x,y,fx,fy;
    while (scanf("%d%d%d",&n,&m,&q)==3)
    {
        for (i=1;i<=n;i++)
          set[i]=i;
        for (i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            unionset(x,y);
        }
        for (i=1;i<=q;i++)
        {
            scanf("%d%d",&x,&y);
            fx=findset(x);
            fy=findset(y);
            if (fx==fy) printf("yes\n");
              else printf("no\n");
        }
    }
    return 0;
}
 