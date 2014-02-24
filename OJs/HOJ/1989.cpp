/*This Code is Submitted by Timer for Problem 1989 at 2012-09-20 20:38:07*/
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int a[800];
int b[800];
char e[800][502];
map <string,int> q;
int n;

int main()
{
  int t,top,i;
  int max,y;
  string temp;
  memset(a,0,sizeof(a));
  memset(e,0,sizeof(e));
  scanf("%s",e[1]);
  top^=top;
  n=1;
  while (e[n][0]!='#')
  {
    temp=e[n];
    t=q[temp];
    if (t==0)
    {
      top++;
      q[temp]=top;
      b[top]=n;
      a[top]++;
    }
    else
    {
      a[t]++;
    }
    n++;
    scanf("%s",e[n]);
  }
  n--;
  max^=max;
  for (i=1;i<=top;i++)
  {
    if (a[i]>max)
    {
      max=a[i];
      y=b[i];
    }
    else
    if (a[i]==max)
      if (strcmp(e[b[i]],e[y])<0)
        y=b[i];
  }
  printf("%s\n",e[y]);
  return 0;
}