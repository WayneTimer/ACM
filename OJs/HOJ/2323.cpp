/*This Code is Submitted by Timer for Problem 2323 at 2012-07-10 14:26:27*/
#include <cstdio>
#include <cstring>

using namespace std;

int n;

int main()
{
  int i,j,p,l,u;
  char s[200];
  int a[200];
  int w,e,g;
  scanf("%d",&n);
  getchar();
  for (i=1;i<=n;i++)
  {
    memset(a,0,sizeof(a));
    gets(s);
    l=strlen(s);
    j=l-1;
    while (s[j]!=' ') j--;
    u=j+1;
    j--;
    p=l-1;
    w=-1;
    g=0;
    while ((p>=u)||(j>=0))
    {
      e=g;
      g=0;
      w++;
      if (p>=u) 
      {
        e+=s[p]-'0';
        p--;
      }
      if (j>=0)
      {
        e+=s[j]-'0';
        j--;
      }
      if (e>=2) 
      {
        g=1;
        e=e-2;
      }
      a[w]=e;
    }
    if (g>0)
    {
      w++;
      a[w]=1;
    }
    printf("%d ",i);
    while ((a[w]==0)&&(w>0)) w--;
    for (j=w;j>=0;j--)
      printf("%d",a[j]);
    printf("\n");
  }
  return 0;
}