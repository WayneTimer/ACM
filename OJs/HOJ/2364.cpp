/*This Code is Submitted by Timer for Problem 2364 at 2012-07-10 15:47:09*/
#include <cstdio>
#include <cstring>

using namespace std;

int a[1005];

void qsort(int l,int r)
{
  int mid,i,j,t;
  i=l;
  j=r;
  mid=a[(l+r)>>1];
  do
  {
    while (a[i]<mid) i++;
    while (a[j]>mid) j--;
    if (i<=j)
    {
      t=a[j];
      a[j]=a[i];
      a[i]=t;
      i++;
      j--;
    }
  } while (i<=j);
  if (l<j) qsort(l,j);
  if (i<r) qsort(i,r);
}

int main()
{
  int i,t,n,s,max;
  scanf("%d",&t);
  while (t--)
  {
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
    qsort(1,n);
    max=0;
    for (i=n;i>=1;i--)
    {
      s=a[i]*(n-i+1);
      if (s>max) max=s;
    }
    printf("%d\n",max);
  }
  return 0;
}