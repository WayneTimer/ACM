/*This Code is Submitted by Timer for Problem 1952 at 2012-07-31 11:10:02*/
#include <cstdio>
#include <cstring>

using namespace std;

char e[10000010];
int p[10000010];

void prefix(const char *str,int *next)
{
  int m,k,i;
  m=strlen(str);
  k=-1;
  next[0]=-1;
  for (i=1;i<m;i++)
  {
    while ((k!=-1) && (str[k+1]!=str[i]))
      k=next[k];
    if (str[k+1]==str[i]) k++;
    next[i]=k;
  }
}

int main()
{
  int l,x;
  gets(e);
  l=strlen(e);
  while (!((e[0]=='.')&&(l==1)))
  {
    memset(p,0,sizeof(p));
    prefix(e,p);
    x=l-1-p[l-1];
    printf("%d\n",l/x);
    gets(e);
    l=strlen(e);
  }
  return 0;
}