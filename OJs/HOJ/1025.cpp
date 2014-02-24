/*This Code is Submitted by Timer for Problem 1025 at 2012-08-30 16:24:54*/
#include <cstdio>
#include <cstring>

int b[32];
int a[1010];
int n;

int main()
{
  int i,T,x,j;
  b[0]=1;
  for (i=1;i<=30;i++)
    b[i]=(b[i-1]<<1)+1;
  scanf("%d",&T);
  while (T--)
  {
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    if (n==0)
    {
      puts("0 []");
      continue;
    }
    i=30;
    x=n;
    j^=j;
    while (x>0)
    {
      while (x>=b[i])
      {
        x-=b[i];
        j++;
        a[j]=i;
      }
      i--;
    }
    printf("%d [%d",n,a[j]);
    for (i=j-1;i>=1;i--)
      printf(",%d",a[i]);
    printf("]\n");
  }
  return 0;
}