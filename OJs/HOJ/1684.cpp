/*This Code is Submitted by Timer for Problem 1684 at 2011-11-25 19:29:45*/
#include <stdio.h>
#include <string.h>

int main()
{
  int n,i,j,c;
  char a[300][300];
  char x[300];
  scanf("%d",&n);
  getchar();
  c=1;
  while (n!=0)
  {
    printf("SET %d\n",c);
    j=0;
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++)
    {
      gets(x);
      if (i%2) printf("%s\n",x);
        else 
        {
          j++;
          strcpy(a[j],x);
        }
    }
    for (i=j;i>=1;i--)
      printf("%s\n",a[i]);
    scanf("%d",&n);
    getchar();
    c++;
  }
  return 0;
}