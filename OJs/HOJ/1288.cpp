/*This Code is Submitted by Timer for Problem 1288 at 2011-11-08 00:27:45*/
#include <stdio.h>
#include <string.h>

int main()
{
  long a[40010],b[40010];
  long n,p,i,ii,j,max;
  scanf("%ld",&n);
  for (ii=1;ii<=n;ii++)
  {
    scanf("%ld",&p);
    for (i=1;i<=p;i++)
    {
      scanf("%ld",&a[i]);
    }
    a[0]=0;
    memset(b,0,sizeof(b));
    max=1;
    b[1]=a[1];
    b[0]=0;
    for (i=2;i<=p;i++)
    {
      for (j=max;j>=0;j--)
      {
        if (a[i]>b[j]) 
        {
          if (j==max) 
          {
            max++;
            b[max]=a[i];
            break;
          } else
          {
            if (a[i]<b[j+1]) 
            {
              b[j+1]=a[i];
              break;
            }
            break;
          }
        }
      }
    }
    printf("%ld\n",max);
  }
  return 0;
}