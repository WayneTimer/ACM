/*This Code is Submitted by Timer for Problem 2991 at 2012-04-18 13:11:35*/
#include <stdio.h>
#include <string.h>

struct exin
{
  char s[500];
  double d;
};

int main()
{
  struct exin a[101][2];
  int j,k,i,t,n,l,u,maxt,mint,fushu;
  double x,w,max,min;
  char e[501];
  while (scanf("%d",&t)==1)
  {
  for (u=1;u<=t;u++)
  {
    scanf("%d",&n);
    getchar();
    gets(e);
    l=strlen(e);
    i=0;
    for (j=1;j<=n;j++) 
    {
      while (e[i]!='(') i++;
      i++;
      k=i;
      x=0;
      fushu=0;
      while ((e[k]!=',')&&(e[k]!='.'))
      {
        a[j][0].s[k-i]=e[k];
        if (e[k]=='-') 
        {
          fushu=1;
          k++;
          continue;
        }
        x=x*10+(e[k]-'0');
        k++;
      }
      if (e[k]=='.') 
      {
        a[j][0].s[k-i]=e[k];
        k++;
        w=10;
        while (e[k]!=',')
        {
          a[j][0].s[k-i]=e[k];
          x=x+(e[k]-'0')/w;
          k++;
          w=w*10;
        }
      }
      a[j][0].s[k-i]='\0';
      a[j][0].d=x;
      if (fushu) a[j][0].d=-a[j][0].d;
      i=k+1;
      k=i;
      x=0;
      fushu=0;
      while ((e[k]!=')')&&(e[k]!='.'))
      {
        a[j][1].s[k-i]=e[k];
        if (e[k]=='-') 
        {
          fushu=1;
          k++;
          continue;
        }
        x=x*10+(e[k]-'0');
        k++;
      }
      if (e[k]=='.') 
      {
        a[j][1].s[k-i]=e[k];
        k++;
        w=10;
        while (e[k]!=')')
        {
          a[j][1].s[k-i]=e[k];
          x=x+(e[k]-'0')/w;
          k++;
          w=w*10;
        }
      }
      a[j][1].s[k-i]='\0';
      a[j][1].d=x;
      if (fushu) a[j][1].d=-a[j][1].d;
    }
    max=a[1][1].d;
    maxt=1;
    min=a[1][1].d;
    mint=1;
    for (i=2;i<=n;i++)
    {
      if (a[i][1].d==max)
        if (a[i][0].d<a[maxt][0].d)
        {
          maxt=i;
        }
      if (a[i][1].d>max)
      {
        max=a[i][1].d;
        maxt=i;
      }
      if (a[i][1].d==min)
        if (a[i][0].d<a[mint][0].d)
        {
           mint=i;
        }
      if (a[i][1].d<min)
      {
        min=a[i][1].d;
        mint=i;
      }
    }
    printf("(%s,%s)",a[maxt][0].s,a[maxt][1].s);
    printf(" (%s,%s)\n",a[mint][0].s,a[mint][1].s);
  }
  }
  return 0;
}