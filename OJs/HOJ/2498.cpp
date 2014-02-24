/*This Code is Submitted by Timer for Problem 2498 at 2013-03-18 19:59:35*/
#include <cstdio>

char a[12];
char b[12];
int n;
long long ans;

int main()
{
  int i,j,k;
  long long t;
  scanf("%s",a);
  while (a[0]!='#')
  {
    scanf("%s",b);
    i=0;
    n=0;
    while (a[i]) 
    {
      if (a[i]=='?') n++;
      i++;
    }
    i=0;
    j=n;
    ans=0;
    while (a[i])
    {
      if (a[i]=='?')
      {
        j--;
        t=1;
        for (k=1;k<=j;k++)
          t*=10;
        t*='9'-b[i];
        ans+=t;
      }
      else if (a[i]>b[i])
      {
        t=1;
        for (k=1;k<=j;k++)
          t*=10;
        ans+=t;
        break;
      }
      else if (a[i]<b[i])
        break;
      i++;
    }
    printf("%lld\n",ans);
    scanf("%s",a);
  }
  return 0;
}