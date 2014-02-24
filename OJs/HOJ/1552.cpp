/*This Code is Submitted by Timer for Problem 1552 at 2013-02-28 14:48:00*/
// HOJ 1552 (POJ 2689) 
// 类似题 HOJ 1552
// 筛大范围素数
// 思路：
// 通常这类题所求区间[L,R]，R-L都在10^6以内
// 那么就可以将区间映射到[0,R-L]内进行bool筛选
#include <cstdio>
#include <cstring>

#define MAXP 46341
#define D 1000001

int p[10000];
int m;

inline void init()
{
  int i,j;
  bool f[MAXP+1];
  memset(f,true,sizeof(f));
  for (i=2;i<=MAXP>>1;i++)
    if (f[i])
      for (j=2;i*j<=MAXP;j++)
        f[i*j]=false;
  m^=m;
  for (i=2;i<=MAXP+1;i++)
    if (f[i])
      p[++m]=i;
}

inline void work(long long l,long long r)
{
  bool f[D];
  long long t,j;
  int i,x1,x2,y1,y2,mymin,mymax,last;
  memset(f,true,sizeof(f));
  if (l==1) f[0]=false;
  for (i=1;i<=m;i++)
  {
    t=p[i];
    if (t<<1>r) break;
    j=l/t;
    if (l%t) j++;
    if (j<2) j=2;
    while (t*j<=r)
    {
      f[t*j-l]=false;
      j++;
    }
  }
  i^=i;
  last=-1;
  while (i<=r-l && !f[i]) i++;
  if (i>r-l)
  {
    puts("There are no adjacent primes.");
    return;
  }
  last=i;
  mymin=1000001;
  mymax=-1;
  for (i++;i<=r-l;i++)
    if (f[i])
    {
      if (i-last<mymin)
      {
        x1=last;
        y1=i;
        mymin=i-last;
      }
      if (i-last>mymax)
      {
        x2=last;
        y2=i;
        mymax=i-last;
      }
      last=i;
    }
  if (mymax>0)
    printf("%lld,%lld are closest, %lld,%lld are most distant.\n",x1+l,y1+l,x2+l,y2+l);
  else
    puts("There are no adjacent primes.");
}

int main()
{
  int x,y;
  init();
  while (scanf("%d%d",&x,&y)==2)
    work(x,y);
  return 0;
}