/*This Code is Submitted by Timer for Problem 1142 at 2012-11-17 10:55:43*/
#include <cstdio>
#include <cstring>

int n;
int m;
char e[200];
int a[6000];

int main()
{
  int j,o,l,i,k;
  char r;
  scanf("%d",&n);
  o^=o;
  while (n)
  {
    o++;
    printf("S-Tree #%d:\n",o);
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    getchar();
    gets(e);
    j=1;
    for (i=1;i<=n;i++)
      j*=2;
    for (i=0;i<j;i++)
    {
      r=getchar();
      if (r=='1') a[i]=1;
    }
    scanf("%d",&m);
    getchar();
    for (i=1;i<=m;i++)
    {
      int t;
      gets(e);
      l=strlen(e);
      t^=t;
      j=1;
      for (k=l-1;k>=0;k--)
      {
        if (e[k]=='1') t+=j;
        j*=2;
      }
      if (a[t]) putchar('1');
        else putchar('0');
    }
    puts("");
    puts("");
    scanf("%d",&n);
  }
  return 0;
}
 