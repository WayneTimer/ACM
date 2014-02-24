/*This Code is Submitted by Timer for Problem 2255 at 2014-01-12 14:32:01*/
/*
矩阵快速幂

构造 
              0 q q
(f0 f1 s1) * (1 p p) = (f1 f2 s2)
              0 0 1
*/

#include <cstdio>
#include <cstring>

#define MM 3
#define MOD 10000000

typedef long long ll;

struct matrix
{
  ll a[MM][MM];
};

matrix operator * (matrix q,matrix w)
{
  matrix ret;
  int i,j,k;
  ll t;
  for (i=0;i<MM;i++)
    for (j=0;j<MM;j++)
    {
      t=0;
      for (k=0;k<MM;k++)
      {
        t+=q.a[i][k]*w.a[k][j]%MOD;
        t%=MOD;
      }
      ret.a[i][j]=t;
    }
  return ret;
}

matrix pow(matrix g,ll x)
{
  matrix ret;
  int i;
  memset(ret.a,0,sizeof(ret.a));
  for (i=0;i<MM;i++)
    ret.a[i][i]=1;
  while (x)
  {
    if (x&1)
      ret=ret*g;
    g=g*g;
    x>>=1;
  }
  return ret;
}

ll cal(ll a,ll b,ll p,ll q,ll x)
{
  if (x<-1) return 0;
  if (x==-1) return a;
  if (x==0) return a+b;
  matrix g;
  ll t;
  g.a[0][0]=g.a[2][0]=g.a[2][1]=0;
  g.a[1][0]=g.a[2][2]=1;
  g.a[0][1]=g.a[0][2]=q;
  g.a[1][1]=g.a[1][2]=p;
  g=pow(g,x);
  t=a*g.a[0][2]+b*g.a[1][2]+(a+b)*g.a[2][2];
  t%=MOD;
  return t;
}

int main()
{
  int T;
  ll a,b,p,q,s,e;
  ll s1,s2;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&p,&q,&s,&e);
    s1=cal(a,b,p,q,s-2);
    s2=cal(a,b,p,q,e-1);
    s1=s2-s1;
    while (s1<0) s1+=MOD;
    s1%=MOD;
    printf("%lld\n",s1);
  }
  return 0;
}