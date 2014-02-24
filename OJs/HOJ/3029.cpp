/*This Code is Submitted by Timer for Problem 3029 at 2012-07-24 19:57:10*/
#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

char e[150],temp[150],clhs[20005][150];
int z,n,q;
stack <int> w;

int getnum(char a[150])
{
  int i,l,j,g;
  int x,ans;
  memset(temp,0,sizeof(temp));
  l=strlen(a);
  i=1;
  j=0;
  while (a[i]!=',')
  {
    temp[j]=a[i];
    i++;
    j++;
  }
  g=1;
  i=l-2;
  ans=0;
  while (a[i]!=',')
  {
    x=a[i]-'0';
    x=x*g;
    ans+=x;
    g=g*10;
    i--;
  }
  return ans;
}

void cyr(char a[150])
{
  z++;
  strcpy(clhs[z],a);
}

int main()
{
  int x,now,i,j;
  while (scanf("%d%d",&n,&q)==2)
  {
    getchar();
    z=0;
    now=0;
    for (j=1;j<=n;j++)
    {
      gets(e);
      if (e[0]!='<') continue;
      if (e[1]=='/')
      {
        x=w.top();
        now-=x;
        w.pop();
      }
      else
      {
        x=getnum(e);
        w.push(x);
        now+=x;
        if (q==now) cyr(temp);
      }
    }
    printf("%d\n",z);
    for (i=1;i<=z;i++)
      printf("%s\n",clhs[i]);
  }
  return 0;
}