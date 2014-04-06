#include <cstdio>
#include <cstring>

int n,r;
int a[300][300];
int w[300][300];

int main()
{
  int i,j,k,up,top;
  while (scanf("%d%d",&n,&r)==2)
  {
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    memset(w,0,sizeof(w));
    up=r+1;
    if (up>n) up=n;
    for (i=1;i<=up;i++)
      for (j=1;j<=up;j++)
        w[1][1]+=a[i][j];
    for (i=1;i<=n;i++)
    {
      if (i!=1)
      {
        w[i][1]=w[i-1][1];
        if (i+r<=n)
        {
          for (j=1;j<=up;j++)
  	    w[i][1]+=a[i+r][j];
        }
        if (i-1-r>=1)
  	  for (j=1;j<=up;j++)
  	    w[i][1]-=a[i-1-r][j];
      }
      for (j=2;j<=n;j++)
      {
        w[i][j]=w[i][j-1];
        top=i+r;
        if (top>n) top=n;
        if (j+r<=n)
        {  
          k=i-r;
          if (k<1) k=1;
          for (;k<=top;k++)
            w[i][j]+=a[k][j+r];
        }
        if (j-1-r>=1)
        {
	  k=i-r;
	  if (k<1) k=1;
	  for (;k<=top;k++)
	    w[i][j]-=a[k][j-1-r];
        }
      }
    }
    for (i=1;i<=n;i++)
    {
      for (j=1;j<n;j++)
        printf("%d ",w[i][j]);
      printf("%d\n",w[i][n]);
    }
  }
  return 0;
}
