/*This Code is Submitted by Timer for Problem 1703 at 2011-11-25 15:08:59*/
#include <stdio.h>
#include <string.h>

int main()
{
  char a[301][301];
  char x;
  int n,i,j,t;
  scanf("%d",&n);
  getchar();
  while (n!=0)
  {
    memset(a,0,sizeof(a));
    a[1][1]=getchar();
    x=getchar();
    i=1;
    j=1;
    while (x!='\n')
    {
      if ((j>=n)&&((i%2)!=0))
      {
        i++;
        a[i][j]=x;
        x=getchar();
        continue;
      }
      if ((j<=1)&&((i%2)==0))
      {
        i++;
        a[i][j]=x;
        x=getchar();
        continue;
      }
      if (i%2) j++;
        else j--;
      a[i][j]=x;
      x=getchar();
    }
    t=i;
    for (j=1;j<=n;j++)
    {
      for (i=1;i<=t;i++)
        printf("%c",a[i][j]);
    }
    printf("\n");
    scanf("%d",&n);
    getchar();
  }
  return 0;
}