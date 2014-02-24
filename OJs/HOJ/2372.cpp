/*This Code is Submitted by Timer for Problem 2372 at 2013-03-06 12:15:08*/
#include <cstdio>

struct cyr
{
  long long s,v;
  int g;
};

int n;
cyr a[110];

int main()
{
  long long ans;
  int i,j,p,mymax;
  while (scanf("%d",&n)==1)
  {
    scanf("%lld",&a[1].v);
    a[1].s=a[1].v;
    a[1].g=1;
    ans=a[1].s;
    mymax=1;
    for (i=2;i<=n;i++)
    {
      scanf("%lld",&a[i].v);
      p=-1;
      for (j=1;j<i;j++)
      {
        if (a[j].v>=a[i].v)
        {
          if (p==-1) p=j;
          else if (a[j].s>a[p].s) p=j;
          else if (a[j].s==a[p].s && a[j].g>a[p].g) p=j;
        }
      }
      if (p==-1)
      {
        a[i].s=a[i].v;
        a[i].g=1;
      }
      else
      {
        a[i].s=a[p].s+a[i].v;
        a[i].g=a[p].g+1;
      }
      if (a[i].s>a[mymax].s)
        mymax=i;
      else if (a[i].s==a[mymax].s && a[i].g>a[mymax].g)
        mymax=i;
    }
    printf("%lld %d\n",a[mymax].s,a[mymax].g);
  }
  return 0;
}