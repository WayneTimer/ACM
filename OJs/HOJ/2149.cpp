/*This Code is Submitted by Timer for Problem 2149 at 2013-02-04 23:48:19*/
#include <cstdio>
#include <cstring>

int n;
int a[26];
int b[26];

int main()
{
  int i,s,t,j;
  char e[500];
  while (scanf("%d",&n)==1)
  {
    getchar();
    for (i=1;i<=n;i++)
    {
      gets(e);
      memset(a,0,sizeof(a));
      memset(b,0,sizeof(b));
      s^=s;
      j^=j;
      while (e[j] && e[j]!='\n')
      {
        a[e[j]-'a']++;
        j++;
      }
      gets(e);
      j^=j;
      while (e[j] && e[j]!='\n')
      {
        b[e[j]-'a']++;
        j++;
      }
      for (j=0;j<26;j++)
      {
        t=a[j]-b[j];
        if (t<0) t=-t;
        s+=t;
      }
      printf("Case #%d:  %d\n",i,s);
    }
  }
  return 0;
}