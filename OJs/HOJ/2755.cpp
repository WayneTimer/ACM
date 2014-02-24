/*This Code is Submitted by Timer for Problem 2755 at 2011-11-10 01:27:57*/
#include <stdio.h>
#include <string.h>

int main()
{
  int c,o,i,j,t,r,f,u;
  char e[100],name[100];
  int a[3001],b[3001];
  scanf("%d",&c);
  for (o=1;o<=c;o++)
  {
    f=1;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%s",e);
    scanf("%d",&t);
    for (i=1;i<=t;i++)
    {
      scanf("%d",&u);
      a[i]=u;
    }
    for (i=1;i<t;i++)
      {
      for (j=i+1;j<=t;j++)
        if (a[i]>a[j])
        {
          r=a[i];
          a[i]=a[j];
          a[j]=r;
        }
      }
    scanf("%s",name);
    scanf("%s",e);
    scanf("%d",&r);
    for (i=1;i<=r;i++)
    {
      scanf("%d",&u);
      b[u]=1;
    }
    scanf("%s",e);
    scanf("%d",&r);
    for (i=1;i<=r;i++)
    {
      scanf("%d",&u);
      b[u]=1;
    }
    scanf("%s",e);
    scanf("%d",&r);
    for (i=1;i<=r;i++)
    {
      scanf("%d",&u);
      b[u]=1;
    }
    for (i=1;i<=t;i++)
    {
      if (!(b[a[i]]))
      {
        if (!(f)) printf(" ");
        f=0;
        printf("%d",a[i]);
      }
    }
    if (!(f)) printf("\n");
    if (f) printf("Super Da Lord says:%s well done!\n",name);
  }
  return 0;
}