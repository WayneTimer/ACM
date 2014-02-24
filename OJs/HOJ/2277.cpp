/*This Code is Submitted by Timer for Problem 2277 at 2012-05-01 22:03:39*/
#include <cstdio>
#include <cstring>

using namespace std;

int n;

int main()
{
  char e[51];
  int l,i,a,s,n,m;
  bool flag;
  scanf("%d",&n);
  getchar();
  getchar();
  while (gets(e)!=NULL)
  {
    s=0;
    m=0;
    flag=true;
    do
    {
      m++;
      l=strlen(e);
      a=0;
      for (i=0;i<l;i++)
        a=a*10+e[i]-'0';
      if (flag) 
      {
        n=a;
        flag=false;
      }
      else s=s+a;
    }
    while ((gets(e)!=NULL)&&(e[0]!='\0'));
    if ((s%n)==0) printf("YES\n");
      else printf("NO\n");
  }
  return 0;
}