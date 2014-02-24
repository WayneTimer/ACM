/*This Code is Submitted by Timer for Problem 2620 at 2013-03-08 21:21:07*/
#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,nn,mm;
int a[20100];
int b[20100];

int main()
{
  int i,j,s;
  scanf("%d%d",&n,&m);
  while (n || m)
  {
    nn=n;
    mm=m;
    for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
    for (i=1;i<=m;i++)
      scanf("%d",&b[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    i=1;
    j=1;
    s^=s;
    while (n)
    {
      if (n>m)
        break;
      while (i<=nn && j<=mm && a[i]<=b[j])
      {
        s+=b[j];
        n--;
        m--;
        i++;
        j++;
      }
      while (i<=nn && j<=mm && a[i]>b[j])
      {
        j++;
        m--;
      }
    }
    if (n)
      puts("Loowater is doomed!");
    else
      printf("%d\n",s);
    scanf("%d%d",&n,&m);
  }
  return 0;
}