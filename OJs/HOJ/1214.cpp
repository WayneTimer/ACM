/*This Code is Submitted by Timer for Problem 1214 at 2013-10-25 20:23:18*/
#include <cstdio>
#include <cstring>

#define MAXF 50

typedef long long ll;

ll MAX;
ll f[MAXF];
int m,n;
char str[35000];
char a[100];
ll s;

inline void init()
{
  MAX=1;
  MAX<<=32;
  MAX--;
  f[0]=1;
  f[1]=2;
  m=1;
  while (f[m]<=MAX)
  {
    m++;
    f[m]=f[m-1]+f[m-2];
  }
  m--;
}

inline ll calc()
{
  int l,i,x;
  ll ret;
  memset(a,0,sizeof(a));
  l=strlen(str);
  ret=0;
  l--;
  i=0;
  x=0;
  while (l>=0)
  {
    if (str[l]=='1') 
    {
      ret+=f[i];
      a[i]=1;
      x=i;
    }
    i++;
    l--;
  }
  n=x+1;
  return ret;
}

inline bool check()
{
  int i;
  for (i=1;i<n;i++)
    if (a[i] && a[i-1])
      return false;
  return true;
}

inline void work()
{
  int i;
  bool flag;
  flag=true;
  while (flag)
  {
    flag=false;
    for (i=n-1;i>0;i--)
      if (a[i] && a[i-1])
      {
        a[i+1]=1;
        if (i+1>n-1) n++;
        a[i]=0;
        a[i-1]=0;
        flag=true;
      }
  }
  for (i=n-1;i>=0;i--)
    printf("%d",a[i]);
  puts("");
}

int main()
{
  int T;
  init();
  scanf("%d",&T);
  while (T--)
  {
    scanf("%s",&str);
    s=calc();
    if (check())
      printf("%lld in decimal, already in standard form\n",s);
    else
    {
      printf("%lld in decimal, whose standard form is ",s);
      work();
    }
  }
  return 0;
}