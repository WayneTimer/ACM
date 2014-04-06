//二分
#include <cstdio>

int n,m;
int a[500100];

inline int calc(int v)
{
  int i,ret,t;
  ret=0;
  for (i=1;i<=n;i++)
  {
    /*
    ret+=a[i]/v;
    if (a[i]%v) ret++;
    可简写成如下 */
    ret+=(a[i]+v-1)/v;
  }
  return ret;
}

int main()
{
  int l,r,mid,t,i;
  scanf("%d%d",&n,&m);
  while (!(n==-1 && m==-1))
  {
    r=-1;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      if (a[i]>r) r=a[i];
    }
    l=1;
    while (l<r)
    {
      mid=l+r>>1;
      t=calc(mid);
      if (t>m)
	l=mid+1;
      else
	r=mid;
    }
    printf("%d\n",l);
    scanf("%d%d",&n,&m);
  }
  return 0;
}
