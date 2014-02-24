/*This Code is Submitted by Timer for Problem 1131 at 2013-10-29 00:08:18*/
#include <cstdio>
#include <cstring>

typedef long long ll;

char s[100];
int n,m;
char ans[100];

int main()
{
  ll sum,t;
  int l;
  while (scanf("%s%d%d",s,&n,&m)==3)
  {
    l=strlen(s);
    l--;
    t=1;
    sum=0;
    while (l>=0)
    {
      if (s[l]>='A' && s[l]<='F')
        sum+=t*(s[l]-'A'+10);
      else
        sum+=t*(s[l]-'0');
      t*=n;
      l--;
    }
    if (m!=10)
    {
      l=0;
      while (sum)
      {
        t=sum%m;
        if (t<=9) s[l]='0'+t;
        else s[l]='A'+t-10;
        l++;
        sum/=m;
      }
      if (l>7)
        puts("  ERROR");
      else
      {
        t=7-l;
        while (t--) printf(" ");
        l--;
        while (l>=0)
        {
          printf("%c",s[l]);
          l--;
        }
        puts("");
      }
    }
    else
    {
      if (sum>9999999)
        puts("  ERROR");
      else
        printf("%7lld\n",sum);
    }
  }
  return 0;
}