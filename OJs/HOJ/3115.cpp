/*This Code is Submitted by Timer for Problem 3115 at 2013-07-22 08:47:57*/
/*
反状态压缩——把数据转换成20位的01来进行运算

因为只有20位，而且&,|,^都不会进位，那么一位一位地看，每一位不是0就是1，这样求出每

一位是1的概率，再乘以该位的十进制数，累加，就得到了总体的期望。

对于每一位，状态转移方程如下：

f[i][j]表示该位取前i个数，运算得到j(0或1)的概率是多少。

f[i][1]=f[i-1][1]*p[i]+根据不同运算符和第i位的值运算得到1的概率。

f[i][0]同理。

初始状态：f[0][0~1]=0或1（根据第一个数的该位来设置）

每一位为1的期望 f[n][1]
*/
#include <cstdio>
#include <cstring>

double f[201][2];
int a[201];
double p[201];
char op[201];
int n;
double sum;
char b[201][20];

inline void makebit()
{
  int i,j,x;
  memset(b,0,sizeof(b));
  for (i=0;i<=n;i++)
  {
    x=a[i];
    j=0;
    while (x>0)
    {
      b[i][j]=x&1;
      j++;
      x=x>>1;
    }
  }
}

double DP(int x)
{
  int i;
  memset(f,0,sizeof(f));
  if (b[0][x])
    f[0][1]=1;
  else
    f[0][0]=1;
  for (i=1;i<=n;i++)
  {
    f[i][0]=f[i-1][0]*p[i];
    f[i][1]=f[i-1][1]*p[i];
    if (op[i]=='&')
    {
      if (b[i][x])
      {
        f[i][1]+=f[i-1][1]*(1-p[i]);
        f[i][0]+=f[i-1][0]*(1-p[i]);
      }
      else
      {
        f[i][0]+=f[i-1][1]*(1-p[i]);
        f[i][0]+=f[i-1][0]*(1-p[i]);
      }
    }
    if (op[i]=='|')
    {
      if (b[i][x])
      {
        f[i][1]+=f[i-1][1]*(1-p[i]);
        f[i][1]+=f[i-1][0]*(1-p[i]);
      }
      else
      {
        f[i][1]+=f[i-1][1]*(1-p[i]);
        f[i][0]+=f[i-1][0]*(1-p[i]);
      }
    }
    if (op[i]=='^')
    {
      if (b[i][x])
      {
        f[i][1]+=f[i-1][0]*(1-p[i]);
        f[i][0]+=f[i-1][1]*(1-p[i]);
      }
      else
      {
        f[i][1]+=f[i-1][1]*(1-p[i]);
        f[i][0]+=f[i-1][0]*(1-p[i]);
      }
    }
  }
  return f[n][1];
}

int main()
{
  int x,T,i;
  T=0;
  while (scanf("%d",&n)==1)
  {
    for (i=0;i<=n;i++)
      scanf("%d",&a[i]);
    getchar();
    for (i=1;i<=n;i++)
    {
      op[i]=getchar();
      getchar();
    }
    for (i=1;i<=n;i++)
      scanf("%lf",&p[i]);
    sum=0;
    makebit();
    for (i=0;i<20;i++)
      sum=sum+(1<<i)*DP(i);
    T++;
    printf("Case %d:\n",T);
    printf("%.6lf\n",sum);
  }
  return 0;
}