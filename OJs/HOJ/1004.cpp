/*This Code is Submitted by Timer for Problem 1004 at 2012-01-19 23:24:09*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

long long b,cyr;
int v[100001],w[100000];

int check(long long t)
{
  long long i;
  for (i=1;i<=cyr;i++)
  {
    if (w[i]>=t) return 1;
    if ((t%w[i])==0) return 0;
  }
  return 1;
}

long long dps(long long y)
{
  char a[50];
  long long num,l,i;
  sprintf(a,"%lld",y);
  l=strlen(a);
  for (i=0;i<l;i++)
  {
    a[2*l-i]=a[i];
  }
  a[2*l+1]='\0';
  for (i=0;i<=9;i++)
  {
    a[l]='0'+i;
    num=atol(a);
    if (num>b) return num;
    if (check(num)) printf("%lld\n",num);
  }
  return num;
}

void init()
{
  long i,j;
  memset(v,0,sizeof(v));
  memset(w,0,sizeof(w));
  v[1]=1;
  for (i=2;i<=50000;i++)
  {
    for (j=2;(i*j)<=100000;j++)
      v[i*j]=1;
  }
  j=0;
  for (i=2;i<=100000;i++)
    if (v[i]==0) 
    {
      j++;
      w[j]=i;
    }
  cyr=j;
}

int main()
{
  long long s,a,x,i;
  char u[50];
  init();
  while (scanf("%lld%lld",&a,&b)==2)
  {
    if (a<=11)
    {
      if (b<=11) x=b;
        else x=11;
      if ((2>=a)&&(2<=x)) printf("2\n");
      if ((3>=a)&&(3<=x)) printf("3\n");
      if ((5>=a)&&(5<=x)) printf("5\n");
      if ((7>=a)&&(7<=x)) printf("7\n");
      if ((11>=a)&&(11<=x)) printf("11\n");
    }
    if (b>11)
    {
      i=1;
      while (1)
      {
        s=dps(i);
        if (s>b) break;
        i++;
        sprintf(u,"%lld",i);
        u[strlen(u)]='\0';
        switch (u[0])
        {
          case '2':
            u[0]='3';
            i=atol(u);
            break;
          case '4':
            u[0]='7';
            i=atol(u);
            break;
          case '5':
            u[0]='7';
            i=atol(u);
            break;
          case '6':
            u[0]='7';
            i=atol(u);
            break;
          case '8':
            u[0]='9';
            i=atol(u);
            break;
        }
      }
    }
  }
  return 0;
}
