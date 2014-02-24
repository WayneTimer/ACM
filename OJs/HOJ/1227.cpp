/*This Code is Submitted by Timer for Problem 1227 at 2011-11-09 00:03:33*/
#include <stdio.h>
#include <string.h>

int f[301][301];
char a[301],b[301];

int main()
{
  int x,y,i,j,l1,l2,max;
  while (scanf("%s%s",a,b)==2)
  {
    memset(f,0,sizeof(f));
    l1=strlen(a);
    l2=strlen(b);
    for (i=0;i<l1;i++)
      for (j=0;j<l2;j++)
      {
        if (a[i]==b[j])
        {
          x=i-1;
          y=j-1;
          if ((y<0)||(x<0)) f[i][j]=1;
            else f[i][j]=f[x][y]+1;
        } else
        {
          x=i-1;
          y=j-1;
          if (x<0) max=0; 
            else max=f[x][j];
          if ((y>=0)&&(f[i][y]>max))
            max=f[i][y];
          f[i][j]=max;
        }
      }
    printf("%d\n",f[l1-1][l2-1]);
  }
  return 0;
}