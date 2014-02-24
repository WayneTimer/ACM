/*This Code is Submitted by Timer for Problem 1067 at 2012-02-05 15:56:29*/
#include <cstdio>
#include <string.h>

using namespace std;

int n;
int a[1002];

int main()
{
  int i;
  int max,t,m;
  bool flag;
  scanf("%d",&n);
  while (n!=0)
  {
    memset(a,0,sizeof(a));
    scanf("%d",&a[1]);
    while (a[1]!=0)
    {
    for (i=2;i<=n;i++)
      scanf("%d",&a[i]);
    max=1;
    flag=true;
    do
    {
      t=max;
      m=a[t];
      for (i=t+1;i<=n;i++)
      {
        if (a[i]<a[t])
        {
          if (a[i]<m)
            m=a[i];
          else 
          {
            flag=false;
            break;
          }
        } else
        {
          if (t==max)
            max=i;
        }
      }
    } while ((flag)&&(t!=max));
    if (flag) printf("Yes\n");
      else printf("No\n");
    scanf("%d",&a[1]);
    }
    printf("\n");
    scanf("%d",&n);
  }
  return 0;
}