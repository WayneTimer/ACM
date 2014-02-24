/*This Code is Submitted by Timer for Problem 2333 at 2013-03-06 00:37:18*/
#include <cstdio>

struct cyr
{
  int e,r;
};

int p,w;
int s;
char a[2000];
cyr v[30];

int main()
{
  int T,i,t;
  t=1;
  for (i=1;i<=18;i++)
  {
    v[i].e=(i-1)/3;
    v[i].r=t;
    t++;
    if (t>3) t-=3;
  }
  v[19].e=5;
  v[19].r=4;
  v[20].e=6;
  v[20].r=1;
  v[21].e=6;
  v[21].r=2;
  v[22].e=6;
  v[22].r=3;
  v[23].e=7;
  v[23].r=1;
  v[24].e=7;
  v[24].r=2;
  v[25].e=7;
  v[25].r=3;
  v[26].e=7;
  v[26].r=4;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d%d",&p,&w);
    getchar();
    gets(a);
    if (a[0]==' ') 
    {
      s=p;
      t=-1;
    }
    else 
    {
      t=v[a[0]-'A'+1].e;
      s=v[a[0]-'A'+1].r*p;
    }
    i=1;
    while (a[i])
    {
      if (a[i]==' ')
      {
        s+=p;
        t=-1;
      }
      else
      {
        if (v[a[i]-'A'+1].e==t) s+=w;
        t=v[a[i]-'A'+1].e;
        s+=v[a[i]-'A'+1].r*p;
      }
      i++;
    }
    printf("%d\n",s);
  }
  return 0;
}