/*This Code is Submitted by Timer for Problem 2941 at 2012-08-08 15:31:21*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int v;
  int pos;
};

const int maxk=100010;
int n,m,k;
cyr a[maxk];
int f[maxk];
cyr line[maxk<<1];
int head,tail;

int main()
{
  int i;
  while (scanf("%d",&k)==1)
  {
    scanf("%d%d",&n,&m);
    for (i=1;i<=k;i++)
    {
      scanf("%d",&a[i].v);
      a[i].pos=i;
    }
    memset(f,-1,sizeof(f));
    memset(line,0,sizeof(line));
    head=1;
    tail=0;
    f[0]=0;
    for (i=n;i<=k;i++)
    {
      if (line[head].pos!=0)
        if (line[head].pos<i-m)
          head++;
      if (f[i-n]>=0)
      {
        while ((head<=tail) && (f[i-n]+a[i-n+1].v>=line[tail].v))
          tail--;
        tail++;
        line[tail].v=f[i-n]+a[i-n+1].v;
        line[tail].pos=i-n;
      }
      f[i]=line[head].v+a[i].v;
    }
    printf("%d\n",f[k]);
  }
  return 0;
}