/*This Code is Submitted by Timer for Problem 1732 at 2011-12-04 21:02:03*/
#include <stdio.h>
#include <string.h>

int a[27];
int l;
char sum[400];

int dps(int dep)
{
  int i,x,t;
  if (dep<=0) 
  {
    printf("%s\n",sum);
    return 0;
  }
  for (i=1;i<=26;i++)
  {
    if (a[i]>0)
    {
      a[i]--;
      t=strlen(sum);
      sum[t]='a'+i-1;
      sum[t+1]='\0';
      dps(dep-1);
      sum[t]='\0';
      a[i]++;
    }
  }
  return 0;
}

int main()
{
  char e[30];
  int i;
  while (gets(e)!=NULL)
  {
    memset(a,0,sizeof(a));
    memset(sum,0,sizeof(sum));
    l=strlen(e);
    for (i=0;i<l;i++)
    {
      a[e[i]-'a'+1]++;
    }
    dps(l);
  }
  return 0;
}