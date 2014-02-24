/*This Code is Submitted by Timer for Problem 1107 at 2012-03-09 21:38:41*/
#include <cstdio>
#include <cstring>

using namespace std;

int n,c;
int cyr[1001];
int p[1001];
int a[1500];

int main()
{
  int i,j,t;
  memset(cyr,0,sizeof(cyr));
  memset(p,0,sizeof(p));
  memset(a,true,sizeof(a));
  for (i=2;i<=1000;i++)
    if (a[i])
      for (j=2;j<=500;j++)
      {
        if ((i*j)>1000) break;
        a[i*j]=false;
      }
  j=0;
  for (i=1;i<=1000;i++)
  {
    if (a[i]) 
    {
      j++;
      p[j]=i;
    }
    cyr[i]=j;
  }
  while (scanf("%d%d",&n,&c)==2)
  {
    printf("%d %d:",n,c);
    c=c*2;
    if ((cyr[n]%2)==1) c--;
    if (c<cyr[n])
    {
      t=cyr[n]/2;
      if ((cyr[n]%2)==1)
      {
        t++;
        i=c/2;
        t=t-i;
        for (i=t;i<=t+c-1;i++)
          printf(" %d",p[i]);
      }
      else 
      {
        i=c/2;
        t=t-i+1;
        for (i=t;i<=t+c-1;i++)
          printf(" %d",p[i]);
      }
    }
    else
    {
      c=cyr[n];
      for (i=1;i<=c;i++)
        printf(" %d",p[i]);
    }
    printf("\n");
    printf("\n");
  }
  return 0;
}