/*This Code is Submitted by Timer for Problem 1305 at 2012-03-05 23:59:45*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  char name[201];
  long s;
  long time;
};

int n;
cyr a[1001];

int main()
{
  int i,j;
  long sum,x,y;
  char e[201];
  while (scanf("%d",&n)==1)
  {
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++)
    {
      scanf("%s",e);
      strcpy(a[i].name,e);
      for (j=1;j<=4;j++)
      {
        scanf("%ld%ld",&x,&y);
        if (y!=0) 
        {
          sum=y+(x-1)*20;
          a[i].s++;
          a[i].time=a[i].time+sum;
        }
      }
    }
    x=a[1].s;
    y=a[1].time;
    strcpy(e,a[1].name);
    for (i=2;i<=n;i++)
    {
      if (a[i].s>x)
      {
        x=a[i].s;
        y=a[i].time;
        strcpy(e,a[i].name);
      }
      if (a[i].s==x)
        if (a[i].time<y)
        {
          x=a[i].s;
          y=a[i].time;
          strcpy(e,a[i].name);
        }
    }
    printf("%s %ld %ld\n",e,x,y);
  }
  return 0;
}