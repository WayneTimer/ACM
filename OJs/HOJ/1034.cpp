/*This Code is Submitted by Timer for Problem 1034 at 2013-10-25 13:04:34*/
#include <cstdio>
#include <vector>

using namespace std;

#define MAXN 510
#define pb push_back

char s[MAXN<<1];
int a[MAXN];
int b[MAXN];
int c[MAXN];
int al,bl,cl,mul_len;
char op;
vector <int> v[MAXN];

inline int work(int i,int &len,int f[])
{
  len=0;
  while (s[i]>='0' && s[i]<='9')
  {
    len++;
    f[len]=s[i]-'0';
    i++;
  }
  return i;
}

inline void output()
{
  int i,l,t,g;
  l=al;
  if (bl+1>l) l=bl+1;
  if (cl>l) l=cl;
  t=l-al;
  for (i=1;i<=t;i++)
    printf(" ");
  for (i=1;i<=al;i++)
    printf("%d",a[i]);
  puts("");
  t=l-bl-1;
  for (i=1;i<=t;i++)
    printf(" ");
  printf("%c",op);
  for (i=1;i<=bl;i++)
    printf("%d",b[i]);
  puts("");
  if (cl>bl+1)
    g=cl;
  else
    g=bl+1;
  t=l-g;
  for (i=1;i<=t;i++)
    printf(" ");
  for (i=1;i<=g;i++)
    printf("-");
  puts("");
  t=l-cl;
  for (i=1;i<=t;i++)
    printf(" ");
  for (i=cl;i>=1;i--)
    printf("%d",c[i]);
  puts("");
}

inline void add()
{
  int i,g,j;
  g=0;
  i=al;
  j=bl;
  cl=0;
  while (i>=1 || j>=1)
  {
    cl++;
    if (i>=1 && j>=1)
    {
      c[cl]=a[i]+b[j]+g;
      g=c[cl]/10;
      c[cl]%=10;
      i--;
      j--;
    }
    else if (i>=1)
    {
      c[cl]=a[i]+g;
      g=c[cl]/10;
      c[cl]%=10;
      i--;
    }
    else
    {
      c[cl]=b[j]+g;
      g=c[cl]/10;
      c[cl]%=10;
      j--;
    }
  }
  while (g)
  {
    cl++;
    c[cl]=g;
    g=c[cl]/10;
    c[cl]%=10;
  }
}

inline void sub()
{
  int i,j,g;
  i=al;
  j=bl;
  g=0;
  cl=0;
  while (i>=1 || j>=1)
  {
    cl++;
    if (i>=1 && j>=1)
    {
      c[cl]=a[i]-b[j]+g;
      if (c[cl]<0)
      {
        g=-1;
        c[cl]+=10;
      }
      else
        g=0;
      i--;
      j--;
    }
    else if (i>=1)
    {
      c[cl]=a[i]+g;
      if (c[cl]<0)
      {
        g=-1;
        c[cl]+=10;
      }
      else
        g=0;
      i--;
    }
    else
    {
      c[cl]=b[j]+g;
      if (c[cl]<0)
      {
        g=-1;
        c[cl]+=10;
      }
      else
        g=0;
      j--;
    }
  }
  while (c[cl]==0 && cl>1) cl--;
}

inline void out(int i,int l)
{
  int t,j,k;
  t=v[i].size();
  for (j=t-1;j>0;j--)
    if (v[i][j]>0) break;
  t=l-j-1;
  k=j;
  for (j=1;j<=t;j++) printf(" ");
  for (j=k;j>=0;j--)
    printf("%d",v[i][j]);
  puts("");
}

inline void mul()
{
  int i,j,k,g,x,u,p;
  mul_len=al;
  if (bl+1>mul_len) mul_len=bl+1;
  for (i=0;i<MAXN;i++)
  {
    v[i].clear();
    v[0].pb(0);
    v[0].pb(0);
  }
  k^=k;
  p^=p;
  for (j=bl;j>=1;j--)
  {
    k++;
    g=0;
    u=0;
    p=k;
    for (i=al;i>=1;i--)
    {
      x=a[i]*b[j]+g;
      g=x/10;
      x%=10;
      v[k].pb(x);
      v[0][p-1]+=x+u;
      u=v[0][p-1]/10;
      v[0][p-1]%=10;
      p++;
    }
    if (g) 
    {
      v[k].pb(g);
      v[0][p-1]+=g+u;
      u=v[0][p-1]/10;
      v[0][p-1]%=10;
      p++;
    }
    while (u)
    {
      v[0][p-1]+=u;
      u=v[0][p-1]/10;
      v[0][p-1]%=10;
      p++;
    }
  }
  p--;
  if (p>mul_len) mul_len=p;
  x=mul_len-al;
  for (i=1;i<=x;i++) printf(" ");
  for (i=1;i<=al;i++) printf("%d",a[i]);
  puts("");
  x=mul_len-bl-1;
  for (i=1;i<=x;i++) printf(" ");
  printf("*");
  for (i=1;i<=bl;i++) printf("%d",b[i]);
  puts("");
  if (bl>1)
  {
    g=v[1].size();
    while (v[1][g-1]==0) g--;
    if (bl+1>g) g=bl+1;
    x=mul_len-g;
    for (i=1;i<=x;i++) printf(" ");
    for (i=1;i<=g;i++) printf("-");
    puts("");
    for (i=1;i<=bl;i++)
      out(i,mul_len-i+1);
  }
  x=mul_len-p;
  for (i=1;i<=x;i++) printf(" ");
  for (i=1;i<=p;i++) printf("-");
  puts("");
  out(0,mul_len);
}

int main()
{
  int T,i;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%s",s);
    i=work(0,al,a);
    op=s[i];
    i++;
    work(i,bl,b);
    if (op=='+')
    {
      add();
      output();
    }
    else if (op=='-')
    {
      sub();
      output();
    }
    else
      mul();
    puts("");
  }
  return 0;
}