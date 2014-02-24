/*This Code is Submitted by Timer for Problem 2689 at 2012-03-25 12:56:44*/
#include <cstdio>
#include <cstring>

using namespace std;

int a[106];
int n,m;

int main()
{
  int i,s,t,v,x,k,max,j;
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
    for (i=1;i<=m;i++)
    {
      scanf("%d",&x);
      if (x==0)
      {
        scanf("%d%d",&k,&v);
        a[k]=v;
      }
      if (x==1)
      {
        scanf("%d%d%d",&s,&t,&v);
        max=-1;
        for (j=s;j<=t;j++)
          if (a[j]<=v)
            if (a[j]>max)
              max=a[j];
        if (max==-1) printf("0\n");
          else printf("%d\n",max);
      }
    }
  }
  return 0;
}