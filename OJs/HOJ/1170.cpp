/*This Code is Submitted by Timer for Problem 1170 at 2012-11-23 16:07:43*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[400];
char a[24];
bool t[30][30];
int l;

bool check()
{
  int i,j;
  for (i=0;i<l-1;i++)
  {
    for (j=i+1;j<l;j++)
      if (t[a[i]-'a'][a[j]-'a']) return false;
  }
  return true;
}

int main()
{
  int i,j;
  bool flag=false;
  while (gets(str))
  {
    if (flag) puts("");
      else flag=true;
    memset(t,false,sizeof(t));
    memset(a,0,sizeof(a));
    l=strlen(str);
    j^=j;
    for (i=0;i<l;i+=2)
    {
      a[j]=str[i];
      j++;
    }
    sort(a,a+j);
    gets(str);
    l=strlen(str);
    for (i=0;i<l;i+=4)
      t[str[i+2]-'a'][str[i]-'a']=true;
    l=j;
    if (check()) printf("%s\n",a);
    while (next_permutation(a,a+l))
      if (check()) printf("%s\n",a);
  }
  return 0;
}
 