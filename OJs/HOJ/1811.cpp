/*This Code is Submitted by Timer for Problem 1811 at 2011-11-24 00:43:19*/
#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
  int n,i,j,sum,xx;
  float x,y;
  double s,t,min;
  float a[101][101],w[101][2];
  int b[101];
  while (scanf("%d",&n)==1)
  {
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(w,0,sizeof(w));
    for (i=1;i<=n;i++)
    {
      scanf("%f%f",&x,&y);
      w[i][0]=x;
      w[i][1]=y;
      for (j=1;j<i;j++)
      {
        t=(w[j][0]-x)*(w[j][0]-x);
        t=t+(w[j][1]-y)*(w[j][1]-y);
        a[i][j]=sqrt(t);
        a[j][i]=a[i][j];
      }
    }
    b[1]=1;
    sum=1;
    s=0;
    while (sum<n)
    {
      min=999999999;
      for (i=1;i<=n;i++)
        if (b[i])
        {
          for (j=1;j<=n;j++)
            if (i!=j)
            {
              if (!(b[j]))
              {
                if (a[i][j]<min)
                {
                  min=a[i][j];
                  xx=j;
                }
              }
            }
        }
      b[xx]=1;
      s=s+min;
      sum++;
    }
    printf("%.2f\n",s);
  }
  return 0;
}