/*This Code is Submitted by Timer for Problem 2314 at 2012-07-09 11:31:28*/
#include <cstdio>
#include <cstring>

using namespace std;

int T,n,m;
int a[1005];

void qsort(int l,int r)
{
  int mid,t,i,j;
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
  int p,i,s;
  scanf("%d",&T);
  for (p=1;p<=T;p++)
  {
    memset(a,0,sizeof(a));
    printf("Scenario #%d:\n",p);
    scanf("%d %d",&n,&m);
    for (i=1;i<=m;i++)
      scanf("%d",&a[i]);
    qsort(1,m);
    s=0;
    for (i=m;i>=1;i--)
    {
      s++;
      n=n-a[i];
      if (n<=0) 
      {
        printf("%d\n",s);
        break;
      }
    }
    if (n>0) printf("impossible\n");
    printf("\n");
  }
  return 0;
}