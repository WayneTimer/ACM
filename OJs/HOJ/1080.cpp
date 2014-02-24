/*This Code is Submitted by Timer for Problem 1080 at 2011-11-07 00:04:47*/
#include <stdio.h>
#include <string.h>

int main()
{ 
  char a[2][5000];
  int r,l,i,p,q,s,t,j,u;
  char e;
  memset(a,'\0',sizeof(a));
  scanf("%s",a[0]);
  while (!(a[0][0]=='0'))
  {
  p=1;
  q=0;
  l=strlen(a[0]);
  while (l>1)
  {
    t=p;
    p=q;
    q=t;
    a[q][0]='0';
    r=0;
    for (i=0;i<=(l-1);i++)
    {
      s=a[p][i]-'0';
      j=0;
      a[q][j]=a[q][j]+s;
      while ((a[q][j]-'0')>9)
      {
        a[q][j]=(a[q][j]-'0')%10+'0';
        if ((j+1)>r)
        {
          r++;
          a[q][r]='0';
        }
        a[q][j+1]++;
        j++;
      }
    }
    l=r+1;
  }
  printf("%d\n",a[q][0]-'0');
  memset(a[0],'\0',sizeof(a[0]));
  memset(a[1],'\0',sizeof(a[1]));
  scanf("%s",a[0]);
  }
  return 0;
}