/*This Code is Submitted by Timer for Problem 1099 at 2012-02-23 16:33:51*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int x;
  int y;
};

int n;
struct cyr v[701];

int main()
{
  int i,j,k;
  int s,max,t,u;
  scanf("%d",&n);
  while (n!=0)
  {
    memset(v,0,sizeof(v));
    max=2;
    for (i=1;i<=n;i++)
      scanf("%d%d",&v[i].x,&v[i].y);
    for (i=1;i<n;i++)
    {
      for (j=i+1;j<=n;j++)
      {  
        s=2;
        t=v[i].x-v[j].x;
        u=v[i].y-v[j].y;
        for (k=j+1;k<=n;k++)
        {
          if (t*(v[k].y-v[i].y)==u*(v[k].x-v[i].x))
            s++;
        }
        if (s>max) max=s;
      }
    }
    printf("%d\n",max);
    scanf("%d",&n);
  }
  return 0;
}