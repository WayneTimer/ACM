/*This Code is Submitted by Timer for Problem 1962 at 2011-10-30 23:35:33*/
#include <stdio.h>

int main()
{
  int o,p,i,n,f;
  int a[1001];
  long s;
  double sum;
  char e='%';
  scanf("%d",&o);
  for (p=1;p<=o;p++)
  {
    scanf("%d",&n);
    s=0;
    for (i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
      s=s+a[i];
    }
    sum=(double) s;
    sum=sum/n;
    f=0;
    for (i=0;i<n;i++)
      if (a[i]>sum) f++;
    sum=(double) f;
    sum=(100*sum)/n;
    printf("%.3f%c\n",sum,e);
  }
  return 0;
}