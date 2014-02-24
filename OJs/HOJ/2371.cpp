/*This Code is Submitted by Timer for Problem 2371 at 2012-07-10 19:09:18*/
#include <cstdio>
#include <cstring>

using namespace std;

const char week[7][15]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int a[10050];

void qsort(int l,int r)
{
  int mid,i,j,t;
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
      i++;
      j--;
    }
  } while (i<=j);
  if (l<j) qsort(l,j);
  if (i<r) qsort(i,r);
}

int main()
{
  int w,c,y,m,d;
  int n,p,i;
  m=9;
  d=18;
  p=0;
  while (scanf("%d",&n)==1)
  {
    p++;
    a[p]=n;
  }
  qsort(1,p);
  for (i=1;i<=p;i++)
  {
    n=a[i];
    c=n/100;
    y=n%100;
    w=c/4-2*c+y+y/4+(m+1)*13/5+d-1;
    while (w<0) w+=7;
    w=w%7;
    printf("%d-09-18 %s\n",n,week[w]);
  }
  printf("Never forget 9-18, folks.\n");
  return 0;
}