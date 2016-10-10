#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int v;
  int pos;
};

const int maxn=1000010;
cyr a[maxn];
int min_ans[maxn];
int max_ans[maxn];
cyr min[maxn];
cyr max[maxn];
int n,k;

int main()
{
  int i,headmax,tailmax,headmin,tailmin;
  scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a[i].v);
    a[i].pos=i;
  }
  headmax=1;
  tailmax=0;
  headmin=1;
  tailmin=0;
  memset(max,0,sizeof(max));
  memset(min,0,sizeof(min));
  for (i=1;i<=n;i++)
  {
    if (min[headmin].pos!=0)
      if ((i-min[headmin].pos)>=k)
        headmin++;
    while ((headmin<=tailmin) && (a[i].v<=min[tailmin].v))
      tailmin--;
    tailmin++;
    min[tailmin]=a[i];
    min_ans[i]=min[headmin].v;
    //-------------------------------
    if (max[headmax].pos!=0)
      if ((i-max[headmax].pos)>=k)
        headmax++;
    while ((headmax<=tailmax) && (a[i].v>=max[tailmax].v))
      tailmax--;
    tailmax++;
    max[tailmax]=a[i];
    max_ans[i]=max[headmax].v;
  }
  printf("%d",min_ans[k]);
  for (i=k+1;i<=n;i++)
    printf(" %d",min_ans[i]);
  printf("\n");
  printf("%d",max_ans[k]);
  for (i=k+1;i<=n;i++)
    printf(" %d",max_ans[i]);
  printf("\n");
  return 0;
}