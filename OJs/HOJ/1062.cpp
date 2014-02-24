/*This Code is Submitted by Timer for Problem 1062 at 2012-01-26 14:35:02*/
/* HOJ 1062 */
#include <stdio.h>
#include <string.h>

long a[100001];
long b[100001];

void qsort(long l,long r)
{
  long i,j,mid,t;
  i=l;
  j=r;
  mid=a[(l+r)/2];
  do
  {
    while (a[i]<mid) i++;
    while (a[j]>mid) j--;
    if (i<=j)
    {
      t=a[i];
      a[i]=a[j];
      a[j]=t;
      t=b[i];
      b[i]=b[j];
      b[j]=t;
      i++;
      j--;
    }
  } while (i<=j);
  if (l<j) qsort(l,j);
  if (i<r) qsort(i,r);
}

int main()
{
  long t,n,i,j,max,min;
  long s;
  scanf("%ld",&n);
  while (n!=0)
  {
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for (i=1;i<=n;i++)
    {
      scanf("%ld",&a[i]);
      b[i]=a[i];
    }
    qsort(1,n);
    for (i=n-1;i>=1;i--)
    { 
      a[i]=a[i]*a[i+1]+1;
    }
    min=a[1];
    for (i=2;i<=n;i++)
    {
      b[i]=b[i-1]*b[i]+1;
      t=b[i];
      j=i+1;
      while ((j<=n)&&(t>b[j]))
      {
        b[j-1]=b[j];
        j++;
      }
      j--;
      b[j]=t;
    }
    max=b[n];
    printf("%ld\n",max-min);
    scanf("%ld",&n);
  }
  return 0;
}