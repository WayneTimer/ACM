/*This Code is Submitted by Timer for Problem 2363 at 2012-08-26 15:20:50*/
#include <cstdio>
#include <cstring>

#define N 10000

int n,up,s,num;
bool a[N],b[N];
int p[10];
char e[100];

inline void cyr()
{
  int i,x;
  for (i=1;i<=up;i++)
    if (a[i] && b[i])
    {
      num++;
      x=i;
      while (x>0)
      {
        p[x%10]++;
        x/=10;
      }
    }
  if (num==1)
    printf("%d address\n",num);
  else
    printf("%d addresses\n",num);
  for (i^=i;i<=9;i++)
  {
    s+=p[i];
    printf("Make %d digit %d\n",p[i],i);
  }
  if (s==1)
    printf("In total %d digit\n",s);
  else
    printf("In total %d digits\n",s);
  return;
}

int main()
{
  int T,i,x,y,w;
  scanf("%d",&T);
  while (T--)
  {
    up^=up;
    memset(a,false,sizeof(a));
    memset(b,true,sizeof(b));
    gets(e);
    gets(e);
    printf("%s\n",e);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      gets(e);
      e[0]=getchar();
      if (e[0]=='+')
      {
        getchar();
        scanf("%d%d%d",&x,&y,&w);
        while (x<=y)
        {
          a[x]=true;
          x+=w;
        }
        if (y>up) up=y;
      }
      else
      if (e[0]=='-')
      {
        getchar();
        scanf("%d%d%d",&x,&y,&w);
        while (x<=y)
        {
          b[x]=false;
          x+=w;
        }
      }
      else
      {
        ungetc(e[0],stdin);
        scanf("%d",&x);
        a[x]=true;
        if (x>up) up=x;
      }
    }
    memset(p,0,sizeof(p));
    s^=s;
    num^=num;
    cyr();
  }
  return 0;
}